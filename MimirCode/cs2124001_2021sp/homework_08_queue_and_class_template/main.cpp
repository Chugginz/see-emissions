/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   Testing code written in templated header files
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

#include "List.h"
#include "Node.h"
#include "Queue.h"

int main(){
    //Adding a queue of strings
    Queue <std::string> string_queue;
    //Should return TRUE
    cout << "Testing is Queue is empty: " << string_queue.is_empty() << endl;
    //Adding value "Hello World"
    string_queue.enqueue("Hello World!");
    //Should return FALSE
    cout << "Testing if Queue is empty: " << string_queue.is_empty() << endl;
    //Adding many values
    string_queue.enqueue("How are you?");
    string_queue.enqueue("I am well.");
    string_queue.enqueue("And you?");
    string_queue.enqueue("Pretty good.");
    //Reading Queue (Should read all values)
    cout << string_queue << endl;
    //Dequeing the first item (Should return Hello World!)
    cout << string_queue.dequeue() << endl;
    
    return 0;
}