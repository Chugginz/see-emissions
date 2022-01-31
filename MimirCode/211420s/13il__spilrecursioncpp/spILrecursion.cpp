/**
 *******************************************************************************
 * @file    spILrecursion.cpp
 * @brief   Iterative and recursive functions being tested to  
 *          ensure the results are correct for both GCD and
 *          exponentiation.
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Thursday, April 16
 *      Instructor:    Nancy Draganjac
 *
 * @author  Christian Huggins
 * @date    April 16, 2020
 *******************************************************************************
**/

#include <iostream>
    using std::cout;
    using std::cin;
    using std::endl;

int iterativePower(int base, int exponent)
{
    int result = 1;
    for (int i = 1; i <= exponent; ++i)
       result = result * base;

    return result;
}

int recursivePower(int base, int exponent)
{
    int result = 0;
    if (exponent >= 1)
        result = base * recursivePower(base, exponent - 1);
    else
        result = 1;
        
    return result;
}

int iterativeGCD(int a, int b)
{
    int remainder;

    while (b != 0)
    {
        remainder = a % b;
        a = b;
        b = remainder;
    }

    return a;
}

int recursiveGCD(int a, int b)
{
    int remainder, result;
    
    if (b != 0)
    {
        remainder = a % b;
        result = recursiveGCD(b, remainder);
    }
    else
        result = a;
    
    return result;
}

int main()
{
    int x = 3, k = 5;
    
    cout << endl << x << "^" << k << " iteratively = " 
    << iterativePower(x, k) << endl;
    
    cout << endl << x << "^" << k << " recursively = " 
    << recursivePower(x, k) << endl;
    
    int a = 270, b = 192;
    
    cout << endl << a << " and " << b << " GCD is (iteratively) = "
    << iterativeGCD(a, b) << endl;
    
    cout << endl << a << " and " << b << " GCD is (recursively) = "
    << recursiveGCD(a, b) << endl;
}