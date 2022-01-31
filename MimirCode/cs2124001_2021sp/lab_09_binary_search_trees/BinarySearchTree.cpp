// @BinarySearchTree.cpp

#include "BinarySearchTree.h"

void BinarySearchTree::add_iteratively( const CityStateZip& new_city ){
    CSZNode* new_node = new CSZNode{new_city};
    
    if (root == nullptr)
        root = new_node;
    else{
        bool result = false;
        CSZNode* current = root;
        while (result == false){
            if (*new_node < *current){
                if (current->get_left() == nullptr){
                    current->set_left(new_node);
                    result = true;
                }
                else
                    current = current->get_left();
            }
            else{
                if (current->get_right() == nullptr){
                    current->set_right(new_node);
                    result = true;
                }
                else
                    current = current->get_right();
            }
        }
    }
}

void BinarySearchTree::write_recursively( std::ostream& strm ) const{
    write_recursively(strm, root);
}

void BinarySearchTree::write_recursively
    ( std::ostream& strm, CSZNode* current_root ) const{
    if (current_root != nullptr){
        write_recursively(strm, current_root->get_left());
        strm << *current_root << std::endl;
        write_recursively(strm, current_root->get_right());
    }        
}