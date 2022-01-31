/**
 *******************************************************************************
 * @file    Fraction.h
 * @brief   This header file contains functions allowing the user to conduct
 *          mathematical equations with fractions using the class created
 *          in this function, Fraction.
 *
 * @author  Christian Huggins
 * @date    February 22nd, 2021
 *******************************************************************************
**/

#include<stdexcept>
#include<iostream>
    using std::cout;
    using std::endl;
    using std::cin;

class Fraction {
public:
    //Constructor
    Fraction(int n, int d);
    //Methods/Accessors
    Fraction add(int i) const;
    void write(std::ostream& strm=std::cout) const;
    //Accessors
    int get_numerator() const {return numerator;}
    int get_denominator() const {return denominator;}
    //Addition
    Fraction operator+ (int i) const;
    Fraction operator+ (const Fraction& op2) const;
    //Subrtraction
    Fraction operator- (int i) const;
    Fraction operator- (const Fraction& op2) const;
    //Unary Subtraction
    Fraction operator- () const;
    //Multiplication
    Fraction operator* (int i) const;
    Fraction operator* (const Fraction& op2) const;
    //Division
    Fraction operator/ (int i) const;
    Fraction operator/ (const Fraction& op2) const;
    //Less Than
    bool operator< (int i) const;
    bool operator< (const Fraction& op2) const;
    //Greater Than
    bool operator> (int i) const;
    bool operator> (const Fraction& op2) const;
    //Less Than or Equal to
    bool operator<= (int i) const;
    bool operator<= (const Fraction& op2) const;
    //Greater Than or Equal to
    bool operator>= (int i) const;
    bool operator>= (const Fraction& op2) const;
    //Equal to
    bool operator== (int i) const;
    bool operator== (const Fraction& op2) const;
    //Not Equal to
    bool operator!= (int i) const;
    bool operator!= (const Fraction& op2) const;
private:
    //Mutator
    void reduce();
    //Variables
    int numerator   = 0;
    int denominator = 1;
};

//Addition operator
Fraction operator+ (int i, const Fraction& f);
//Subtraction operator
Fraction operator- (int i, const Fraction& op2);
//Multiplication operator
Fraction operator* (int i, const Fraction& op2);
//Division operator
Fraction operator/ (int i, const Fraction& op2);
//Stream insertion operator
std::ostream& operator<< (std::ostream& outfile, const Fraction& f);
//Less than operator
bool operator< (int i, const Fraction& op2);
//Greater than operator
bool operator> (int i, const Fraction& op2);
//Less than or equal to operator
bool operator<= (int i, const Fraction& op2);
//Greater than or equal to operator
bool operator>= (int i, const Fraction& op2);
//Equal to operator
bool operator== (int i, const Fraction& op2);
//Not equal to operator
bool operator!= (int i, const Fraction& op2);