// @ IntNode.cpp

#include "IntNode.h"

IntNode::IntNode(int new_value){
    payload = new_value;
}

int IntNode::get_data() const{
    return payload;
}

void IntNode::set_next(IntNode* new_next){
    next = new_next;
}

IntNode* IntNode::get_next() const{
    return next;
}

void IntNode::debug_write(std::ostream& outfile) const{
    if (next != nullptr)
        outfile << payload << "(->" << next->get_data() << ")";
    else
        outfile << payload << "(-> / ) ";
}

std::ostream& operator<<(std::ostream& outfile, const IntNode& IntNode){
    IntNode.debug_write(outfile);
    
    return outfile;
}