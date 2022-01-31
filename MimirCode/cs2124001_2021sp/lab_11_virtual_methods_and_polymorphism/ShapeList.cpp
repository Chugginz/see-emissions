// @ ShapeList.h

#include "ShapeList.h"
#include <memory>

void ShapeList::add( Shape* newShape ) {
    this->push_back( std::unique_ptr<Shape>{newShape} );
}

void ShapeList::write( ostream& strm_out ) const {
    for ( const auto& item : *this ) {
        item->write( strm_out );
        strm_out << '\n';
    }
}

ostream& operator<<( ostream& strm_out, const ShapeList& shapes ) {
    shapes.write( strm_out );
    return strm_out;
}
