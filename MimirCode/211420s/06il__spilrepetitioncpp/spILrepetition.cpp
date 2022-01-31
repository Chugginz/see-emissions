/**
 *******************************************************************************
 * @file    spILrepetition.cpp
 * @brief   
 *
 * More general information about what this program or project will do shall be
 * placed here (the file containing main() is usually the first place a programmer
 * would look for information about a large program with many source files).
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Thursday, February 20
 *      Instructor:    Draganjac
 *
 * @author  Christian Huggins
 * @date    February 20, 2020
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;

#include<iomanip>
    using std::fixed;
    using std::setprecision;

int main()
{
    
    //While loop segment converting fahrenheit to celcius
    
    float i = 0;
    
    //Chart Header
    cout << "\tFah\t\tCel\n";
    cout << "----------------------\n";
    
    while (i <= 100)
    {
        float number;
        
        number = ((i - 32) * (5.0 / 9.0));
        
        cout << setprecision(2) << fixed << "\t" << i << "\t" << number << endl;
        
        i += 5;
    }
    
    //Do-while loop segment converting fahrenheit to kelvin
    
    int incrementChoice;
    float k = 0;
    
    //Do-while loop used for input validation
    do
    {
        cout << "What would you like to increment by? ";
        cin >> incrementChoice;
    }   while (incrementChoice <= 0 && incrementChoice > 200);
    
    //Chart Header
    cout << "\n\tFah\t\tKel\n";
    cout << "----------------------\n";
    
    do
    {  
        float number;
        
        number = ((k + 459.69) * (5.0 / 9.0));
        
        cout << setprecision(2) << fixed << "\t" << k << "\t" << number << endl;
        
        k += incrementChoice;
    }   while (k <= 200);
    
    //For loop segment converting celcius to rankine
    
    int startingTemp;
    
    //Do-while loops used for input validation
    do
    {
        cout << "\nWhat would you like to increment by? ";
        cin >> incrementChoice;
    }   while (incrementChoice <= 0 && incrementChoice > 200);
    
    do
    {
        cout << "What would you like to be your starting temp (in Celcius)? ";
        cin >> startingTemp;
    }   while (startingTemp <= 0 && startingTemp > 200);
    
    //Chart Header
    cout << "\n\tCel\t\tRan\n";
    cout << "----------------------\n";
    
    for (int l = 1; l <= 25; l++)
    {
        float number;
        
        number = (startingTemp * (9.0 / 5.0) + 32 + 459.67);
        
        cout << setprecision(2) << fixed << "\t" << startingTemp 
            << "\t\t" << number << endl;
            
        startingTemp += incrementChoice;
    }
    
    return 0;
}
