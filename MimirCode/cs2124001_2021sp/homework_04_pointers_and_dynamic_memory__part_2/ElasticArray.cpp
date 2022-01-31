/**
 *******************************************************************************
 * @file    ElasticArray.cpp
 * @brief   Provides function definitions for function prototypes given
 *          in the class ElasticArray in header file ElasticArray.h
 *
 * @author  Christian Huggins
 * @date    February 15th, 2021
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
        //Initialize _array
        _array = new int[size];
        //Initialize _size
        _size = size;
        //Initialize _max_size
        _max_size = size;
        
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
    if (i < 0 || i >= _size)
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
    //Copy of max size is max size of array
    _max_size = source._max_size;
    //Copy of array is size of other array
    _array = new int[_size];
    //As i increases and is less than size, set copy of array elements equal
    // to those of the other array
    for (int i = 0; i < _size; i++)
        _array[i] = source._array[i];
}

/**
 * @brief                   This function acts as a mutator
 *
 * @detailed                This function increases the size of the array by 1,
 *                          adding a value given in the parameter to the back
 *                          of the array.
 *              
 * @param   int value       Value desired to be added to array
**/

void ElasticArray::push_back(int value){
    //If the size of the array has not hit the maximum
    if (_size < _max_size){
        //Set the array value at the index of the size (next free value),
        // equal to the value passed by parameters.
        _array[_size] = value;
        //Increment size for class update
        _size++;
    }
    else{
        resize();
        //Set the array value at the index of the size (next free value),
        // equal to the value passed by parameters.
        _array[_size] = value;
        //Increment size for class update
        _size++;
    }
}

/**
 * @brief                   This function acts as a mutator
 *
 * @detailed                This function increases the max size of an array,
 *                          either by making it 16, or by doubling the current
 *                          max size
**/

void ElasticArray::resize(){
    if (_max_size == 0)
        //If max size is 0, make it 16
        _max_size = 16;
    else
        //If max size is not 0, double it.
        _max_size = _max_size * 2;
    //Create a new array with the new size
    int* array = new int[_max_size];
    //Increment i to size of old array, copying values from old to new array
    for (int i = 0; i < _size; i++)
            array[i] = _array[i];
    //Delete old array values
    delete [] _array;
    //Change _array pointer to that of the new array
    _array = array;
}

/**
 * @brief                   This function acts as a mutator
 *
 * @detailed                This function decreases the size of the array by 1,
 *                          removing a value in the back of the array.
 *              
 * @return      int         Returns the value that was removed from back of 
 *                          the array
**/

int ElasticArray::pop_back(){
    //If the size is 0, throw error because user can't pop back
    if (_size == 0)
        throw std::out_of_range ("Array size is 0");
    //Create temp value that is being erased to return
    int temp = _array[_size];
    //Decrement size
    _size--;
    //Fix size by shrinking to fit
    shrink_to_fit();
    //Return value deleted
    return temp;
}

/**
 * @brief                   This function acts as a mutator
 *
 * @detailed                This function decreases the size of the array,
 *                          either narrowing it down to 0, or narrowing it down
 *                          to the logical size rather than physical size
 *              
 * @param   int new_size    The value of the new size the array is shrinking to
**/

void ElasticArray::shrink_to_fit(){
    //If logical size is 0
    if (_size == 0){
        //Deallocate memory of array
        delete [] _array;
        //Setting array equal to nullptr
        _array = nullptr;
        //Set the size to new size, or just 0.
        _max_size = 0;
    }
    //If shrinking the array size
    else if (_size < _max_size){
        //Create new array with new size
        int* new_array = new int[_size];
        //Set new values at index equal to old values at index
        for (int i = 0; i < _size; i++)
            new_array[i] = _array[i];
        //Deallocate memory of array
        delete [] _array;
        //Pointing array pointer to new array
        _array = new_array;
        //Set size equal to new size
        _max_size = _size;
    }
}

/**
 * @brief                   This function acts as an accessor
 *
 * @detailed                This function returns the beginning of an array
 *              
 * @return      int*        Returns a pointer to the int
**/

int* ElasticArray::begin(){
    //Pointer to an int of the beginning (0)
    int* begin = 0;
    //Return value
    return begin;
}

/**
 * @brief                   This function acts as an accessor
 *
 * @detailed                This function returns the end of an array
 *              
 * @return      int*        Returns a pointer to the int
**/

int* ElasticArray::end(){
    //Pointer to an int of the end (_size)
    int* end = new int(_size);
    //Return value
    return end;
}

/**
 * @brief                   This is an overloaded operator
 *
 * @detailed                This function concatenates two arrays, one that is
 *                          given through a parameter and one that is already
 *                          in the class. Then, the class containing the new
 *                          array is returned
 *              
 * @param   const ElasticArray& rhs       Right hand side class containing an
 *                                      array
 * 
 * @return  ElasticArray    Returns an object of type ElasticArray containing
 *                          a new concatenated array
**/

ElasticArray ElasticArray::operator+(const ElasticArray& rhs) const{
    //Combining both array sizes, lhs and rhs
    int new_size = this->_size + rhs._size;
    //Create a new object with an array size of the new size
    ElasticArray dest_array{new_size};
    //Initialize a counting method to use to maintain the location of the
    // new array index after the first loop of the lhs
    int count;
    //As count increases but is less than the size, set new array value equal
    // to array value at index i, then set new count value
    for (int i = 0; i < this->_size; i++){
        dest_array._array[i] = this->_array[i];
        count = i;
    }
    //As count increases but is less than the rhs size, set new array value
    // equal to array value at index i while the new array is at count + 1
    for (int i = 0; i < rhs._size; i++){
        
        dest_array._array[count] = rhs._array[i];
        count ++;
    }
    //Return the object with the new array
    return dest_array;
}