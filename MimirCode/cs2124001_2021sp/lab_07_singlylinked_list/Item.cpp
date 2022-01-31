// @ Item.cpp

#include "Item.h"

std::ostream& Item::write( std::ostream& fout ) const{
    fout << std::setiosflags(std::ios::left);
    fout << std::setw(30) << name << magic;
    fout << std::resetiosflags(std::ios::left);
    
    return fout;
}

std::ostream& operator<<(std::ostream& fout, const Item& item){
    item.write(fout);
    
    return fout;
}