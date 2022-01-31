/**
 *******************************************************************************
 * @file    card_test.cpp
 * @brief   A program that will keep track of your shopping cart and total
 *          everything for you.
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      9/8/2020
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    September 8, 2020
 *******************************************************************************
**/
#ifndef CART_TEST_CPP
#define CART_TEST_CPP
#include "ShoppingCart.h"


int main()
{
    string username, itemName;
    double price;
    int quantity;
    string choice = "y";
    ShoppingCart cart;

    while (choice == "y")
    {
        cout << "\nEnter the name of the item: ";
        cin >> itemName;
        cout << "\nEnter the price (leave out dollar sign): ";
        cin >> price;
        cout << "\nEnter the quantity: ";
        cin >> quantity;
        
        
        
        cart.add(Item(itemName, price, quantity));
    
        cout << "\nAre there any more items you would like to add?" 
        << " (y or n): ";
        cin >> choice;
    }
    
    cart.write();

    return 0;
}

#endif