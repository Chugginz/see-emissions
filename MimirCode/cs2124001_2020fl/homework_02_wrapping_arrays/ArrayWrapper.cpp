/**
 *******************************************************************************
 * @file    ArrayWrapper.h
 * @brief   Code for functions within the class mentioned in the header file
 *          "ArrayWrapper.h"
 *
 * @author  Christian Huggins
 * @date    September 21, 2020
 *******************************************************************************
**/

#include "ThinArrayWrapper.h"

#include<stdexcept>

#include<iostream>
    using std::cout;
    using std::endl;

/**
 * @brief       This function is a constructor
 *
 * @detailed    If size is acceptable, replace other size
 *              
 * @param      size     size provided for array
**/

ArrayWrapper::ArrayWrapper(int size){
    if (size > 0)
        this -> size = size;
}

/**
 * @brief       This function gets the size of the array
 *
 * @detailed    This function gives the user the size of the array
 *              
 * @return      Returns the size
**/

int ArrayWrapper::get_size() const{
    return size;
}

/**
 * @brief       This function gets contents of array at certain location
 *
 * @detailed    As long as the index is within bounds, the function will
 *              find the memory location and return whats in memory
 *              
 * @param       index       Desired memory location
 * 
 * @return      Returns memory in desired location
**/

int ArrayWrapper::get(int index) const{
    //If within bounds
    if (index >= 0 && index <= size)
        index = array[index];
    else
        throw std::out_of_range{"Array index out of range."};
    
    return index;
}

/**
 * @brief       This function sets a value in an array
 *
 * @detailed    Provided a memory location and desired value, function
 *              assigns new value to provided memory location
 *              
 * @param       index        Desired memory location
 * 
 * @param       value        Desired value for memory location
**/

void ArrayWrapper::set(int index, int value){
    //If within bounds
    if (index >= 0 && index <= size)
        array[index] = value;
    else
        throw std::out_of_range{"Array index out of range."};
}
