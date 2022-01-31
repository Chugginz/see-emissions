/**
 *******************************************************************************
 * @file    spHWlight.cpp
 * @brief   Program to display light electrons and convert wavelength to 
 *          electrons
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      e.g. Monday, January 27
 *      Instructor:    Gidget Scrivner
 *
 * @author  Christian Huggins
 * @date    1/22/2020
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
    
#include<cmath>

#include<iomanip>
    using std::setprecision;
    using std::fixed;
    
const double PLANCKS = 6.626 * pow(10, -34);
const double LIGHT_SPEED = 3 * pow(10, 8);

int main()
{
    double wavelength, energy;
        wavelength = 650 * pow(10, -9);
        energy = (PLANCKS * LIGHT_SPEED) / wavelength;
        energy = energy * 6.242 * pow(10, 18);
        
    cout << "Red Light -\t\t" << setprecision(5) << energy << endl;
    
        wavelength = 550 * pow(10, -9);
        energy = (PLANCKS * LIGHT_SPEED) / wavelength;
        energy = energy * 6.242 * pow(10, 18);
        
    cout << "Green Light -\t" << setprecision(5) << energy << endl;
    
        wavelength = 470 * pow(10, -9);
        energy = (PLANCKS * LIGHT_SPEED) / wavelength;
        energy = energy * 6.242 * pow(10, 18);
        
    cout << "Blue Light -\t" << setprecision(5) << energy << endl;
    
    cout << "Enter a wavelength (380 to 740): ";
        
        cin >> wavelength;
        wavelength = wavelength * pow(10, -9);
        energy = (PLANCKS * LIGHT_SPEED) / wavelength;
        energy = energy * 6.242 * pow(10, 18);
        
    cout << "The energy in volts is " << setprecision(5) << energy << endl;
    
    return 0;
}
