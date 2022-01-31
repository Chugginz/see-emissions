// @DynamicArray.h

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray{
public:
   DynamicArray(int size);
   int  size() const { return _size; }
   int& at(int i);
   ~DynamicArray();

private:
   int* _array = nullptr;
   int  _size  = 0;
};

#endif