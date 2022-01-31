/**
 *******************************************************************************
 * @file    BinarySearchTree.cpp
 * @brief   Used as a header file for the BinarySearchTree class
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

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include<iostream>
#include<stack>
#include "CSZNode.h"
#include "CityStateZip.h"

class BinarySearchTree {
public:
    //Contructor
    BinarySearchTree( ) = default;
    
    //Accessor
    void write_recursively(std::ostream& strm) const;
    void write_iteratively(std::ostream& strm) const;
    
    //Mutators
    void erase_recursively();
    void add_recursively(const CityStateZip& new_city);
    void add_iteratively(const CityStateZip& new_city);
    
    //Destructor
    ~BinarySearchTree();
private:                 
    //Methods
    void add_recursively     // called by public version
        (CSZNode* new_node, CSZNode* current_root);
    void write_recursively   // called by public version
        (std::ostream& strm, CSZNode* current_root) const;
    void erase_recursively(CSZNode* current_root);
    
    //Attributes
    CSZNode* root = nullptr; // initially empty tree (null root)
    
    //Disallow copy-ctor and assignment:
    BinarySearchTree( const BinarySearchTree& ) = delete;
    BinarySearchTree& operator=( const BinarySearchTree& rhs ) = delete;
};

#endif