// @Triangle.h

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"


class Triangle : public Shape {
public:
    //Constructor
    Triangle(double x, double y, double b, double h);
    //Alternate Constructor
    Triangle(std::istream& fin);
    //Function tells user base, height, and reference cooridinates
    void write(std::ostream& fout) const;
    //Destructor
    ~Triangle();
private:
    //Base and height of the triangle
    double base, height;
};

//Overloading of stream operator so it acts as write method
std::ostream& operator<<(std::ostream& fout, const Triangle& n);

#endif