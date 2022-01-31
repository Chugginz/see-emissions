/**
 *******************************************************************************
 * @file    Shape.h
 * @brief   Header file containing the class Shape that is a base class for 
 *          other files in which it is used to provide reference points for 
 *          the different shapes provided.
 *
 * @author  Christian Huggins
 * @date    November 9th, 2020
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

// Class Shape should be placed in Shape.h
class Shape {
public:
    //Constructor
    Shape(double x, double y);
    //Alternate Constructor
    Shape(std::istream& fin);
    //Accessors
    double get_ref_x() const;
    double get_ref_y() const;
    //Function tells user reference points of the shape
    virtual void write (std::ostream& outfile) const;
    //Get's distance from a given coordinate pair to the shape's coordinates
    double getDistanceTo (double p_x, double p_y) const;
    //Pure virtual methods
    virtual double area ( ) const = 0;
    virtual double perimeter() const = 0;
    virtual bool contains (double p_x, double p_y) const = 0;
    //Destructor
    virtual ~Shape ( );
private:
    //Reference point x of a shape
    double ref_x;
    //Reference point of y of a shape
    double ref_y;
};

std::ostream& operator<<( std::ostream& fout, const Shape& n);

#endif