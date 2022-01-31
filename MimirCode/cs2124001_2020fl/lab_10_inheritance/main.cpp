/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      11/2/2020
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    November 2nd, 2020
 *******************************************************************************
**/

#include "Square.h"
#include "Circle.h"
#include "ShapeList.h"
#include<string>
    using std::string;
#include<fstream>
    using std::ifstream;

int main(){
    //Part 1
    Circle c1{0, 0, 1};
    Square s1{1, 0.5, 2.3};
    cout << "c1: " << c1 << endl;
    cout << "s1: " << s1 << endl;
    
    //Part 2a
    cout << "Press <enter> to continue...";
    cin.get( );  // waits on another <enter> key
    ShapeList shapes;
    shapes.add( new Circle{1, 2.3, 3} );
    shapes.add( new Square{5, 5, 10.2} );
    cout << "List via stream insertion operator:\n";
    cout << shapes << endl;
    cout << "\nList via write method:\n";
    shapes.write( cout );
    cout << endl;
    
    //Part 2b
    cout << "Press <enter> to continue...";
    cin.get( );  // waits on another <enter> key
    
    ifstream fin( "oop09in.txt" );
    if ( !fin ) {
        cout << "Input file could not be opened!  Exiting!\n";
        exit( 1 );
    }
    
    ShapeList shapes2;
    while ( fin.good( ) ) {
        string object_type;
        fin >> object_type;
        if ( object_type == "Square" ) {
            // TODO: add a new Square object (constructed from the stream)
            //       to the `shapes2` list.
            /*double x, y, s;
            fin >> x;
            fin >> y;
            fin >> s;*/
            shapes2.add(new Square{fin});
        } else if ( object_type == "Circle" ) {
            // TODO: add a new Circle object (constructed from the stream)
            //       to the `shapes2` list.
           /* double x, y, r;
            fin >> x;
            fin >> y;
            fin >> r;*/
            shapes2.add(new Circle{fin});
        } else {
            cout << "Unexpected object type: " << object_type << endl;
            exit( 2 );
        }
    }
    
    cout << "Object locations:\n" << shapes2 << endl;
    
    shapes2.erase();
    
    return 0;
}