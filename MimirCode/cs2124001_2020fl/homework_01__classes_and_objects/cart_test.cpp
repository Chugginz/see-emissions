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


int main(){
ShoppingCart cart;

//Demonstrating the use of add function
cart.add(Item("Ruffles", 1.25, 3));
cart.print_vector();

//Demonstrating the updating quantity and multiple items function
cout << "\n";
cart.update_quantity("Ruffles", 1);
cart.add(Item("Doritos", 0.99, 4));
cart.print_vector();

//Demonstrating the remove function
cout << "\n";
cart.remove("Ruffles");
cart.print_vector();

cout << "\n";
cart.add(Item("Toothbrush", 2.49, 1));
cart.add(Item("Basketball", 9.99, 2));
cart.add(Item("Club Penguin Membership", 20.00, 1));
cart.write();

return 0;
}

#endif