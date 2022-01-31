/**
 *******************************************************************************
 * @file    spHWselection.cpp
 * @brief   Brief description of what this file contains shall be placed here.
 *
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Monday, February 10
 *      Instructor:    Gidget Scrivner
 *
 * @author  Christian Huggins
 * @date    Sunday, February 9
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;

#include<iomanip>
    using std::setprecision;
    
#include<cmath>
    using std::sin;
    using std::sqrt;
    
int main()
{
    // Offers option of which way they'd like to find the area
    int choice;
    cout << "Which way would you like to calculate the area of the triangle?\n";
    cout << "[1] - base and height\n";
    cout << "[2] - length of three sides\n";
    cout << "[3] - sides a and b, and angle C (in degrees)\n";
    cout << "Choice: ";
    cin >> choice;
    
    // If they choose 1, enter base and height
    if (choice == 1)
    {
        double base, height, area;
        cout << "\nEnter the base: ";
        cin >> base;
        cout << "\nEnter the height: ";
        cin >> height;
        
        //One half * base * height
        area = .5 * base * height;
        
        //If area doesn't exist, let the user know
        if (area < 0)
        {
            cout << "The values given do not meet the requirements of a triangle\n";
        }
        else
        {
            cout << "\nThe area of the triangle is " <<
             setprecision(5) << area << endl;
        }
    }
    // If they choose option 2, enter all side lengths
    else if (choice == 2)
    {
        double side1, side2, side3, s, area;
        cout << "\nEnter the length of side 1: ";
        cin >> side1;
        cout << "\nEnter the length of side 2: ";
        cin >> side2;
        cout << "\nEnter the length of side 3: ";
        cin >> side3;
        
        s = (side1 + side2 + side3) / 2;
        
        area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
        
        //If area doesn't exist, let the user know
        if (area < 0 || s < 0)
        {
            cout << "The values given do not meet the requirements of a triangle\n";
        }
        else
        {
            cout << "\nThe area of the triangle is " <<
                setprecision(5) << area << endl;
        }
    }
    //If they choose 3, enter two sides and angle for unknown side
    else if (choice == 3)
    {
        double side1, side2, angleC, area;
        cout << "\nEnter the length of side 1: ";
        cin >> side1;
        cout << "\nEnter the length of side 2: ";
        cin >> side2;
        cout << "\nEnter the angle of angle C (in degrees): ";
        cin >> angleC;
        
        //Equation for finding area with two sides and angle
        area = (side1 * side2 * sin(angleC * (3.14 / 180))) / 2;
        
        //If area doesn't exist, let the user know
        if (area < 0)
        {
            cout << "The values given do not meet the requirements of a triangle";
        }
        else
        {
            cout << "\nThe area of the triangle is " << 
                setprecision(5) << area << endl;
        }
    }
    //If they don't cooperate like necessary, then we kick their butts to the curb with nothing
    else
        cout << "That is not an option. Goodbye.\n";
        
    return 0;
    
}
