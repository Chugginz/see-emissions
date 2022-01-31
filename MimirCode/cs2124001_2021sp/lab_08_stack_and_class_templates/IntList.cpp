// @ IntList.cpp

#include "IntList.h"

IntList::~IntList(){
    //While the head is no nullptr
    while (head != nullptr){
        //Call remove front function
        remove_front();
    }
}

bool IntList::is_empty() const{
    //Initialize result as false
    bool result = false;
    //If head does not point to anythin
    if (head == nullptr)
        //Set the result to true
        result = true;
    //Return the result
    return result;
}

void IntList::add_front(int newData){
    //Create new node with new data
    IntNode* new_node = new IntNode{newData};
    //If the head does not point to anything
    if (head == nullptr){
        //Set the head and tail to point to the new node
        head = new_node;
    }
    else{
        //Set the new node's next to head
        new_node->set_next(head);
        //Point head to the new node
        head = new_node;
    }
}

int IntList::remove_front(){
    //Create a new node set to point to what head is
    IntNode* removed_node = head;
    int removed_data = head->get_data();
    //If there is no head
    if (head == nullptr)
        //Nothing can be removed, so throw an exception
        std::length_error("List is empty");
    //Else
    else{
        //Delete the head node
        delete head;
        //Set the new head node to point to the next node
        head = removed_node->get_next();
    }
    //Return the erased head node
    return removed_data;
}

void IntList::write(std::ostream& outfile) const{
    //Creates a current pointer to iterate through list
    IntNode* current = head;
    //While the current is not nullptr
    while (current != nullptr){
        //Write dereferenced current node to outfile stream
        outfile << *current << endl;
        //Set the current to the next value of current
        current = current->get_next();
    }
}

std::ostream& operator<<(std::ostream& outfile, const IntList& list){
    //Call list's write function giving the outfile stream
    list.write(outfile);
    //Return the outfile
    return outfile;
}