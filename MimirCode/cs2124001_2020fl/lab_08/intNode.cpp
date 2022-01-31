// @ intNode.cpp

#include "intNode.h"
#include<iostream>
    using std::cout;
    
IntNode::IntNode(int new_value){
    payload = new_value;
    next = nullptr;
}

int IntNode::get_data() const{
    return payload;
}

void IntNode::set_next( IntNode* new_next ){
    if (next != nullptr)
        next -> set_next(new_next);
    else
        next = new_next;
}

IntNode* IntNode::get_next() const{
    return next;
}

void IntNode::debug_write(std::ostream& outfile ) const{
    outfile << payload << " (-> ";
    if (next == nullptr)
        outfile << "/ ) ";
    else
        outfile << get_next()->get_data() << " ) ";
}

std::ostream& operator<<(std::ostream& outfile, const IntNode& node ){
    node.debug_write(outfile);
    
    return outfile;
}