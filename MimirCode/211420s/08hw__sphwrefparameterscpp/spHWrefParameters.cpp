/**
 *******************************************************************************
 * @file    spHWrefParameters.cpp
 * @brief   Brief description of what this file contains shall be placed here.
 *
 * More general information about what this program or project will do shall be
 * placed here (the file containing main() is usually the first place a programmer
 * would look for information about a large program with many source files).
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Tuesday, March 10th
 *      Instructor:    Draganjac
 *
 * @author  Christian Huggins
 * @date    3/9/20
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
    
#include<cmath>

/**
 * @brief       This function calculates the number of roots and 
 *              values of the roots
 *
 * @detailed    Given values for a, b, and c, the function will
 *              determine if there are any roots. If there are,
 *              the function will calculate the value of them
 *              using the quadratic formula.
 *              
 * @remarks
 *      This function only requires the values for a, b, and c in
 *      the parameters
 * 
 * @param       a       The value of the constant being multiplied
 *                      by x^2
 * @param       b       The value of the constant being multiplied
 *                      by x
 * @param       c       The value of the constant not being
 *                      multiplied by an x.
 * @param       x1      Value of a root.
 * @param       x2      Value of a root if there are 2 roots.
 *
 * @return  Returns the number of roots
**/

int calcQuadraticRoots(double a, double b, double c, double &x1, double &x2)
{
    int root = 0;
    double discrim;
    
    discrim = b * b - 4 * a * c;
    x1 = 0;
    x2 = 0;
    
    //If discriminant is negative, return 0 roots
    if (discrim < 0)
        return root;
    //If discriminant is 0, find root and return number of roots
    else if (discrim == 0)
    {
        root++;
        
        if (b == 0)
        {
            x1 = 0;
            return root;
        }
        else
        {
            x1 = -b / (2 * a);
            return root;
        }
    }
    else
    {
        //If discriminant is positive, find roots and return 
        //number of roots
        x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        
        root = 2;
        return root;
    }
}

/**
 * @brief       This function calculates the number of times that
 *              a circle crosses the x-axis
 *
 * @detailed    Given values for the center coordinates and radius,
 *              the function will determine if the circle crossed
 *              the x-axis. If the circle did cross, the function
 *              will calculate where the circle did cross.
 *              
 * @remarks
 *      This function only requires the coordinates for the center
 *      of the circle and the value of the radius
 * 
 * @param       centerX     The x coordinate for the center
 *                          of the circle
 * @param       centerY     The x coordinate for the center
 *                          of the circle
 * @param       radius      The value of the radius of the circle
 * @param       x1          If the circle crossed once, where the
 *                          circle crossed the x-axis
 * @param       x2          If the circle cross twice. where the
 *                          circle crossed the x-axis again.
 *
 * @return  Returns the number of times crossed
**/

int calcCircleIntersections(double centerX, double centerY, 
    double radius, double &x1, double &x2)
{
    double a, b, c;
    int timesCrossed;
    
    a = 1;
    b = -2 * centerX;
    c = (centerX * centerX) + (centerY * centerY) - (radius * radius);
    
    timesCrossed = calcQuadraticRoots(a, b, c, x1, x2);
    
    return timesCrossed;
    
}

/**
 * @brief       This function displays the results of the 
 *              calcQuadraticRoots function nicely.
 *
 * @detailed    Given the number of roots, the function will
 *              then determine which values to display. If
 *              roots is 0, none. If roots is 1, then display x1.
 *              If roots is 2, then display both x1 and x2. The
 *              function also displays the number of roots.
 *              
 * @remarks
 *      This function only requires the roots parameter to be
 *      manually entered.
 * 
 * @param       root        The result returned via the
 *                          calcQuadraticRoots function.
 * @param       x1      Value of a root.
 * @param       x2      Value of a root if there are 2 roots.
**/

void displayQuadraticResults(int root, double &x1, double &x2)
{
    if (root != 1)
        cout << "There are " << root << " roots." << endl;
    else
        cout << "There is " << root << " root." << endl;
    
    if (root > 0)
    {
        if (root > 1)
            cout << "There are roots at " << x1 << " and " << x2 << endl;
        else
            cout << "There is a root at " << x1 << endl;
    }
}

/**
 * @brief       This function displays the results of the 
 *              calcCircleIntersections function nicely.
 *
 * @detailed    Given the number of time crossed, the function will
 *              then determine which values to display. If
 *              times is 0, none. If times is 1, then display x1.
 *              If times is 2, then display both x1 and x2. The
 *              function also displays the number of times crossed.
 *              
 * @remarks
 *      This function only requires the timesCrossed parameter to 
 *      be manually entered.
 * 
 * @param       timesCrossed    The result returned via the
 *                              calcQuadraticRoots function.
 * @param       x1              Location where circle crossed
 *                              x-axis.
 * @param       x2              Location where circle crossed
 *                              x-axis if times crossed is 2.
**/

void displayCircleResults(int timesCrossed, double &x1, double &x2)
{
    if (timesCrossed != 1)
    {
        cout << "The circle crosses the x-axis " << timesCrossed 
        << " times." << endl;
    }
    else
    {
        cout << "The circle crossed the x-axis " << timesCrossed 
        << " time." << endl;
    }
    
    if (timesCrossed > 0)
    {
        if (timesCrossed == 1)
            cout << "It crossed at x = " << x1 << endl;
        else
            cout << "It crossed at x =  " << x1 << " and x = " << x2 << endl;
    }
}


int main()
{
    double x1, x2;

    //Test for positive result
    displayQuadraticResults(calcQuadraticRoots(1, 4, 1, x1, x2), x1, x2);
    //Test for 0 result
    displayQuadraticResults(calcQuadraticRoots(1, 2, 1, x1, x2), x1, x2);
    //Test for negative result
    displayQuadraticResults(calcQuadraticRoots(1, 1, 1, x1, x2), x1, x2);
    
    //Test for 2 times
    displayCircleResults(calcCircleIntersections(-2, 1, 2, x1, x2), x1, x2);
    //Test for 1 time
    displayCircleResults(calcCircleIntersections(-1, 1, -1, x1, x2), x1, x2);
    //Test for 0 times
    displayCircleResults(calcCircleIntersections(-.5, 4, 1, x1, x2), x1, x2);
    
    return 0;
}
