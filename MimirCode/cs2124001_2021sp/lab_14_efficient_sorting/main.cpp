/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      04/26/2021
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    April 26th, 2021
 *******************************************************************************
**/

#include "quicksort.h"
#include "heapsort.h"

int main(){
    srand(1);
    int test_array[100] = {4, 11, 3, 2, 7, 12, 18, 9, 9, 1};
    int size = 10;
    
    //Testing Partition
    std::cout << "\nPartitioned List:\n";
    partition(test_array, 0, size - 1);
    check_array(test_array, size);
    //Testing Quicksort
    std::cout << "\nOriginal Sorted List:\n";
    quicksort(test_array, size);
    check_array(test_array, size);
    //Testing insert and sift down
    max_heap_insert(19, test_array, size);
    max_heap_sift_down(test_array, size);
    check_array(test_array, size);
    //Testing remove and other sift down
    heap_remove(test_array, size);
    max_heap_sift_down(test_array, 0, size - 1);
    check_array(test_array, size);
    //Creating two new identical lists
    std::cout << "\nNew List:\n";
    int test_array2[25];
    int test_array3[25];
    size = add_to_array(test_array2, 0, 25);
    for (int i = 0; i <= size; i++)
        test_array3[i] = test_array2[i];
    //Show new test array 2
    std::cout << "\nOriginal Array 2:\n";
    check_array(test_array2, size);
    //Generates max heap via bottom up
    std::cout << "\nBottom Up Array 2:\n";
    make_max_heap_bottom_up(test_array2, size);
    check_array(test_array2, size);
    //Show new test array 3
    std::cout << "\nOriginal Array 3:\n";
    check_array(test_array3, size);
    //Generates max heap via top down
    std::cout << "\nTop Down Array 3:\n";
    make_max_heap_top_down(test_array3, size);
    check_array(test_array3, size);
    
    //Heap sorts the array
    //heap_sort(test_array2, size);
    //std::cout << "\nHeap Sort Array:\n";
    //check_array(test_array2, size);
    
    return 0;
}