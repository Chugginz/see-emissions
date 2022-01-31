/**
 *******************************************************************************
 * @file    ShapeList.cpp
 * @brief   All function definitions for the header file ShapeList that is a
 *          list used to hold different shapes provided.
 *
 * @author  Christian Huggins
 * @date    April 5th, 2021
 *******************************************************************************
**/

#include "ShapeList.h"

/**
 * @brief       This is a function to add a shape to the list
 *
 * @detailed    Provided a shape of data type Shape*, the shape will be
 *              passed to the push_back function in order to add it to the
 *              list
 *              
 * @param       Shape* newShape     Object of data type Shape* added to list
**/

void ShapeList::add(Shape* newShape){
    push_back(newShape);
}

/**
 * @brief       This is the write function used to display the list's shapes
 *              and it's data
 *
 * @detailed    Provided the ostream data type "strm_out", the function
 *              displays the shape's and their data in the list in order
 *              until the end of the list
 *              
 * @param       ostream& strm_out   ostream used to display the
 *                                  list and its data to the user
**/

void ShapeList::write(std::ostream& strm_out) const{
    //For loop used to traverse through the list writing each shape's
    // reference points
    for ( const auto& item : *this ) {
        //write shape's details
        item->write( strm_out );
        strm_out << '\n';
    }
}

/**
 * @brief       Overloading the stream insertion operator to act
 *              as the write function for the list
 *
 * @detailed    Provided the ostream data type "fout", the function
 *              displays each shape and it's data in order until the end
 *              of the list
 *              
 * @param       ostream& fout       ostream used to display the
 *                                  shape's data to the user
 * 
 * @param       ShapeList& n        object of the list accessed
 *                                  to call function write and access its
 *                                  data
 *
 * @return      Returns the ostream parameter that was passed to it by reference
**/

std::ostream& operator<<(std::ostream& strm_out, const ShapeList& shapes){
    //For loop used to traverse through the list used to act the same
    // way as the write function
    for ( const auto& item : shapes)
        strm_out << *item << '\n';
    
    return strm_out;
}

/**
 * @brief       Function frees the memory in the heap
 *
 * @detailed    While the front of the list does not equal nullptr, the
 *              front will be deleted, made equal to nullptr, then popped
 *              out of the heap in order to move to the next object to free
 *              data
**/

void ShapeList::erase(){
    //While the front is not null
    while (front() != nullptr){
        //Delete the front, set it to nullptr, then pop it out of the heap
        delete front();
        front () = nullptr;
        pop_front();
    }
}

/**
 * @brief       Finds the closest object to the given coordinate pair
 *
 * @detailed    Provided a pair of coordinates, the function will traverse
 *              the list searching for the smallest distance in order to
 *              determine which shape is closest to the points. Every time a
 *              shape is closer than the last, the new shape's details override
 *              the previous shape's in order to always have the smallest
 *              distance
 *              
 * @param       double p_x          x coordinate of user provided coordinate 
 *                                      pair
 * 
 * @param       double p_y          y coordinate of user provided coordinate 
 *                                      pair
 *
 * @return      Returns the shape that is closest to the given coordinate pair
**/

Shape* ShapeList::findClosestTo(double p_x, double p_y) const{
    //Set smallest value to incredibly high number so that
    // if there is a first shape, it changes it
    double smallest = item->getDistanceTo(p_x, p_y);
    //Smallest shape is nullptr until we know there is a shape
    Shape* smallestShape = nullptr;
    
    //For loop used to traverse through the list to find the shape
    // with the shortest distance from the given coordinate points
    for ( const auto& item : *this ){
        if (item->getDistanceTo(p_x, p_y) < smallest){
            smallest = item->getDistanceTo(p_x, p_y);
            smallestShape = item;
        }
    }
    
    return smallestShape;
}

/**
 * @brief       Destructor of the class ShapeList
 *
 * @detailed    Calls the function erase to clear all memory in the heap
**/

ShapeList::~ShapeList(){
    //Call erase function to free the memory used by the list
    erase();
}