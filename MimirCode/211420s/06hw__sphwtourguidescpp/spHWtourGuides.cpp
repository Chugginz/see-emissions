/**
 *******************************************************************************
 * @file    spHWtourGuides.cpp
 * @brief   Brief description of what this file contains shall be placed here.
 *
 * More general information about what this program or project will do shall be
 * placed here (the file containing main() is usually the first place a programmer
 * would look for information about a large program with many source files).
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Monday, February 24
 *      Instructor:    Draganjac
 *
 * @author  Christian Huggins
 * @date    Wednesday, February 19
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::end;
    
#include<fstream>
    using std::ofstream;
    using std::ifstream;
    using std::fstream;
    using std::ios;
    
int main()
{
    fstream tourGuidesData;
    
    tourGuidesData.open("spHWtourGuidesData.txt", ios::app);
  
    long int id_number, tourLength, counter;
    counter = 1;
    
    float dayExpense, accommodationExpense;
    
    char choice;
    
    do
    {
        tourGuidesData << "\n";
        
        do
        {
            cout << "Enter employee ID number (1001 - 9999): ";
            cin >> id_number;
        }   while (id_number < 1001 || id_number > 9999);
        
        tourGuidesData << id_number << " ";
        
        do
        {
            cout << "Enter length of tour (6 - 92): ";
            cin >> tourLength;
        }   while (tourLength < 6 || tourLength > 92);
        
        tourGuidesData << tourLength << " ";
        counter = 1;
        
        while (counter <= 7)
        {
            do
            {
                cout << "Enter expenses for day " << counter << " (0.00 or more): ";
                cin >> dayExpense;
            }   while (dayExpense < 0.00);
            
            tourGuidesData << dayExpense << " ";
            counter++;
        }
        
        counter = 1;
        
        while (counter <= 6)
        {
            do
            {
                cout << "Enter accommodation expense for night " << counter
                << " (0.00 or more): ";
                cin >> accommodationExpense;
            }   while (accommodationExpense < 0.00);
            
            tourGuidesData << accommodationExpense << " ";
            counter++;
        }
        do
        {
            cout << "Is there more data to add (Y or N)? ";
            cin >> choice;
        }   while (choice != 'y' && choice != 'Y' && choice != 'n' &&
            choice != 'N');
            
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}
