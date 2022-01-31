// @ UniquePtr.h

#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H

#include<string>
    using std::string;
#include "Foo.h"

template <typename dataType>
class UniquePtr{
    public:
        /*UniquePtr(dataType* ptr) : _ptr{ptr}{};
        //Alternate Constructor
        UniquePtr(const std::string& str = "") : _ptr{new dataType{str}}{};*/
        //General Constructor
        template <typename... Args>
        UniquePtr(const Args&... args) : _ptr{new dataType{args...}}{}
        //Disallows
        UniquePtr (const UniquePtr&)           = delete; // disallow copy construction
        UniquePtr& operator=(const UniquePtr&) = delete; // disallow assignment
        //Operator Prototypes
        dataType& operator* () const;
        dataType* operator->() const;
        //Destructor
        ~UniquePtr(){delete _ptr;};
    protected:
        dataType* _ptr;
};

template <typename dataType>
class UniquePtr<dataType[]>{
    public:
        //Array Constructor
        UniquePtr(int size) : _ptr{new dataType[size]}{}
        //Disallows
        UniquePtr (const UniquePtr&)           = delete; // disallow copy construction
        UniquePtr& operator=(const UniquePtr&) = delete; // disallow assignment
        //Operator Prototypes
        dataType& operator* () const;
        dataType& operator[] (int i) const;
        //Destructor
        ~UniquePtr(){delete [] _ptr;};
    protected:
        dataType* _ptr;
};

template <typename dataType>
dataType& UniquePtr<dataType>::operator*() const{
    return *_ptr;
}

template <typename dataType>
dataType* UniquePtr<dataType>::operator->() const{
    return _ptr;
}

template <typename dataType>
dataType& UniquePtr<dataType[]>::operator*() const{
    return *_ptr;
}

template <typename dataType>
dataType& UniquePtr<dataType[]>::operator[](int i) const{
    return _ptr[i];
}

#endif