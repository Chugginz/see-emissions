/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      04/12/2021
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    April 12th, 2021
 *******************************************************************************
**/

#include "UniquePtr.h"

int main(){
    // Let user know first object is being made
    std::cout << "Creating first object...\n";
    UniquePtr<Foo> p1{"First"};
    {
        //Let user know unique ptr is being created then when the scope
        // is closing
        std::cout << "Creating second object with short lifetime...\n";
        UniquePtr<Foo> p2{"Second"};
        std::cout << "\nSecond object is about to go out of scope...\n";
    }
    // Scope closed so destructor should fire
    std::cout << "Second object should be gone.\n";
    // managed array of 5 `Foo`s.
    UniquePtr<Foo[]> array_of_Foos{5};
    // managed array of 10 `double`s.
    UniquePtr<double[]> array_of_doubles{10};
    // Storing value in first slot of array of doubles testing [] overload
    array_of_doubles[0] = 6;
    std::cout << "\nTesting [] overload, reading first element (should be 6): " 
        << array_of_doubles[0];
    // Testing the arrow overloaded operator
    std::cout << "\nTesting arrow operator: Serial (should be 1): " 
        << p1->serial();
    // Manage unique pointer to string
    UniquePtr<std::string> p3{"\nTest String and Indirection Operator\n\n"};
    // Test indirection overloaded operator by reading out what's in "p3"
    std::cout << *p3;
    std::cout << "Destructors should fire:\n";
    
    return 0;
}