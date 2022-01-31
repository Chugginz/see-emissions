/**
 *******************************************************************************
 * @file    Circle.h
 * @brief   Header file containing an array of vertices used for Polygon
 *
 * @author  Christian Huggins
 * @date    April 11th, 2021
 *******************************************************************************
**/

#ifndef POINT2D_H
#define POINT2D_H

#include<iostream>

/**
 * Point2D is a 2-dimensional Cartesian
 * point with Real-valued coordinates.
 */
 
class Point2D{
public:
    double x;  ///< x-coordinate of this point
    double y;  ///< y-coordinate of this point
    /**
     * construct a Point2D given the x- and y-
     * coordinates of its location.
     */
    Point2D(double x, double y) : x{x}, y{y}{}
    /**
     * default-construct a Point2D at the origin.
     */
    Point2D() : x(0), y(0){}
};

std::ostream& operator<<(std::ostream& strm, const Point2D& point);

#endif