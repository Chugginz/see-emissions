/**
 *******************************************************************************
 * @file    Circle.cpp
 * @brief   All function definitions for the header file Circle that helps
 *          provide information about a Shape data type that is a circle.
 *
 * @author  Christian Huggins
 * @date    April 5th, 2021
 *******************************************************************************
**/

#include "Circle.h"

/**
 * @brief       This is the constructor given the values for the reference
 *              points and the radius
 *
 * @detailed    Provided the x and y for the reference point, the constructor
 *              passes these values to the base classes constructor while
 *              the r is stored as the radius.
 *              
 * @param       double x        x coordinate of the reference point
 * 
 * @param       double y        y coordinate of the reference point
 * 
 * @param       double r        radius of the circle
**/

Circle::Circle(double x, double y, double r) : Shape{x, y}{
    cout << "DEBUG: Executing Circle constructor...\n";
    //Assign radius the value r
    radius = r;
}

/**
 * @brief       This is the constructor given the file stream
 *
 * @detailed    Provided the file stream, the constructor will first
 *              pass it to the base classes constructor to store the
 *              x and y reference points, then proceed to read from it
 *              to receive the radius of the circle
 *              
 * @param       istream& fin    File stream used to read the values
 *                              from the file itself
**/

Circle::Circle(std::istream& fin) : Shape{fin}{
    cout << "DEBUG: Executing Circle constructor...\n";
    //Read and store radius from file
    fin >> radius;
}

/**
 * @brief       This is the write function used to display the circle's
 *              details for the user
 *
 * @detailed    Provided the ostream data type "fout", the function
 *              first passes it to the Shape classes write method,
 *              then uses it to display to the user the radius of 
 *              the circle
 *              
 * @param       ostream& fout       ostream used to display the
 *                                  shape's data to the user
**/

void Circle::write(std::ostream& fout) const{
    //Use Shape's write method to display ref points
    Shape::write(fout);
    //Write size of radius
    fout << "Radius: " << radius << endl;
}

/**
 * @brief       Overloading the stream insertion operator to act
 *              as the write function for circle
 *
 * @detailed    Provided the ostream data type "fout", the function
 *              first passes it to the write function of the object
 *              with the data type of Circle, then returns it.
 *              
 * @param       ostream& fout       ostream used to display the
 *                                  shape's data to the user
 * 
 * @param       Circle& n           object of data type Circle accessed
 *                                  to call function write and access its
 *                                  data
 *
 * @return      Returns the ostream parameter that was passed to it by reference
**/

std::ostream& operator<<(std::ostream& fout, const Circle& n){
    //Access object of data type Circle and use it's write method
    //using fout
    n.write(fout);
    
    return fout;
}

/**
 * @brief       Destructor of the class Circle
 *
 * @detailed    Informs the user that the Circle class has closed (destructed)
**/

Circle::~Circle(){
    //Let user know destructor is ran
    cout << "executing Circle destructor...\n";
}