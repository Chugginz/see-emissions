// @ quicksort.h

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include<iostream>
#include<algorithm>
#include<cstdlib>
    using std::rand;

int partition(int (array)[], int left, int right);

int choose_pivot(int left, int right);

void quicksort(int array[], int left, int right);

void quicksort(int array[], int size);

void check_array(int array[], int size);

int partition(int array[], int left, int right){
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

void quicksort(int array[], int left, int right){
    if (left < right){
        int division = partition(array, left, right);
        quicksort(array, left, division - 1);
        quicksort(array, division + 1, right);
    }
}

void quicksort(int array[], int size){
    int left = 0;
    int right = size - 1;
    quicksort(array, left, right);
}

void check_array(int array[], int size){
    for (int i = 0; i < size; i++)
        std::cout << "Array Value - " << i + 1 << " : " << array[i] << "\n";
}

int add_to_array(int array[], int size, int goal){
    while (size < goal){
        int value = rand() % 21;
        array[size] = value;
        std::cout << "New Value: " << value << "\n";
        size++;
    }
    
    return size;
}

#endif