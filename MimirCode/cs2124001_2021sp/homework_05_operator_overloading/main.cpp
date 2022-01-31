/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   This file is used to thoroughly test the code written in both the
 *          other header files as well as the other implementation files
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      2/22/2021
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    February 22nd, 2021
 *******************************************************************************
**/

#include<stdexcept>
#include<iostream>
    using std::cout;
    using std::endl;
    using std::cin;
#include "Fraction.h"

int main(){
    //Initializing two fractions
    Fraction f1 {2, 5};
    Fraction f2 {5, 2};
    
    cout << "\tTesting add function\n";
    cout << "f1 (2/5) + 2 = 12/5\n";
    cout << "Result: " << f1.add(2) << endl << endl;
    
    cout << "\tTesting accessors\n";
    cout << "Numerator: 2, Denominator: 5\n";
    cout << "Actual - N: " << f1.get_numerator() << ", D: " 
        << f1.get_denominator() << endl << endl;
    
    cout << "\tTesting Addition Operators\n";
    cout << "f1 (2/5) + 2 = 12/5\n";
    cout << "Result: " << f1 + 2 << endl << endl;
    cout << "f1 (2/5) + f2 (5/2) = 2/1\n";
    cout << "Result: " << f1 + f2 << endl << endl;
    cout << "2 + f1 (2/5) = 12/5\n";
    cout << "Result: " << 2 + f1 << endl << endl;
    
    cout << "\tTesting Subtraction Operators\n";
    cout << "f2 (5/2) - 1 = 3/2\n";
    cout << "Result: " << f2 - 1 << endl << endl;
    cout << "f2 (5/2) - f1 (2/5) = 21/10\n";
    cout << "Result: " << f2 - f1 << endl << endl;
    cout << "2 - f1 (2/5) = 8/5\n";
    cout << "Result: " << 2 - f1 << endl << endl;
    
    cout << "\tTesting Multiplication Operators\n";
    cout << "f1 (2/5) * 2 = 4/5\n";
    cout << "Result: " << f1 * 2 << endl << endl;
    cout << "f1 (2/5) * f2 (5/2) = 1/1\n";
    cout << "Result: " << f1 * f2 << endl << endl;
    cout << "2 * f2 (5/2) = 5/1\n";
    cout << "Result: " << 2 * f2 << endl << endl;
    
    cout << "\tTesting Division Operators\n";
    cout << "f1 (2/5) / 2 = 1/5\n";
    cout << "Result: " << f1 / 2 << endl << endl;
    cout << "f2 (5/2) / f1 (2/5) = 25/4\n";
    cout << "Result: " << f2 / f1 << endl << endl;
    cout << "2 / f1 (2/5) = 5/1\n";
    cout << "Result: " << 2 / f1 << endl << endl;
    
    return 0;
}