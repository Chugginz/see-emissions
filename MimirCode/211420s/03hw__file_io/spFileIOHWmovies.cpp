/**
 *******************************************************************************
 * @file    spFileIOHWmovies.cpp
 * @brief   This file will display a list of movies along with statistics on 
 *          them
 *
 * @remarks
 *      Course:        Computer Science nnnn, Spring 2020
 *      Due Date:      e.g. Monday, February 3
 *      Instructor:    Gidget Schrivner
 *
 * @author  Christian Huggins
 * @date    January 29, 2020
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
    
#include<fstream>
    using std::ifstream;
    
#include<string>
    using std::string;

int main()
{
    string title;
    getLine(cin, title, "\n");
    cout << title << endl;
    
    return 0;
}
