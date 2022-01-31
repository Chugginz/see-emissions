/**
 *******************************************************************************
 * @file    heapsort.h
 * @brief   A header file acting as a library, containing functions that conduct
 *          a heap sort as well as timing it.
 *
 * @author  Christian Huggins
 * @date    December 11th, 2020
 *******************************************************************************
**/

#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "maxheap.h"

/**
 * @brief       This function performs a heap sort.
 *
 * @detailed    This templated version of heap_sort performs a max heap
 *              sort, bottom up, then removes elements from the heap while
 *              the number of elements remaining is greater than 1
 *              
 * @param       T array[]        the array being accessed and sorted
 * 
 * @param       int size         Passed to make max heap bottom up
**/

template <typename T>
void heap_sort(T array[], int size);

/**
 * @brief       This function times multiple heap sorts and then averages them
 *
 * @detailed    This templated version of track heap time initialized the time
 *              variables, starts the time, performs a heap sort, then stops the
 *              time. The function does this 3 more times recording each time
 *              by adding it to the previous, divides it by 3, and then returns
 *              the average
 *              
 * @param       T array[]       the array being accessed and sorted
 * 
 * @param       T array2[]      the array used for copying it's information
 *                              to the first after it's sorted
 * 
 * @param       int size        Passed to heap sort and the copy function
**/

template <typename T>
double track_heap_time(T array1[], T array2[], int size);

template <typename T>
void heap_sort(T array[], int size){
    make_max_heap_bottom_up(array, size);
    //make element remaining equal to size
    int elem_remain = size;
    //While element is greater than one
    while (elem_remain > 1)
        //We remove from the heap the element at that index in the array
        heap_remove(array, elem_remain);
}

template <typename T>
double track_heap_time(T array1[], T array2[], int size){
    //Initializing variables for storing time
    std::chrono::high_resolution_clock::time_point  begin, end;
    std::chrono::duration<double>                   elapsed_time;
    double                                          elapsed_seconds = 0;
    
    //Record speed times 3 times
    for (int i = 0; i < 3; i++){
        //Record start time of quicksort
        begin = std::chrono::high_resolution_clock::now();
        heap_sort(array1, size);
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

#endif