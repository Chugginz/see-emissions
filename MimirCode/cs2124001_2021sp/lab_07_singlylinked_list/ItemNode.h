// @ItemNode.h

#ifndef ITEMNODE_H
#define ITEMNODE_H

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
#include <string>
#include <vector>    
#include <iomanip>
#include <fstream>
#include "Item.h"

class ItemNode {
public:
    ItemNode( const Item& new_item ) : payload{new_item} {};
    Item          get_item( ) const;
    ItemNode*     get_next( ) const;
    void          set_next( ItemNode* node );
    std::ostream& write( std::ostream& fout ) const;
    ~ItemNode();
private:
    Item      payload;
    ItemNode* next = nullptr;
};
std::ostream& operator<<( std::ostream& fout, const ItemNode& node );

#endif