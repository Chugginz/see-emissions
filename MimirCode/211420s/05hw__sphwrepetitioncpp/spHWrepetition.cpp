/**
 *******************************************************************************
 * @file    spHWrepetition.cpp
 * @brief   Add two numbers while also increasing both
 *
 * @assignment  hw_05
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Monday, February 17
 *      Instructor:    Nancy Draganjac
 *
 * @author  Christian Huggins
 * @date    Sunday, February 16
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;

#include<fstream>
    using std::ofstream;

int main()
{
    //Get two numbers for the sets
    int number1, number2;
    cout << "Enter a number for the first set: ";
    cin >> number1;
    cout << "\nEnter a number for the second set: ";
    cin >> number2;
    
    //Open file "addTable.txt for reading"
    ofstream inTable;
    inTable.open("addTable.txt");
    
    inTable << "\t\t";
    
    // While counter is <= 10, send number to file, increase number
    //  ,and increase counter
    for (int count = 1; count <= 10; ++count)
        {
            inTable << number1 << "\t";
            number1++;
        }
    
    if (number1 < 100 && number2 < 100)
        inTable << endl << "    ------------------------------------------";
    else if (number1 < 1000 && number2 < 1000)
        inTable << endl << "    -------------------------------------------";
    else
        inTable << endl << "    -------------------------------------------"
        << "-------------------------------------";
        
        
    //While counter <= 10, output to file number 2, and
    //  use next loop. Once done, add 1 and repeat.
    for (int j = 1; j <= 10; ++j)
        {
            inTable << endl << number2 << " |\t";
            
            //While counter > 0, add the numbers together
            //  and subtract counter to get correct number.
            //  Then add and repeat
            for (int k = 10; k > 0; --k)
                inTable << (number2 + (number1 - k)) << "\t";
            
            number2++;
        }
    
    return 0;
}
