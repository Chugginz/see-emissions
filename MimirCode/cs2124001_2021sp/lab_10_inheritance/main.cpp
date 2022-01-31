/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      3/29/2021
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    March 29th, 2021
 *******************************************************************************
**/

#include "Square.h"
#include "Circle.h"
#include "Triangle.h"
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
            /*
            double x, y, s;
            fin >> x;
            fin >> y;
            fin >> s;
            shapes2.add(new Squre{x, y, s});
            */
            shapes2.add(new Square{fin});
        } else if ( object_type == "Circle" ) {
            /*
            double x, y, r;
            fin >> x;
            fin >> y;
            fin >> r;
            shapes2.add(new Circle{x, y, r});
            */
            shapes2.add(new Circle{fin});
        } else if ( object_type == "Triangle" ) {
            /*
            double x, y, b, h
            fin >> x;
            fin >> y;
            fin >> b;
            fin >> h;
            shapes2.add(new Triangle{x, y, b, h})
            */
            shapes2.add(new Triangle{fin});
            //Accidentally made triangle class misinterpreting the checkpoint 2
        } else {
            cout << "Unexpected object type: " << object_type << endl;
            exit( 2 );
        }
    }
    
    cout << "Object locations:\n" << shapes2 << endl;
    
    //Part 3
    shapes2.erase();
    
    return 0;
}