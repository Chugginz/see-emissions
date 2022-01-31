// @file Item.cpp
#include "Item.h"
#include <iomanip>
#include <iostream>

Item::Item( std::string name, double price, int quantity ) {
    this->name     = name;  // `this->` means "self"
    this->price    = price;
    this->quantity = quantity;
}

std::string Item::get_name( ) const {
    return name;
}

double Item::get_price( ) const {
    return price;
}

int Item::get_quantity( ) const {
    return quantity;
}

void Item::set_price( double new_price ) {
    price = new_price;
}

void Item::set_quantity( int new_quantity ) {
    quantity = new_quantity;
}

void Item::print( ) const {
    std::cout << std::fixed << std::setprecision( 2 );
    std::cout << name << '\n';
    std::cout << "\tPrice: $  " << price << '\n';
    std::cout << "\tQuantity: " << quantity << '\n';
}
