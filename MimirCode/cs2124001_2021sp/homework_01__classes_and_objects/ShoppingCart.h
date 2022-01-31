/**
 *******************************************************************************
 * @file    ShoppingCart.h
 * @brief   A header file acting as a library, containing methods that
 *          manage a vector that acts as a shopping cart.
 *
 * @author  Christian Huggins
 * @date    January 27th, 2021
 *******************************************************************************
**/
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include "Item.h"
#include<vector>
    using std::vector;
#include<string>
    using std::string;
#include<iostream>
    using std::cout;

class ShoppingCart {
    
public:
    //Mutators
    void add(Item itemData);
    bool update_quantity(string name, int q);
    bool remove(string name);
    //Accessors
    void print_vector();
    double total_value();
    void write();
    
private:
    //Vector that acts as a list or shopping cart
    vector<Item> list;
};

#endif