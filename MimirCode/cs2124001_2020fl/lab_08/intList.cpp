// @ intList.cpp

#include "intList.h"
#include "intNode.h"
#include<iostream>
    using std::cout;
    using std::endl;
    
IntList::~IntList(){
    delete head;
    head = nullptr;
    cout << "Memory Freed";
}

bool IntList::is_empty() const{
    bool result;
    
    if (head == nullptr)
        result = true;
    else
        result = false;
        
    return result;
}

void IntList::add_front( int newData){
    IntNode newNode{newData};
    IntNode* front = new IntNode(newNode); // If not work, parenthesis
    
    if (head != nullptr)
        head -> set_next(front);
    else
        head = front;
}

void IntList::write(std::ostream& outfile) const{
    IntNode* current = head -> get_next();
    while (current != nullptr){
        outfile << current << endl;
        current = head -> get_next();
    }
}

std::ostream& operator<<(std::ostream& outfile, const IntList& list ){
    list.write(outfile);
    
    return outfile;
}