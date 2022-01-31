/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      11/16/2020
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    November 16th, 2020
 *******************************************************************************
**/

#include "UniquePtr.h"

int main(){
    /*
    std::cout << "Creating first object...\n";
    UniquePtr<Foo> p1{"First"};
    {
        std::cout << "Creating second object with short lifetime...\n";
        UniquePtr<Foo> p2{"Second"};
        std::cout << "Second object is about to go out of scope...\n";
        //UniquePtr<std::string> p3{"Test String\n"};
        //std::cout << *p3;
        
    }
    std::cout << "Second object should be gone.\n";
    */
    
    // managed array of 5 `Foo`s.
    UniquePtr<Foo[]> array_of_Foos{5};
    // managed array of 10 `double`s.
    UniquePtr<double[]> array_of_doubles{10};
    return 0;
}