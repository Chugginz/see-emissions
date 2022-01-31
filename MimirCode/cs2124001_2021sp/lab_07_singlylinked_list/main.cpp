/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      3/1/2021
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    March 1, 2021
 *******************************************************************************
**/

#include "ItemList.h"

int main(){
    //Checkpoint 1
    std::ofstream dbg{"debug.txt"};  // open a file named debug.txt

    Item test_item{"Great Sword", 1};
    dbg << "test item: \n" << test_item << "\n" << endl;
    
    ItemNode test_node_1{ Item{"Amulet of Feasting", 2} };
    dbg << "test game item node: \n" << test_node_1 << "\n" << endl;
    
    ItemNode test_node_2{ Item{"Potion of Fire Walking", 3} };
    test_node_1.set_next( &test_node_2 );
    dbg << "test 2 items: \n" << test_node_1 << "\n" << test_node_2 << endl;
    
    ItemList inventory1;
    
    //Checkpoint 2
    inventory1.add_front( Item{"Stone Shield", 1} );
    inventory1.add_front( Item{"Potion of Health", 1} );
    
    dbg << "inventory1 listings with 2 nodes (head: Potion of Health, tail: Stone Shield):\n"
    << inventory1 << "\n" << endl;
    
    inventory1.add_back( Item{"Cap of Health", 2} );
    inventory1.add_back( Item{"Captain's Pike",  1} );
    
    dbg << "inventory1 listings with 4 nodes (head: Potion of Health, tail: Captain's Pike):\n"
        << inventory1 << endl;
    
    ItemList inventory2;
    
    inventory2.add_back( Item{"Ruby Wand", 1} );
    inventory2.add_back( Item{"Greatsword"} );
    inventory2.add_front( Item{"Cloak of Shadows", 3} );
    
    dbg << "inventory2 listings with 3 nodes (head: Cloak of Shadows, tail: Greatsword):\n"
    << inventory2 << endl;
    
    //Checkpoint 3
    try {
        Item first = inventory1.remove_front( );
    
        dbg << "removed from head of inventory1:\n"
            << first << "\n"
            << "inventory1 now:\n"
            << inventory1 << endl;
    } 
    catch ( const std::length_error& e ) { 
        dbg << e.what( ) << "\n"; 
    }
    
    //Checkpoint 4
    inventory2.erase ();
    dbg << "inventory2 listings after erase:\n" << inventory2 << "\n" << endl;
    
    return 0;
}