// @ Item.cpp

#include <iostream>
    using std::cout;
    using std::cin;
    using std::endl;
#include <string>
#include <vector>    
#include <iomanip>
#include <fstream>
#include "Item.h"

std::ostream& Item::write( std::ostream& fout ) const{
    fout << std::setiosflags(std::ios::left);
    fout << name << " " << magic <<"\n";
    fout << std::resetiosflags(std::ios::left);
}

std::ostream& Item::operator<<(std::ostream& fout, const Item& item){
    write(item);
}