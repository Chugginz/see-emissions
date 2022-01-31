/**
 * @file ItemArray.h
 * TODO: Complete the documentation.
 */
#ifndef ITEMARRAY_H
#define ITEMARRAY_H

#include "MenuItem.h"

class ItemArray {
public:
class forward_iterator;
    //Default Constructor
    ItemArray() = default;
    //Copy Constructor
    ItemArray(const ItemArray& orig);
    //Destructor
    ~ItemArray();
    
    //Mutators
    push_back(const MenuItem& item);
    void clear();
    
    //Accessors
    MenuItem& at(int index);
    const MenuItem& at(int index) const;
    MenuItem& back();
    const MenuItem& back() const;
    MenuItem& front();
    const MenuItem& front() const;
    int capacity() const {return _capacity;}
    int size() const {return _size;}
    
    //Forward Iterator TODO
    forward_iterator begin() const;
    
    //Overloaded Operators
    //TODO
    MenuItem& operator[] (int index) const;
    const MenuItem& operator[] (int index) const;
    ItemArray& operator= (const ItemArray& rhs) const;
    
private:
    MenuItem** _array = nullptr;
    int _size = 0;
    int _capacity = 0;
};

//Class forward_iterator
ItemArray::forward_iterator{
public:
    forward_iterator(const ItemArray& ia, int index = 0);
    
    MenuItem& operator*();
    bool operator==(const forward_iterator rhs) const;
    bool operator!=(const forward_iterator rhs) const;
    forward_iterator& operator++() const;
private:
    const ItemArray& container;
    int current_index;
}

//Namespace std
namespace std {
    template <> struct iterator_traits<ItemArray::forward_iterator> {
        typedef ptrdiff_t            difference_type;
        typedef ItemArray            value_type;
        typedef ItemArray*           pointer;
        typedef ItemArray&           reference;
        typedef forward_iterator_tag iterator_category;
    };
}

#endif  // !ITEMARRAY_H