// @DynamicArray.cpp

#include "DynamicArray.h"

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
    
#include<stdexcept>
    
DynamicArray::DynamicArray(int size){
    if (size > 0){
        _array = new int[size];
        _size = size;
        cout << "\nSize: " << size << endl;
    }
}

DynamicArray::~DynamicArray(){
    delete [] _array;
    _array = nullptr;
    cout << "Memory Freed\n";
}

int& DynamicArray::at(int i){
    if (i < 0 && i > _size)
        throw std::out_of_range{"Array index out of range."};
    
    return _array[i];
}