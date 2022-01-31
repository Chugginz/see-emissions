/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   The main file used in order to test the different classes and their
 *          functions to ensure all code is working properly
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      04/5/2021
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    April 5th, 2021
 *******************************************************************************
**/

#include "Square.h"
#include "Circle.h"
#include "ShapeList.h"
#include "Rectangle.h"
#include "Triangle.h"
#include<string>
    using std::string;
#include<fstream>
    using std::ifstream;

int main(){
    //Part 1
    Circle c1{0, 0, 1};
    Square s1{1, 0.5, 2.3};
    //Triangle and Rectangle Test
    Triangle t1{4, 5, 2, 3.5};
    Rectangle r1{3, 6, 3.6, 6};
    cout << "c1: " << c1 << endl;
    cout << "s1: " << s1 << endl;
    //Triangle and Rectangle output
    cout << "t1: " << t1 << endl;
    cout << "r1: " << r1 << endl;
    
    //Part 2a
    cout << "Press <enter> to continue...";
    cin.get();  // waits on another <enter> key
    ShapeList shapes;
    shapes.add(new Circle{1, 2.3, 3});
    shapes.add(new Square{5, 5, 10.2});
    cout << "List via stream insertion operator:\n";
    cout << shapes << endl;
    cout << "\nList via write method:\n";
    shapes.write(cout);
    cout << endl;
    
    //Part 2b
    cout << "Press <enter> to continue...";
    cin.get();  // waits on another <enter> key
    
    ifstream fin("oop09in.txt");
    if (!fin) {
        cout << "Input file could not be opened!  Exiting!\n";
        exit(1);
    }
    
    ShapeList shapes2;
    while (fin.good()){
        string object_type;
        fin >> object_type;
        if (object_type == "Square"){
            // If object is a square, add square to shapes list
            shapes2.add(new Square{fin});
        } else if (object_type == "Circle"){
            // If object is a circle, add circle to shapes list
            shapes2.add(new Circle{fin});
        } else if (object_type == "Triangle"){
            // If objext is a triangle, add triangle to shapes list
            shapes2.add(new Triangle{fin});
        } else if (object_type == "Rectangle"){
            // If object is a rectangle, add rectangle to shapes list
            shapes2.add(new Rectangle{fin});
        } else{
            cout << "Unexpected object type: " << object_type << endl;
            exit(2);
        }
    }
    
    cout << "Object locations:\n" << shapes2 << endl;
    
    //Testing functions
    cout << "test \"closest\" methods...\n";
    double x;
    double y;
    cout << "Enter coordinates for search of closest object reference: ";
    cin >> x >> y;
    Shape* closestObj = shapes2.findClosestTo( x, y );
    // If there is a closest object, read it
    if (closestObj != nullptr)
        cout << "The object closest to the point provided is located at "
             << *closestObj << endl;
    // Else, there is no object
    else
        cout << "No objects were entered!\n";
    
    // Free all memory
    shapes2.erase();
    
    return 0;
}