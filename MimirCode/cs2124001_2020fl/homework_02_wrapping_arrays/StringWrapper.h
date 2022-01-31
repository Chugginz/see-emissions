/**
 *******************************************************************************
 * @file    ArrayWrapper.h
 * @brief   Class StringWrapper used for testing string arrays
 *
 * @author  Christian Huggins
 * @date    September 21, 2020
 *******************************************************************************
**/

#ifndef STRINGWRAPPER_H
#define STRINGWRAPPER_H

class StringWrapper{
public:
    StringWrapper(const char a[] );
    char get(int index) const;
    void set(int index, char value);
    
    const static int max_capacity = 1048576;
private:
    //Character array
    char array[max_capacity];
};

#endif