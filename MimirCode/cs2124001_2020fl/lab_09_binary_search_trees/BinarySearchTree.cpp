// @ BinarySearchTree.cpp

#include "BinarySearchTree.h"
#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
    

void BinarySearchTree::add_iteratively(const CityStateZip& new_city){
    CSZNode* new_node = new CSZNode{new_city};
        //Could not get new_node to initialize
    CSZNode* current  = root;
    CSZNode* previous = nullptr;
    
    if (root == nullptr)
        root = new_node;
    else{
        while (current != nullptr) {
            previous = current;
            if (*new_node < *current)
                current = current->get_left();
            else  // *new_node > *current
                current = current->get_right();
        }
        if (*new_node < *previous)
            previous->set_left(new_node);
        else  // *new_node > *previous
            previous->set_right(new_node);
    }
}

void BinarySearchTree::write_recursively(std::ostream& strm) const{
    CSZNode* current = root;
    CSZNode* next = nullptr;
}