// @Fraction.cpp

#include<stdexcept>
#include<iostream>
#include "Fraction.h"
#include "gcd.h"

Fraction::Fraction(int n, int d){
    numerator = n;
    denominator = d;
    
    if (d == 0)
        throw std::out_of_range{"Array index out of range."};
}

void Fraction::write (std::ostream&) const{
    std::cout << numerator << "/" << denominator;
}

Fraction Fraction::add (int i) const{
    int n = numerator;
    int d = denominator;
    n += (i * d);
    
    return Fraction{n, d};
}

Fraction Fraction::operator+ (int i) const{
    int n = numerator;
    int d = denominator;
    n += (i * d);
    
    return Fraction{n, d};
}

Fraction Fraction::operator+ (const Fraction& op2) const{
    int n, d;
    
    if (denominator != op2.denominator){
        d = denominator * op2.denominator;
        n = (numerator * op2.denominator) + (op2.numerator * denominator);
    }
    else{
        n = numerator + op2.numerator;
        d = denominator;
    }
        
    return Fraction{n,d};
}

void Fraction::reduce(){
    denominator = gcd(numerator, denominator);
    numerator /= denominator;
}

//Homework Beginning

Fraction operator+ (int i, const Fraction& f){
    return f.add(i);
}

std::ostream& operator<< (std::ostream& outfile, const Fraction& f){
    f.write(outfile);
    
    return outfile;
}

//Subtractions

Fraction Fraction::operator- (int i) const{
    int d = denominator;
    int n = numerator;
    
    n -= (d * i);
    
    return Fraction{n,d};
}

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

Fraction Fraction::operator- (int i, const Fraction& op2) const{
    int d = op2.denominator;
    int n = op2.numerator;
    
    n = (d * i) - op2.numerator;
    
    return Fraction{n,d};
}

//Unary Subtraction

Fraction Fraction::operator- () const{
    int n = numerator;
    int d = denominator;
    
    return Fraction{-n,d};
}

//Multiplications

Fraction Fraction::operator* (int i) const{
    int n = numerator;
    int d = denominator;
    
    n = (n * i)
    
    return Fraction{n,d};
}

Fraction Fraction::operator* (const Fraction& op2) const{
    int n, d;
    
    d = denominator * op2.denominator;
    n = numerator * op2.numerator;
    
    return Fraction{n,d};
}

//Division

Fraction Fraction::operator/ (int i) const{
    int n, d;
    
    n = denominator * i;
    d = numerator;
    
    return Fraction{n,d};
}

Fraction Fraction::operator/ (const Fraction& op2) const{
    int n = denominator;
    int d = numerator;
    
    d = d * op2.denominator;
    n = n * op2.numerator;
}

//Less Than

bool Fraction::operator< (int i) const{
    bool result = false;
    
    if ((numerator / denominator) < i)
        result = true;
        
    return result;
}

bool Fraction::operator< (const Fraction& op2) const{
    double fraction = numerator / denominator;
    double fraction2 = op2.numerator / op2.denominator;
    bool result = false;
    
    if (fraction < fraction2)
        result = true;
        
    return result;
}

bool Fraction::operator< (int i, const Fraction& op2) const{
    bool result = false;
    
    if (i < (op2.numerator / op2.denominator))
        result = true;
        
    return result;
}

//Greater Than

bool Fraction::operator> (int i) const{
    bool result = false;
    
    if ((numerator / denominator) > i)
        result = true;
        
    return result;
}

bool Fraction::operator> (const Fraction& op2) const{
    double fraction = numerator / denominator;
    double fraction2 = op2.numerator / op2/denominator;
    bool result = false;
    
    if (fraction > fraction2)
        result = true;
        
    return result;
}

bool Fraction::operator> (int i, const Fraction& op2) const{
    bool result = false;
    
    if (i > (op2.numerator / op2.denominator))
        result = true;
        
    return result;
}

//Less Than or Equal to

bool Fraction::operator<= (int i) const{
    bool result = false;
    
    if ((numerator / denominator) <= i)
        result = true;
        
    return result;
}

bool Fraction::operator<= (const Fraction& op2) const{
    double fraction = numerator / denominator;
    double fraction2 = op2.numerator / op2.denominator;
    bool result = false;
    
    if (fraction <= fraction2)
        result = true;
        
    return result;
}

bool Fraction::operator<= (int i, const Fraction& op2) const{
    bool result = false;
    
    if (i <= (op2.numerator / op2.denominator))
        result = true;
        
    return result;
}

//Greater Than or Equal to

bool Fraction::operator> (int i) const{
    bool result = false;
    
    if ((numerator / denominator) >= i)
        result = true;
        
    return result;
}

bool Fraction::operator> (const Fraction& op2) const{
    double fraction = numerator / denominator;
    double fraction2 = op2.numerator / op2/denominator;
    bool result = false;
    
    if (fraction >= fraction2)
        result = true;
        
    return result;
}

bool Fraction::operator> (int i, const Fraction& op2) const{
    bool result = false;
    
    if (i >= (op2.numerator / op2.denominator))
        result = true;
        
    return result;
}

//Equal to

bool Fraction::operator== (int i) const{
    bool result = false;
    
    if (abs((numerator / denominator) - i) < .001)
        result = true;
        
    return result;
}

bool Fraction::operator== (const Fraction& op2) const{
    double fraction = numerator / denominator;
    double fraction2 = op2.numerator / op2.denominator;
    bool result = false;
    
    if (abs(fraction - fraction2) < .001)
        result = true;
        
    return result;
}

bool Fraction::operator== (int i, const Fraction& op2) const{
    bool result = false;
    
    if (abs(i - (op2.numerator / op2.denominator)) < .001)
        result = true;
    
    return result;
}

//Not Equal to

bool Fraction::operator!= (int i) const{
    bool result = false;
    
    if (abs((numerator / denominator) - i) > .001)
        result = true;
        
    return result;
}

bool Fraction::operator!= (const Fraction& op2) const{
    double fraction = numerator / denominator;
    double fraction2 = op2.numerator / op2.denominator;
    bool result = false;
    
    if (abs(fraction - fraction2) > .001)
        result = true;
        
    return result;
}

bool Fraction::operator!= (int i, const Fraction& op2) const{
    bool result = false;
    
    if (abs(i - (op2.numerator / op2.denominator)) > .001)
        result = true;
    
    return result;
}