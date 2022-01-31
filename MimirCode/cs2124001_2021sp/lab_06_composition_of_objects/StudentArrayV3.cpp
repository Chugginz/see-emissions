// @ StudentArrayV3.cpp

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

StudentArrayV3::StudentArrayV3(){
    for (int i = 0; i < max_array_size; i++)
        //Initializing all values of members to nullptr so they aren't random 
        //values from memory
        members[i] = nullptr;
}

StudentArrayV3::~StudentArrayV3(){
    //As i increments and is less than number of students
    for (int i = 0; i < number_of_students; i++){
        //Delete the element at index i of the array members
        delete members[i];
        //Set the element to nullptr so it's not accidentally used later
        members[i] = nullptr;
    }
    //Let user know the memory has been freed (deconstructor has fired)
    cout << "Memory Freed\n";
}

void StudentArrayV3::add(){
    //Set the value of element at index number of students to
    // a new student object
    members[number_of_students] = new Student;
    //Increment number of number of students
    number_of_students++;
}

void StudentArrayV3::write(){
    for (int i = 0; i < number_of_students; i++){
        //Use the element at that index's write method
        members[i]->write();
    }
}