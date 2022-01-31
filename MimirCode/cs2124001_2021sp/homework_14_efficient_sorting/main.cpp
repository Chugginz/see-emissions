/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   Main file used for testing functions from other files
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      04/29/2021
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    April 29th, 2021
 *******************************************************************************
**/

#include "quicksort.h"
#include "heapsort.h"

int main(){
    
    //Test 1 - 100000
    //Initializing srand
    srand(time(0));
    //Initializing arrays 1 and 2
    int size = 100000;
    int array1[100000];
    int array2[100000];
    
    size = add_to_array(array1, 0, size, 1000000);
    copy_array(array1, array2, size);
    double time_elapsed;
    
    //Run average
    time_elapsed = track_heap_time(array1, array2, size);
    //Display time elapsed
    std::cout << "Test 1 (100,000, ints):\nSize - " << size 
        << " - - Heap Sort - " << time_elapsed << "s. ";
    
    //Run average
    time_elapsed = track_quick_time(array1, array2, size);
    //Display time elapsed
    std::cout << " - - Quick Sort - " << time_elapsed << "s.\n";
    
    
    //Test 2 - 10000
    //Initializing arrays 2 and 3
    size = 100000;
    int array3[100000];
    int array4[100000];
    
    //Updated array size incase it needed to be
    size = add_to_array(array3, 0, size, 1000);
    //Copy the array to backup for copying
    copy_array(array3, array4, size);
    
    //Run average
    time_elapsed = track_heap_time(array3, array4, size);
    //Display time elapsed
    std::cout << "\nTest 2 (100, ints):\nSize - " << size 
        << " - - Heap Sort - " << time_elapsed << "s. ";
    
    //Run average
    time_elapsed = track_quick_time(array3, array4, size);
    //Display time elapsed
    std::cout << " - - Quick Sort - " << time_elapsed << "s.\n";
    
    
    //Test 3 - 10000, doubles
    size = 100000;
    int array5[100000];
    int array6[100000];
    
    //Updated array size incase it needed to be
    size = add_to_array(array5, 0, size, 100000);
    //Copy array to have a backup for copying
    copy_array(array5, array6, size);
    
    //Run average
    time_elapsed = track_heap_time(array5, array6, size);
    //Display time elapsed
    std::cout << "\nTest 3 (10,000, doubles):\nSize - " << size 
        << " - - Heap Sort - " << time_elapsed << "s. ";
    
    //Run average
    time_elapsed = track_quick_time(array5, array6, size);
    //Display time elapsed
    std::cout << " - - Quick Sort - " << time_elapsed << "s.\n";
    
    /*
    //Test 4 - 3 - 10, strings
    size = 100000;
    std::string array7[100000];
    std::string array8[100000];
    
    for (int i = 0; i < size; i++){
        int value = rand() % 11 + 3;
        array7[i] = random_string(value);
    }
    
    copy_array(array7, array8, size);
    
    //Run average
    time_elapsed = track_heap_time(array7, array8, size);
    //Display time elapsed
    std::cout << "\nTest 4 (3-10, strings):\nSize - " << size 
        << " - - Heap Sort - " << time_elapsed << "s. ";
    
    //Run average
    time_elapsed = track_quick_time(array5, array6, size);
    //Display time elapsed
    std::cout << " - - Quick Sort - " << time_elapsed << "s.\n";
    */
    return 0;
}