// @ ItemList.cpp

#include "ItemList.h"

void ItemList::add_front( const Item& new_item ){
    ItemNode* new_node = new ItemNode(new_item);
    
    if (head == nullptr)
        tail = new_node;
    else
        new_node->set_next(head);
    
    head = new_node;
}

std::ostream& ItemList::write( std::ostream& fout ) const{
    ItemNode* current = head;
    while (current != nullptr){
        current->write(fout);
        current = current->get_next();
    }
    
    return fout;
}

std::ostream& operator<<( std::ostream& fout, const ItemList& list ){
    list.write(fout);
    
    return fout;
}

void ItemList::add_back( const Item& new_item ){
    ItemNode* new_node = new ItemNode(new_item);
    
    if (tail == nullptr)
        head = new_node;
    else
        tail->set_next(new_node);
        
    tail = new_node;
}

Item ItemList::remove_front(){
    if (head == nullptr)
        throw std::length_error{ "Cannot remove from an empty list." };
    
    ItemNode* old_head = head;
    Item result = old_head->get_item();
    head = head->get_next();
    
    if (head == nullptr)
        tail = nullptr;
    delete old_head;
    
    return result;
}

void ItemList::erase ( ){
    while (head != nullptr)
        remove_front();
}

ItemList::~ItemList( ){
    erase();
}