/**
 *******************************************************************************
 * @file    Polygon.h
 * @brief   Header file containing the class Polygon that is a derived class of
 *          the class Shape that contains methods in order to further define 
 *          a shape if it is a polygon.
 *
 * @author  Christian Huggins
 * @date    November 9th, 2020
 *******************************************************************************
**/

#ifndef POLYGON_H
#define POLYGON_H

#include "Point2D.h"
#include "Shape.h"

class Polygon : public Shape {
public:
    //Constructor
    Polygon( const Point2D* vertices, int vertex_count );
    //Alternate Constructor
    Polygon(std::istream& fin);
    //Function tells user vertices of polygon
    void write( std::ostream& strm_out ) const;
    //Finds area of polygon
    double area() const;
    //Finds perimeter of polygon
    double perimeter() const;
    //Finds if point is within polygon
    bool contains(double p_x, double p_y) const;
    
    Polygon( const Polygon& )            = delete; // disallow copies by ctor
    Polygon& operator=( const Polygon& ) = delete; // and/or by assignment
    //Destuctor
    ~Polygon( );
private:
    //Array of vertices of polygon
    Point2D* vertices     = nullptr;
    //Number of vertices
    int      vertex_count = 0;
};

//Overloading of stream operator so it acts as write method
std::ostream& operator<<( std::ostream& strm_out, const Polygon& p );

#endif