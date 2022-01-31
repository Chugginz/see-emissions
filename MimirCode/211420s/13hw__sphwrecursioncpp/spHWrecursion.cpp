/**
 *******************************************************************************
 * @file    spHWrecursion.cpp
 * @brief   This program executes three different functions
 *          that calculates three different series.
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Monday, April 20
 *      Instructor:    Nancy Draganjac
 *
 * @author  Christian Huggins
 * @date    April 20, 2020
 *******************************************************************************
**/

#include<iostream>
    using std::cin;
    using std::cout;
    using std::endl;
    
#include<iomanip>
    using std::fixed;
    using std::setprecision;

/**
 * @brief       This function calculates a series
 *
 * @detailed    The calculation of the series 1/i is done given
 *              any number, from i -> 0.
 *              
 * @param      i     Any number chosen
**/

double seriesFinder(double i)
{
    double result = 0;
    
    if (i > 0)
        result = (1 / i) + seriesFinder(i - 1);
    else
        result = 0;
        
    return result;
}

/**
 * @brief       This function calculates a series
 *
 * @detailed    The calculation of the series i/(2i + 1) is done 
 *              given any number, from i -> 0.
 *              
 * @param      i     Any number chosen
**/

double seriesFinder1(double i)
{
    double result = 0;
    
    if (i > 0)
        result = (i / (2 * i + 1)) + seriesFinder1(i - 1);
    else
        result = 0;
        
    return result;
}

/**
 * @brief       This function calculates a series
 *
 * @detailed    The calculation of the series i/(i + 1) is done 
 *              given any number, from i -> 0.
 *              
 * @param      i     Any number chosen
**/

double seriesFinder2(double i)
{
    double result = 0;
    
    if (i > 0)
        result = (i / (i + 1)) + seriesFinder2(i - 1);
    else
        result = 0;
        
    return result;
}

int main()
{
    //#s 1-10 for seriesFinder
    double counter = 1;
    cout << endl << "Series Finder #1 Test" << endl;
    while (counter <= 10)
    {
        cout << fixed << setprecision(6) << seriesFinder(counter) 
        << endl;
        counter++;
    }
    
    //#s 1-10 for seriesFinder1
    counter = 1;
    cout << endl << "Series Finder #2 Test" << endl;
    while (counter <= 10)
    {
        cout << fixed << setprecision(6) << seriesFinder1(counter) 
        << endl;
        counter++;
    }
    
    //#s 1-10 for seriesFinder2
    counter = 1;
    cout << endl << "Series Finder #3 Test" << endl;
    while (counter <= 10)
    {
        cout << fixed << setprecision(6) << seriesFinder2(counter) 
        << endl;
        counter++;
    }
}




