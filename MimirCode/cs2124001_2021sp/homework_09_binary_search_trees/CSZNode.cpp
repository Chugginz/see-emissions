/**
 *******************************************************************************
 * @file    CSZNode.cpp
 * @brief   Used as an implementation file for the CSZNode class
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      3/15/2021
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    March 15th, 2021
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
    
#include "CSZNode.h"

/**
 * @brief                   Sets left
 *
 * @detailed                Sets the new left parameter to be the new value
 *                          of the left attribute in the private sector
 *                          of the class
 *              
 * @param   CSZNode* new_left   The new left being assigned to the 
 *                              left attribute
**/

void CSZNode::set_left(CSZNode* new_left){
    left = new_left;
}

/**
 * @brief                   Sets right
 *
 * @detailed                Sets the new right parameter to be the new value
 *                          of the right attribute in the private sector
 *                          of the class
 *              
 * @param   CSZNode* new_left   The new right being assigned to the 
 *                              right attribute
**/

void CSZNode::set_right(CSZNode* new_right){
    right = new_right;
}

/**
 * @brief                   Gets payload
 *
 * @detailed                Returns whatever value is assigned to payload
 *              
 * @return  CityStateZip    Returns the object payload of data type
 *                          CityStateZip
**/

CityStateZip CSZNode::get_data() const{
    return payload;
}

/**
 * @brief                   Gets left
 *
 * @detailed                Returns whatever value is assigned to left
 *              
 * @return  CSZNode*        Returns the object left of data type
 *                          CSZNode*
**/

CSZNode* CSZNode::get_left() const{
    return left;
}

/**
 * @brief                   Gets right
 *
 * @detailed                Returns whatever value is assigned to right
 *              
 * @return  CSZNode*        Returns the object right of data type
 *                          CSZNode*
**/

CSZNode* CSZNode::get_right() const{
    return right;
}

/**
 * @brief                   Writes to stream
 *
 * @detailed                Calls payload's write method and passes it the
 *                          stream parameter fout
 *              
 * @param       ostream& fout   The stream being passed to the write function
**/

void CSZNode::write(std::ostream& fout) const{
    payload.write(fout);
}

/**
 * @brief                   Overloaded Stream Insertion Operator
 *
 * @detailed                Passes the fout stream to the write method and
 *                          then returns it afterwards
 *                          
 * @param       ostream& fout   The stream being passed to the write method
 *                              and then returned
 * 
 * @param       CSZNode& n      The object being used to access the
 *                              write method
 * 
 * @return      ostream&    Returns the fout stream
**/

std::ostream& operator<<(std::ostream& fout, const CSZNode& n){
    n.write(fout);
    
    return fout;
}

/**
 * @brief                   Overloaded Less Than Operator
 *
 * @detailed                Compares the string names of two objects of type
 *                          CSZNode& and then returns weather or not the first
 *                          is less than the second as a boolean value true or
 *                          false
 * 
 * @param       CSZNode& op2    The object being used to access the city
 *                              values
 * 
 * @return      bool            A true or false value dependent on if the first
 *              object is less than the second
**/

bool CSZNode::operator < (const CSZNode& op2) const{
    bool result = false;
    
    if (get_data().city() < op2.get_data().city())
        result = true;
        
    return result;
}