/**
 *******************************************************************************
 * @file    ShapeList.h
 * @brief   Header file containing the class ShapeList that is a derived class 
 *          of a list of shapes that is used to store different types of shapes.
 *
 * @author  Christian Huggins
 * @date    April 11th, 2021
 *******************************************************************************
**/

#ifndef SHAPELIST_H
#define SHAPELIST_H

#include <list>
#include "Shape.h"

class ShapeList : protected std::list<Shape*>{
public:
    //Constructor
    ShapeList() = default;
    //Function to add a new shape to the list
    void add(Shape* newShape);
    //Function that displays every shape and it's details to the user
    void write(std::ostream& strm_out) const;
    //Frees the memory of the list
    void erase();
    //Function that finds the shape closest to the coordinate pair
    // provided by the user
    Shape* findClosestTo(double p_x, double p_y) const;
    //Print all shapes that the point is inside
    void print_shapes_containing(double p_x, double p_y) const;
    //Print all shapes and their perimeters
    void print_perimeters() const;
    //Print all shapes and their areas
    void print_areas() const;
    //Destructor
    ~ShapeList();
    
    //Overloading of stream operator so it acts as write method
    friend std::ostream& 
    operator<<(std::ostream& strm_out, const ShapeList& shapes);
    
};

#endif