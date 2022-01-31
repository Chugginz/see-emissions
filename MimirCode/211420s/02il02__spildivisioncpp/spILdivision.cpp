/**
 *******************************************************************************
 * @file    spILdivision.cpp
 * @brief   Using the division algorithm
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      e.g. Wednesday, January 22
 *      Instructor:    Gidget Scrivner
 *
 * @author  Christian Huggins
 * @date    1/22/2020
 *******************************************************************************
**/

#include<iostream>
    using std::cin;
    using std::cout;
    using std::endl;
    
int main()
{
    cout << "Enter an integer for the dividend: ";
    int a, d;
    cin >> a;
    cout << "Enter another non zero integer for the divisor: ";
    cin >> d;
    
    int r, q;
    r = a % d;
    q = (a - r) / d;
    
    cout << "If a = " << a << " and d = " << d << ", then q = " << q <<
    " and r = " << r << ", since " << a << " = (" << q << ")(" << d <<
    ") + " << r << "." << endl;
    cout << "When dividing a negative, you may receive a wrong answer" << endl;
    return 0;

}
