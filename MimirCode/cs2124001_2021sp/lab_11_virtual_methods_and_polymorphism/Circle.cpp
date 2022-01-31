// @ Circle.cpp

#include "Circle.h"

Circle::Circle(double x, double y, double r) : Shape{x, y} {
    cout << "DEBUG: Executing Circle constructor...\n";
    radius = r;
}

Circle::Circle(std::istream& fin) : Shape{fin} {
    cout << "DEBUG: Executing Circle constructor...\n";
    fin >> radius;
    fin.ignore();
}

void Circle::write(std::ostream& fout) const{
    Shape::write(fout);
    fout << "Radius: " << radius << endl;
}

std::ostream& operator<<(std::ostream& fout, const Circle& n){
    n.write(fout);
    
    return fout;
}

Circle::~Circle(){
    cout << "Circle::~Circle\n";
}