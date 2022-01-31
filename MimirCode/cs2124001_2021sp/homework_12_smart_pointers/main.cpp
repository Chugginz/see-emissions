/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   The main file used in order to test the different classes and their
 *          functions to ensure all code is working properly
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      04/19/2021
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    April 19th, 2021
 *******************************************************************************
**/

#include "SharedPtr.h"
#include "UniquePtr.h"
#include "Foo.h"

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
    
    //Create object "sp" and new scope
    SharedPtr<Foo> sp("test object");
    {   
        //Reference count should be 1
        std::cout << *sp.get_ref_count() << std::endl;
        //Create object "sp_copy1", copy of "sp" and new scope
        SharedPtr<Foo> sp_copy1{ sp };
        {
            //Reference count should be 2
            std::cout << *sp_copy1.get_ref_count() << std::endl;
            //Create object "sp_copy2". copy of "sp_copy1"
            SharedPtr<Foo> sp_copy2{ sp_copy1 };
            //Reference count should be 3
            std::cout << *sp_copy2.get_ref_count() << std::endl;
        }   // sp_copy2 goes out of scope here
        //Reference count should be 2
        std::cout << *sp_copy1.get_ref_count() << std::endl;
    }// sp goes out of scope here
    //Reference count should be 1
    std::cout << *sp.get_ref_count() << std::endl;
    
    return 0;
    //Reference count should be 0 after this scope closes
}