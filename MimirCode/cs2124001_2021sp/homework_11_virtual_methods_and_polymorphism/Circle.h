/**
 *******************************************************************************
 * @file    Circle.h
 * @brief   Header file containing the class Circle that is a derived class of
 *          the class Shape that contains methods in order to further define 
 *          a shape if it is a circle.
 *
 * @author  Christian Huggins
 * @date    April 11th, 2021
 *******************************************************************************
**/

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

// Class Circle should be placed in Circle.h
class Circle : public Shape {
public:
    //Constructor
    Circle(double x, double y, double r);
    //Alternate Constructor
    Circle(std::istream& fin);
    //Function tells user radius and circle ref coordinates
    void write(std::ostream& fout) const;
    //Finds area of circle
    double area() const;
    //Finds perimeter of circle
    double perimeter() const;
    //Finds if point is in circle
    bool contains(double p_x, double p_y) const;
    //Destructor
    ~Circle();
private:
    //Radius of the circle
    double radius;
};

//Overloading of stream operator so it acts as write method
std::ostream& operator<<(std::ostream& fout, const Circle& n);

#endif