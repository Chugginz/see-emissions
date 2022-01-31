// @ Polygon.h

#ifndef POLYGON_H
#define POLYGON_H

#include "Point2D.h"
#include "Shape.h"

class Polygon : public Shape {
public:
    Polygon( const Point2D* vertices, int vertex_count );
    Polygon(std::istream& fin);
    ~Polygon( );
    void write( std::ostream& strm_out ) const;
    
    Polygon( const Polygon& )            = delete; // disallow copies by ctor
    Polygon& operator=( const Polygon& ) = delete; // and/or by assignment

private:
    Point2D* vertices     = nullptr;
    int      vertex_count = 0;
};

std::ostream& operator<<( std::ostream& strm_out, const Polygon& p );

#endif