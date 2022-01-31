/**
 *******************************************************************************
 * @file    Queue.h
 * @brief   Templated code for the IntQueue class
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

#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

template <typename ValueType>
class Queue{
public:
    //Accessors
    bool                    is_empty() const;
    void                    debug_write(std::ostream& outfile) const;
    //Mutators
    void                    enqueue(ValueType operand);
    ValueType               dequeue();
private:
    //Attributes
    List<ValueType>         list;
};
//Overloaded Operators
template <typename ValueType>
std::ostream& operator<<(std::ostream& outfile, const Queue<ValueType>& queue);

/**
 * @brief                   Checks if the queue is empty
 *
 * @detailed                This function calls the list's is_empty function
 *              
 * @return  bool            Returns whether or not the queue is empty
**/
template <typename ValueType>
bool Queue<ValueType>::is_empty() const{
    return list.is_empty();
}

/**
 * @brief                   Adds to the end of a queue
 *
 * @detailed                This function calls the list add back function
 *              
 * @param   int operand     Used to be passed the add back function
**/
template <typename ValueType>
void Queue<ValueType>::enqueue(ValueType operand){
    list.add_back(operand);
}

/**
 * @brief                   Removes from the front of a queue
 *
 * @detailed                This function calls the list's remove front
 *                          function to dequeue the first element from the list
 *              
 * @return  int             Returns the data that was dequeued
**/
template <typename ValueType>
ValueType Queue<ValueType>::dequeue(){
    return list.remove_front();
}

/**
 * @brief                   Writes the items in the list
 *
 * @detailed                This function calls the list's write function
 *              
 * @param   ostream& outfile    Stream written to in the write function
**/
template <typename ValueType>
void Queue<ValueType>::debug_write(std::ostream& outfile) const{
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
template <typename ValueType>
std::ostream& operator<<(std::ostream& outfile, const Queue<ValueType>& queue){
    queue.debug_write(outfile);
    
    return outfile;
}
#endif