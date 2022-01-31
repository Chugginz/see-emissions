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
    physicalArraySize = 3;
    for (int i = 0; i < physicalArraySize; i++)
        members[i] = nullptr;
}

StudentArrayV4::~StudentArrayV4(){
    for (int i = 0; i < number_of_students; i++){
        delete members[i];
        members[i] = nullptr;
    }
    cout << "Memory Freed\n";
}

void StudentArrayV4::add(){
    if (number_of_students == physicalArraySize){
        Student** copy = members;
        members = new Student*[physicalArraySize + 3];
        for (int i = 0; i < number_of_students; i++){
            members[i] = copy[i];
        }
        for (int i = 0; i < number_of_students; i++){
            delete copy[i];
            copy[i] = nullptr;
        }
    }
    members[number_of_students] = new Student;
    number_of_students++;
}

void StudentArrayV4::write(){
    for (int i = 0; i < number_of_students; i++){
        members[i]->write();
    }
}