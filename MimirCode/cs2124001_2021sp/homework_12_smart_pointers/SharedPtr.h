/**
 *******************************************************************************
 * @file    SharedPtr.h
 * @brief   Templated header file containing classes and their needed
 *          implementations. These classes allow for shared pointers to exist
 *          in both standard, and array form.
 *
 * @author  Christian Huggins
 * @date    April 19th, 2021
 *******************************************************************************
**/

#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include<string>
    using std::string;
#include<iostream>

template <typename dataType>
class SharedPtr{
    public:
        /**
         * @brief       This is a templated constructor for the class SharedPtr
         *
         * @detailed    Given any arguments, dynamically allocate space for
         *              the ptr containing the new arguments, and set the
         *              reference count to 1.
         *              
         * @param       int size    The size used for determining array size
        **/
        
        template <typename... Args>
        SharedPtr(const Args&... args) : 
            _ptr{new dataType{args...}}, ref_count{new int{1}}{}
        //Copy Constructor
        SharedPtr (const SharedPtr& orig);
        //Operator Prototypes
        //SharedPtr& operator=(const SharedPtr& orig);
        dataType& operator*() const;
        dataType* operator->() const;
        //Accessors
        /**
         * @brief       This is a templated accessor for the ptr
         *
         * @detailed    Returns the pointer that is protected, used to
         *              return an attribute that can't be accessed otherwise
         * 
         * @return      Returns the pointer
        **/
        
        dataType* get_ptr() const {return _ptr;}
        
        /**
         * @brief       This is a templated accessor for the ptr
         *
         * @detailed    Returns the pointer that is protected, used to
         *              return an attribute that can't be accessed otherwise
         * 
         * @return      Returns the reference count
        **/
        
        int* get_ref_count() const {return ref_count;}
        //Destructor
        ~SharedPtr();
    protected:
        //Protected Attributes
        dataType* _ptr;
        int* ref_count;
};

/**
 * @brief       This is a templated copy constructor for the class SharedPtr
 *
 * @detailed    Taking an object of type SharedPtr, copy its information over
 *              to the new object and increment the reference count by one.
 *              
 * @param       const SharedPtr& orig   Original object being copied from
**/

template <typename dataType>
SharedPtr<dataType>::SharedPtr(const SharedPtr& orig){
    this->_ptr = orig._ptr;
    this->ref_count = orig.ref_count;
    *this->ref_count += 1;
}

/**
 * @brief       This is a templated assignment operator for the class SharedPtr
 *
 * @detailed    Taking an object of type SharedPtr, copy its information over
 *              to the new object and increment the reference count by one.
 *              
 * @param       const SharedPtr& orig   Original object being copied from
 * 
 * @return      Returns the referenced class
**/

/*template <typename dataType>
SharedPtr& SharedPtr<dataType>::operator=(const SharedPtr& orig){
    this->_ptr = orig._ptr;
    this->ref_count = orig.ref_count;
    this->ref_count++;

    return orig;
}*/

/**
 * @brief       This is a templated indirection operator for the class SharedPtr
 *
 * @detailed    Taking the object on the left, return the dereferenced ptr
 *              to be accessed
 *              
 * @return      Returns the dereferenced ptr within the class
**/

template <typename dataType>
dataType& SharedPtr<dataType>::operator*() const{
    return *_ptr;
}

/**
 * @brief       This is a templated arrow operator for the class SharedPtr
 *
 * @detailed    Taking the object on the left, return the ptr to be accessed
 *              
 * @return      Returns the ptr within the class
**/

template <typename dataType>
dataType* SharedPtr<dataType>::operator->() const{
    return _ptr;
}

/**
 * @brief       This is a templated destructor for the regular class
 *
 * @detailed    This destructor deletes the pointer, and either decerements or
 *              deletes the reference counter depending on if the value is
 *              1 or not. If it is one, it is deleted since it will no longer be
 *              shared with anyone.
**/

template <typename dataType>
SharedPtr<dataType>::~SharedPtr(){
    delete _ptr;
    _ptr = nullptr;
    if (*ref_count != 1)
        --*ref_count;
    else{
        delete ref_count;
        ref_count = nullptr;
    }
}

template <typename dataType>
class SharedPtr<dataType[]>{
    public:
        /**
         * @brief       This is a templated constructor for the class SharedPtr
         *              for arrays
         *
         * @detailed    Given a size, create an array that size of the templated
         *              data type, and then also initializes 1 for the reference
         *              count
         *              
         * @param       int size    The size used for determining array size
        **/
        
        SharedPtr(int size) : _ptr{new dataType[size]}, ref_count{new int{1}}{}
        //Copy Constructor
        SharedPtr (const SharedPtr&);
        //Operator Prototypes
        //SharedPtr& operator=(const SharedPtr&);
        dataType& operator* () const;
        dataType& operator[] (int i) const;
        //Accessors
        /**
         * @brief       This is a templated accessor for the ptr
         *
         * @detailed    Returns the pointer that is protected, used to
         *              return an attribute that can't be accessed otherwise
         * 
         * @return      Returns the pointer
        **/
        
        dataType* get_ptr() const {return _ptr;}
        
        /**
         * @brief       This is a templated accessor for the ptr
         *
         * @detailed    Returns the pointer that is protected, used to
         *              return an attribute that can't be accessed otherwise
         * 
         * @return      Returns the reference count
        **/
        
        int* get_ref_count() const {return ref_count;}
        //Destructor
        ~SharedPtr();
    protected:
        //Protected Attributes
        dataType* _ptr;
        int* ref_count;
};

/**
 * @brief       This is a templated copy constructor for the class SharedPtr
 *              for arrays
 *
 * @detailed    Taking an object of type SharedPtr array, copy its information 
 *              over to the new object and increment the reference count by one.
 *              
 * @param       const SharedPtr& orig   Original object being copied from
**/

template <typename dataType>
SharedPtr<dataType[]>::SharedPtr(const SharedPtr& orig){
    this->_ptr = orig._ptr;
    this->ref_count = orig.ref_count;
    *this->ref_count += 1;
}

/**
 * @brief       This is a templated assignment operator for the class SharedPtr
 *              for arrays
 *
 * @detailed    Taking an object of type SharedPtr array, copy its information 
 *              over to the new object and increment the reference count by one.
 *              
 * @param       const SharedPtr& orig   Original object being copied from
 * 
 * @return      Returns the referenced class
**/

/*template <typename dataType>
SharedPtr& SharedPtr<dataType[]>::operator=(const SharedPtr& orig){
    this->_ptr = orig._ptr;
    this->ref_count = orig.ref_count;
    this->ref_count++;

    return orig;
}*/

/**
 * @brief       This is a templated indirection operator for the class SharedPtr
 *              for arrays
 *
 * @detailed    Taking the object on the left, return the dereferenced ptr
 *              to be accessed
 *              
 * @return      Returns the dereferenced ptr within the class
**/

template <typename dataType>
dataType& SharedPtr<dataType[]>::operator*() const{
    return *_ptr;
}

/**
 * @brief       This is a templated arrow operator for the class SharedPtr
 *              for arrays
 *
 * @detailed    Taking the object on the left, return the ptr to be accessed
 *              
 * @return      Returns the ptr within the class
**/

template <typename dataType>
dataType& SharedPtr<dataType[]>::operator[](int i) const{
    return _ptr[i];
}

/**
 * @brief       This is a templated destructor for the array class
 *
 * @detailed    This destructor deletes the pointer, and either decerements or
 *              deletes the reference counter depending on if the value is
 *              1 or not. If it is one, it is deleted since it will no longer be
 *              shared with anyone.
**/

template <typename dataType>
SharedPtr<dataType[]>::~SharedPtr(){
    delete [] _ptr;
    _ptr = nullptr;
    if (*ref_count != 1)
        --*ref_count;
    else{
        delete ref_count;
        ref_count = nullptr;
    }
}

#endif