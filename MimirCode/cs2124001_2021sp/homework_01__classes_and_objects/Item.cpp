/**
 *******************************************************************************
 * @file    Item.cpp
 * @brief   An implementation file that contains all definitions to methods
 *          that were established in the header file Item.h
 *
 * @author  Christian Huggins
 * @date    January 27th, 2021
 *******************************************************************************
**/
#include "Item.h"
#include <iomanip>
#include <iostream>

/**
 * @brief       This function acts as a constructor initializing all values
 *              in the class Item upon initialization
 *
 * @detailed    If provided the item's name, price, and quantity, the
 *              constructor will set the values in the private section
 *              to be the same as the parameters given
 *              
 * @param      name     The name of an item that is being initialized
 * 
 * @param       price       Representing price used to change the value
 *                  of an item's price
 *
 * @param       quantity    Representing quantity used to change
 *                  the value of an item's quantity.
**/

Item::Item( std::string name, double price, int quantity ) {
    this->name     = name;  // `this->` means "self"
    this->price    = price;
    this->quantity = quantity;
}

/**
 * @brief       This function acts as an accessor that provides the user
 *              the name of the item.
 *
 * @detailed    This function is an accessor that allows the user to get
 *              the name of an item by returning it. This is necessary
 *              because the name is private, thus can only be accessed
 *              within the class.
 *              
 * @return      Returns a string that holds the name of an item
**/

std::string Item::get_name( ) const {
    return name;
}

/**
 * @brief       This function acts as an accessor that provides the user
 *              the price of the item.
 *
 * @detailed    This function is an accessor that allows the user to get
 *              the price of an item by returning it. This is necessary
 *              because the price is private, thus can only be accessed
 *              within the class.
 *              
 * @return      Returns a double that holds the price of an item
**/

double Item::get_price( ) const {
    return price;
}

/**
 * @brief       This function acts as an accessor that provides the user
 *              the quantity of the item.
 *
 * @detailed    This function is an accessor that allows the user to get
 *              the quantity of an item by returning it. This is necessary
 *              because the quantity is private, thus can only be accessed
 *              within the class.
 *              
 * @return      Returns an int that holds the quantity of an item
**/

int Item::get_quantity( ) const {
    return quantity;
}

/**
 * @brief       This function acts as a mutator that allows the user to change
 *              the price of an item.
 *
 * @detailed    This function is a mutator that allows the user to set a new
 *              price of an item. This is done by taking a new price in as a
 *              parameter. The price in the class is then overwritten with
 *              a new value.
 * 
 * @param       new_price       This parameter is the new desired price the
 *                  user wants to set for the item. It is is used to overwrite
 *                  the old price. This is a double because the price often
 *                  times goes into the decimals.
**/

void Item::set_price( double new_price ) {
    price = new_price;
}

/**
 * @brief       This function acts as a mutator that allows the user to change
 *              the quantity of an item.
 *
 * @detailed    This function is a mutator that allows the user to set a new
 *              quantity of an item. This is done by taking a new quantity in as a
 *              parameter. The quantity in the class is then overwritten with
 *              a new value.
 * 
 * @param       new_quantity      This parameter is the new desired quantity the
 *                  user wants to set for the item. It is is used to overwrite
 *                  the old quantity. This is an int because you can't buy
 *                  half of an item.
**/


void Item::set_quantity( int new_quantity ) {
    quantity = new_quantity;
}

/**
 * @brief       This function allows the user to print all info about the item
 *              to the screen.
 *
 * @detailed    This function allows the user to print all info about the item
 *              to the screen. This saves the user time so they don't have to
 *              format every time they want to see the different aspects of an
 *              item.
**/


void Item::print( ) const {
    std::cout << std::fixed << std::setprecision( 2 );
    std::cout << name << '\n';
    std::cout << "\tPrice: $  " << price << '\n';
    std::cout << "\tQuantity: " << quantity << '\n';
}
