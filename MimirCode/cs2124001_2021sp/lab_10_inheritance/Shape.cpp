// @ Shape.cpp

#include "Shape.h"

Shape::Shape(double x, double y) {
    cout << "DEBUG: Executing Shape constructor...\n";
    ref_x = x;
    ref_y = y;
}

Shape::Shape(std::istream& fin) {
    cout << "DEBUG: Executing Shape constructor...\n";
    fin >> ref_x;
    fin >> ref_y;
}

void Shape::write(std::ostream& fout) const{
    fout << "Shape's Reference Point: (" << ref_x << "," << ref_y << ")\n";
}

std::ostream& operator<<(std::ostream& fout, const Shape& n){
    n.write(fout);
    
    return fout;
}

Shape::~Shape(){
    cout << "executing Shape destructor...\n";
}