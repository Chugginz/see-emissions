/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      3/15/2021
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    March 15th, 2021
 *******************************************************************************
**/

#include "CSZNode.h"
#include "BinarySearchTree.h"
#include<limits>
#include<fstream>
#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;

CityStateZip read_CityStateZip( std::istream& fin ) {
    std::string  city, state;
    unsigned int zip = 0;
    getline( fin, city, ',' );
    getline( fin, state, ',' );
    fin >> zip;
    fin.ignore( std::numeric_limits<std::streamsize>::max( ), '\n' );
    CityStateZip new_csz{city, state, zip};
    return new_csz;
}

int main(){
    
    std::ifstream fin{"city_list.txt"};
    if ( !fin ) {
      cout << "Error opening city_list.txt!\n";
      exit( 1 );
    }
    
    CSZNode n1{read_CityStateZip( fin )};
    CSZNode n2{read_CityStateZip( fin )};
    
    cout << "test CSZNodes:\n";
    cout << n1 << endl;
    cout << n2 << endl;
    cout << endl;
    
    //Part 2
    cout << "Press <enter> to continue...\n";
    cin.get();
    BinarySearchTree city_tree;
    
    fin.clear();   // restore stream state so I/O may proceed
    fin.seekg(0);  // seek "get" to file start (byte #0)
    
    while (fin.good())
        city_tree.add_iteratively(read_CityStateZip(fin));
    
    cout << "Recursive Tree Listing of Iterative Additions\n";
    city_tree.write_recursively(cout);
    
    return 0;
}