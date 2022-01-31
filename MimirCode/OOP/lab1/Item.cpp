// @file Item.cpp
// Implimentations for 'class' item

#include "Item.h"

// Default Constructor:
Item::Item()
{
    price = 0.0;
    quantity = 0;
}

void Item::set_name(string n)
{
    name = n;
}

string Item::get_name()
{
    return name;
}

//Constructor
Item::Item(string n, double p, int q)
{
    name = n;
    price = p;
    quantity = q;
}

void Item::set_price(double p)
{
    price = p;
}

double Item::get_price()
{
    return price;
}

void Item::set_quantity(int q)
{
    quantity = q;
}

int Item::get_quantity()
{
    return quantity;
}
