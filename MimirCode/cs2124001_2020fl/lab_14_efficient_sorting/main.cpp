/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      12/7/2020
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    December 7th, 2020
 *******************************************************************************
**/

#include "quicksort.h"
#include "heapsort.h"

int main(){
    srand(1);
    int test_array[100] = {4, 11, 3, 2, 7, 12, 18, 9, 9, 1};
    int size = 10;
    
    std::cout << "\nOriginal Sorted List\n\n";
    quicksort(test_array, size);
    check_array(test_array, size);
    
    std::cout << "\nNew Sorted List\n\n";
    int test_array2[25];
    size = add_to_array(test_array2, 0, 25);
    std::cout << "\nOriginal Array:\n";
    check_array(test_array2, size);
    make_max_heap_top_down(test_array2, 25);
    std::cout << "\nTop Down Array:\n";
    check_array(test_array2, size);
    make_max_heap_bottom_up(test_array2, size);
    std::cout << "\nBottom Up Array:\n";
    check_array(test_array2, size);
    heap_sort(test_array2, size);
    std::cout << "\nHeap Sort Array:\n";
    check_array(test_array2, size);
    
    /*
    std::cout << "\nNow Removing Values\n\n";
    while (size > 0){
        std::cout << "Element removed:" 
            << heap_remove(test_array2, size) << "\n";
    }
    */
    
    
    return 0;
}