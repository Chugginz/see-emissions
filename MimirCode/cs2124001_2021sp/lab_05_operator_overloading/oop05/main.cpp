/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      2/15/2021
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    February 15th, 2021
 *******************************************************************************
**/

#include<stdexcept>
#include<iostream>
    using std::cout;
    using std::endl;
    using std::cin;
#include "Fraction.h"

int main(){
    
    // Part 1
    Fraction f1 {3, 5};
    cout << "f1: ";
    f1.write();
    cout << endl;
    
    // Part 2
    Fraction f2 = f1.add(2);
    cout << "f2: ";
    f2.write();
    cout << endl;
    
    //Part 3
    Fraction f3 = f1.operator+(2);
    cout << "f3: ";
    f3.write();
    cout << endl;
    
    //Part 3.5ish
    Fraction f4 = f1 + 2;
    cout << "f4: ";
    f4.write();
    cout << endl;
    
    //Part 4
    cout << "f1 + f2: ";
    Fraction f5 = f1 + f2;
    f5.write();
    cout << endl;
        
    cout << "f2 + f1: ";
    Fraction f6 = f2 + f1;
    f6.write();
    cout << endl;
    
    cout << "f1 + f2 + f3: ";
    Fraction f7 = f1 + f2 + f3;
    f7.write();
    cout << endl;
    
    //Part 5
    cout << " 1 + f1:      ";
    Fraction f8 = 1 + f1;
    f8.write();
    cout << endl;
    
    //Part 6
    cout << "f1 (w/ <<):   " << f1 << endl;
    
    return 0;
}