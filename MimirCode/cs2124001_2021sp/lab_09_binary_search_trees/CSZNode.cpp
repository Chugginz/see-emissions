// @ CSZNode.cpp

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
    
#include "CSZNode.h"

void CSZNode::set_left(CSZNode* new_left){
    left = new_left;
}

void CSZNode::set_right(CSZNode* new_right){
    right = new_right;
}

CityStateZip CSZNode::get_data() const{
    return payload;
}

CSZNode* CSZNode::get_left() const{
    return left;
}

CSZNode* CSZNode::get_right() const{
    return right;
}

void CSZNode::write(std::ostream& fout) const{
    payload.write(fout);
}

std::ostream& operator<<(std::ostream& fout, const CSZNode& n){
    n.write(fout);
    
    return fout;
}

bool CSZNode::operator < (const CSZNode& op2) const{
    bool result = false;
    
    if (get_data().city() < op2.get_data().city())
        result = true;
        
    return result;
}