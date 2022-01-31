/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      10/05/2020
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    October 5, 2020
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
#include <string>
#include <vector>    
#include <iomanip>
#include <fstream>
#include "Item.h"

int main(){
    
    std::ofstream dbg{"debug.txt"};  // open a file named debug.txt

    Item test_item{"Great Sword", 1};
    dbg << "test item: \n" << test_item << "\n" << endl;
    
    return 0;
}