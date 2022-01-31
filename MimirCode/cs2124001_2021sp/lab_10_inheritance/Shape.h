// @ Shape.h

#ifndef SHAPE_H
#define SHAPE_H

#include<iostream>
    using std::cout;
    using std::endl;
    using std::cin;

// Class Shape should be placed in Shape.h
class Shape {
public:
    Shape(double x, double y);
    Shape(std::istream& fin);
    void write(std::ostream& fout) const;
    ~Shape();
private:
    double ref_x;
    double ref_y;
};

std::ostream& operator<<( std::ostream& fout, const Shape& n);

#endif