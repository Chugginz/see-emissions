/**
 *******************************************************************************
 * @file    IntQueue.cpp
 * @brief   Implementation file for class IntQueue
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

#include "IntQueue.h"

/**
 * @brief                   Checks if the queue is empty
 *
 * @detailed                This function calls the IntList's is_empty function
 *              
 * @return  bool            Returns whether or not the queue is empty
**/

bool IntQueue::is_empty() const{
    return list.is_empty();
}

/**
 * @brief                   Adds to the end of a queue
 *
 * @detailed                This function calls the list add back function
 *              
 * @param   int operand     Used to be passed the add back function
**/

void IntQueue::enqueue(int operand){
    list.add_back(operand);
}

/**
 * @brief                   Removes from the front of a queue
 *
 * @detailed                This function calls the IntList's remove front
 *                          function to dequeue the first element from the 
 *                          IntList
 *              
 * @return  int             Returns the value that was dequeued
**/

int IntQueue::dequeue(){
    return list.remove_front();
}

/**
 * @brief                   Writes the items in the IntList
 *
 * @detailed                This function calls the IntList's write function
 *              
 * @param   ostream& outfile    Stream written to in the write function
**/

void IntQueue::debug_write(std::ostream& outfile) const{
    list.write(outfile);
}

/**
 * @brief                   Overloaded Stream Insertion Operator
 *
 * @detailed                This function calls the write function from the
 *                          queue class
 *              
 * @param   ostream& outfile    The stream being written to
 * 
 * @param   Queue& queue     The queue used to access the write method
 * 
 * @return  ostream&        This returns the stream outfile
**/

std::ostream& operator<<(std::ostream& outfile, const IntQueue& queue){
    queue.debug_write(outfile);
    
    return outfile;
}