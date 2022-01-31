/**
 *******************************************************************************
 * @file    spILselection.cpp
 * @brief   This will allow a user to choose a month and day
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Wednesday, February 6
 *      Instructor:    Gidget Schrivner
 *
 * @author  Christian Huggins
 * @date   February 6, 2020
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
    
/**
int main()
{
    double month;
    cout << "Enter a number for a month: ";
    cin >> month;

    if (month == 1)
        cout << "\nJanuary has 31 days.\n";
    else if (month == 2)
    {
        int year;
        cout << "Enter the year: ";
        cin >> year;
        if ((year % 100) == 0)
        {
            if ((year % 400) == 0)
            {    
                cout << "\nFebruary in the year of " << year << " has 29 "
                << "days.\n";
            }
            else
            {
                cout << "\nFebruary in the year of " << year << " has 28 "
                << "days.\n";
            }
        }
        else if ((year % 100) < 0)
        {
            if ((year % 4) == 0)
            {    
                cout << "\nFebruary in the year of " << year 
                << " has 29 days.\n";
            }
        }
        else
            cout << "\nFebruary in the year of " << year << " has 28 days.\n";
    }
    else if (month == 3)
        cout << "\nMarch has 31 days.\n";
    else if (month == 4)
        cout << "\nApril has 30 days.\n";
    else if (month == 5)
        cout << "\nMay has 31 days.\n";
    else if (month == 6)
        cout << "\nJune has 30 days.\n";
    else if (month == 7)
        cout << "\nJuly has 31 days.\n";
    else if (month == 8)
        cout << "\nAugust has 31 days.\n";
    else if (month == 9)
        cout << "\nSeptember has 30 days.\n";
    else if (month == 10)
        cout << "\nOctober has 31 days.\n";
    else if (month == 11)
        cout << "\nNovember has 30 days.\n";
    else
        cout << "\nDecember has 31 days.\n";
    
    return 0;
}
**/

int main()
{
    double month;
    cout << "Enter a number for a month: ";
    cin >> month;

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
        || month == 10 || month == 12)
            cout << "\nJanuary has 31 days.\n";
    else if (month == 2)
    {
        int year;
        cout << "Enter the year: ";
        cin >> year;
        
        if ((year % 400) == 0 && (year % 100) == 0)
        {    
            cout << "\nFebruary in the year of " << year << " has 29 "
                << "days.\n";
        }
        else
        {
            if ((year % 100) != 0 && (year % 4) == 0)
            {
                cout << "\nFebruary in the year of " << year << " has 29 "
                    << "days.\n";
            }
            else
            {
                cout << "\nFebruary in the year of " << year << " has "
                    << "28 days.\n";
            }
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        cout << "\nThis month has 30 days.\n";
    
    return 0;
}



