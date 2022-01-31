/**
 *******************************************************************************
 * @file    ArrayWrapper.h
 * @brief   Code for all functions within the "StringWrapper" class
 *
 * @author  Christian Huggins
 * @date    September 21, 2020
 *******************************************************************************
**/

#include "StringWrapper.h"

#include<cstring>

#include<stdexcept>

#include<iostream>
    using std::cout;

/**
 * @brief       This function adds a cstring to a cstring array
 *
 * @detailed    Copies first function into protected array
 *              
 * @param      a[]     A cstring provided
**/

StringWrapper::StringWrapper(const char a[]){
    char strcpy(char array[], char a[]);
    if (a[strlen(a)] == '\0')
        //if last character is null terminated, state
        cout << "\nNull Terminated\n";
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
    if (index >= 0 && index <= max_capacity)
        //if index within bounds, assign memory in index
        // location to index
        index = array[index];
    else
        throw std::out_of_range{"Array index out of range."};
        
    return index;
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
    if (index >= 0 && index <= max_capacity)
        array[index] = value;
    else
        throw std::out_of_range{"Array index out of range."};
}
