/**
 *******************************************************************************
 * @file    Shape.cpp
 * @brief   All function definitions for the header file Shape that helps
 *          define a shape.
 *
 * @author  Christian Huggins
 * @date    April 5th, 2021
 *******************************************************************************
**/

#include "Shape.h"

/**
 * @brief       This is the constructor given the values for the reference
 *              points
 *
 * @detailed    Provided the x and y for the reference point, the constructor
 *              will assign the reference values in the class the values
 *              passed through the parameters
 *              
 * @param       double x        x coordinate of the reference point
 * 
 * @param       double y        y coordinate of the reference point
**/

Shape::Shape(double x, double y){
    cout << "DEBUG: Executing Shape constructor...\n";
    //Assign the reference point x the value of x
    ref_x = x;
    //Assign the reference point y the value of y
    ref_y = y;
}

/**
 * @brief       This is the constructor given the file stream
 *
 * @detailed    Provided the file stream, the constructor will read
 *              from the file stream to store the data in the reference points
 *              
 * @param       istream& fin    File stream used to read the values
 *                              from the file itself
**/

Shape::Shape(std::istream& fin){
    cout << "DEBUG: Executing Shape constructor...\n";
    //Read and store the value of the reference point of x from file
    fin >> ref_x;
    //Read and store the value of the reference point of y from file
    fin >> ref_y;
}

/**
 * @brief       This is the write function used to display the shape's data
 *
 * @detailed    Provided the ostream data type "fout", the function
 *              will display to the user the x and y values of the
 *              reference points
 *              
 * @param       ostream& fout       ostream used to display the
 *                                  shape's data to the user
**/

void Shape::write(std::ostream& fout) const{
    //Display to user the x and y coordinates of the reference point
    fout << "\n(" << ref_x << ", " << ref_y << ") ";
}

/**
 * @brief       Overloading the stream insertion operator to act
 *              as the write function for shape
 *
 * @detailed    Provided the ostream data type "fout", the function
 *              first passes it to the write function of the object
 *              with the data type of Shape, then returns it
 *              
 * @param       ostream& fout       ostream used to display the
 *                                  shape's data to the user
 * 
 * @param       Shape& n            object of data type Shape accessed
 *                                  to call function write and access its
 *                                  data
 *
 * @return      Returns the ostream parameter that was passed to it by reference
**/

std::ostream& operator<<(std::ostream& fout, const Shape& n){
    //Access object of data type Shape and use it's write method
    //using fout
    n.write(fout);
    
    return fout;
}

/**
 * @brief       This function finds the distance from a given coordinate pair
 *              to the shape's reference points
 *
 * @detailed    Provided the x and y for the coordinate pair in which the
 *              distance is wanted from, the distance formula is enacted
 *              to find the distance from the given coordinate pair to the
 *              shape's reference points, then returns that distance
 *              
 * @param       double p_x        x coordinate of the coordinate pair
 * 
 * @param       double p_y        y coordinate of the coordinate pair
 * 
 * @return      Returns the distance from the coordinate pair to the reference
 *              point
**/

double Shape::getDistanceTo (double p_x, double p_y) const{
    //Initialize a value distance for equation
    double distance;
    
    //Distance equation - square root of (x2 - x1)^2 + (y2 - y1)^2
    distance = sqrt(pow((p_x - ref_x), 2) + pow((p_y - ref_y), 2));
    
    return distance;
}

/**
 * @brief       Destructor of the class Shape
 *
 * @detailed    Informs the user that the Shape class has closed (destructed)
**/

Shape::~Shape(){
    //Let user know that the destructor is being ran
    cout << "executing Shape destructor...\n";
}