/**
 *******************************************************************************
 * @file    spHWtourGuidesReport.cpp
 * @brief   
 *
 * This program allows you to add tours to a list, which include ID
 *  number, number of days touring, and expenses for night and day.
 *  The program then reads the chart back to you.
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Monday, March 2
 *      Instructor:    Draganjac
 *
 * @author  Christian Huggins
 * @date    March 2, 2020
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
    
#include<iomanip>
    using std::setprecision;
    using std::fixed;
    
#include<fstream>
    using std::ofstream;
    using std::ifstream;
    using std::ios;
    using std::getline;
    
#include<string>
    using std::string;

/**
 * @brief       This program gets data for either ID number or
 *              number of days spent touring
 *
 * @detailed    Depending on the max or min, the program will then 
 *              request either number of days spent touring or 
 *              ID number then returning that value
 *              
 * @remarks
 *      This function require an input of either ID number or
 *      days spend touring.
 * 
 * @param        prompt     Uses a string for prompt
 * @param        min     Int min for setting min in function
 * @param[out]   max     Int max for setting max in function
 *
 * @return  Either returns ID number or days spent touring
**/

int getData(string prompt, int min, int max)
{
    

    if (max == 9999)
    {
        int IDnumber;
        
        do
        {
            cout << prompt;
            cin >> IDnumber;
        }   while (IDnumber < min || IDnumber > max);
        
        return IDnumber;
    }
    else
    {
        int lengthOfTour;
        
        do
        {
            cout << prompt;
            cin >> lengthOfTour;
        }   while (lengthOfTour < min || lengthOfTour > max);
    
        return lengthOfTour;
    }
}

/**
 * @brief       This program gets expenses for either the day or 
 *              night
 *
 * @detailed    Depending on the prompt, the function will either 
 *              get the expense for the day or for the night.
 *              
 * @remarks
 *      This function require an input of either a day expense or 
 *      night expense.
 * 
 * @param        prompt     Uses a string for prompt
 * @param        min     Int min for setting min in function
 *
 * @return  Either returns day expense or night expense.
**/


double getExpense(string prompt, double min)
{
    if (prompt == "\nEnter the daily expense: ")
    {
        double dayExpenses;
        
        do
        {
            cout << prompt;
            cin >> dayExpenses;
        }   while (dayExpenses < min);
        
        return dayExpenses;
    }
    else
    {
        double nightExpenses;
        
        do
        {
            cout << prompt;
            cin >> nightExpenses;
        }   while (nightExpenses < min);
        
        return nightExpenses;
    }
}

/**
 * @brief       This program gets the answer of whether or not the 
 *              use has more info to submit.
 *              
 * @remarks
 *      This function require an input of whether or not the user
 *      has more info to submit.
 *
 * @return  Returns the answer of whether or not the user wants to 
 *          add more.
**/

char getMoreData()
{
    char answer;
    
    do
    {
        cout << "\nWould you like to enter more data (Y/N)? ";
        cin >> answer;
    }   while (answer != 'y' && answer != 'Y' && answer != 'n' && 
        answer != 'N');
    
    return answer;
}

/**
 * @brief       This program opens the file originally appended
 *              to read and reads line by line until the end
 *              
 * @remarks
 *      This function uses the getline function to read a line,
 *      continuously couting it until it has reached the end
 *      of the file
**/

void displayReport()
{
    string tourGuideLine;
    ifstream tourGuideData;
    tourGuideData.open("spHWtourGuidesData.txt");
    
    do
    {
        getline(tourGuideData, tourGuideLine, '\n');
        
        if (tourGuideLine != "End")
            cout << tourGuideLine << endl;
    }   while (tourGuideLine != "End");
    
    tourGuideData.close();
}

int main()
{
    int IDnumber, lengthOfTour;
    double dayExpenses, nightExpenses;
    char answer;
    ofstream tourGuideData;
    tourGuideData.open("spHWtourGuidesData.txt", ios::app);
    
    
    
    do
    {
        IDnumber = getData("\nEnter an ID number from "
        "1001 - 9999: ", 1001, 9999);
        lengthOfTour = getData("\nEnter the number of days of the" 
        " tour from 6 - 92: ", 6, 92);
        
        tourGuideData << endl << IDnumber << " " << lengthOfTour << " ";
        
        for (int i = 0; i < lengthOfTour; i++)
        {
            dayExpenses = getExpense("\nEnter the daily expense: ", 0);
            tourGuideData << setprecision(2) << fixed 
                << dayExpenses << " ";

            if (i < lengthOfTour - 1)
            {
                nightExpenses = getExpense("\nEnter the" 
                " nightly expense: ", 0);
                tourGuideData << setprecision(2) << fixed 
                << nightExpenses << " ";
            }
        }
        answer = getMoreData();
        
    }   while (answer == 'y' || answer == 'Y');
    
    if (answer == 'n' || answer == 'N')
    {
        tourGuideData << endl << "End";
        tourGuideData.close();
    }    
    
    displayReport();
    
    return 0;   
}
