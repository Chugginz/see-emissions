// @ ShapeList.cpp

#include "ShapeList.h"

void ShapeList::add( Shape* newShape ){
    push_back(newShape);
}

void ShapeList::write(std::ostream& strm_out ) const{
    for ( const auto& item : *this ) {
        item->write( strm_out );
        strm_out << '\n';
    }
}

std::ostream& operator<<(std::ostream& strm_out, const ShapeList& shapes){
    for ( const auto& item : shapes)
        strm_out << *item << '\n';
    
    return strm_out;
}

void ShapeList::erase(){
    while (front() != nullptr){
        delete front();
        front () = nullptr;
        pop_front();
    }
}

ShapeList::~ShapeList(){
    erase();
}