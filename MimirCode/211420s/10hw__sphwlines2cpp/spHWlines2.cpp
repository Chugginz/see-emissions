/**
 *******************************************************************************
 * @file    spHWlines2.cpp
 * @brief   Determining whether lines are coinciding, parallel,
 *          perpendicular, or intersecting
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Monday, March 30
 *      Instructor:    Nancy Draganjac
 *
 * @author  Christian Huggins
 * @date    March 30, 2020
 *******************************************************************************
**/
#include<iostream>
    using std::cin;
    using std::cout;
    using std::endl;

#include<iomanip>
    using std::fixed;
    using std::setprecision;

#include<cmath>
    // using fabs
    
const double EPSILON = 0.00001;
    
// from class

/**
 * @brief       This function gets a point from the user
 *
 * @detailed    Requires input from user for an x and y
 *              
 * @param       x       Static value for x so user can input a    
 *                      value
 * @param       y       Static value for y so user can input a 
 *                      value
**/

void getPoint(double& x, double& y)
{
    cout << "Enter the x-coordinate of the point: ";
    cin >> x;
    cout << "Enter the y-coordinate of the point: ";
    cin >> y;    
}

void calculateMidpoint(double x1, double y1, double x2, double y2,
                       double& midX, double& midY)
{
    midX = (x1 + x2) / 2.0;
    midY = (y1 + y2) / 2.0;
}

/**
 * @brief       This function calculates the slope of a line
 *
 * @detailed    Given values for x1, y1, x2, y2, the function
 *              will use the slope equation to find the slope
 *              and assign it to the static variable m
 * 
 * @param       x1       The value of the first x-coordinate
 * @param       y1       The value of the first y-coordinate
 * @param       x2       The value of the second x-coordinate
 * @param       y2       The value of the second y-coordinate
 * @param       m        Static variable for slope
 *
 * @return  Returns true or false depending on if the slope exists
**/

bool calculateSlope(double x1, double y1, double x2, double y2, double& m)
{
    bool isDefined = false;
    if (x2 != x1)
    {
            isDefined = true;
            if (y2 == y1)
                m = 0;
            else
                m = (y2 - y1) / (x2 - x1);
    }
    else
        m = 999;
        
    return isDefined;
}

/**
 * @brief       This function calculates the y-intercept
 *
 * @detailed    Given values the x-coordinate, y-coordinate,
 *              and slope, the equation for finding the
 *              y-intercept will be used
 * 
 * @param       x       x-coordinate
 * @param       y       Y-coordinate
 * @param       m       Slope
 *
 * @return  Returns a double, y-intercept
**/

double calculateYIntercept(double x, double y, double m)
{
    return y - (m * x);
}

/**
 * @brief       This function determines whether two lines are
 *              coinciding
 *
 * @detailed    Given values x1, y1, x2, y2 of line 1 and
 *              x1, y1, x2, y2 of line 2, slopes and coordinates
 *              will be checked to see whether or not two lines
 *              are the same
 * 
 * @param       line1x1       First x-coordinate of line 1
 * @param       line1y1       First y-coordinate of line 1
 * @param       line1x2       Second x-coordinate of line 1
 * @param       line1y2       Second y-coordinate of line 1
 * @param       line2x1       First x-coordinate of line 2
 * @param       line2y1       First y-coordinate of line 2
 * @param       line2x2       Second x-coordinate of line 2
 * @param       line2y2       Second y-coordinate of line 2
 *
 * @return  Returns true or false based on if two lines are the
 *          same or not
**/

// in-lab
bool areCoinciding(double line1x1, double line1y1, double line1x2, double line1y2,
                   double line2x1, double line2y1, double line2x2, double line2y2)
{
    double slope1, slope2;
    calculateSlope(line1x1, line1y1, line1x2, line1y2, slope1);
    calculateSlope(line2x1, line2y1, line2x2, line2y2, slope2);
    bool result = false;
    
    if (slope1 == 999 && slope2 == 999)
    {
        if (fabs(line1x1 - line2x1) <= EPSILON)
            result = true;
    }
    else if (fabs(slope1 - slope2) <= EPSILON)
    {
        if (fabs(calculateYIntercept(line1x1, line1y1, slope1) -
        calculateYIntercept(line2x1, line2y1, slope2)) <= EPSILON)
            result = true;
    }
    
    return result;
}

/**
 * @brief       This function determines whether two lines are
 *              parallel
 *
 * @detailed    Given values x1, y1, x2, y2 of line 1 and
 *              x1, y1, x2, y2 of line 2, slopes and coordinates
 *              will be checked to see whether or not two lines
 *              are parallel
 * 
 * @param       line1x1       First x-coordinate of line 1
 * @param       line1y1       First y-coordinate of line 1
 * @param       line1x2       Second x-coordinate of line 1
 * @param       line1y2       Second y-coordinate of line 1
 * @param       line2x1       First x-coordinate of line 2
 * @param       line2y1       First y-coordinate of line 2
 * @param       line2x2       Second x-coordinate of line 2
 * @param       line2y2       Second y-coordinate of line 2
 *
 * @return  Returns true or false based on if two lines are 
 *          parallel or not
**/

bool areParallel(double line1x1, double line1y1, double line1x2, double line1y2,
                 double line2x1, double line2y1, double line2x2, double line2y2)
{
    double slope1, slope2;
    calculateSlope(line1x1, line1y1, line1x2, line1y2, slope1);
    calculateSlope(line2x1, line2y1, line2x2, line2y2, slope2);
    bool result = false;
    
    if (fabs(slope1 - slope2) <= EPSILON)
        result = true;
    
    return result;
}

/**
 * @brief       This function determines whether two lines are
 *              perpendicular
 *
 * @detailed    Given values x1, y1, x2, y2 of line 1 and
 *              x1, y1, x2, y2 of line 2, slopes and coordinates
 *              will be checked to see whether or not two lines
 *              are the perpendicular
 * 
 * @param       line1x1       First x-coordinate of line 1
 * @param       line1y1       First y-coordinate of line 1
 * @param       line1x2       Second x-coordinate of line 1
 * @param       line1y2       Second y-coordinate of line 1
 * @param       line2x1       First x-coordinate of line 2
 * @param       line2y1       First y-coordinate of line 2
 * @param       line2x2       Second x-coordinate of line 2
 * @param       line2y2       Second y-coordinate of line 2
 *
 * @return  Returns true or false based on if two lines are the
 *          perpendicular or not
**/

bool arePerpendicular(double line1x1, double line1y1, double line1x2, double line1y2,
                      double line2x1, double line2y1, double line2x2, double line2y2)
{
    double slope1, slope2;
    calculateSlope(line1x1, line1y1, line1x2, line1y2, slope1);
    calculateSlope(line2x1, line2y1, line2x2, line2y2, slope2);
    bool result = false;
    
    if (fabs(slope1 * slope2) == 1)
        result = true;
    else if (slope1 == 999 || slope2 == 999)
    {
        if (slope1 == 0 || slope2 == 0)
            result = true;
    }
    
    return result;
}

/**
 * @brief       This function determines the coordinates of
 *              intersection for two lines
 *
 * @detailed    Given values x1, y1, x2, y2 of line 1 and
 *              x1, y1, x2, y2 of line 2, slopes and coordinates
 *              will be used to determine the points of 
 *              intersection if there are any
 * 
 * @param       line1x1       First x-coordinate of line 1
 * @param       line1y1       First y-coordinate of line 1
 * @param       line1x2       Second x-coordinate of line 1
 * @param       line1y2       Second y-coordinate of line 1
 * @param       line2x1       First x-coordinate of line 2
 * @param       line2y1       First y-coordinate of line 2
 * @param       line2x2       Second x-coordinate of line 2
 * @param       line2y2       Second y-coordinate of line 2
 * @param       x             x-coordinate where two lines 
 *                            intersect
 * @param       y             y-coordinate where two lines
 *                            intersect
 *
 * @return  Returns true or false based on if two lines are the
 *          same or not
**/

bool calculateIntersection(double line1x1, double line1y1, double line1x2, double line1y2,
                           double line2x1, double line2y1, double line2x2, double line2y2,
                           double& x, double& y)
{
    double slope1, slope2;
    calculateSlope(line1x1, line1y1, line1x2, line1y2, slope1);
    calculateSlope(line2x1, line2y1, line2x2, line2y2, slope2);
    bool result = false;
    
    if (areCoinciding(line1x1, line1y1, line1x2, line1y2, line2x1, 
    line2y1, line2x2, line2y2) == false)
    {
        if (areParallel(line1x1, line1y1, line1x2, line1y2, line2x1
        , line2y1, line2x2, line2y2) == false)
        {
            x = (calculateYIntercept(line1x1, line1y1, slope1) -
        calculateYIntercept(line2x1, line2y1, slope2)) / 
        (slope2 - slope1);
            y = (slope1 * x + (calculateYIntercept(line1x1, line1y1, slope1)));
            result = true;
        }
    }
    
    return result;
}

// for testing purposes
void testGetPoint()
{
    double x, y;
    getPoint(x, y);
    cout << "You entered (" << x << ", " << y << ").\n";    
}

void testSingleLine(double x1, double y1, double x2, double y2)
{
    double midX, midY;
    calculateMidpoint(x1, y1, x2, y2, midX, midY);
    cout << "\nThe midpoint of the line segment defined by ("
         << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ") is ("
         << midX << ", " << midY << ")\n";

    double slope;
    if (calculateSlope(x1, y1, x2, y2, slope))
    {
        double yIntercept = calculateYIntercept(x1, y1, slope);
        cout << "The equation of the line is y = " << slope << "x ";
        if (yIntercept < 0)
            cout << "- " << fabs(yIntercept) << endl;
        else
            cout << "+ " << yIntercept << endl;
    }
    else
        cout << "The equation of the line is x = " << y1 << endl;
}

void displayEquationOfLine(double x1, double y1, double x2, double y2)
{
    cout << "The equation of the line defined by (" << x1 << ", " 
         << y1 << ") and (" << x2 << ", " << y2 << ") is ";
    
    double m;
    if (calculateSlope(x1, y1, x2, y2, m))
    {
        double yIntercept = calculateYIntercept(x1, y1, m);
        cout << "y = "; 

        if (fabs(m) > EPSILON)  // slope is not 0
        {
            cout << m << "x ";
        
            if (yIntercept < -EPSILON)
                cout << "- " << fabs(yIntercept);
            else if (yIntercept > EPSILON)
                cout << "+ " << yIntercept;

        }
        else  // slope is 0
        {
            if (fabs(yIntercept) < EPSILON)
                cout << 0;
            else
                cout << yIntercept;
        }
        
    }
    else
        cout << "x = " << x1;
        
    cout << endl;

}

void displayMidPointAndEquation(double x1, double y1, double x2, double y2)
{
    displayEquationOfLine(x1, y1, x2, y2);    

    double midX, midY;
    calculateMidpoint(x1, y1, x2, y2, midX, midY);
    cout << "The midpoint of the line segment is (" << midX << ", " << midY << ")\n";
}

void testLines(double x1, double y1, double x2, double y2, 
               double x3, double y3, double x4, double y4)
{
    cout << endl;

    displayMidPointAndEquation(x1, y1, x2, y2);
    displayMidPointAndEquation(x3, y3, x4, y4);

    if (areCoinciding(x1, y1, x2, y2, x3, y3, x4, y4))
        cout << "The lines are the same.\n";
    else if (areParallel(x1, y1, x2, y2, x3, y3, x4, y4))
        cout << "The lines are parallel.\n";
    else
    {
        if (arePerpendicular(x1, y1, x2, y2, x3, y3, x4, y4))
            cout << "The lines are perpendicular.\n";
    
        double x5, y5;
        calculateIntersection(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5);
        cout << "The lines intersect at (" << x5 << ", " << y5 << ").\n";
    }
}

int main()
{
    cout << fixed << setprecision(1);
    
    testGetPoint();
    
    testSingleLine(0, 0, 9, 9);
    testSingleLine(0, 0, -9, 9);
    testSingleLine(0, 0, 0, 9);
    testSingleLine(0, 0, 9, 0);
    
    testLines(0, 0, 1, 1, 2, 2, 3, 3);  // neither vertical, coinciding
    testLines(0, 0, 1, 1, 0, 1, 1, 2);  // neither vertical, parallel
    testLines(0, 0, 1, 1, 0, 0, -1, 1); // neither vertical, perpendicular
    testLines(0, 0, 1, 1, 5, 6, 7, 7);  // neither vertical, intersecting
    testLines(5, 0, 5, 7, 5, 9, 5, 11); // vertical, coinciding
    testLines(5, 0, 5, 7, 4, 0, 4, 7);  // vertical, parallel
    testLines(5, 0, 5, 7, 4, 7, 3, 7);  // 1st line vertical, perpendicular
    testLines(4, 7, 3, 7, 5, 0, 5, 7);  // 2nd line vertical, perpendicular
    testLines(5, 0, 5, 7, 0, 0, 1, 1);  // 1st line vertical, intersecting
    testLines(0, 0, 1, 1, 5, 0, 5, 7);  // 2nd line vertical, intersecting
    
    return 0;
}

