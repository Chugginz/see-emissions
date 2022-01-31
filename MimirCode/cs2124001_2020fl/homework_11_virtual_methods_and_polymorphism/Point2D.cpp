/**
 *******************************************************************************
 * @file    Circle.h
 * @brief   Code defintion file containing an array of vertices used for Polygon
 *
 * @author  Christian Huggins
 * @date    November 17th, 2020
 *******************************************************************************
**/

#include "Point2D.h"

/**
 * Overloaded stream insertion operator to allow a Point2D to
 * be displayed in a standard ostream.
 * @param strm      the stream to write the Point2D into
 * @param point     the Point2D object to output
 * @return          the modified `strm` is returned
 */
std::ostream& operator<<( std::ostream& strm, const Point2D& point ) {
    return strm << "(" << point.x << ", " << point.y << ")";
}