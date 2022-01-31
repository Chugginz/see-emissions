/**
 *******************************************************************************
 * @file    ElasticArray.h
 * @brief   Header file containing class ElasticArray consisting of a wrapped
 *          array, its size, as well as multiple class-related functions.
 *
 * @author  Christian Huggins
 * @date    February 8th, 2021
 *******************************************************************************
**/

#ifndef ELASTICARRAY_H
#define ELASTICARRAY_H

class ElasticArray{
public:
    ElasticArray() = default;   //Default Constructor
    ElasticArray(int size);     //Constructor
    ElasticArray(const ElasticArray& source);   //Copy Constructor
    int size() const { return _size; }      //Accessor
    int front() const;                      //Accessor
    int back() const;                       //Accessor
    int& at(int i);                         //Accessor
    const ElasticArray operator=(const ElasticArray &elastic);  //copy ctor
    ~ElasticArray();                        //Deconstructor

private:
    int* _array = nullptr;                  //Array initialization
    int  _size  = 0;                        //Size initialization
};

#endif