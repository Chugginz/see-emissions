// @ ShapeList.h

#ifndef SHAPELIST_H
#define SHAPELIST_H

// [...] other necessary headers not shown for brevity
#include <list>
#include "Shape.h"

class ShapeList : protected std::list<Shape*> {
public:
    ShapeList( ) = default;
    void add(Shape* newShape);
    void write(std::ostream& strm_out) const;
    void erase();
    ~ShapeList();
    
    friend std::ostream& 
    operator<<(std::ostream& strm_out, const ShapeList& shapes);
    
};

#endif