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
    //Initializing all values of members to nullptr so they aren't random 
    //values from memory
    for (int i = 0; i < max_array_size; i++)
        members[i] = nullptr;
}

StudentArrayV3::~StudentArrayV3(){
    for (int i = 0; i < number_of_students; i++){
        delete members[i];
        members[i] = nullptr;
    }
    cout << "Memory Freed\n";
}

void StudentArrayV3::add(){
    members[number_of_students] = new Student;
    number_of_students++;
}

void StudentArrayV3::write(){
    for (int i = 0; i < number_of_students; i++){
        members[i]->write();
    }
}