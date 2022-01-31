/**
 *******************************************************************************
 * @file    OrderedMovieList.cpp
 * @brief   
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      3/7/2021
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    March 7, 2021
 *******************************************************************************
**/

#include "OrderedMovieList.h"

/**
 * @brief                   Removes front node from the list
 *
 * @detailed                This function takes the head of the list, pushes
 *                          it back one (unless the next pointer is a nullptr)
 *                          and deletes what was at the head
 *              
 * @return  Movie           Returns an object of type movie with the information
 *                          of the object that was in the node
 *                          that was just removed.
**/

Movie OrderedMovieList::remove_front(){
    if (head == nullptr)
        throw std::length_error{ "Cannot remove from an empty list." };
    
    MovieNode* old_head = head;
    Movie result = old_head->get_movie();
    head = head->get_next();
    delete old_head;
    
    return result;
}

/**
 * @brief                   Removes the nodes from the list
 *
 * @detailed                This function takes the remove front function,
 *                          and calls it until the list is empty
 *                          (where the head points to nullptr)
**/

void OrderedMovieList::erase(){
    while (head != nullptr)
        remove_front();
}

/**
 * @brief                   Writes the nodes from the list
 *
 * @detailed                This function takes the head of the list, and points
 *                          the current pointer to it. Then, while the current
 *                          isn't at the end, it continues to call that nodes
 *                          write function.
 *              
 * @param   std::ostream& fout      takes the file stream of fout
 * 
 * @return  fout            Returns the fout stream that was passed through
 *                          the parameter
**/

std::ostream& OrderedMovieList::write(std::ostream& fout) const{
    MovieNode* current = head;
    while (current != nullptr){
        current->write(fout);
        current = current->get_next();
    }
    
    return fout;
}

/**
 * @brief                   Stream insertion operator
 *
 * @detailed                This function takes the list object and uses    
 *                          its write function to write the list out with
 *                          fout
 *              
 * @param   std::ostream& fout      takes the file stream of fout
 * 
 * @param   const OrderedMovieList& list    Passes an object of type list
 *                                  to be read
 * 
 * @return  fout            Returns the fout stream that was passed through
 *                          the parameter
**/

std::ostream& operator<<(std::ostream& fout, const OrderedMovieList& list){
    list.write(fout);
    
    return fout;
}

/**
 * @brief                   Destructs the object
 *
 * @detailed                This function calls the erase function in order
 *                          to delete all of the nodes from the list
**/

OrderedMovieList::~OrderedMovieList(){
    erase();
}

/**
 * @brief                   Checks if list is empty
 *
 * @detailed                This function starts by having a false result,
 *                          then checks if the head is pointing to nullptr.
 *                          If it is, it means the list is empty, thus
 *                          a true result is returned
**/

bool OrderedMovieList::is_empty() const{
    bool result = false;
    if (head == nullptr)
        result = true;
        
    return result;
}

/**
 * @brief                   Inserts node into list
 *
 * @detailed                This function inserts a node into a list, then 
 *                          sorts it into the list by checking it with every
 *                          node until it is alphabetized
 *              
 * @param   const Movie& new_movie  Takes a Movie& type object to add to list
**/

void OrderedMovieList::insert(const Movie& new_movie){
    //Create new node
    MovieNode* new_node = new MovieNode(new_movie);
    
    //If there is no head
    if (head == nullptr)
        //Set the head to point to the new node
        head = new_node;
    else{
        //Initialize previous to nullptr
        MovieNode* previous = nullptr;
        //Initialize current to the head
        MovieNode* current = head;
        //Initialize result to false
        bool result = false;
        //If the new node comes first in the alphabet
        if (new_node < current){
            //set the new node's next to point to the current
            new_node->set_next(current);
            //Then, set the head to now point to the new node
            head = new_node;
        }
        //Otherwise
        else{
            //While the result equals false and there's still a next value
            while (result == false && current->get_next() != nullptr){
                //Move the previous pointer up to the current
                previous = current;
                //Move the current pointer up to the next pointer
                current = current->get_next();
                //Now compare the new pointer and current pointer
                result = new_node < current;
            }
            //If the new pointer was less than the current pointer
            if (result == true){
                //Set the previous's next to point to the new node
                previous->set_next(new_node);
                //Then set the new node's next to point to the current node
                new_node->set_next(current);
            }
            //Else
            else
                //Set current's next to point to the new node
                current->set_next(new_node);
            
            //Delete previous and current pointers now
            //delete previous;
            //delete current;
        }
    }
}