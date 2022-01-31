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
    if (size > 0){
        members = new Student[size];
        number_of_students = size;
        cout << "\nThe new number of students is " << size << endl;
    }
}

StudentArrayV2::~StudentArrayV2(){
    delete [] members;
    members = nullptr;
    cout << "Memory Freed\n";
}

void StudentArrayV2::write(){
    for (int i = 0; i < number_of_students; i++){
        members[i].write();
    }
}