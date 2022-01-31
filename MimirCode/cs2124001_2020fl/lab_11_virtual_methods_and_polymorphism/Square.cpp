// @ Square.cpp

#include "Square.h"

Square::Square(double x, double y, double s) : Shape{x, y} {
    cout << "DEBUG: Executing Square constructor...\n";
    side = s;
}

Square::Square(std::istream& fin) : Shape{fin} {
    cout << "DEBUG: Executing Square constructor...\n";
    fin >> side;
    fin.ignore();
}

void Square::write(std::ostream& fout) const{
    Shape::write(fout);
    fout << "Side: " << side << endl;
}

Square::~Square(){
    cout << "Square::~Square\n";
}

std::ostream& operator<<(std::ostream& fout, const Square& n){
    n.write(fout);
    
    return fout;
}