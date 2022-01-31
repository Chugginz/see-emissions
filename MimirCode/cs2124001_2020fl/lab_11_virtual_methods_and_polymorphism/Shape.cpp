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
    fout << "\n(" << ref_x << ", " << ref_y << ") ";
}

std::ostream& operator<<(std::ostream& fout, const Shape& n){
    n.write(fout);
    
    return fout;
}

double Shape::getDistanceTo (double p_x, double p_y) const{
    double distance;
    
    distance = sqrt(pow((p_x - ref_x), 2) + pow((p_y - ref_y), 2));
    
    return distance;
}

Shape::~Shape(){
    cout << "Shape::~Shape\n";
}