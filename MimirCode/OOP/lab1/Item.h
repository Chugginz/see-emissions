// @file Item.h
// Class definition for class "Item"
// We need "include guards"":
#ifndef ITEM_H
#define ITEM_H

#include <string>
    using std::string;

class Item
{
    public:
        Item();  // <-- This is a default constructor
        Item(string n, double p, int q);
        void set_name(string n);        //ACCESSOR
        string get_name();              //MUTATOR
        void set_price(double p);
        double get_price();
        void set_quantity(int q);
        int get_quantity();
    private:
        string name;
        double price;
        int quantity;
};

#endif