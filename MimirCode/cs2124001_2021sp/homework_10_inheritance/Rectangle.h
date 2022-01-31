/**
 *******************************************************************************
 * @file    Rectangle.h
 * @brief   Header file containing the class Rectangle that is a derived class 
 *          of the class Shape that contains methods in order to further define 
 *          a shape if it is a Rectangle.
 *
 * @author  Christian Huggins
 * @date    April 5th, 2021
 *******************************************************************************
**/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape{
public:
    //Constructor
    Rectangle(double x, double y, double w, double h);
    //Alternate Constructor
    Rectangle(std::istream& fin);
    //Function tells user width, height and rectangle's ref coordinates
    void write(std::ostream& fout) const;
    //Destructor
    ~Rectangle();
private:
    //Width and height of rectangle
    double width, height;
};

//Overloading of stream operator so it acts as write method
std::ostream& operator<<(std::ostream& fout, const Rectangle& n);

#endif