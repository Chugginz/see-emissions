// @file ShoppingCart.h
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
    void add(Item itemData);
    bool update_quantity(string name, int q);
    bool remove(string name);
    void print_vector();
    double total_value();
    void write();
private:
    vector<Item> list;
};



#endif