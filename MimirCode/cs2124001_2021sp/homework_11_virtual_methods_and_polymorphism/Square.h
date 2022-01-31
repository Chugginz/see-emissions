/**
 *******************************************************************************
 * @file    Square.h
 * @brief   Header file containing the class Square that is a derived class of
 *          the class Shape that contains methods in order to further define 
 *          a shape if it is a Square.
 *
 * @author  Christian Huggins
 * @date    April 11th, 2021
 *******************************************************************************
**/

#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

// Class Square should be placed in Square.h
class Square : public Shape {
public:
    //Constructor
    Square(double x, double y, double s);
    //Alternate Constructor
    Square(std::istream& fin);
    //Function tells user reference points of the shape
    void write(std::ostream& fout) const;
    //Function returning area of square
    double area() const;
    //Function returing perimeter of square
    double perimeter() const;
    //Function returning whether or not point is in square
    bool contains(double p_x, double p_y) const;
    //Destructor
    ~Square();
private:
    //Side of the square
    double side;
};

//Overloading of stream operator so it acts as write method
std::ostream& operator<<(std::ostream& fout, const Square& n);

#endif