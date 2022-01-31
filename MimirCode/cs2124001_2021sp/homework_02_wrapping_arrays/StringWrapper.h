/**
 *******************************************************************************
 * @file    StringWrapper.h
 * @brief   Class String Wrapper used for testing string arrays
 *
 * @author  Christian Huggins
 * @date    February 1, 2021
 *******************************************************************************
**/

#ifndef STRINGWRAPPER_H
#define STRINGWRAPPER_H

#include<string>
    using std::getline;
#include<cstring>
#include<stdexcept>
#include<iostream>
    using std::cout;

class StringWrapper {
public:
    StringWrapper(char a[]);
    
    char get(int index) const;
    void set(int index, char value);
    
    void write(std::ostream& strm=std::cout) const;
    void readline(std::istream& strm=std::cin, char delim='\n');
    
    const static int max_capacity = 1048576;
private:
    //Character array
    char array[max_capacity];
};

#endif