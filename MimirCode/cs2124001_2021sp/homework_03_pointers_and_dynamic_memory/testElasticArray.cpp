/**
 *******************************************************************************
 * @file    testElasticArray.cpp
 * @brief   Main file for testing to ensure that code in functions in
 *          ElasticArray.cpp work correctly
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      2/8/2021
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    February 8th, 2021
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
    
#include "ElasticArray.h"

/**
 * @brief           This function tests the copy constructor
 *
 * @detailed        If copy constructor is wrong, value 999 will be printed
 *              
 * @param      a    An object of ElasticArray
**/

void test_ElasticArray_copy_ctor(ElasticArray a){
    for(int i = 0; i < a.size(); ++i)
        // just a value that will be easy to notice when printed.
        a.at(i) = 999;  
}

int main(){
    //Part 1
    ElasticArray this_requires_a_default_ctor;
    
    //Part 2
    //Testing front and back functions
    //this_requires_a_default_ctor.back();
    //this_requires_a_default_ctor.front();
    
    //Part 3
    ElasticArray source_array{5};
    ElasticArray destination_array{5};
    
    for(int i = 0; i < source_array.size(); ++i){
        source_array.at(i) = (i + 1); // fills with {1,2,3,4,5}
    }
    // Try to copy:
    destination_array = source_array;    // doesn't do what you want it to do...
    
    // change the supposed "copy":
    for(int i = 0; i < destination_array.size(); ++i)
        // double all the values in the "copy"
        destination_array.at(i) *= 2;     
        
    
    
    // Now let's have a look at the original array. (It *should* be the same
    // as before... but is it?)
    std::cout << "Original array should be:\n";
    std::cout << "1\t2\t3\t4\t5\n";
    std::cout << "It is:\n";
    for(int i = 0; i < source_array.size(); ++i)
        std::cout << source_array.at(i) << '\t';
    
    std::cout << std::endl;
    
    //Part 4
    ElasticArray source2_array{5};
    ElasticArray destination2_array{5};
    
    for(int i = 0; i < source2_array.size(); ++i)
        source2_array.at(i) = (i + 1); // fills with {1,2,3,4,5}
    
    // Try to copy:
    destination2_array = source2_array;
    
    // Now let's have a look at the original array. (It *should* be the same
    // as before... but is it?)
    std::cout << "Original array should be:\n";
    std::cout << "1\t2\t3\t4\t5\n";
    std::cout << "It is:\n";
    for(int i = 0; i < destination2_array.size(); ++i)
        std::cout << destination2_array.at(i) << '\t';
    
    std::cout << std::endl;
    
    test_ElasticArray_copy_ctor(destination2_array);
    
    return 0;
}