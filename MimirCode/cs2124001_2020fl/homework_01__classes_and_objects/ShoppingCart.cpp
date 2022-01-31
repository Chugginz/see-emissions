// @file ShoppingCart.cpp
#ifndef SHOPPINGCART_CPP
#define SHOPPINGCART_CPP
#include "ShoppingCart.h"

/**
 * @brief       This function adds an item to the shopping cart
 *
 * @detailed    Requires an Item to add a name, price, and quantity
 *              to a list (vector)
 *              
 * @param      itemData     An item consisting of a name, price,
 *              and quantity
**/

void ShoppingCart::add(Item itemData, vector<Item> username)
{
    int size = list.size();
    int counter = 0;
    bool does_exist = false;
    
    if (itemData.get_quantity() <= 0)
        cout << "\n You can not add less than one of something... \n";
    else
    {
        while (counter < size)
        {
            if ((list.at(counter).get_name() == itemData.get_name()) 
                && (list.at(counter).get_price() == itemData.get_price()))
            {
                int newQuantity = list.at(counter).get_quantity() 
                    + itemData.get_quantity();
                    
                list.at(counter).set_quantity(newQuantity);
                does_exist = true;
            }
            
            counter++;
        }
        
        if (does_exist == false)
            list.push_back(itemData);
    }
}

/**
 * @brief       This function updates an items quantity
 *
 * @detailed    Requires a name and quantity to change the items
 *              quantity value
 *              
 * @param      name     The name of an item that needs its
 *                  quantity updated
 * 
 * @param       q       Representing quantity used to change
 *                  the value of an items quantity.
 *
 * @return      Returns true or false based on whether or not
 *              changes were made
**/

bool ShoppingCart::update_quantity(string name, int q)
{
    int size = list.size();
    int counter = 0;
    bool result = false;
    int quantity = q;
    
    
    while (counter < size)
    {
        if (list.at(counter).get_name() == name)
        {
            if (quantity < 1)
                quantity = 0;
                
            list.at(counter).set_quantity(quantity);
            
            if (quantity == 0)
                list.erase(list.begin() + counter);
                
            result = true;
            counter = size;
        }
        else
            counter++;
    }
    
    return result;
}

/**
 * @brief       This function removes an item from the list (vector)
 *
 * @detailed    Requires a name to know which item to remove from the list
 *              
 * @param      name     The name of an item that needs to be removed
 * 
 * @return      Returns true or false based on whether or not
 *              changes were made
**/

bool ShoppingCart::remove(string name)
{
    bool result = false;
    int counter = 0;
    int size = list.size();
    
    while (counter < size)
    {
        if (list.at(counter).get_name() == name)
        {
            list.erase(list.begin() + counter);
                
            result = true;
            counter = size;
        }
        else
            counter++;
    }
    
    return result;
}

/**
 * @brief       This function totals numbers
 *
 * @detailed    This function adds together the prices of all
 *              of the items and takes in account the quantity
 *              to get the total value of the cart
 *              
 * @return      Returns the total value of the cart
**/

double ShoppingCart::total_value()
{
    int counter = 0;
    int size = list.size();
    double sum = 0;
    
    while (counter < size)
    {
        sum += (list.at(counter).get_price() * list.at(counter).get_quantity());
        counter ++;
    }
    
    return sum;
}

/**
 * @brief       This function writes out everything in the cart and gives the
 *              total cart value
 *
 * @detailed    This function lists every item, its price and quantity, and then
 *              gives the final total at the end.
 *              
**/

void ShoppingCart::write()
{
    int counter = 0;
    int size = list.size();
    double sum = 0;
    
    ShoppingCart cart;
    
    while (counter < size)
    {
        cout << list.at(counter).get_name() << " is/are $" 
            << list.at(counter).get_price() << " and you have " 
            << list.at(counter).get_quantity() << " in your cart.\n";
        sum += (list.at(counter).get_price() * list.at(counter).get_quantity());
        counter++;
    }
    cout << "\nYour total will be $" << total_value() << "\n";
}

/**
 * @brief       This function writes out everything in the cart
 *
 * @detailed    This function was a custom test I made to ensure
 *              everything couts properly by displaying every item,
 *              their prices and their quantities.
 *              
**/

void ShoppingCart::print_vector()
{
    int counter = 0;
    int size = list.size();
    
    while (counter < size)
    {
        cout << list.at(counter).get_name() << " are $" 
            << list.at(counter).get_price() << " and you have " 
            << list.at(counter).get_quantity() << " in your cart.\n";
        counter++;
    }
}

#endif