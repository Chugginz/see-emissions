/**
 *******************************************************************************
 * @file    spILrefParameters.cpp
 * @brief   Overloading functions sort() to sort 2, 3, and 4 numbers from least
 *          to greatest.
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Thursday, March 5
 *      Instructor:    Draganjac
 *
 * @author  Christian Huggins
 * @date    March 5, 2020
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
    

void sort(int &smallNum, int &largeNum)
{  
    int numHolder = 0;
    
    cout << "\nEnter a number: ";
    cin >> smallNum;
    cout << "\nEnter another number: ";
    cin >> largeNum;
    
    if (smallNum > largeNum)
    {
        numHolder = smallNum;
        smallNum = largeNum;
        largeNum = numHolder;
    }
}

void sort(int &smallestNum, int &smallNum, int &largeNum)
{
    int numHolder = 0;
    
    cout << "\nEnter a number: ";
    cin >> smallestNum;
    cout << "\nEnter another number: ";
    cin >> smallNum;
    cout << "\nEnter another number: ";
    cin >> largeNum;
    
    if (smallestNum > smallNum || smallestNum > largeNum)
    {
        if (smallestNum >= largeNum)
        {
            numHolder = smallestNum;
            smallestNum = largeNum;
            largeNum = numHolder;
        }
        if (smallestNum >= smallNum)
        {
            numHolder = smallestNum;
            smallestNum = smallNum;
            smallNum = numHolder;
        }
        if (smallNum >= largeNum)
        {
            numHolder = smallNum;
            smallNum = largeNum;
            largeNum = numHolder;
        }
    }
}

void sort(int &smallestNum, int &smallNum, int &largeNum, int &largestNum)
{
    int numHolder;
    
    cout << "\nEnter a number: ";
    cin >> smallestNum;
    cout << "\nEnter another number: ";
    cin >> smallNum;
    cout << "\nEnter another number: ";
    cin >> largeNum;
    cout << "\nEnter another number: ";
    cin >> largestNum;
    
    if (smallestNum >= largestNum)
    {
        numHolder = smallestNum;
        smallestNum = largestNum;
        largestNum = numHolder;
    }
    if (smallestNum >= largeNum)
    {
        numHolder = smallestNum;
        smallestNum = largeNum;
        largeNum = numHolder;
    }
    if (smallestNum >= smallNum)
    {
        numHolder = smallestNum;
        smallestNum = smallNum;
        smallNum = numHolder;
    }
    if (smallNum >= largestNum)
    {
        numHolder = smallNum;
        smallNum = largestNum;
        largestNum = numHolder;
    }
    if (smallNum >= largeNum)
    {
        numHolder = smallNum;
        smallNum = largeNum;
        largeNum = numHolder;
    }
    if (largeNum >= largestNum)
    {
        numHolder = largeNum;
        largeNum = largestNum;
        largestNum = numHolder;
    }
}

int main()
{
    int smallNum, largeNum;
    sort(smallNum, largeNum);
    cout << endl << smallNum << " - Small Number" << endl;
    cout << largeNum << " - Large Number" << endl;
    
    int smallestNum;
    sort(smallestNum, smallNum, largeNum);
    cout << endl << smallestNum << " - Smallest Number" << endl;
    cout << smallNum << " - Small Number" << endl;
    cout << largeNum << " - Large Number" << endl;
    
    int largestNum;
    sort(smallestNum, smallNum, largeNum, largestNum);
    cout << endl << smallestNum << " - Smallest Number" << endl;
    cout << smallNum << " - Small Number" << endl;
    cout << largeNum << " - Large Number" << endl;
    cout << largestNum << " - Largest Number" << endl;
    
    
    return 0;
}