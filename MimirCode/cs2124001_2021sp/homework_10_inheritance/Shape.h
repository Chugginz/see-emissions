/**
 *******************************************************************************
 * @file    Shape.h
 * @brief   Header file containing the class Shape that is a base class for 
 *          other files in which it is used to provide reference points for 
 *          the different shapes provided.
 *
 * @author  Christian Huggins
 * @date    April 5th, 2021
 *******************************************************************************
**/

#ifndef SHAPE_H
#define SHAPE_H

#include<iostream>
    using std::cout;
    using std::endl;
    using std::cin;
#include<cmath>
    using std::pow;


class Shape{
public:
    //Constructor
    Shape(double x, double y);
    //Alternate Constructor
    Shape(std::istream& fin);
    //Function tells user reference points of the shape
    void write(std::ostream& fout) const;
    //Get's distance from a given coordinate pair to the shape's coordinates
    double getDistanceTo(double p_x, double p_y) const;
    //Destructor
    ~Shape();
private:
    //Reference point x of a shape
    double ref_x;
    //Reference point of y of a shape
    double ref_y;
};


std::ostream& operator<<( std::ostream& fout, const Shape& n);

#endif