/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   Testing code written in templated header files
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      3/15/2021
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    March 15, 2021
 *******************************************************************************
**/

#include<cctype>
#include "IntNode.h"
#include "IntList.h"
#include "IntStack.h"

int main(){
    //Checkpoint 1
    cout << "The Stack & the Class Template (in-lab portion)\n";
    IntNode int_item_1( 101 );
    IntNode int_item_2( 212 );
    cout << "test nodes: " << int_item_1 << ' ' << int_item_2 << "\n";
    int_item_1.set_next( &int_item_2 );
    cout << "test next:  " << int_item_1 << ' ' << int_item_2 << "\n\n";
    
    //Checkpoint 2a
    IntList list1;
    list1.add_front( 101 );
    list1.add_front( 212 );
    list1.add_front( 323 );
    list1.add_front( 434 );
    cout << "test list 101/212/323/434:\n" << list1 << "\n\n";
    
    //Checkpoint 2b
    int list_data_1;
    try {
       list_data_1 = list1.remove_front( );
       cout << "test list remove #1: " << list_data_1 << endl;
    } 
    catch ( const std::length_error& ) { 
       cout << "test list remove #1 failed\n"; 
    }
    
    cout << "list is now:\n" << list1 << "\n";
    int list_data_2;
    try {
       list_data_2 = list1.remove_front( );
       cout << "test list remove #2: " << list_data_2 << endl;
    } 
    catch ( const std::length_error& ) { 
       cout << "test list remove #2 failed\n"; 
    }
    cout << "list is now:\n" << list1 << "\n\n";
    
    //Checkpoint 2c
    IntStack stack;
    stack.push( 101 );
    stack.push( 212 );
    stack.push( 323 );
    stack.push( 434 );
    cout << "test stack 101/212/323/434:\n" << stack << endl;
    
    int stack_data_1;
    try {
        stack_data_1 = stack.pop( );
        cout << "test stack pop #1: " << stack_data_1 << endl;
    }
    catch ( const std::length_error& ) {
        cout << "test stack pop #1 failed\n"; 
    }
    
    cout << "stack is now:\n" << stack << endl;
    
    int stack_data_2;
    try {
        stack_data_2 = stack.pop( );
        cout << "test stack pop #2: " << stack_data_2 << endl;
    }
    catch ( const std::length_error& ) {
        cout << "test stack pop #2 failed\n"; 
    }
    cout << "stack is now:\n" << stack << endl;
    
    //Checkpoint 3
    IntStack postfix_stack;
    ifstream infile( "stack_calc.txt", std::ios::in );
    if ( !infile )
        cout << "error opening data file!\n";
    else {
        bool stackError = false;  // true if stack empties too soon or unexpected operator
        while ( infile.good( ) && !stackError ) {
            char token;
            infile >> token;
        
            if (isdigit(token)){
                int number = std::stoi(&token, nullptr);
                postfix_stack.push(number);
            }
            else{
                //Number 2 because chronologically, this number was 2nd
                int number2 = postfix_stack.pop();
                int number1 = postfix_stack.pop();
                
                if (token == '+')
                    number2 = number1 + number2;
                else if (token == '-')
                    number2 = number1 - number2;
                else if (token == '*')
                    number2 = number1 * number2;
                else if (token == '/')
                    number2 = number1 / number2;
                    
                postfix_stack.push(number2);
            }
            
    
            cout << "stack is now \n" << postfix_stack << "\n\n";
        }  // end of "read file" loop
        if ( stackError )
            cout << "invalid expression!!\n";
        else {
            try {
                int result = postfix_stack.pop( );
                cout << "expression evaluates to " << result << endl;
            } 
            catch ( const std::length_error& ) {
                cout << "final pop of IntStack failed\n";
            }
            if ( postfix_stack.is_empty( ) ){
                cout << "OK: empty stack => well-formed postfix expression!\n";
            }
            else {  // stack is not empty: there were too many numbers in the input!
                cout << "ERROR: non-empty stack => illegal postfix "
                     << "expression!\n";
            }
        }
    }
    
    return 0;
}