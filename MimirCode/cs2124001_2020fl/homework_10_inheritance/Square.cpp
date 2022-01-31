/**
 *******************************************************************************
 * @file    Square.h
 * @brief   Header file containing the class Square that is a derived class of
 *          the class Shape that contains methods in order to further define 
 *          a shape if it is a Square.
 *
 * @author  Christian Huggins
 * @date    November 9th, 2020
 *******************************************************************************
**/

#include "Square.h"

/**
 * @brief       This is the constructor given the values for the reference
 *              points and the side
 *
 * @detailed    Provided the x and y for the reference point, the constructor
 *              passes these values to the base classes constructor while
 *              the s is stored as the side.
 *              
 * @param       double x        x coordinate of the reference point
 * 
 * @param       double y        y coordinate of the reference point
 * 
 * @param       double s        side of the square
**/

Square::Square(double x, double y, double s) : Shape{x, y} {
    cout << "DEBUG: Executing Square constructor...\n";
    //Assign side the value of s
    side = s;
}

/**
 * @brief       This is the constructor given the file stream
 *
 * @detailed    Provided the file stream, the constructor will first
 *              pass it to the base classes constructor to store the
 *              x and y reference points, then proceed to read from it
 *              to receive the side of the square
 *              
 * @param       istream& fin    File stream used to read the values
 *                              from the file itself
**/

Square::Square(std::istream& fin) : Shape{fin} {
    cout << "DEBUG: Executing Square constructor...\n";
    //Read and store side from file
    fin >> side;
}

/**
 * @brief       This is the write function used to display the square's
 *              details for the user
 *
 * @detailed    Provided the ostream data type "fout", the function
 *              first passes it to the Shape classes write method,
 *              then uses it to display to the user the side of 
 *              the square
 *              
 * @param       ostream& fout       ostream used to display the
 *                                  shape's data to the user
**/

void Square::write(std::ostream& fout) const{
    //Use Shape's write method to display ref points
    Shape::write(fout);
    //Write size of side
    fout << "Side: " << side << endl;
}

/**
 * @brief       Overloading the stream insertion operator to act
 *              as the write function for square
 *
 * @detailed    Provided the ostream data type "fout", the function
 *              first passes it to the write function of the object
 *              with the data type of Square, then returns it.
 *              
 * @param       ostream& fout       ostream used to display the
 *                                  shape's data to the user
 * 
 * @param       Square& n           object of data type Square accessed
 *                                  to call function write and access its
 *                                  data
 *
 * @return      Returns the ostream parameter that was passed to it by reference
**/

std::ostream& operator<<(std::ostream& fout, const Square& n){
    //Access object of data type Square and use it's write method
    //using fout
    n.write(fout);
    
    return fout;
}

/**
 * @brief       Destructor of the class Square
 *
 * @detailed    Informs the user that the Square class has closed (destructed)
**/

Square::~Square(){
    //Let user know that the destructor is being ran
    cout << "executing Square destructor...\n";
}