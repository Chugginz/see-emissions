/**
 *******************************************************************************
 * @file    IntQueue.h
 * @brief   Header file for class IntQueue
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

#ifndef INT_QUEUE_H
#define INT_QUEUE_H

#include "IntList.h"

class IntQueue{
public:
    //Accessors
    bool is_empty() const;
    void debug_write(std::ostream& outfile) const;
    //Mutators
    void enqueue(int operand);
    int  dequeue();
private:
    //Attributes
    IntList list;
};
//Overloaded Operators
std::ostream& operator<<(std::ostream& outfile, const IntQueue& queue);

#endif