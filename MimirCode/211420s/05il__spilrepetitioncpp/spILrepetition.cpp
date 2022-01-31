/**
 *******************************************************************************
 * @file    spILrepetition.cpp
 * @brief   Reversing a number read from a file, then writing to a new one
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Thursday, February 13
 *      Instructor:    Nancy Draganjac
 *
 * @author  Christian Huggins
 * @date    February 13, 2020
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
    
#include<fstream>
    using std::ifstream;
    using std::ofstream;
    
#include<iomanip>
    using std::setprecision;
    
int main()
{

    ifstream numberText("numbers.txt");
    if (numberText.is_open())
    {
        ofstream reversed;
        reversed.open("reversed.txt");
    
        int number, output, newNumber, lastNumber;
    
        while (! numberText.eof())
        {
            numberText >> number;
            lastNumber = 0;
            newNumber = 0;
            output = 0;
            
            while (number * 11 >= 10)
            {
                lastNumber = number % 10;
                
                newNumber = output;
                
                output = (newNumber * 10) + lastNumber;
                
                number = number / 10;
            }
            
            reversed << output << endl;
            
        }
    
        reversed.close();
        numberText.close();
    }
    else
        cout << "No data available";
    
    return 0;
}
