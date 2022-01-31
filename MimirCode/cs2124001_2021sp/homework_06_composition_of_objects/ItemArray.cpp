// @ ItemArray.cpp

#include "ItemArray.h"

ItemArray::ItemArray(const ItemArray& orig){
    _array = orig._array;
    _size = orig._size;
    _capacity = orig._capacity;
}

ItemArray::~ItemArray(){
    clear();
}

ItemArray::push_back(const MenuItem& item){
    //If the array size equals the array capacity
    if (_size == _capacity){
        //Create a copy (original) of the array
        MenuItem** original = _array;
        //Set array equal to the physical size of the array plus 5
        _array = new MenuItem*[_capacity + 5];
        //Now set array element as the loop increments same as original 
        // element
        for (int i = 0; i < _size; i++)
            _array[i] = original[i];
        //Set original element to nullptr so it's not accidentally brought
        // in later
        for (int i = 0; i < _size; i++)
            original[i] = nullptr;
        //Delete copied array
        delete [] original;
        //Set the original array to nullptr to precent accidental later usage
        original = nullptr;
    }
    //Set the value at index of size equal to a new item
    _array[_size] = new MenuItem(item);
    //Increment size
    _size++;
}

MenuItem& ItemArray::at(int index){
    //If the index is more than the size or less than 0
    if (index > _size || index < 0)
        //Give an out of bounds error
        std::length_error("Index out of bounds");
    //Initialize a Menu Item referfence to be returned
    MenuItem& item = *_array[index];
    
    //Return the reference to the MenuItem
    return item;
}

const MenuItem& ItemArray::at(int index) const{
    //If the index is more than the size or less than 0
    if (index > _size || index < 0)
        //Give an out of bounds error
        std::length_error("Index out of bounds");
    //Initialize a const Menu Item referfence to be returned
    const MenuItem& item = *_array[index];
    
    //Return the const reference to the MenuItem
    return item;
}

MenuItem& ItemArray::back(){
    //If the size is 0
    if (_size == 0)
        //Give an out of bounds error
        std::length_error("Cannot get back of an empty container");
    //Initialize a Menu Item referfence to be returned
    MenuItem& item = *_array[_size - 1];
    
    //Return the reference to the MenuItem
    return item;
}

const MenuItem& ItemArray::back() const{
    //If the size is 0
    if (_size == 0)
        //Give an out of bounds error
        std::length_error("Cannot get back of an empty container");
    //Initialize a Menu Item referfence to be returned
    const MenuItem& item = *_array[_size - 1];
    
    //Return the reference to the MenuItem
    return item;
}

MenuItem& ItemArray::front(){
    //If the size is 0
    if (_size == 0)
        //Give an out of bounds error
        std::length_error("Cannot get front of an empty container");
    //Initialize a Menu Item referfence to be returned
    MenuItem& item = *_array[0];
    
    //Return the reference to the MenuItem
    return item;
}

const MenuItem& ItemArray::front() const{
    //If the size is 0
    if (_size == 0)
        //Give an out of bounds error
        std::length_error("Cannot get front of an empty container");
    //Initialize a Menu Item referfence to be returned
    const MenuItem& item = *_array[0];
    
    //Return the reference to the MenuItem
    return item;
}

void ItemArray::clear(){
    //While the counter is less than size and counting up
    for (int i = 0; i < _size; i++)
        //Set array element at index of counter equal to nullptr
        _array[i] = nullptr;
    
    //Delete the array memory
    delete [] array;
    
    //Set array to nullptr
    _array = nullptr;
}

forward_iterator begin() const{
    
    
    return forward_iterator()
}

forward_iterator::forward_iterator(const ItemArray& ia, int index){
    //Set container equal to given ItemArray type object
    container = ia;
    //Set current index to given index
    current_index = index;
}

MenuItem& forward_iterator::operator*(){
    //Return the object of type MenuItem via indirection operator
    return **container._array[current_index];
}

forward_iterator& forward_iterator::operator++(){
    //Increment the current index
    current_index++;
    //Create a new forward_iterator with the current index
    forward_iterator& new_iterator 
        = forward_iterator(container, current_index)
    
    //Return the new iterator with the curent index
    return new_iterator;
}

bool forward_iterator::operator== (const forward_iterator& rhs) const{
    //Initialize result as false
    bool result = false;
    
    //If the indexes are the same
    if (current_index == rhs.current_index){
        //And if the containers are the same
        if (container == rhs.container)
            //Set the result of them being equal to true
            result = true;
    }
    
    //Return the true or false result
    return result;
}

bool forward_iterator::operator!= (const forward_iterator& rhs) const{
    //Initialize result as false
    bool result = true;
    
    //If the indexes are the same
    if (current_index == rhs.current_index){
        //And if the containers are the same
        if (container == rhs.container)
            //Set the result of them being equal to true
            result = false;
    }
    
    //Return the true or false result
    return result;
}