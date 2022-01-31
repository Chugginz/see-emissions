// @ Square.cpp

#include "Square.h"

Square::Square(double x, double y, double s) : Shape{x, y} {
    cout << "DEBUG: Executing Square constructor...\n";
    side = s;
}

Square::Square(std::istream& fin) : Shape{fin} {
    cout << "DEBUG: Executing Square constructor...\n";
    fin >> side;
}

void Square::write(std::ostream& fout) const{
    fout << "Square's Side - " << side << endl;
    Shape::write(fout);
}

Square::~Square(){
    cout << "executing Square destructor...\n";
}