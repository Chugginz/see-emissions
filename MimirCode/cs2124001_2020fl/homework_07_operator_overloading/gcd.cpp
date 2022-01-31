/**
 *******************************************************************************
 * @file    gcd.cpp
 * @brief   This file provides a function definition for the function gcd 
 *          created in the gcd header file.
 *
 * @author  Christian Huggins
 * @date    February 22nd, 2021
 *******************************************************************************
**/

#include "gcd.h"

/**
 * @brief                   Greatest Common Denominator Finder
 *
 * @detailed                This function finds the simplified denominator
 *                          used for a reduced fraction
 * 
 * @param   int n               The numerator passed to this function
 * 
 * @param   int d               The denominator passed to this function
 * 
 * @return  int                 Returns the value for n (previously numerator)
**/

int gcd(int n, int d) {
    int remainder;

    while (d != 0) {
        remainder = n % d;
        n = d;
        d = remainder;
    }

    return n;
}