/**
 *******************************************************************************
 * @file    pointers_inlab.cpp
 * @brief   
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      9/21/2020
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    September 21, 2020
 *******************************************************************************
**/

#include<iomanip>
    using std::fixed;
    using std::setprecision;
    
#include<iostream>
    using std::cout;
    using std::endl;
    using std::cin;

#include "DynamicArray.h"

void displayArray(const int* const array, int size)
{
   const int* const end = array + size;                         // mark the end of the array
   cout << "Array values:  \n";
   for (const int* current = array; current != end; current++){ // "moves" current toward end
      cout << *current << endl;
   }
   cout << endl;
}

int* getData (int& sizeOfDynArray)
{
   cout << "How many more values would you like to enter?  ";
   cin  >> sizeOfDynArray;
   int* dynamicArray = new int[sizeOfDynArray];
   for (int i = 0; i < sizeOfDynArray; ++i){
      cout << "Enter value " << (i + 1) << ":  ";
      cin  >> dynamicArray[i];
   }
   return dynamicArray;
}

int main(){
    
    //Checkpoint 1
    int  values[5] = {325, 879, 120, 459, 735};
    int* valuePtr  = values;  // valuePtr is a pointer to values.
    
    cout << "valuePtr:   " << valuePtr  << endl;
    cout << "*valuePtr:  " << *valuePtr << endl << endl;
    
    double  payRate = 10.25;
    double* ratePtr = &payRate;
    cout << fixed << setprecision(2);
    cout << "address of payRate:      " << ratePtr  << endl;
    cout << "value stored in payRate: " << *ratePtr << endl << endl;
    
    *ratePtr = 12.50;
    cout << "altered value of payRate:  " << payRate << endl << endl;
    
    double grossPay;
    grossPay = payRate * 40;
    cout << "grossPay calculated with payRate:   " << grossPay << endl;
    grossPay = *ratePtr * 40;
    cout << "grossPay calculated using ratePtr:  " << grossPay << endl << endl;
    
    cout << "values[0]:  " << values[0] << endl;
    cout << "*valuePtr:  " << *valuePtr << endl;
    valuePtr++;
    cout << "values[1]:  " << values[1] << endl;
    cout << "*valuePtr after increment:  " << *valuePtr << endl << endl;
    
    //Checkpoint 2
    displayArray(values, 5);
    
    double* price = new double;
    *price = 88.25;
    cout << "address of price:  " <<  price << endl;
    cout << "value of price:    " << *price << endl << endl;
    delete price;     // de-allocates the memory (the OS will mark it as "available")
    price = nullptr;  // null the pointer so that it cannot be dereferenced again.
    
    int sizeOfDynArray;
    int* dynArray = getData(sizeOfDynArray);
    displayArray(dynArray, sizeOfDynArray);
    delete [] dynArray;
    dynArray = nullptr;   // null the pointer for safety.
    
    //Checkpoint 3
    DynamicArray my_array(4);
    for(int i = 0; i < my_array.size(); ++i){
        my_array.at(i) = 100;
    }
    
    return 0;
}