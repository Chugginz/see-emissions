/**
 *******************************************************************************
 * @file    quicksort.h
 * @brief   A header file acting as a library, containing functions that conduct
 *          acts with the array and heapifying, sifting, etc.
 *
 * @author  Christian Huggins
 * @date    April 29th, 2021
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

/**
 * @brief       This function partitions an array
 *
 * @detailed    Given a pivot index, this function swaps the value at the
 *              pivot index with the farthest right value, and then sets the
 *              pivot index to the left index. A loop is then executed swaping
 *              i values and the pivot index value when the i index value is
 *              less than the other, and then increments the pivot index.
 *              Lastly, the pivot index value and the i index value are swapped
 *              and the pivot index is returned.
 *              
 * @param       T array[]       The array being accessed and sorted
 * 
 * @param       int left        The farthest left index of the array
 * 
 * @param       int right       The farthest right index of the array
 * 
 * @return      Returns the index that was used for the pivot
**/

template <typename T>
int partition(T array[], int left, int right);

/**
 * @brief       This function chooses a pivot index
 *
 * @detailed    Using a do-while loop, this function finds a random index as
 *              long as it is between the the left and the right. That index
 *              is then returned.
 *              
 * @param       int left        The farthest left index of the array
 * 
 * @param       int right       The farthest right index of the array
 * 
 * @return      Returns the index that will be used for pivoting
**/

int choose_pivot(int left, int right);

/**
 * @brief       This function quickly sorts an array
 *
 * @detailed    This function while left is less than right, continues to
 *              partition giving the value to division, and then passing those
 *              values to two more quicksorts, resulting in a recursive
 *              operation until the end of the array.
 *              
 * @param       T array[]       The array being accessed and sorted
 * 
 * @param       int left        The farthest left index of the array
 * 
 * @param       int right       The farthest right index of the array
**/

template <typename T>
void quicksort(T array[], int left, int right);

/**
 * @brief       This function quickly sorts an array
 *
 * @detailed    Establishing the left index as 0 and the right index as the size
 *              minus 1, this function then passes the left, right, and array
 *              to the other quicksort function
 *              
 * @param       T array[]       The array being accessed and sorted
 * 
 * @param       int size        The size of the array being used
**/

template <typename T>
void quicksort(T array[], int size);

/**
 * @brief       This function prints an array
 *
 * @detailed    Using a for loop, the function increments up until the last
 *              index, reading every array to the user so they can see what
 *              values are in the array
 *              
 * @param       T array[]       The array being accessed and sorted
 * 
 * @param       int size        The size of the array being used
**/

template <typename T>
void check_array(T array[], int size);

/**
 * @brief       This function adds to an array
 *
 * @detailed    This function adds to an array, finding a random number within
 *              the maximum array, then adds to it until the array reaches its
 *              goal
 *              
 * @param       T array[]       The array being accessed and sorted
 * 
 * @param       int size        The size of the array being used
 * 
 * @param       int goal        The desired array size
 * 
 * @param       int range_max   The maximum range for the array's index
**/

template <typename T>
int add_to_array(T array[], int size, int goal, int range_max);

/**
 * @brief       This function copies an array
 *
 * @detailed    For each value up until the index, the first array's index
 *              value is copied over to the second array's index
 *              
 * @param       T array[]       The original array being accessed and sorted
 * 
 * @param       T array2[]      The array being copied to
 * 
 * @param       int size        The size of the array that's being copied
**/

template <typename T>
void copy_array(T array[], T array2[], int size);

template <typename T>
double track_quick_time(T array1[], T array2[], int size);

std::string random_string(int length);

template <typename T>
int partition(T array[], int left, int right){
    //Call choose_pivot to get a random pivot point
    int pivot_index = choose_pivot(left, right);
    //Swaps the value at the pivot index and the value at the right index
    std::swap(array[pivot_index], array[right]);
    //Sets the pivot index to the left
    pivot_index = left;
    //With i at left, i less than right - 1, and i increments
    for (int i = left; i < right - 1; i++){
        //If the value at the index i is less than the value at the index pivot
        if (array[i] < array[pivot_index]){
            //Swaps the value at the index i and the value at the index pivot
            std::swap(array[i], array[pivot_index]);
            //Increment the pivot index
            pivot_index++;
        }
    }
    //Swaps the value at the index pivot and the value at the right index
    std::swap(array[pivot_index], array[right]);
    
    return pivot_index;
}

int choose_pivot(int left, int right){
    //Initialize the pivot index
    int pivot_index;
    
    do{
        //Get a random value between the index values
        pivot_index = left + (rand() % (right - left + 1));
    } while (pivot_index < left || pivot_index > right);
    //Do this while the index is not within the range
    
    return pivot_index;
}

template <typename T>
void quicksort(T array[], int left, int right){
    //If the left value is less than the right
    if (left < right){
        //Partition and get the pivot index
        int division = partition(array, left, right);
        //Pass array, left, and the pivot index - 1 to the function again
        quicksort(array, left, division - 1);
        //Pass array, pivot index + 1, and right to the function again
        quicksort(array, division + 1, right);
    }
}

template <typename T>
void quicksort(T array[], int size){
    //Set left to 0
    int left = 0;
    //Set right to the size - 1 for the maximum index available
    int right = size - 1;
    //Pass the array, left, and right to the other quicksort function
    quicksort(array, left, right);
}

template <typename T>
void check_array(T array[], int size){
    //While i is less than size, starting at 0, increment after loop
    for (int i = 0; i < size; i++)
        //Display array value at the index
        std::cout << "Array Value - " << i + 1 << " : " << array[i] << "\n";
}

template <typename T>
int add_to_array(T array[], int size, int goal, int range_max){
    //While the size is less than the goal
    while (size < goal){
        //Get a random value within the range
        T value = rand() % range_max + size / 10;
        //Store the new value at the size index
        array[size] = value;
        //Increment the size index
        size++;
    }
    
    return size;
}

template <typename T>
void copy_array(T array[], T array2[], int size){
    //While i is less than size, starting at 0, increment after loop
    for (int i = 0; i < size; i++)
        //Set the array2's value to be equal to that of the original array's
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