/**
 *******************************************************************************
 * @file    IntNode.cpp
 * @brief   Implementation code for class IntNode
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

#include "IntNode.h"

/**
 * @brief                   Constructor
 *
 * @detailed                This function sets payload to be equal to new_value
**/

IntNode::IntNode(int new_value){
    payload = new_value;
}

/**
 * @brief                   Returns the payload
 *
 * @detailed                This function only consists of a return statement
 *                          providing the user the payload
 *              
 * @return  int             Returns the payload
**/

int IntNode::get_data() const{
    return payload;
}

/**
 * @brief                   Sets the next attribute
 *
 * @detailed                This function provides a new IntNode for the next
 *                          attribute
 *              
 * @param   IntNode* new_next   Sets next IntNode to be the new next
**/

void IntNode::set_next(IntNode* new_next){
    next = new_next;
}

/**
 * @brief                   Gives the next attribute
 *
 * @detailed                This function returns the IntNode that next points 
 *                          to
 *              
 * @return  IntNode*        Returns a IntNode of data type IntNode*
**/

IntNode* IntNode::get_next() const{
    return next;
}

/**
 * @brief                   Writes the content of the IntNode
 *
 * @detailed                This function writes the payload and the next 
 *                          IntNode to the outfile stream
 *              
 * @param   ostream& outfile    The stream being written to
**/

void IntNode::debug_write(std::ostream& outfile) const{
    if (next != nullptr)
        outfile << payload << "->(" << next->get_data() << ")\n";
    else
        outfile << " ( -------- )\n";
}

/**
 * @brief                   Overloaded Stream Insertion Operator
 *
 * @detailed                This function calls the write function from the
 *                          int IntNode class
 *              
 * @param   ostream& outfile    The stream being written to
 * 
 * @param   IntList& list       The int IntNode used to access the write method
 * 
 * @return  ostream&        This returns the stream outfile
**/

std::ostream& operator<<(std::ostream& outfile, const IntNode& IntNode){
    IntNode.debug_write(outfile);
    
    return outfile;
}