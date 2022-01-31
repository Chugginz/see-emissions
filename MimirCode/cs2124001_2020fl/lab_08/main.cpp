/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      10/19/2020
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    October 19th, 2020
 *******************************************************************************
**/

#include "intNode.h"
#include "intList.h"
#include<iostream>
    using std::cout;
#include<stdexcept>

int main(){
    
    cout << "The Stack & the Class Template (in-lab portion)\n";
    IntNode int_item_1( 101 );
    IntNode int_item_2( 212 );
    cout << "test nodes: " << int_item_1 << ' ' << int_item_2 << "\n";
    int_item_1.set_next( &int_item_2 );
    cout << "test next:  " << int_item_1 << ' ' << int_item_2 << "\n\n";
    
    IntList list1;
    list1.add_front( 101 );
    list1.add_front( 212 );
    list1.add_front( 323 );
    list1.add_front( 434 );
    cout << "test list 101/212/323/434:\n" << list1 << "\n\n";
    
    return 0;
}