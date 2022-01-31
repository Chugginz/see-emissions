/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      9/28/2020
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    September 28, 2020
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
#include "StudentArrayV1.h"
#include "StudentArrayV2.h"
#include "StudentArrayV3.h"
#include "StudentArrayV4.h"

int main( ) {
    // version 1
    StudentArrayV1 cs1114;

    cout << "contents of cs1114:\n";
    cs1114.write( );
    
    // version 2
    cout << "\nEnter the number of students for version 2: ";
    int number_of_students;
    cin >> number_of_students;

    StudentArrayV2 cs2114( number_of_students );
    cout << "contents of cs2114:\n";
    cs2114.write( );
    
    // version 3
    StudentArrayV3 cs2124;
    cout << "Enter Student data for version 3 (y/n)? ";
    char option;
    cin >> option;
    while ( option == 'y' || option == 'Y' ) {
        cs2124.add( );
        cout << "Enter more student data (y/n)? ";
        cin >> option;
    }
    cout << "contents of cs2124:\n";
    cs2124.write( );
    
    // version 4
    StudentArrayV4 cs2134;
    cout << "Enter Student data for version 4 (y/n)? ";
    cin >> option;
    while ( option == 'y' || option == 'Y' ) {
        cs2134.add( );
        cout << "Enter more student data (y/n)? ";
        cin >> option;
    }
    cout << "contents of cs2134:\n";
    cs2134.write( );
    
    return 0;
}