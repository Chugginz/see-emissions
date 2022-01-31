/**
 *******************************************************************************
 * @file    StringWrapper.cpp
 * @brief   Code for all functions within the "StringWrapper" class
 *
 * @author  Christian Huggins
 * @date    February 1, 2021
 *******************************************************************************
**/

#include "StringWrapper.h"

/**
 * @brief       This function adds a cstring to a cstring array
 *
 * @detailed    Copies first function into protected array
 *              
 * @param      a[]     A cstring provided
**/

StringWrapper::StringWrapper(char a[]){
    char strcpy(char array[], char a[]);
    a[max_capacity] = '\0';
}

/**
 * @brief       This function retrieves item from given index
 *
 * @detailed    Provides user with item within memory spot of
 *              requested index
 *              
 * @param       index     Desired location of memory
 * 
 * @return      Returns "index" which is item located within
 *              provided index
**/

char StringWrapper::get(int index) const{
    char result;
    
    if (index >= 0 && index < max_capacity)
        //if index within bounds, assign memory in index
        // location to index
        result = array[index];
    else
        throw std::out_of_range{"Array index out of range."};
        
    return result;
}

/**
 * @brief       This function sets values given both memory location
 *              and value
 *
 * @detailed    Given index, function located that memory location,
 *              then assigns that location the value provided
 *              
 * @param       index     Desired memory location
 * 
 * @param       value     Desired value for memory
**/

void StringWrapper::set(int index, char value){
    if (index >= 0 && index < max_capacity)
        array[index] = value;
    else
        throw std::out_of_range{"Array index out of range."};
}

/**
 * @brief       This function writes from the array to the stream.
 *
 * @detailed    As the counter increases from 0 to the max capacity
 *              of the array, the array will read its value at that
 *              index into the stream.
 *              
 * @param       strm     The stream being written into, defaulting
 *                          to cout.
**/

void StringWrapper::write(std::ostream& strm) const{
    for (int i = 0; i < max_capacity; i++)
        strm << array[i];
}

/**
 * @brief       This function reads from the array to the string
 *              of chars
 *
 * @detailed    As the counter increases from 0 to the max capacity
 *              of the array, the strm will read until the end of the
 *              file or until the delim into the array of chars.
 *              
 * @param       strm      The stream being read from into the array
 *                          defaulting to cin.
 * 
 * @param       delim     Delimeter used to determine when to
 *                        stop reading from the stream defaulting
 *                          to '\n'.
**/

void StringWrapper::readline(std::istream& strm, char delim){
    for (int i = 0; i < max_capacity; i++)
        strm.getline(array, delim);
}