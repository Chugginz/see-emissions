// @ Shape.h

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
    Shape(double x, double y);
    Shape(std::istream& fin);
    virtual void write (std::ostream& outfile) const;
    double getDistanceTo (double p_x, double p_y) const;
    virtual ~Shape ( );
private:
    double ref_x;
    double ref_y;
};

std::ostream& operator<<( std::ostream& fout, const Shape& n);

#endif