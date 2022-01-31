// @ StudentArrayV4.cpp

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
#include <string>
#include <vector>    
#include <iomanip>
#include "Student.h"
#include "StudentArrayV2.h"
#include "StudentArrayV3.h"
#include "StudentArrayV4.h"

StudentArrayV4::StudentArrayV4(){
    //Set physical size to 3 according to lab
    physicalArraySize = 3;
    //Set members equal to an array of pointers to an object
    members = new Student*[physicalArraySize];
}

StudentArrayV4::~StudentArrayV4(){
    //For each student
    for (int i = 0; i < number_of_students; i++){
        //Delete the student information
        delete members[i];
        //Set student information to nullptr so it's not accidentally
        // brought in later
        members[i] = nullptr;
    }
    //Delete the array members now
    delete [] members;
    //Also set it to nullptr
    members = nullptr;
    //Let user know memory was freed (destructor has fired off)
    cout << "Memory Freed\n";
}

void StudentArrayV4::add(){
    //If the number of students equals the array size
    if (number_of_students == physicalArraySize){
        //Create a copy of the array
        Student** original = members;
        //Set members equal to the physical size of the array plus 3
        members = new Student*[physicalArraySize + 3];
        for (int i = 0; i < number_of_students; i++){
            //Now set member element as the loop increments same as copy element
            members[i] = original[i];
        }
        for (int i = 0; i < number_of_students; i++){
            //Set copy element to nullptr so it's not accidentally brought
            // in later
            original[i] = nullptr;
        }
        //Delete the copied array
        delete [] original;
        //Set the copy array to nullptr to precent accidental later usage
        original = nullptr;
    }
    //Set the value at index of number of students equal to a new student
    members[number_of_students] = new Student;
    //Increment number of new students
    number_of_students++;
}

void StudentArrayV4::write(){
    for (int i = 0; i < number_of_students; i++){
        //Use the element at that index's write method
        members[i]->write();
    }
}