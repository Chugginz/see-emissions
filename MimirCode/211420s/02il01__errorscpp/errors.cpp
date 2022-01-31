/**
 *******************************************************************************
 * @file    erros.cpp
 * @brief   Correcting programming errors
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

#include<iomanip>						
    using std::fixed;					
	using std::setprecision;	

const double PAY_RATE = 12.50;

int main()
{
    cout << "Enter number of hours worked: ";
	double hours;
	cin >> hours;
	
	double netPay;
	netPay = hours * PAY_RATE;

	cout << fixed << setprecision(2);	
	cout << "The net pay is $" << netPay << endl;
	cout << "Exiting..." << endl;
	return 0;
}
