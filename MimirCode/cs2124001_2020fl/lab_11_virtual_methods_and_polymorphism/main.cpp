/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      11/9/2020
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    November 9th, 2020
 *******************************************************************************
**/

#include "Circle.h"
#include "Square.h"
#include "ShapeList.h"
#include "Polygon.h"
#include<string>
    using std::string;
#include<fstream>
    using std::ifstream;

int main(){
    ifstream fin( "oop10in.txt" );
    if ( !fin ) {
        cout << "Input file could not be opened!  Exiting!\n";
        exit( 1 );
    }
    
    ShapeList shapes;
    
    while ( !fin.eof() ) {
        string object_type;
        fin >> object_type;
        if ( object_type == "Square" ) {
    
            // TODO: add a Square object to the list from the file
            shapes.add(new Square{fin});
            //Testing purposes
            cout << "Square added\n";
        } 
        else if ( object_type == "Circle" ) {
    
            // TODO: add a Circle object to the list from the file
            shapes.add(new Circle{fin});
            //Testing purposes
            cout << "Circle added\n";
        } 
        else if ( object_type == "Polygon" ) {
    
            // TODO: add a Polygon object to the list from the file
            shapes.add(new Polygon{fin});
            //Testing purposes
            cout << "Polygon added\n";
        }
        else if ( object_type != "" ) {
            cout << "Unexpected object type: " << object_type << endl;
            exit( 2 );
        }
    }
    
    cout << "Object locations:\n" << shapes << endl;
    
    return 0;
}