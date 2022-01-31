/**
 *******************************************************************************
 * @file    CSZNode.h
 * @brief   Used as a header file for the CSZNode class
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

#ifndef CSZNODE_H
#define CSZNODE_H

#include<iostream>
#include "CityStateZip.h"

class CSZNode {
public:
    //Constructor
    CSZNode( const CityStateZip& data ) : payload{data} {};
    
    //Mutators
    void         set_left( CSZNode* new_left );
    void         set_right( CSZNode* new_right );
    
    //Accessors
    CityStateZip get_data( ) const;
    CSZNode*     get_left( ) const;
    CSZNode*     get_right( ) const;
    void write( std::ostream& fout ) const;
    
    //Overloaded Operator
    bool operator<(const CSZNode& op2) const;
private:
    //Attributes
    CityStateZip payload;
    CSZNode*     left  = nullptr;
    CSZNode*     right = nullptr;
};

//Overloaded Operator
std::ostream& operator<<( std::ostream& fout, const CSZNode& n);

#endif