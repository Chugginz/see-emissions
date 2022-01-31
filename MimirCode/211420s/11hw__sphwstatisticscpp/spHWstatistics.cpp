/**
 *******************************************************************************
 * @file    spHWstatistics.cpp
 * @brief   This program should read values from a vector
 *          to do what the user requested and even read
 *          from files to store into a vector.
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Monday, April 6
 *      Instructor:    Nancy Draganjac
 *
 * @author  Christian Huggins
 * @date    April 6, 2020
 *******************************************************************************
**/

#include<vector>
    using std::vector;
    
#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;

#include<cmath>

#include<iomanip>
    using std::setw;
    
#include<string>
    using std::string;
    
#include<fstream>
    using std::ofstream;
    using std::ifstream;
    using std::getline;

/**
 * @brief       This function calculates the mean of values in a
 *              vector
 *
 * @detailed    Requires a vector in which the data will be read
 *              and stored into "average" which will then be
 *              averaged
 *              
 * @param      data     Vector data is needed as a parameter
 *                      so its data can be read off of it
**/

double calcMean(const vector<int> data)
{
    double average = 0;
    double counter = 0;
    
    for (double number : data)
    {
        average += number;
        counter++;
    }
        
    return (average / counter);
}

/**
 * @brief       This function calculates the standard deviation of
 *              values in a vector
 *
 * @detailed    Requires a vector in which the data will be read
 *              and stored into "stdDev" which will then be
 *              put through the standard deviation formula
 *              
 * @param      data     Vector data is needed as a parameter
 *                      so its data can be read off of it
**/

double calcStandardDeviation(const vector<int> data)
{
    double mean = calcMean(data);
    double counter = 0;
    double stdDev = 0;
    
    for (double number : data)
    {
        stdDev += pow(number - mean, 2);
        counter++;
    }
    
    return sqrt(stdDev / (counter - 1.0));
}

/**
 * @brief       This function displays values from a vector in a
 *              grid like shape evenly spaced, limited 5 per line
 *
 * @detailed    Requires a vector in which the data will be read
 *              and shown to the user, spaced apart evenly, limited
 *              5 per line before a new line is created
 *              
 * @param      data     Vector data is needed as a parameter
 *                      so its data can be read off of it
**/

void displayValues(const vector<int> data)
{
    double counter = 0, i = 0;
    
    while (i < data.size())
    {
        while (counter < 5 && i < data.size())
        {
            if (counter < 4)
                cout << data.at(i) << setw(5);
            else
                cout << data.at(i);
                
            i++;
            counter++;
        }
        
        cout << endl;
        counter = 0;
    }
}

/**
 * @brief       This function calculates the maximum of values in a
 *              vector
 *
 * @detailed    Requires a vector in which the data will be read
 *              and stored into "max" which will be compared to the
 *              next value to ensure it is the maximum number of
 *              all of the data. If it is less than a number,
 *              it will be replaced by that number.
 *              
 * @param      data     Vector data is needed as a parameter
 *                      so its data can be read off of it
**/

int findMaximum(const vector<int> data)
{
    int max = data.at(0);
    
    for (double number : data)
    {
        if (number > max)
            max = number;
    }
    
    return max;
}

/**
 * @brief       This function calculates the minimum of values in a
 *              vector
 *
 * @detailed    Requires a vector in which the data will be read
 *              and stored into "min" which will be compared to the
 *              next value to ensure it is the minimum number of
 *              all of the data. If it is greater than a number,
 *              it will be replaced by that number.
 *              
 * @param      data     Vector data is needed as a parameter
 *                      so its data can be read off of it
**/

int findMinimum(const vector<int> data)
{
    int min = data.at(0);
    
    for (double number : data)
    {
        if (number < min)
            min = number;
    }
    
    return min;
}

/**
 * @brief       This function reads values from a new file and
 *              stores those numbers into a vector
 *
 * @detailed    Using the file name passed through the parameter,
 *              the user will determine a file to read from.
 *              Based on if it exists or not, the function will 
 *              either read the file and its values will be stored
 *              into the vector, or the function will alert the
 *              user that the file does not exist.
 *              
 * @param      data     Vector data is needed as a parameter
 *                      so its data can be read off of it
 * 
 * @param     fileName  A string decided by the user that
 *                      should be the name of a file
**/

void readValues(string fileName, vector<int> &data)
{
    int line;
    
    ifstream file(fileName);
    if (!file)
        cout << "\nThis file does not exist.\n\n";
    else
    {
        data.clear();
        while (file >> line)
            data.push_back(line);
        cout << "\nFile has been read.\n";
    }
}

int main()
{
    //Initializing vector "data" as an int as well as choice
    vector<int>data;
    readValues("vectorTestData.txt", data);
    int choice;
    
    //A do-while loop to execute the prompt before and during loop
    do
    {
        cout << "1. Find maximum" << endl;
        cout << "2. Find minimum" << endl;
        cout << "3. Find mean" << endl;
        cout << "4. Find standard deviation" << endl;
        cout << "5. Display values" << endl;
        cout << "6. Read a new set of values" << endl;
        cout << "7. Exit program" << endl;
        cin >> choice;
        
        //While choice is not an option, prompt the user for a new choice
        while (choice > 7 || choice < 1)
        {
            cout << "\nThat is not a proper choice. Please rechoose.\n";
            cin >> choice;
        }
        //If choice is 1, calculate max
        if (choice == 1)
        {
            cout << "The maximum is " << findMaximum(data) << ".\n";
        }
        //If choice is 2, calculate min
        else if (choice == 2)
        {
            cout << "The minimum is " << findMinimum(data) << ".\n";
        }
        //If choice is 3, calculate mean
        else if (choice == 3)
        {
            cout << "The mean is " << calcMean(data) << ".\n";
        }
        //If choice is 4, calculate standard deviation
        else if (choice == 4)
        {
            cout << "The standard deviation is " << calcStandardDeviation(data)
            << ".\n";
        }
        //If choice is 5, run displayValues function
        else if (choice == 5)
            displayValues(data);
        //If choice is 6, prompt user for file name, look for file,
        // and store file in vector if possible.
        else if (choice == 6)
        {
            string fileName;
            cout << "\nPlease type a file name\n";
            cin >> fileName;
            readValues(fileName, data);
        }
        //If choice is 7, push through loop to end program.
    }   while (choice != 7);
    
    //Inform user program is ending
    cout << "\nExiting program...\n\n";
    
    return 0;
}










