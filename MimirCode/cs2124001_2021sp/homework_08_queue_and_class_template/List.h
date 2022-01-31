/**
 *******************************************************************************
 * @file    List.h
 * @brief   Templated code for the IntList class
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

#ifndef LIST_H 
#define LIST_H

#include "Node.h"

template <typename ValueType>
class List{
public:
    //Default Constructor
    List()              = default;
    //Destructor
    ~List();
    //Accessors
    bool                is_empty() const;
    void                write(std::ostream& outfile) const;
    //Mutators
    void                add_front(ValueType newData);
    void                add_back(ValueType newData);
    ValueType           remove_front();
    // disallow copies by marking the following as "delete":
    List<ValueType>      (const List<ValueType>&) = delete;
    List<ValueType>&     operator=(const List<ValueType>&) = delete;

private:
    //Attribute
    Node<ValueType>*     head = nullptr;
    Node<ValueType>*     tail = nullptr;
};
//Overloaded Operators
template <typename ValueType>
std::ostream& operator<<(std::ostream& outfile, const List<ValueType>& list);

/**
 * @brief                   Destructor
 *
 * @detailed                This function executes a while loop, by calling the
 *                          remove front function until the list is empty.
**/
template <typename ValueType>
List<ValueType>::~List(){
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
template <typename ValueType>
bool List<ValueType>::is_empty() const{
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
template <typename ValueType>
void List<ValueType>::add_front(ValueType newData){
    //Create new node with new data
    Node<ValueType>* new_node = new Node<ValueType>{newData};
    //If the head does not point to anything
    if (head == nullptr){
        //Set the head to point to the new node
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
template <typename ValueType>
void List<ValueType>::add_back(ValueType newData){
    //Create new node with new data
    Node<ValueType>* new_node = new Node<ValueType>{newData};
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
 * @return  ValueType             Returns the removed node
**/
template <typename ValueType>
ValueType List<ValueType>::remove_front(){
    //Create a new node set to point to what head is
    Node<ValueType>* removed_node = head;
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
template <typename ValueType>
void List<ValueType>::write(std::ostream& outfile) const{
    //Creates a current pointer to iterate through list
    Node<ValueType>* current = head;
    //While the current is not nullptr
    while (current != nullptr){
        //Write dereferenced current node to outfile stream
        outfile << *current;
        //Set the current to the next data of current
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
template <typename ValueType>
std::ostream& operator<<(std::ostream& outfile, const List<ValueType>& list){
    //Call list's write function giving the outfile stream
    list.write(outfile);
    //Return the outfile
    return outfile;
}
#endif