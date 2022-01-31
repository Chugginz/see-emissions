/**
 *******************************************************************************
 * @file    cart_test.cpp
 * @brief   This is the main file used for testing purposes for the other code
 *          written for the project.
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      1/28/2021
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    January 27th, 2021
 *******************************************************************************
**/
#include "ShoppingCart.h"
#include "Item.h"

int main(){
ShoppingCart cart;

//Demonstrating the use of add function
cart.add(Item("Ruffles", 1.25, 3));
cart.print_vector();

//Demonstrating the updating quantity and multiple items function
cout << "\n";
//Changing the quantity of Item Ruffles from 3 to 1
cart.update_quantity("Ruffles", 1);
//Adding Item Doritos with the price of $.99 and quantity of 4
cart.add(Item("Doritos", 0.99, 4));
cart.print_vector();

//Demonstrating the remove function
cout << "\n";
//Removing the Item Ruffles from the shopping cart
cart.remove("Ruffles");
cart.print_vector();

cout << "\n";
//Adding Item Toothbrush with the price of $2.49 and quantity of 1
cart.add(Item("Toothbrush", 2.49, 1));
//Adding Item Basketball with the price of $9.99 and quantity of 2
cart.add(Item("Basketball", 9.99, 2));
//Adding Item Club Penguin Membership of $20.00 and quantity of 1
cart.add(Item("Club Penguin Membership", 20.00, 1));
cart.write();

return 0;
}