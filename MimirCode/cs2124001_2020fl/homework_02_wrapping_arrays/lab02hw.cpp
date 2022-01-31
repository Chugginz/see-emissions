/**
 *******************************************************************************
 * @file    lab02hw.cpp
 * @brief   Main code testing all functions in other cpp files and header
 *          contents
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      9/21/2020
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    September 21, 2020
 *******************************************************************************
**/

#include <iostream>
    using std::cout;
    using std::cin;
    using std::endl;

#include "ThinArrayWrapper.h"

int main(){
    //Part 1
    //SuperThinArrayWrapper is the first struct being initialized
    SuperThinArrayWrapper a;
    //ThinArrayWrapper is second struct being initialized
    //ThinArrayWrapper b;
    
    for (int i = 0; i < 20; i++){
        a.array[i] = (10 + i * 10);
    }
    
    print_array(a);
    
    //Part 2
    //fill_array_v1(b);
    
    //print_array(b);
    
    //ThinArrayWrapper c = fill_array_v2();
    //cout << endl << c.array[1];
    
    //Part 3
    ArrayWrapper wrapper(20);
    
    cout << endl << wrapper.get_size();
    wrapper.set(12, 14);
    cout << endl << wrapper.get(12) << endl;
    //Throw Test
    //cout << endl << wrapper.get(24) << endl; 
    
    //Part 4
    ArrayWrapper catch_example_array{20};
    for(int i = 0; i < catch_example_array.get_size(); ++i){
        catch_example_array.set(i, (i+1));
    }
    int selected_index = 0;
    while(selected_index >= 0){
        std::cout << "Enter an index to print the item.  (-1 to stop): ";
        std::cin  >> selected_index;
        if(selected_index != -1){
            try{
                int value = catch_example_array.get(selected_index);
                std::cout << "The item at index " << selected_index
                          << " is " << value << '\n';
            }
            catch(const std::out_of_range&){
                std::cout << "The index " << selected_index 
                          << " is not a valid index.\n";
                std::cout << "Valid indices are 0 to "
                          << catch_example_array.get_size() - 1
                          << '\n';
                // Reset to allow the loop to continue if index was negative.
                selected_index = 0;  
            }
        }
    }
    
    //Part 5
    
    
    return 0;
}

