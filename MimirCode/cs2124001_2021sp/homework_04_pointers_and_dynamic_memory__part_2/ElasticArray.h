/**
 *******************************************************************************
 * @file    ElasticArray.h
 * @brief   Header file containing class ElasticArray consisting of a wrapped
 *          array, its size, as well as multiple class-related functions.
 *
 * @author  Christian Huggins
 * @date    February 15th, 2021
 *******************************************************************************
**/

#ifndef ELASTICARRAY_H
#define ELASTICARRAY_H

class ElasticArray{
public:
    typedef int* iterator;      //Defined new type class iterator
    ElasticArray() = default;   //Default Constructor
    ElasticArray(int size);     //Constructor
    ElasticArray(const ElasticArray& source);   //Copy Constructor
    int size() const { return _size; }      //Accessor
    int capacity() const { return _max_size; } //Accessor
    int front() const;                      //Accessor
    int back() const;                       //Accessor
    int& at(int i);                         //Accessor
    iterator begin();                            //Accessor
    iterator end();                              //Accessor
    void push_back(int value);              //Mutator
    void resize();                          //Mutator
    int pop_back();                         //Mutator
    void shrink_to_fit();        //Mutator
    const ElasticArray operator=(const ElasticArray &elastic);  //copy ctor
    //Overloaded operator
    int& operator[](const int index) { return at(index); }
    //Overloaded operator
    ElasticArray operator+(const ElasticArray& rhs) const;
    ~ElasticArray();                        //Deconstructor

private:
    int* _array = nullptr;                  //Array initialization
    int  _size  = 0;                        //Size initialization
    int _max_size = 0;                       //Max Size initialization
};

#endif

//AT push_back method