/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   Lab work
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      8/31/2020
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    August 31, 2020
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    
#include "Item.h"
    
int main()
{
        //Top-down development
        //Want to have some chips
        //Item chips {"Ruffles", 1.25, 3};
        
        //Item item1; // requires a "default constructor"
        //item1.set_name("Ruffles");
        
        // Intent is to print the name
        //cout << item1.get_name() << "\n";
        
        Item chips("Ruffles", 1.25, 3);
        cout << "The chips are " << chips.get_name() << ". They cost $"
        << chips.get_price() << " and I have " << chips.get_quantity()
        << " bags.\n";
        
        chips.set_price(0.99);
        chips.set_quantity(69);
        
        cout << "The updated chips are " << chips.get_name() << ". They cost $"
        << chips.get_price() << " and I have " << chips.get_quantity()
        << " bags.\n";
        
        return 0;
}
