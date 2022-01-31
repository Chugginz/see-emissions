/**
 *******************************************************************************
 * @file    IntNode.h
 * @brief   Header file for class IntNode
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

#ifndef INT_NODE_H
#define INT_NODE_H

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
#include <string>
#include <vector>    
#include <iomanip>
#include <fstream>

class IntNode{
public:
    //Constructor
    IntNode(int new_value);
    //Accessors
    int      get_data() const;
    IntNode* get_next() const;
    void     debug_write(std::ostream& outfile) const;
    //Mutator
    void     set_next(IntNode* new_next);
private:
    //Attributes
    int      payload;
    IntNode* next = nullptr;
};
//Overloaded Operators
std::ostream& operator<<(std::ostream& outfile, const IntNode& IntNode);

#endif