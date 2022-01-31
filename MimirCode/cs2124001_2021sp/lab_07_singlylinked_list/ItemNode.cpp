// @ ItemNode.cpp

#include "ItemNode.h"

Item ItemNode::get_item() const {
    return payload;
}

ItemNode* ItemNode::get_next() const{
    return next;
}

void ItemNode::set_next( ItemNode* node ){
    next = node;
}

std::ostream& ItemNode::write( std::ostream& fout ) const{
    payload.write(fout);
    if (next != nullptr)
        fout << " ( " << next->payload.name << " )\n";
    else
        fout << " ( -------- )\n";
    
    return fout;
}

std::ostream& operator<<( std::ostream& fout, const ItemNode& node ){
    node.write(fout);
    
    return fout;
}

ItemNode::~ItemNode(){
    cout << "Deleting node containing " << payload << endl;
}