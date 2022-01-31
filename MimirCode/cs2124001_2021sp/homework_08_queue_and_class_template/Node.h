/**
 *******************************************************************************
 * @file    Node.h
 * @brief   Templated code for the IntNode class
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

#ifndef NODE_H
#define NODE_H

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
#include <string>
#include <vector>    
#include <iomanip>
#include <fstream>

template <typename ValueType>
class Node{
public:
    //Constructor
    Node<ValueType>      (ValueType new_data);
    //Accessors
    ValueType            get_data() const;
    Node<ValueType>*     get_next() const;
    void                 debug_write(std::ostream& outfile) const;
    //Mutator
    void                 set_next(Node* new_next);
private:
    //Attributes
    ValueType            payload;
    Node<ValueType>*     next = nullptr;
};
//Overloaded Operators
template <typename ValueType>
std::ostream& operator<<(std::ostream& outfile, const Node<ValueType>& node);

/**
 * @brief                   Constructor
 *
 * @detailed                This function sets payload to be equal to new_data
**/
template <typename ValueType>
Node<ValueType>::Node(ValueType new_data){
    payload = new_data;
}

/**
 * @brief                   Returns the payload
 *
 * @detailed                This function only consists of a return statement
 *                          providing the user the payload
 *              
 * @return  int             Returns the payload
**/
template <typename ValueType>
ValueType Node<ValueType>::get_data() const{
    return payload;
}

/**
 * @brief                   Sets the next attribute
 *
 * @detailed                This function provides a new node for the next
 *                          attribute
 *              
 * @param   Node* new_next   Sets next node to be the new next
**/
template <typename ValueType>
void Node<ValueType>::set_next(Node<ValueType>* new_next){
    next = new_next;
}

/**
 * @brief                   Gives the next attribute
 *
 * @detailed                This function returns the node that next points to
 *              
 * @return  Node*        Returns a node of data type Node*
**/
template <typename ValueType>
Node<ValueType>* Node<ValueType>::get_next() const{
    return next;
}

/**
 * @brief                   Writes the content of the node
 *
 * @detailed                This function writes the payload and the next node
 *                          to the outfile stream
 *              
 * @param   ostream& outfile    The stream being written to
**/
template <typename ValueType>
void Node<ValueType>::debug_write(std::ostream& outfile) const{
    if (next != nullptr)
        outfile << payload << "->(" << next->get_data() << ")\n";
    else
        outfile << " ( -------- )\n";
}

/**
 * @brief                   Overloaded Stream Insertion Operator
 *
 * @detailed                This function calls the write function from the
 *                          int node class
 *              
 * @param   ostream& outfile    The stream being written to
 * 
 * @param   IntList& list       The int node used to access the write method
 * 
 * @return  ostream&        This returns the stream outfile
**/
template <class ValueType>
std::ostream& operator<<(std::ostream& outfile, const Node<ValueType>& node){
    node.debug_write(outfile);
    
    return outfile;
}
#endif