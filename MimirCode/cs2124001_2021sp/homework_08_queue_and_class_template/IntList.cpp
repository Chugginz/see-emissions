/**
 *******************************************************************************
 * @file    IntList.cpp
 * @brief   Implementation file for class IntList
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      3/15/2021
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    March 15, 2021
 *******************************************************************************
**/

#include "IntList.h"

/**
 * @brief                   Destructor
 *
 * @detailed                This function executes a while loop, by calling the
 *                          remove front function until the list is empty.
**/

IntList::~IntList(){
    //While the head is no nullptr
    while (head != nullptr){
        //Call remove front function
        remove_front();
    }
}

/**
 * @brief                   Checks if list is empty
 *
 * @detailed                After initializing a bool type variable to
 *                          represent the result, if there is no head,
 *                          then the list is empty and the result should be
 *                          made true. After, return the result.
 *              
 * @return  bool            Returns the result of type bool
**/

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

/**
 * @brief                   Adds a new node to the front of the list
 *
 * @detailed                This function creates a new node given new data.
 *                          Then, it checks if there is a head. If the head
 *                          does not exist, then set the head to point to the
 *                          new node. Otherwise, set the new node's next to
 *                          the head, then point the head to the new node.
 *              
 * @param   int newData     Takes new data to use for a new node
**/

void IntList::add_front(int newData){
    //Create new node with new data
    IntNode* new_node = new IntNode{newData};
    //If the head does not point to anything
    if (head == nullptr){
        //Set the head and tail to point to the new node
        head = new_node;
        tail = new_node;
    }
    else{
        //Set the new node's next to head
        new_node->set_next(head);
        //Point head to the new node
        head = new_node;
    }
}

/**
 * @brief                   Adds to the end of a list
 *
 * @detailed                This function checks to see if a tail exists. If
 *                          one doesn't, then the function will create a new
 *                          node and point the head to it. Otherwise, the 
 *                          tail's next will be set to new node, and the tail
 *                          will be set to the new node.
 *              
 * @param   int newData     Used to create a new node to be added to the
 *                          end of the list
**/

void IntList::add_back(int newData){
    //Create new node with new data
    IntNode* new_node = new IntNode{newData};
    //If the tail does not exist
    if (tail == nullptr){
        //Set the tail and head to point to the new node
        head = new_node;
        tail = new_node;
    }
    //Else
    else{
        //Set the tail's next node to the new node
        tail->set_next(new_node);
        //Point tail to the new node
        tail = new_node;
    }
}

/**
 * @brief                   Removes the front node from the list
 *
 * @detailed                After bounds checking, if no exception is thrown,
 *                          the node going to be erased will be stored, the head
 *                          will be deleted for dynamic memory purposes, then
 *                          the head will point to the erased head's next,
 *                          and then the erased node will be returned.
 *
 * @return  int             Returns the removed node
**/

int IntList::remove_front(){
    //Create a new node set to point to what head is
    IntNode* removed_node = head;
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
    return removed_node->get_data();
}

/**
 * @brief                   Writes the content of the list
 *
 * @detailed                This function iterates through the list, writing
 *                          the contents of the nodes to the outfile
 *              
 * @param   ostream& outfile    The stream being written to
**/

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

/**
 * @brief                   Overloaded Stream Insertion Operator
 *
 * @detailed                This function calls the write function from the list
 *                          class
 *              
 * @param   ostream& outfile    The stream being written to
 * 
 * @param   List& list       The list used to access the write method
 * 
 * @return  ostream&        This returns the stream outfile
**/

std::ostream& operator<<(std::ostream& outfile, const IntList& list){
    //Call list's write function giving the outfile stream
    list.write(outfile);
    //Return the outfile
    return outfile;
}