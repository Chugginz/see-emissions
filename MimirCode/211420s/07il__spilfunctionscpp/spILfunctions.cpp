/**
 *******************************************************************************
 * @file    spILfunctions.cpp
 * @brief   Writing functions for each calculating distance, getting seconds, 
 *          and calculating coordinate distance
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Thursday 27, 2020
 *      Instructor:    Dragnajac
 *
 * @author  Christian Huggins
 * @date    Thursday 27, 2020
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;

#include<iomanip>
    using std::fixed;
    using std::setprecision;
    
#include<cmath>

float GRAVITY = 9.80665;

float calculateDistance(float seconds)
{
    float distance;
    
    distance = (.5) * GRAVITY * seconds;
    
    return distance;
}

float getSeconds()
{
    float seconds;
    do
    {
        cout << "How many seconds did the object: ";
        cin >> seconds;
    } while (seconds < 0);
    
    return seconds;
}

double calculateDistance(double x1, double y1, double x2, double y2)
{
    double distance;
    
    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    
    return distance;
}

int main()
{
    cout.imbue(std::locale("en_US.utf-8"));
    cout << fixed << setprecision(5);
    
    // test calculateDistance for falling object
    cout << "An object falling for 12 seconds will fall "
         << calculateDistance(12) << " meters.\n"
         << "Answer should be 706.07880 meters.\n\n"
         << "An object falling for 15.6 seconds will fall "
         << calculateDistance(15.6) << " meters.\n"
         << "Answer should be 1,193.27317 meters.\n\n\n";
    
    // test getSeconds
    double seconds = getSeconds();
    cout << "An object falling for " << seconds 
         << " seconds will fall "
         << calculateDistance(seconds) << " meters.\n\n\n";
    
         
    // test calculateDistance for two points
    cout << "Distance between (5, 15) and (5, -4) is "
         << calculateDistance(5, 15, 5, -4) << ".\n"
         << "Answer should be 19.00000.\n\n"
         << "Distance between (20.6, 9.3) and (-5.2, -1.9) is "
         << calculateDistance(20.6, 9.3, -5.2, -1.9) << ".\n"
         << "Answer should be 28.12614.\n";
    
    return 0;
}

