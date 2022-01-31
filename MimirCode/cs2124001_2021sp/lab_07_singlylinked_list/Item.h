// @ Item.h

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
    using std::cout;
    using std::cin;
    using std::endl;
#include <string>
#include <vector>    
#include <iomanip>
#include <fstream>

struct Item {
    Item(std::string name, int magic=0)
        : name{name}, magic{magic} {}
    std::string name;       /// Item name
    int         magic = 0;  /// Amount of "magic" the item is imbued with

    std::ostream& write( std::ostream& fout ) const;
};
std::ostream& operator<<( std::ostream& fout, const Item& item );

#endif