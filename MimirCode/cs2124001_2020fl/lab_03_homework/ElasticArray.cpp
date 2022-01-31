/**
 *******************************************************************************
 * @file    ElasticArray.cpp
 * @brief   Provides function definitions for function prototypes given
 *          in the class ElasticArray in header file ElasticArray.h
 *
 * @author  Christian Huggins
 * @date    September 27, 2020
 *******************************************************************************
**/

#include "ElasticArray.h"

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
    
#include<stdexcept>

/**
 * @brief               This function is a constructor
 *
 * @detailed            Initializes values within the class ElasticArray
 *              
 * @param   int size    Desired size of array     
**/

ElasticArray::ElasticArray(int size){
    //If size is greater than 0, establish new array and size
    if (size > 0){
        _array = new int[size];
        _size = size;
        
        //Let user know size of array
        cout << "\nCreated Array with a size of: " << size << endl;
    }
}

/**
 * @brief               This function acts as a default constructor
 *
 * @detailed            Frees memory after it is done being used
**/

ElasticArray::~ElasticArray(){
    //Free memory
    delete [] _array;
    _array = nullptr;
    cout << "Memory has been freed.\n";
}

/**
 * @brief               This function finds a value at the desired index
 *
 * @detailed            Given a value (i), this function will find the element
 *                      in the location i of the array
 *              
 * @param      int i    desired index value
**/

int& ElasticArray::at(int i){
    //If element is negative or not in array memory scope, throw
    if (i < 0 && i >= _size)
        throw std::out_of_range{"Array index out of range."};
    
    //Return array at element location
    return _array[i];
}

/**
 * @brief               This function finds the value of the front index
 *
 * @detailed            Searches the first index if the array exists,
 *                      and gives the element at that location
**/

int ElasticArray::front() const{
    //If 0 is less than size of array, pass
    if (0 < _size)
        ;
    //Else, throw due to array not existing
    else
        throw 
        std::out_of_range("Cannot retrieve a value from an empty container.");
        
    //Return first element of array
    return _array[0];
}

/**
 * @brief               This function finds the value of the last index
 *
 * @detailed            Searches the last index if the array exists,
 *                      and gives the element at that location
**/

int ElasticArray::back() const{
    //If size of array is greater than 0, pass
    if (_size > 0)
        ;
    //Else, throw due to array not existing
    else
        throw 
        std::out_of_range("Cannot retrieve a value from an empty container.");
        
    //Return last element of array
    return _array[_size - 1];
}

/**
 * @brief                   This function overloads the = operator
 *
 * @detailed                This function essentially overloads the = operator
 *                      allowing it to also act as a copy constructor
 *              
 * @param   ElasticArray elastic   Object name for ElasticArray class wanting
 *                                  copied
**/

const ElasticArray ElasticArray::operator=(const ElasticArray &elastic){
    //If arrays are not the same
    if (this != &elastic){
        //Deallocate memory for copy of array
        delete[] _array;
        //Copy of size is size of array
        _size = elastic._size;
        //Copy of array is size of other array
        _array = new int[_size];
        //As i increases and is less than size, set copy of array elements
        // equal to those of the other array
        for (int i = 0; i < _size; i++)
            _array[i] = elastic._array[i];
    }
    //Return value for array on the left
    return *this;
}

/**
 * @brief                   This function acts as a copy constructor
 *
 * @detailed                This function copies items from the sources
 *                          object making it a copy constructor
 *              
 * @param   ElasticArray source   Object name for ElasticArray class wanting 
 *                                  copied
**/

ElasticArray::ElasticArray(const ElasticArray& source){
    //Copy of size is size of array
    _size = source._size;
    //Copy of array is size of other array
    _array = new int(_size);
    //As i increases and is less than size, set copy of array elements equal
    // to those of the other array
    for (int i = 0; i < _size; i++)
        _array[i] = source._array[0];
}