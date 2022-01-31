// @ StudentArrayV1.cpp

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
#include <string>
#include <vector>    
#include <iomanip>
#include "StudentArrayV1.h"
#include "Student.h"

void StudentArrayV1::write(){
    //As i increments but is less than the number of members
    for (int i = 0; i < n_members; i++){
        //Use the element at that index's write method
        members[i].write();
    }
}