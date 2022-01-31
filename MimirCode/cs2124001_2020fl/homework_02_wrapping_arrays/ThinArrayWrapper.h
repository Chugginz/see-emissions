/**
 *******************************************************************************
 * @file    ThinArrayWrapper.h
 * @brief   Header file containing structures, classes, and function prototypes
 *          for testing array abilities
 *
 * @author  Christian Huggins
 * @date    September 21, 2020
 *******************************************************************************
**/

#ifndef THINARRAYWRAPPER_H
#define THINARRAYWRAPPER_H

struct SuperThinArrayWrapper{
    int array[20];
};

struct ThinArrayWrapper{
    const static int size = 20;
    int array[size];
};

class ArrayWrapper{
public:
    ArrayWrapper(int size);
    int get_size() const;
    int get(int index) const;
    void set(int index, int value);
    // More methods will be placed here...

    const static int max_capacity = 262144; // 1MiB max size (1MiB / sizeof(int))
private:
    int array[max_capacity];    // internal storage (partially-filled array)
    int size = 0;               // logical size (how many elements are used)
};

void print_array(SuperThinArrayWrapper a);

void print_array(ThinArrayWrapper a);

void fill_array_v0(ThinArrayWrapper a);

void fill_array_v1(ThinArrayWrapper& a);

ThinArrayWrapper fill_array_v2();

#endif