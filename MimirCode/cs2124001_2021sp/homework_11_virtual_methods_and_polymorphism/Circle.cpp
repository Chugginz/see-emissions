/**
 *******************************************************************************
 * @file    Circle.cpp
 * @brief   All function definitions for the header file Circle that helps
 *          provide information about a Shape data type that is a circle.
 *
 * @author  Christian Huggins
 * @date    April 11th, 2021
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
    fin >> radius;
    fin.ignore();
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
    Shape::write(fout);
    fout << "Radius: " << radius << endl;
}

/**
 * @brief       Calculates the area of a circle
 *
 * @detailed    Taking the radius stored in the class circle, the method
 *              multiplies the radius by itself followed by pi, returning
 *              the value calculated
 *              
 * @return      Returns the area found by the area formula for a circle
**/

double Circle::area() const{
    //Area formula - pi * radius squared
    return (M_PI * pow(radius, 2));
}

/**
 * @brief       Calculates the perimeter of a circle
 *
 * @detailed    Taking the radius stored in the class circle, the method
 *              multiplies the radius by pi and then by two, returning the
 *              value calculated
 *              
 * @return      Returns the value found by the perimeter formula for a circle
**/

double Circle::perimeter() const{
    //Perimeter formula - 2 * pi * radius
    return (2 * M_PI * radius);
}

/**
 * @brief       Calculates whether or not a coordinate is in a circle
 *
 * @detailed    Taking the points given by the user, the method calculates the
 *              distance between the given point and the center of the circle,
 *              and then determines if the radius is longer than that distance.
 *              If so, we know that the point is not in the circle.
 *              
 * @param       double p_x      The x value of a given point
 * 
 * @param       double p_y      The y value of a given point
 * 
 * @return      Returns true of false depending on if point is in the circle
**/

bool Circle::contains(double p_x, double p_y) const{
    //Initialize the x and y points and the result
    double x = Shape::get_ref_x();
    double y = Shape::get_ref_y();
    bool result = false;
    
    //If distance is smaller than radius, in circle
    if (sqrt(pow((p_x - x), 2) + pow((p_y - y), 2)) < radius){
        result = true;
    }
    
    return result;
}

/**
 * @brief       Destructor of the class Circle
 *
 * @detailed    Informs the user that the Circle class has closed (destructed)
**/

Circle::~Circle(){
    cout << "Circle::~Circle\n";
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
    n.write(fout);
    
    return fout;
}