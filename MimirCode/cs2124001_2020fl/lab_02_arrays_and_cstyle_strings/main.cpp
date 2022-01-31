/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   Testing the knowledge and operations of arrays and cstrings
 *          of both the setting of them and retrieval of them
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      9/14/2020
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    September 14, 2020
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::endl;

#include<cstdlib>

#include<cstring>

#include "array_functions.h"

#include "Rectangle.h"

#include "c_string_utils.h"

int main(){
    srand(42);
    const int size = 100;
    int randomArray[size];
    char array2[15][15];
    Rectangle array3[20];
    
    //Beginning of random array section
    fill_random(randomArray, size);
    cout << average(randomArray, size) << endl;
    //test(randomArray[], size);
    
    //Beginning of puzzle array section
    make_puzzle(array2, 15);
    print_puzzle(array2, 15);
    
    //Beginning of rectangle section
    //print_rectangles(array3, 20);
    random_rectangles(array3, 20);
    print_rectangles(array3, 20);
    
    //Beginning of cstring section
    char state[]{ "Arkansas" };
    std::cout << state << " has " << my_strlen(state)
          << " (logical) characters and occupies "
          << sizeof(state) << " bytes.\n";
    
    return 0;
}