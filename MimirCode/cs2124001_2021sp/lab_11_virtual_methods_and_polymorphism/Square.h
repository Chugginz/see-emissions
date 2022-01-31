// @ Square.h

#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

// Class Square should be placed in Square.h
class Square : public Shape {
public:
    Square(double x, double y, double s);
    Square(std::istream& fin);
    void write(std::ostream& fout) const;
    ~Square();
private:
    double side;
};

std::ostream& operator<<(std::ostream& fout, const Square& n);

#endif