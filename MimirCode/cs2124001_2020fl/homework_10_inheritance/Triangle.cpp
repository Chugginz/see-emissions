/**
 *******************************************************************************
 * @file    Triangle.cpp
 * @brief   All function definitions for the header file Triangle that helps
 *          provide information about a Shape data type that is a Triangle.
 *
 * @author  Christian Huggins
 * @date    November 9th, 2020
 *******************************************************************************
**/

#include "Triangle.h"

/**
 * @brief       This is the constructor given the values for the reference
 *              points and the base and height
 *
 * @detailed    Provided the x and y for the reference point, the constructor
 *              passes these values to the base classes constructor while
 *              the b and h values are assigned to the base and height.
 *              
 * @param       double x        x coordinate of the reference point
 * 
 * @param       double y        y coordinate of the reference point
 * 
 * @param       double b        base of the triangle
 * 
 * @param       double h        height of the triangle
**/

Triangle::Triangle(double x, double y, double b, double h) : Shape{x, y} {
    cout << "DEBUG: Executing Triangle constructor...\n";
    //Assign base the value of b
    base = b;
    //Assign height the value of h
    height = h;
}

/**
 * @brief       This is the constructor given the file stream
 *
 * @detailed    Provided the file stream, the constructor will first
 *              pass it to the base classes constructor to store the
 *              x and y reference points, then proceed to read from it
 *              to receive the base and height of the triangle
 *              
 * @param       istream& fin    File stream used to read the values
 *                              from the file itself
**/

Triangle::Triangle(std::istream& fin) : Shape{fin} {
    cout << "DEBUG: Executing Triangle constructor...\n";
    //Read and store base from file
    fin >> base;
    //Read and store height from file
    fin >> height;
}

/**
 * @brief       This is the write function used to display the triangle's
 *              details for the user
 *
 * @detailed    Provided the ostream data type "fout", the function
 *              first passes it to the Shape classes write method,
 *              then uses it to display to the user the base and height
 *              of the triangle
 *              
 * @param       ostream& fout       ostream used to display the
 *                                  shape's data to the user
**/

void Triangle::write(std::ostream& fout) const{
    //Use Shape's write method to display ref points
    Shape::write(fout);
    //Write to user the base and height of the triangle
    fout << "Base: " << base << " Height: " << height << endl;
}

/**
 * @brief       Overloading the stream insertion operator to act
 *              as the write function for triangle
 *
 * @detailed    Provided the ostream data type "fout", the function
 *              first passes it to the write function of the object
 *              with the data type of Triangle, then returns it.
 *              
 * @param       ostream& fout       ostream used to display the
 *                                  shape's data to the user
 * 
 * @param       Triangle& n         object of data type Triangle accessed
 *                                  to call function write and access its
 *                                  data
 *
 * @return      Returns the ostream parameter that was passed to it by reference
**/

std::ostream& operator<<(std::ostream& fout, const Triangle& n){
    //Access object of data type Circle and use it's write method
    //using fout
    n.write(fout);
    
    return fout;
}

/**
 * @brief       Destructor of the class Triangle
 *
 * @detailed    Informs the user that the Triangle class has closed (destructed)
**/

Triangle::~Triangle(){
    //Let the user know the destructor is being ran
    cout << "executing Triangle destructor...\n";
}