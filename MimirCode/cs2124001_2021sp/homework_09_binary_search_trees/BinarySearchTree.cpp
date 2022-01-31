/**
 *******************************************************************************
 * @file    BinarySearchTree.cpp
 * @brief   Used as an implementation for the BinarySearchTree class
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

#include "BinarySearchTree.h"

/**
 * @brief                   Adds to Binary Search Tree Iteratively
 *
 * @detailed                This function creates a new node. If there is no
 *                          root, then the new node will become the root. Else,
 *                          the function will compare the values of the new node
 *                          in order to store it in the correct order in the
 *                          binary search tree
 *              
 * @param   const CityStateZip& new_city    new_city is an object of type
 *                                          CityStateZip that is to be
 *                                          used to create a new node to be
 *                                          stored in the binary search tree
**/

void BinarySearchTree::add_iteratively(const CityStateZip& new_city){
    //Create new node using new_city
    CSZNode* new_node = new CSZNode{new_city};
    
    //If there is no root
    if (root == nullptr)
        //Set root to the new node
        root = new_node;
    else{
        //Create a flag
        bool result = false;
        //Create a current pointer to point to root
        CSZNode* current = root;
        //While the flag is false
        while (result == false){
            //If the value of the new node is less than the value of current's
            if (*new_node < *current){
                //And if current's left node does not exist
                if (current->get_left() == nullptr){
                    //Set current's left node to be the new node
                    current->set_left(new_node);
                    //Also change the flag to true to end the loop
                    result = true;
                }
                else
                    //Iterate the curent pointer to the left node
                    current = current->get_left();
            }
            else{
                //If current's right node does not exist
                if (current->get_right() == nullptr){
                    //Set current's right node to be the new node
                    current->set_right(new_node);
                    //Also change the flag to true to end the loop
                    result = true;
                }
                else
                    //Iterate the current pointer to the right node
                    current = current->get_right();
            }
        }
    }
}

/**
 * @brief                   Adds to Binary Search Tree Recursively (Public)
 *
 * @detailed                This method creates a new node using the data
 *                          from the parameter new_city, as well a creates
 *                          a current pointer that points to root. It then
 *                          passes these two to the private add_recursively
 *                          method for the new node to be added to the
 *                          binary search tree.
 *              
 * @param   const CityStateZip& new_city    new_city is an object of type
 *                                          CityStateZip that is to be
 *                                          used to create a new node to be
 *                                          stored in the binary search tree
**/

void BinarySearchTree::add_recursively(const CityStateZip& new_city){
    //Create new node using new_city
    CSZNode* new_node = new CSZNode{new_city};
    //Create a current pointer to point to root
    CSZNode* current = root;
    //Call private add recursively method
    add_recursively(new_node, current);
}

/**
 * @brief                   Adds to Binary Search Tree Recursively (Private)
 *
 * @detailed                This method is private so it can only be called
 *                          by the public method. Given the new node and the
 *                          current pointer, the method will iterate through
 *                          the binary search tree until the empty location for 
 *                          the new node is found.
 *              
 * @param   CSZNode* new_node       The new node being stored in the binary
 *                                  search tree.
 * 
 * @param   CSZNode* current_root   The current pointer used to iterate through
 *                                  the binary search tree.
**/

void BinarySearchTree::add_recursively
    (CSZNode* new_node, CSZNode* current_root){
    //If the value of the new node is less than the value of current's
    if (*new_node < *current_root){
        //And if current's left node does not exist
        if (current_root->get_left() == nullptr)
            current_root->set_left(new_node);
        //If it does exist
        else
            //Call private add recursively method with left node of current
            // as current
            add_recursively(new_node, current_root->get_left());
    }
    //Else the value of the new node is greater than or equal to the value
    // of current's
    else{
        //And if current's right node does not exist
        if (current_root->get_right() == nullptr)
            current_root->set_right(new_node);
        //If it does exist
        else
            //Call private add recursively method with right node of current
            // as current
            add_recursively(new_node, current_root->get_right());
    }
}

/**
 * @brief                   Writes to a stream iteratively
 *
 * @detailed                This function using a stack, traverses the left
 *                          of the binary search tree until it can't continue,
 *                          then it reads it's stack, goes right if possible,
 *                          does the same if necessary, then traverses back
 *                          up slowly repeating the previous steps.
 *              
 * @param   ostream& strm   This is the stream being written to
**/

void BinarySearchTree::write_iteratively(std::ostream& strm) const{
    //Create stack containing objects of type CSZNode*
    std::stack<CSZNode*> nodeStack;
    //Creating current pointer to traverse through the BST
    CSZNode* current = root;
    //Creating previous pointer to track when to stream object
    CSZNode* previous = current->get_left();
    //Creating a flag for if traversing left has been done
    bool done_left = false;
    //Creating finished loop sentinel
    bool finished = false;
    //Pushing root onto the stack
    nodeStack.push(current);
    //While the tree hasn't been completely traversed
    while (finished != true){
        //While there is a left node and the user has not traversed left
        while (current->get_left() != nullptr && done_left == false){
            //Set the current to the left node
            current = current->get_left();
            //Push the current on to the top of the stack
            nodeStack.push(current);
        }
        //The left has now been traversed
        done_left = true;
        //If the right does not equal the previous
        if (current->get_right() != previous)
            //Read the current to the stream
            strm << current->get_data() << std::endl;
        //If there is a right
        if (current->get_right() != nullptr 
            && current->get_right() != previous){
            //Set the previous to the current
            previous = current;
            //Move the current to the right
            current = current->get_right();
            //Push current on top of stack
            nodeStack.push(current);
            //Reset the traverse flag since we've moved right
            done_left = false;
        }
        else{
            //std::cout << "popping" << std::endl;
            //Pop off the top of stack (should be same as current)
            nodeStack.pop();
            //If the stack is empty
            if (nodeStack.empty())
                //Set the finished sentinel to true
                finished = true;
            else{
                //Set the previous to current
                previous = current;
                //Set the current to the now top of stack
                current = nodeStack.top();
            }
        }
    }
}

/**
 * @brief                   Writes to a stream recursively (public)
 *
 * @detailed                This function passes a stream and the root
 *                          to a private recursive function to write the list
 *              
 * @param   ostream& strm   This is the stream being written to
**/

void BinarySearchTree::write_recursively(std::ostream& strm) const{
    //Calls the private write_recursively method
    write_recursively(strm, root);
}

/**
 * @brief                   Writes to a stream recursively (public)
 *
 * @detailed                This function passes a stream and the current root
 *                          to itself using the left root, then reads the
 *                          current root, and then passes a stream and the
 *                          current root to itself using the right root as long
 *                          as the current root is not nullptr
 *              
 * @param   ostream& strm   This is the stream being written to
 * 
 * @param   CSZNode* current_root   The root used as a starting point 
 *                                  to traverse
**/

void BinarySearchTree::write_recursively
    (std::ostream& strm, CSZNode* current_root) const{
    //If the current root it not nullptr
    if (current_root != nullptr){
        //Call private recursive function with left node
        write_recursively(strm, current_root->get_left());
        //Strm insert the current root as well as move to next line
        strm << *current_root << std::endl;
        //Call private recursive function with right node
        write_recursively(strm, current_root->get_right());
    }        
}

/**
 * @brief                   Erases a binary search tree recursively (public)
 *
 * @detailed                This function passes the root to the private
 *                          erase recursively function to erase the binary
 *                          search tree
**/

void BinarySearchTree::erase_recursively(){
    //Calls the private erase_recursively method
    erase_recursively(root);
}

/**
 * @brief                   Erases a binary search tree recursively (private)
 *
 * @detailed                This function passes the current root
 *                          to itself using the left root, then passes a 
 *                          and the current root to itself using the right root,
 *                          then sets the current root to nullptr, as long 
 *                          as the current root is not nullptr.
 *              
 * @param   CSZNode* current_root   The root used as a starting point 
 *                                  to traverse
**/

void BinarySearchTree::erase_recursively(CSZNode* current_root){
    //If the current root it not nullptr
    if (current_root != nullptr){
        //Call private recursive function with left node
        erase_recursively(current_root->get_left());
        //Call private recursive function with right node
        erase_recursively(current_root->get_right());
        //Delete the current node
        //delete current_root;
        current_root = nullptr;
    }
}

/**
 * @brief                   Destructor
 *
 * @detailed                Calls the erase function to clear the tree
**/

BinarySearchTree::~BinarySearchTree(){
    erase_recursively();
}