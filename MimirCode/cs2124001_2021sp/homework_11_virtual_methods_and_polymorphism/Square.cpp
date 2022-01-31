/**
 *******************************************************************************
 * @file    Square.h
 * @brief   Header file containing the class Square that is a derived class of
 *          the class Shape that contains methods in order to further define 
 *          a shape if it is a Square.
 *
 * @author  Christian Huggins
 * @date    April 11th, 2021
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

Square::Square(double x, double y, double s) : Shape{x, y}{
    cout << "DEBUG: Executing Square constructor...\n";
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

Square::Square(std::istream& fin) : Shape{fin}{
    cout << "DEBUG: Executing Square constructor...\n";
    fin >> side;
    fin.ignore();
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
    Shape::write(fout);
    fout << "Side: " << side << endl;
}

/**
 * @brief       Calculates the area of a square
 *
 * @detailed    Taking the side stored in the class circle, the method
 *              multiplies the side by itself, returning the value calculated
 *              
 * @return      Returns the area found by the area formula for a square
**/

double Square::area() const{
    //Area formula - side * side
    return (side * side);
}

/**
 * @brief       Calculates the perimeter of a square
 *
 * @detailed    Taking the side stored in the class square, the method
 *              multiplies the side by 4, returning the value calculated
 *              
 * @return      Returns the value found by the perimeter formula for a square
**/

double Square::perimeter() const{
    //Perimter formula - 4 * side
    return (side * 4);
}

/**
 * @brief       Calculates whether or not a coordinate is in a square
 *
 * @detailed    Taking the points given by the user, the method calculates the
 *              bounds of the square. It then determines if the given points
 *              are in between the bounds. The result is then returned as
 *              either true or false.
 *              
 * @param       double p_x      The x value of a given point
 * 
 * @param       double p_y      The y value of a given point
 * 
 * @return      Returns true of false depending on if point is in the square
**/

bool Square::contains(double p_x, double p_y) const{
    //Initialize variables
    double x = Shape::get_ref_x();
    double y = Shape::get_ref_y();
    double higherBound = y + side;
    double lowerBound = y;
    double rightBound = x + side;
    double leftBound = x;
    bool result = false;
    
    //If point is within all bounds, it's in the square
    if (p_y < higherBound && p_y > lowerBound && p_x < rightBound
        && p_x > leftBound){
            result = true;
    }
    
    return result;
}

/**
 * @brief       Destructor of the class Square
 *
 * @detailed    Informs the user that the Square class has closed (destructed)
**/

Square::~Square(){
    cout << "Square::~Square\n";
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
    n.write(fout);
    
    return fout;
}