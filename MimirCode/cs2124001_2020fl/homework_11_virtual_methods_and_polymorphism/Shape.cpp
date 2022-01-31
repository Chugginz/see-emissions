/**
 *******************************************************************************
 * @file    Shape.cpp
 * @brief   All function definitions for the header file Shape that helps
 *          define a shape.
 *
 * @author  Christian Huggins
 * @date    November 9th, 2020
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

Shape::Shape(double x, double y) {
    cout << "DEBUG: Executing Shape constructor...\n";
    ref_x = x;
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

Shape::Shape(std::istream& fin) {
    cout << "DEBUG: Executing Shape constructor...\n";
    fin >> ref_x;
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
    fout << "\n(" << ref_x << ", " << ref_y << ") ";
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
    double distance;
    
    distance = sqrt(pow((p_x - ref_x), 2) + pow((p_y - ref_y), 2));
    
    return distance;
}

double Shape::get_ref_x() const{
    return ref_x;
}
double Shape::get_ref_y() const{
    return ref_y;
}

/**
 * @brief       Destructor of the class Shape
 *
 * @detailed    Informs the user that the Shape class has closed (destructed)
**/

Shape::~Shape(){
    cout << "Shape::~Shape\n";
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
    n.write(fout);
    
    return fout;
}