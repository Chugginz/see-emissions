/**
 *******************************************************************************
 * @file    ThinArrayWrapper.cpp
 * @brief   Code for functions of classes and structures in the header file
 *          "ThinArrayWrapper.h"
 *
 * @author  Christian Huggins
 * @date    February 1, 2021
 *******************************************************************************
**/

#include <iostream>
    using std::cout;
    using std::cin;
    using std::endl;

#include "ThinArrayWrapper.h"

/**
 * @brief       This function prints SuperThinArrayWrapper
 *
 * @detailed    Starting from 0 going to arrays max, each value of the array
 *              will be couted seperated by a comma
 *              
 * @param      a     An item
**/

void print_array(SuperThinArrayWrapper a){
    for (int i = 0; i < 20; i++){
        if (i < 19)
            cout << a.array[i] << ", ";
        else
            //if last, no comma
            cout << a.array[i] << endl; 
    }
}

/**
 * @brief       This function prints ThinArrayWrapper
 *
 * @detailed    Starting from 0 going to arrays max, each value of the array
 *              will be couted seperated by a comma
 *              
 * @param      a     An item
**/

void print_array(ThinArrayWrapper a){
    for (int i = 0; i < a.size; i++){
        if (i < (a.size - 1))
            cout << a.array[i] << ", ";
        else
            //if last value, don't place comma
            cout << a.array[i] << endl;
    }
}

/**
 * @brief       This function fills thinarray incorrectly
 *
 * @detailed    Due to making a copy of the array, this function
 *              was intended to fill an array but does not
 *              
 * @param      a     An item
**/

void fill_array_v0(ThinArrayWrapper a){
    for (int i = 0; i < a.size; i++){
        cout << "\nEnter a value for the array: ";
        cin >> a.array[i];
    }
}

/**
 * @file        ThinArrayWrapper.cpp
 * @brief       This function fills an array due to reference parameter
 *
 * @detailed    Starting from 0 going to arrays max, each value of the array
 *              is entered by the user
 *              
 * @param      a     An item
**/

void fill_array_v1(ThinArrayWrapper& a){
    int size = a.size;
    
    //while counter is less than size, fill array
    for (int i = 0; i < size; i++){
        cout << "\nEnter a value for the array: ";
        cin >> a.array[i];
    }
}

/**
 * @brief       This function fills an array without needing to pass any
 *              parameters
 *
 * @detailed    Creating an object inside, this function fills an array
 *              via user input from 0 to array max
 *              
 * @param      a     An item
**/

ThinArrayWrapper fill_array_v2(){
    ThinArrayWrapper a;
    
    //while counter is less that size, fill array
    for (int i = 0; i < a.size; i++){
        cout << "\nEnter a value for the array: ";
        cin >> a.array[i];
    }
    
    return a;
}