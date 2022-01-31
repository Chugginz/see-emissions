/**
 *******************************************************************************
 * @file    Fraction.cpp
 * @brief   
 *
 * @author  Christian Huggins
 * @date    February 22nd, 2021
 *******************************************************************************
**/

#include<stdexcept>
#include<iostream>
#include "Fraction.h"

/**
 * @brief                   Constructor
 *
 * @detailed                This method acts as the constructor initializing
 *                          the numerator and denominator while also ensuring
 *                          that the denominator provided is not a 0.
 *              
 * @param   int n           This is the value being stored as the numerator
 * 
 * @param   int d           This is the value being stored as the denominator
**/

Fraction::Fraction(int n, int d){
    numerator = n;
    denominator = d;
    
    if (d == 0)
        throw std::out_of_range{"Array index out of range."};
        
    reduce();
}

/**
 * @brief                   Additon Method
 *
 * @detailed                This function acts similar to the addition
 *                          operator overload in which an integer is added
 *                          with a fraction resulting in a new Fraction
 *                          object being return with a new numerator and
 *                          denominator.
 *              
 * @param   int i           This is any integer provided for the method
 *                          that is added to the fraction
 * 
 * @return  Fraction        Returns a fraction with the new numerator
 *                          and denominator
**/

Fraction Fraction::add(int i) const{
    int n = numerator;
    int d = denominator;
    n += (i * d);
    
    return Fraction{n, d};
}

/**
 * @brief                   Mutator
 *
 * @detailed                This function reduces a fraction using modulus
 *                          to ensure that both sides can be simplified if
 *                          possible.
**/

void Fraction::reduce(){
    while (numerator % 2 == 0 && denominator % 2 == 0){
        numerator /= 2;
        denominator /= 2;
    }
        
    if (numerator % denominator == 0){
        numerator /= denominator;
        denominator /= denominator;
    }
}

/**
 * @brief                   Method/Accessor
 *
 * @detailed                This function reduces the overall fraction to the
 *                          lowest form it cant be and then reads and stores
 *                          the numerator and denominator with a "/" in
 *                          between.
 *              
 * @param   ostream& strm   This reads and stores the numerator and
 *                          denominator with a "/" in between
**/

void Fraction::write(std::ostream& strm) const{
    strm << numerator << "/" << denominator;
}

/**
 * @brief                   Stream Insertion Operator Overload
 *
 * @detailed                This function has an integer added
 *                          with a fraction resulting in a new Fraction
 *                          object being return with a new numerator and
 *                          denominator.
 * 
 * @param   ostream& outfile    This is used to pass to the write function
 * 
 * @param   Fraction& f         This is used to access the write function
 *                              within the Fraction class
 * 
 * @return  ostream&            Returns the outfile used for writing
**/

std::ostream& operator<< (std::ostream& outfile, const Fraction& f){
    f.write(outfile);
    
    return outfile;
}

//Addition Operators
/**
 * @brief                   Addition Operator Overload (int)
 *
 * @detailed                This function has an integer added
 *                          with a fraction resulting in a new Fraction
 *                          object being return with a new numerator and
 *                          denominator.
 *              
 * @param   int i           Any integer that is trying to be combined
 *                          with a fraction
 * 
 * @return  Fraction        Returns a Fraction type object with a new
 *                          numerator and denominator
**/

Fraction Fraction::operator+ (int i) const{
    int n = numerator;
    int d = denominator;
    n += (i * d);
    
    return Fraction{n, d};
}

/**
 * @brief                   Addition Operator Overload (fraction)
 *
 * @detailed                This function has a fraction added
 *                          with a fraction resulting in a new Fraction
 *                          object being return with a new numerator and
 *                          denominator.
 *              
 * @param   const Fraction& op2     A Fraction object used to access that
 *                                  object's numerator and denominator
 *                                  to combine them with the current
 *                                  class's numerator and denominator
 * 
 * @return  Fraction        Returns a Fraction type object with a new
 *                          numerator and denominator
**/

Fraction Fraction::operator+ (const Fraction& op2) const{
    int n, d;
    
    if (denominator != op2.denominator){
        n = (numerator * op2.numerator) + (op2.denominator * denominator);
        d = denominator * op2.denominator;
    }
    else{
        n = numerator + op2.numerator;
        d = denominator;
    }
        
    return Fraction{n,d};
}

/**
 * @brief                   Addition Operator Overload (non-class int)
 *
 * @detailed                This function has an integer added
 *                          with a fraction resulting in a new Fraction
 *                          object being return with a new numerator and
 *                          denominator.
 *              
 * @param   int i           Any integer that is trying to be combined
 *                          with a fraction
 * 
 * @return  Fraction        Returns a Fraction type object with a new
 *                          numerator and denominator
**/

Fraction operator+ (int i, const Fraction& f){
    return f.add(i);
}

//Subtractions
/**
 * @brief                   Subtraction Operator Overload (int)
 *
 * @detailed                This function has an integer being subtracted
 *                          from a fraction resulting in a new Fraction
 *                          object being return with a new numerator and
 *                          denominator.
 *              
 * @param   int i           Any integer that is trying to be subtracted
 *                          from a fraction
 * 
 * @return  Fraction        Returns a Fraction type object with a new
 *                          numerator and denominator
**/

Fraction Fraction::operator- (int i) const{
    int d = denominator;
    int n = numerator;
    
    n -= (d * i);
    
    return Fraction{n,d};
}

/**
 * @brief                   Subtraction Operator Overload (fraction)
 *
 * @detailed                This function has a fraction being subtracted
 *                          from a fraction resulting in a new Fraction
 *                          object being return with a new numerator and
 *                          denominator.
 *              
 * @param   const Fraction& op2     Any fraction that is going to be subtracted
 *                                  from the current class's fraction
 * 
 * @return  Fraction        Returns a fraction type object with a new
 *                          numerator and denominator
**/

Fraction Fraction::operator- (const Fraction& op2) const{
    int n, d;
    
    if (denominator != op2.denominator){
        d = denominator * op2.denominator;
        n = (numerator * op2.denominator) - (op2.numerator * denominator);
    }
    else{
        n = numerator - op2.numerator;
        d = denominator;
    }
    
    return Fraction{n,d};
}

/**
 * @brief                   Subtraction Operator Overload (non-class int)
 *
 * @detailed                This function has an integer subtracting
 *                          a fraction resulting in a new Fraction
 *                          object being return with a new numerator and
 *                          denominator.
 *              
 * @param   int i           Any integer that is trying to subtract a fraction
 * 
 * @return  Fraction        Returns a Fraction type object with a new
 *                          numerator and denominator
**/

Fraction operator- (int i, const Fraction& op2){
    int d = op2.get_denominator();
    int n = op2.get_numerator();
    
    n = (d * i) - op2.get_numerator();
    
    return Fraction{n,d};
}

/**
 * @brief                   Negative Unary Operator Overload
 *
 * @detailed                This function changes the numerator to a negative
 *                          (or the opposite) and keeps the denominator the
 *                          same in order to make the fraction negative.
 *              
 * @return  Fraction        Returns a fraction type object with a new
 *                          opposite numerator and positive denominator
**/

Fraction Fraction::operator- () const{
    int n = numerator;
    int d = denominator;
    
    return Fraction{-n,d};
}

//Multiplications
/**
 * @brief                   Multiplication Operator Overload (int)
 *
 * @detailed                This function has an integer being multiplied
 *                          by a fraction resulting in a new Fraction
 *                          object being return with a new numerator and
 *                          denominator.
 *              
 * @param   int i           Any integer that is trying to be multiplied
 *                          by a fraction
 * 
 * @return  Fraction        Returns a fraction type object with a new
 *                          numerator and denominator
**/

Fraction Fraction::operator* (int i) const{
    int n = numerator;
    int d = denominator;
    
    n = (n * i);
    
    return Fraction{n,d};
}

/**
 * @brief                   Multiplication Operator Overload (fraction)
 *
 * @detailed                This function has a fraction being multiplied
 *                          by a fraction resulting in a new Fraction
 *                          object being return with a new numerator and
 *                          denominator.
 *              
 * @param   const Fraction& op2     Any fraction that is trying to 
 *                                  be multiplied by a fraction
 * 
 * @return  Fraction        Returns a fraction type object with a new
 *                          numerator and denominator
**/

Fraction Fraction::operator* (const Fraction& op2) const{
    int n, d;
    
    d = denominator * op2.denominator;
    n = numerator * op2.numerator;
    
    return Fraction{n,d};
}

/**
 * @brief                   Multiplication Operator Overload (non-class int)
 *
 * @detailed                This function has an integer being multiplied
 *                          by a fraction resulting in a new Fraction
 *                          object being return with a new numerator and
 *                          denominator.
 *              
 * @param   int i           Any integer that is trying to be multiplied
 *                          by a fraction
 * 
 * @param   const Fraction& op2     The fraction being multiplied by
 *                                  an int
 * 
 * @return  Fraction        Returns a fraction type object with a new
 *                          numerator and denominator
**/

Fraction operator* (int i, const Fraction& op2){
    int n = op2.get_numerator();
    int d = op2.get_denominator();
    
    n = (n * i);
    
    return Fraction{n,d};
}

//Division
/**
 * @brief                   Division Operator Overload (int)
 *
 * @detailed                This function has an integer used to divide
 *                          a fraction resulting in a new Fraction
 *                          object being return with a new numerator and
 *                          denominator.
 *              
 * @param   int i           Any integer that is being divided by
 * 
 * @return  Fraction        Returns a fraction type object with a new
 *                          numerator and denominator
**/

Fraction Fraction::operator/ (int i) const{
    int n = numerator;
    int d = denominator * i;
    
    return Fraction{n,d};
}

/**
 * @brief                   Division Operator Overload (fraction)
 *
 * @detailed                This function has a fraction being divided
 *                          by a fraction resulting in a new Fraction
 *                          object being return with a new numerator and
 *                          denominator.
 *              
 * @param   const Fraction& op2     Any fraction that is trying to 
 *                                  be divided by a fraction
 * 
 * @return  Fraction        Returns a fraction type object with a new
 *                          numerator and denominator
**/

Fraction Fraction::operator/ (const Fraction& op2) const{
    int n = numerator * op2.denominator;
    int d = denominator * op2.numerator;
    
    return Fraction{n,d};
}

/**
 * @brief                   Division Operator Overload (non-class int)
 *
 * @detailed                This function has an integer being divided
 *                          by a fraction resulting in a new Fraction
 *                          object being return with a new numerator and
 *                          denominator.
 *              
 * @param   int i           Any integer that is trying to be divided
 *                          by a fraction
 * 
 * @param   const Fraction& op2     The fraction dividing the int
 * 
 * @return  Fraction        Returns a fraction type object with a new
 *                          numerator and denominator
**/

Fraction operator/ (int i, const Fraction& op2){
    int n = op2.get_denominator();
    int d = op2.get_numerator();
    
    n *= i;
    
    return Fraction{n,d};
}

//Less Than
/**
 * @brief                   Less Than Operator Overload (int)
 *
 * @detailed                This function has an integer used to compare with
 *                          a fraction resulting in a true or false boolean
 *                          response
 *              
 * @param   int i           Any integer that is being compared to the fraction
 * 
 * @return  bool            Returns a true or false response
**/

bool Fraction::operator< (int i) const{
    bool result = false;
    
    if ((numerator / denominator) < i)
        result = true;
        
    return result;
}

/**
 * @brief                   Less Than Operator Overload (fraction)
 *
 * @detailed                This function has a fraction used to compare with
 *                          a fraction resulting in a true or false boolean
 *                          response
 *              
 * @param const Fraction& op2       Any fraction that is being compared to
 *                                  the current class's fraction
 * 
 * @return  bool            Returns a true or false response
**/

bool Fraction::operator< (const Fraction& op2) const{
    double fraction = numerator / denominator;
    double fraction2 = op2.numerator / op2.denominator;
    bool result = false;
    
    if (fraction < fraction2)
        result = true;
        
    return result;
}

/**
 * @brief                   Less Than Operator Overload (non-class int)
 *
 * @detailed                This function has an integer used to compare with
 *                          a fraction resulting in a true or false boolean
 *                          response
 *              
 * @param   int i           Any integer that is being compared to the fraction
 * 
 * @param const Fraction& op2       Any fraction that is being compared to
 *                                  the int
 * 
 * @return  bool            Returns a true or false response
**/

bool operator< (int i, const Fraction& op2){
    bool result = false;
    
    if (i < (op2.get_numerator() / op2.get_denominator()))
        result = true;
        
    return result;
}

//Greater Than
/**
 * @brief                   Greater Than Operator Overload (int)
 *
 * @detailed                This function has an integer used to compare with
 *                          a fraction resulting in a true or false boolean
 *                          response
 *              
 * @param   int i           Any integer that is being compared to the fraction
 * 
 * @return  bool            Returns a true or false response
**/

bool Fraction::operator> (int i) const{
    bool result = false;
    
    if ((numerator / denominator) > i)
        result = true;
        
    return result;
}

/**
 * @brief                   Greater Than Operator Overload (fraction)
 *
 * @detailed                This function has a fraction used to compare with
 *                          a fraction resulting in a true or false boolean
 *                          response
 *              
 * @param const Fraction& op2       Any fraction that is being compared to
 *                                  the current class's fraction
 * 
 * @return  bool            Returns a true or false response
**/

bool Fraction::operator> (const Fraction& op2) const{
    double fraction = numerator / denominator;
    double fraction2 = op2.numerator / op2.denominator;
    bool result = false;
    
    if (fraction > fraction2)
        result = true;
        
    return result;
}

/**
 * @brief                   Greater Than Operator Overload (non-class int)
 *
 * @detailed                This function has an integer used to compare with
 *                          a fraction resulting in a true or false boolean
 *                          response
 *              
 * @param   int i           Any integer that is being compared to the fraction
 * 
 * @param const Fraction& op2       Any fraction that is being compared to
 *                                  the int
 * 
 * @return  bool            Returns a true or false response
**/

bool operator> (int i, const Fraction& op2){
    bool result = false;
    
    if (i > (op2.get_numerator() / op2.get_denominator()))
        result = true;
        
    return result;
}

//Less Than or Equal To
/**
 * @brief                   Less Than or Equal To Operator Overload (int)
 *
 * @detailed                This function has an integer used to compare with
 *                          a fraction resulting in a true or false boolean
 *                          response
 *              
 * @param   int i           Any integer that is being compared to the fraction
 * 
 * @return  bool            Returns a true or false response
**/

bool Fraction::operator<= (int i) const{
    bool result = false;
    
    if ((numerator / denominator) <= i)
        result = true;
        
    return result;
}

/**
 * @brief                   Less Than or Equal To Operator Overload (fraction)
 *
 * @detailed                This function has a fraction used to compare with
 *                          a fraction resulting in a true or false boolean
 *                          response
 *              
 * @param const Fraction& op2       Any fraction that is being compared to
 *                                  the current class's fraction
 * 
 * @return  bool            Returns a true or false response
**/

bool Fraction::operator<= (const Fraction& op2) const{
    double fraction = numerator / denominator;
    double fraction2 = op2.numerator / op2.denominator;
    bool result = false;
    
    if (fraction <= fraction2)
        result = true;
        
    return result;
}

/**
 * @brief                   Less Than or Equal To Operator Overload 
 *                          (non-class int)
 *
 * @detailed                This function has an integer used to compare with
 *                          a fraction resulting in a true or false boolean
 *                          response
 *              
 * @param   int i           Any integer that is being compared to the fraction
 * 
 * @param const Fraction& op2       Any fraction that is being compared to
 *                                  the int
 * 
 * @return  bool            Returns a true or false response
**/

bool operator<= (int i, const Fraction& op2){
    bool result = false;
    
    if (i <= (op2.get_numerator() / op2.get_denominator()))
        result = true;
        
    return result;
}

//Greater Than or Equal to
/**
 * @brief                   Greater Than or Equal To Operator Overload (int)
 *
 * @detailed                This function has an integer used to compare with
 *                          a fraction resulting in a true or false boolean
 *                          response
 *              
 * @param   int i           Any integer that is being compared to the fraction
 * 
 * @return  bool            Returns a true or false response
**/

bool Fraction::operator>= (int i) const{
    bool result = false;
    
    if ((numerator / denominator) >= i)
        result = true;
        
    return result;
}

/**
 * @brief                   Greater Than or Equal To Operator Overload 
 *                          (fraction)
 *
 * @detailed                This function has a fraction used to compare with
 *                          a fraction resulting in a true or false boolean
 *                          response
 *              
 * @param const Fraction& op2       Any fraction that is being compared to
 *                                  the current class's fraction
 * 
 * @return  bool            Returns a true or false response
**/

bool Fraction::operator>= (const Fraction& op2) const{
    double fraction = numerator / denominator;
    double fraction2 = op2.numerator / op2.denominator;
    bool result = false;
    
    if (fraction >= fraction2)
        result = true;
        
    return result;
}

/**
 * @brief                   Greater Than or Equal To Operator Overload 
 *                          (non-class int)
 *
 * @detailed                This function has an integer used to compare with
 *                          a fraction resulting in a true or false boolean
 *                          response
 *              
 * @param   int i           Any integer that is being compared to the fraction
 * 
 * @param const Fraction& op2       Any fraction that is being compared to
 *                                  the int
 * 
 * @return  bool            Returns a true or false response
**/

bool operator>= (int i, const Fraction& op2){
    bool result = false;
    
    if (i >= (op2.get_numerator() / op2.get_denominator()))
        result = true;
        
    return result;
}

//Equal to
/**
 * @brief                   Equal To Operator Overload (int)
 *
 * @detailed                This function has an integer used to compare with
 *                          a fraction resulting in a true or false boolean
 *                          response
 *              
 * @param   int i           Any integer that is being compared to the fraction
 * 
 * @return  bool            Returns a true or false response
**/

bool Fraction::operator== (int i) const{
    bool result = false;
    
    if (abs((numerator / denominator) - i) < .001)
        result = true;
        
    return result;
}

/**
 * @brief                   Equal To Operator Overload 
 *                          (fraction)
 *
 * @detailed                This function has a fraction used to compare with
 *                          a fraction resulting in a true or false boolean
 *                          response
 *              
 * @param const Fraction& op2       Any fraction that is being compared to
 *                                  the current class's fraction
 * 
 * @return  bool            Returns a true or false response
**/

bool Fraction::operator== (const Fraction& op2) const{
    double fraction = numerator / denominator;
    double fraction2 = op2.numerator / op2.denominator;
    bool result = false;
    
    if (abs(fraction - fraction2) < .001)
        result = true;
        
    return result;
}

/**
 * @brief                   Equal To Operator Overload 
 *                          (non-class int)
 *
 * @detailed                This function has an integer used to compare with
 *                          a fraction resulting in a true or false boolean
 *                          response
 *              
 * @param   int i           Any integer that is being compared to the fraction
 * 
 * @param const Fraction& op2       Any fraction that is being compared to
 *                                  the int
 * 
 * @return  bool            Returns a true or false response
**/

bool operator== (int i, const Fraction& op2){
    bool result = false;
    
    if (abs(i - (op2.get_numerator() / op2.get_denominator())) < .001)
        result = true;
    
    return result;
}

//Not Equal to
/**
 * @brief                   Not Equal To Operator Overload (int)
 *
 * @detailed                This function has an integer used to compare with
 *                          a fraction resulting in a true or false boolean
 *                          response
 *              
 * @param   int i           Any integer that is being compared to the fraction
 * 
 * @return  bool            Returns a true or false response
**/

bool Fraction::operator!= (int i) const{
    bool result = false;
    
    if (abs((numerator / denominator) - i) > .001)
        result = true;
        
    return result;
}

/**
 * @brief                   Not Equal To Operator Overload 
 *                          (fraction)
 *
 * @detailed                This function has a fraction used to compare with
 *                          a fraction resulting in a true or false boolean
 *                          response
 *              
 * @param const Fraction& op2       Any fraction that is being compared to
 *                                  the current class's fraction
 * 
 * @return  bool            Returns a true or false response
**/

bool Fraction::operator!= (const Fraction& op2) const{
    double fraction = numerator / denominator;
    double fraction2 = op2.numerator / op2.denominator;
    bool result = false;
    
    if (abs(fraction - fraction2) > .001)
        result = true;
        
    return result;
}

/**
 * @brief                   Not Equal To Operator Overload 
 *                          (non-class int)
 *
 * @detailed                This function has an integer used to compare with
 *                          a fraction resulting in a true or false boolean
 *                          response
 *              
 * @param   int i           Any integer that is being compared to the fraction
 * 
 * @param const Fraction& op2       Any fraction that is being compared to
 *                                  the int
 * 
 * @return  bool            Returns a true or false response
**/

bool operator!= (int i, const Fraction& op2){
    bool result = false;
    
    if (abs(i - (op2.get_numerator() / op2.get_denominator())) > .001)
        result = true;
    
    return result;
}