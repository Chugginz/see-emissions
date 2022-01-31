// @ StudentArrayV2.cpp

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
#include <string>
#include <vector>    
#include <iomanip>
#include "StudentArrayV2.h"
#include "Student.h"

StudentArrayV2::StudentArrayV2(int size){
    //If size is greater than 0
    if (size > 0){
        //Initialize members to be an array of pointer to an object
        // Student with the size given
        members = new Student[size];
        //Set the number of students equal to size
        number_of_students = size;
        //Let the user know the new number of students
        cout << "\nThe new number of students is " << size << endl;
    }
}

StudentArrayV2::~StudentArrayV2(){
    //Delete the array members
    delete [] members;
    //Set the array members to nullptr so it's not accidentally used later on 
    members = nullptr;
    //Let user know the memory has be freed (destructor fired off)
    cout << "Memory Freed\n";
}

void StudentArrayV2::write(){
    //As i increments but is less than number of students
    for (int i = 0; i < number_of_students; i++){
        //Use the element at that index's write method
        members[i].write();
    }
}