/**
 *******************************************************************************
 * @file    Item.h
 * @brief   A header file acting as a library, containing methods that
 *          manage aspects of an item such as it's name, price, and quantity
 *
 * @author  Christian Huggins
 * @date    January 27th, 2021
 *******************************************************************************
**/
#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item {
public:
    // constructors
    Item(std::string name, double price, int quantity);
    // accessors
    std::string get_name()     const;
    double      get_price()    const;
    int         get_quantity() const;
    // mutators
    void set_price(double new_price);
    void set_quantity(int new_quantity);
    // other methods
    void print() const; 
    
private:
    std::string name;     /// name of the item
    double      price;    /// price for one item
    int         quantity; /// how many are you buying?
};

#endif