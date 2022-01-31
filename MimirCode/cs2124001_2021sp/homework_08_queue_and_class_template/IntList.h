/**
 *******************************************************************************
 * @file    IntList.h
 * @brief   Header file for class IntList
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

#ifndef INT_LIST_H
#define INT_LIST_H

#include "IntNode.h"

class IntList{
public:
    //Default Constructor
    IntList()               = default;
    //Destructor
    ~IntList();
    //Accessors
    bool                    is_empty() const;
    void                    write(std::ostream& outfile) const;
    //Mutators
    void                    add_front(int newData);
    void                    add_back(int newData);
    int                     remove_front();
    // disallow copies by marking the following as "delete":
    IntList(const IntList&) = delete;
    IntList& operator=(const IntList&) = delete;

private:
    //Attribute
    IntNode* head = nullptr;
    IntNode* tail = nullptr;
};
//Overloaded Operators
std::ostream& operator<<(std::ostream& outfile, const IntList& list);

#endif