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

Fraction operator+ (int i, const Fraction& f){
    int n = f.numerator;
    int d = f.denominator;
    n += (i * d);
        
    return Fraction{n,d};
}

void Fraction::reduce(){
    denominator = gcd(numerator, denominator);
    numerator /= denominator;
}

std::ostream& operator<< (std::ostream& outfile, const Fraction& f){
    std::cout << f.numerator << "/" << f.denominator;
    return outfile;
}