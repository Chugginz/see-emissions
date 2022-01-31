/**
 *******************************************************************************
 * @file    Rectangle.cpp
 * @brief   All function definitions for the header file Rectangle that helps
 *          provide information about a Shape data type that is a rectangle.
 *
 * @author  Christian Huggins
 * @date    April 5th, 2021
 *******************************************************************************
**/

#include "Rectangle.h"

/**
 * @brief       This is the constructor given the values for the reference
 *              points and the width and height
 *
 * @detailed    Provided the x and y for the reference point, the constructor
 *              passes these values to the base classes constructor while
 *              the w and h values are assigned to the width and height.
 *              
 * @param       double x        x coordinate of the reference point
 * 
 * @param       double y        y coordinate of the reference point
 * 
 * @param       double w        width of the rectangle
 * 
 * @param       double h        height of the rectangle
 *
**/

Rectangle::Rectangle(double x, double y, double w, double h) : Shape{x, y}{
    cout << "DEBUG: Executing Rectangle constructor...\n";
    //Set width to the value of w
    width = w;
    //Set height to the value of h
    height = h;
}

/**
 * @brief       This is the constructor given the file stream
 *
 * @detailed    Provided the file stream, the constructor will first
 *              pass it to the base classes constructor to store the
 *              x and y reference points, then proceed to read from it
 *              to receive the width and height of the rectangle
 *              
 * @param       istream& fin    File stream used to read the values
 *                              from the file itself
**/

Rectangle::Rectangle(std::istream& fin) : Shape{fin}{
    cout << "DEBUG: Executing Rectangle constructor...\n";
    //Read and store width from file
    fin >> width;
    //Read and store height from file
    fin >> height;
}

/**
 * @brief       This is the write function used to display the rectangle's
 *              details for the user
 *
 * @detailed    Provided the ostream data type "fout", the function
 *              first passes it to the Shape classes write method,
 *              then uses it to display to the user the width and height
 *              of the rectangle
 *              
 * @param       ostream& fout       ostream used to display the
 *                                  shape's data to the user
**/

void Rectangle::write(std::ostream& fout) const{
    //Use Shape's write method to display ref points
    Shape::write(fout);
    //Write the length of width and height
    fout << "Width: " << width << " Height: " << height << endl;
}

/**
 * @brief       Overloading the stream insertion operator to act
 *              as the write function for rectangle
 *
 * @detailed    Provided the ostream data type "fout", the function
 *              first passes it to the write function of the object
 *              with the data type of Rectangle, then returns it.
 *              
 * @param       ostream& fout       ostream used to display the
 *                                  shape's data to the user
 * 
 * @param       Rectangle& n        object of data type Rectangle accessed
 *                                  to call function write and access its
 *                                  data
 *
 * @return      Returns the ostream parameter that was passed to it by reference
**/

std::ostream& operator<<(std::ostream& fout, const Rectangle& n){
    //Access object of data type Rectangle and use it's write method
    //using fout
    n.write(fout);
    
    return fout;
}

/**
 * @brief       Destructor of the class Rectangle
 *
 * @detailed    Informs the user that the Rectanle class has closed (destructed)
**/

Rectangle::~Rectangle(){
    //Let user know that the destructor is being ran
    cout << "executing Rectangle destructor...\n";
}