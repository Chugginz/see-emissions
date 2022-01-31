/**
 *******************************************************************************
 * @file    Circle.cpp
 * @brief   All function definitions for the header file Circle that helps
 *          provide information about a Shape data type that is a circle.
 *
 * @author  Christian Huggins
 * @date    November 9th, 2020
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

Circle::Circle(double x, double y, double r) : Shape{x, y} {
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
 * @parem_out       istream& fin    File stream used to read the values
 *                              from the file itself
**/

Circle::Circle(std::istream& fin) : Shape{fin} {
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
 * @parem_out       ostream& fout       ostream used to display the
 *                                  shape's data to the user
**/

void Circle::write(std::ostream& fout) const{
    Shape::write(fout);
    fout << "Radius: " << radius << endl;
}

double Circle::area() const{
    //Area formula - pi * radius squared
    return (M_PI * pow(radius, 2));
}

double Circle::perimeter() const{
    //Perimeter formula - 2 * pi * radius
    return (2 * M_PI * radius);
}

bool Circle::contains(double p_x, double p_y) const{
    double x = Shape::get_ref_x();
    double y = Shape::get_ref_y();
    bool result = false;
    
    //If line is longer than radius, then outside of circle
    if (sqrt(pow((p_x - x), 2) + pow((p_y - y), 2)) > radius){
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