// @ ShapeList.cpp

#ifndef SHAPE_LIST_H
#define SHAPE_LIST_H

#include <iostream>
using std::ostream;
#include "Shape.h"

#include <list>
#include <memory>

/*
 * This version of the ShapeList uses a `std::unique_ptr` to each
 * Shape that it owns.  The unique pointer is a "smart pointer" that
 * is already capable of deleting the object that it owns when it
 * goes out of scope.  The advantage it gives us here is that we no
 * longer need a destructor here; removing elements from the list is
 * also possible now without introducing leaks.
 */

class ShapeList : public std::list<std::unique_ptr<Shape>> {
public:
    ShapeList( )  = default;
    ~ShapeList( ) = default;
    void add( Shape* newShape );
    void write( ostream& strm_out ) const;
};

ostream& operator<<( ostream& strm_out, const ShapeList& shapes );

#endif