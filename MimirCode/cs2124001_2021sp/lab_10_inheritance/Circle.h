// @ Circle.h

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

// Class Circle should be placed in Circle.h
class Circle : public Shape {
public:
    Circle(double x, double y, double r);
    Circle(std::istream& fin);
    void write(std::ostream& fout) const;
    ~Circle();
private:
    double radius;
};

std::ostream& operator<<(std::ostream& fout, const Circle& n);

#endif