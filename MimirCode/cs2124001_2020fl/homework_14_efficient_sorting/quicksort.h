/**
 *******************************************************************************
 * @file    quicksort.h
 * @brief   A header file acting as a library, containing functions that conduct
 *          acts with the array and heapifying, sifting, etc.
 *
 * @author  Christian Huggins
 * @date    December 11th, 2020
 *******************************************************************************
**/

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include<chrono>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstdlib>
    using std::rand;

template <typename T>
int partition(T array[], int left, int right);

int choose_pivot(int left, int right);

template <typename T>
void quicksort(T array[], int left, int right);

template <typename T>
void quicksort(T array[], int size);

template <typename T>
void check_array(T array[], int size);

template <typename T>
int add_to_array(T array[], int size, int goal, int range_max);

template <typename T>
void copy_array(T array[], T array2[], int size);

template <typename T>
double track_quick_time(T array1[], T array2[], int size);

std::string random_string(int length);

template <typename T>
int partition(T array[], int left, int right){
    //Call choose_pivot to get a random pivot point
    int pivot_index = choose_pivot(left, right);
    int pivot_value = array[pivot_index];
    std::swap(array[pivot_index], array[right]);
    pivot_index = left;
    for (int i = left; i < right; i++){
        if (array[i] < pivot_value){
            std::swap(array[i], array[pivot_index]);
            pivot_index++;
        }
    }
    std::swap(array[pivot_index], array[right]);
    
    return pivot_index;
}

int choose_pivot(int left, int right){
    int pivot_index;
    
    do{
        pivot_index = left + (rand() % (right - left + 1));
    } while (pivot_index > left && pivot_index < right);
    
    return pivot_index;
}

template <typename T>
void quicksort(T array[], int left, int right){
    if (left < right){
        int division = partition(array, left, right);
        quicksort(array, left, division - 1);
        quicksort(array, division + 1, right);
    }
}

template <typename T>
void quicksort(T array[], int size){
    int left = 0;
    int right = size - 1;
    quicksort(array, left, right);
}

template <typename T>
void check_array(T array[], int size){
    for (int i = 0; i < size; i++)
        std::cout << "Array Value - " << i + 1 << " : " << array[i] << "\n";
}

template <typename T>
int add_to_array(T array[], int size, int goal, int range_max){
    while (size < goal){
        T value = rand() % range_max + size / 10;
        array[size] = value;
        size++;
    }
    
    return size;
}

template <typename T>
void copy_array(T array[], T array2[], int size){
    for (int i = 0; i < size; i++)
        array2[i] = array[i];
}

template <typename T>
double track_quick_time(T array1[], T array2[], int size){
    //Initializing variables for storing time
    std::chrono::high_resolution_clock::time_point  begin, end;
    std::chrono::duration<double>                   elapsed_time;
    double                                          elapsed_seconds = 0;
    
    //Record speed times 3 times
    for (int i = 0; i < 3; i++){
        //Record start time of quicksort
        begin = std::chrono::high_resolution_clock::now();
        quicksort(array1, size);
        end   = std::chrono::high_resolution_clock::now(); //Record end time
        //Get the period of time elapsed
        elapsed_time    = end - begin;
        //Convert to (fractional) seconds
        elapsed_seconds += elapsed_time.count();
        copy_array(array2, array1, size);
    }
    //Average time over 3 attempts
    elapsed_seconds = elapsed_seconds / 3;
    
    return elapsed_seconds;
}

std::string random_string(int length){
    std::string result = "";
    // ASCII printable (non-whitespace)
    int set_size = '~' - '!' + 1;
    // characters begin at '!' and end with '~'
    int base     = '!';
    // until the string is the desired length
    for(int i = 0; i < length; i++){
        // append random characters generated within the printable range
        result += static_cast<char>(rand() % set_size + base); 
    } 
    // return the resulting random string
    return result;
}

#endif