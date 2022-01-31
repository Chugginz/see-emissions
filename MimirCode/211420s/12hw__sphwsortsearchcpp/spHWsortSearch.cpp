/**
 *******************************************************************************
 * @file    spHWsortSearch.cpp
 * @brief   A program that will use selection sorting to organize
 *          the vector from smallest to largest and then locate
 *          a variable if it is in the vector.
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Monday, April 13
 *      Instructor:    Nancy Draganjac
 *
 * @author  Christian Huggins
 * @date    April 13, 2020
 *******************************************************************************
**/

#include<iostream>
    using std::cin;
    using std::cout;
    using std::endl;
    
#include<vector>
    using std::vector;

#include<iomanip>
    using std::setw;

/**
 * @brief       This function performs a selection sort that 
 *              organizes the values from smallest to largest
 *
 * @detailed    Requires a vector in which the data will be sorted
 *              from smallest to largest by comparison
 *              
 * @param      data     Vector data is needed as a parameter
 *                      so its data can be read off of it
**/

void sortVectorViaSelection(vector<int> &data)
{
    int max = data.size();
    bool swap = true;
    int counter = 0;
    
    
    while (swap == true)
    {
        int minimum = data.at(counter);
        int location = counter;
        int i = counter;
        swap = false;
        
        while (i < max)
        {
            if (data.at(i) < minimum)
            {
                swap = true;
                location = i;
                minimum = data.at(i);
            }
            i++;
        }
        
        int temp = minimum;
        data.at(location) = data.at(counter);
        data.at(counter) = temp;
        counter++;
    }
}

/**
 * @brief       This function performs a binary search that will
 *              figure out the fastest way to locate a number
 *              and inform the user if it is in the vector
 *
 * @detailed    Requires a vector in which the function will search
 *              to determine if the number given is located in
 *              the function
 *              
 * @param      data         Vector data is needed as a parameter
 *                      so its data can be read off of it
 *
 * @param      valueToFind  A value to find is necessary to search
 *                      the vector for the number
**/

int binarySearchOfVector(const vector<int> data, int valueToFind)
{
    int max = data.size();
    int halfway = max / 2;
    int index = -1;
    
    if (valueToFind >= data.at(halfway))
    {
        for (int i = halfway; i < max; i++)
        {
            if (valueToFind == data.at(i))
                index = i;
        }
    }
    else
    {
        for (int i = 0; i < halfway; i++)
        {
            if (valueToFind == data.at(i))
                index = i;
        }
    }
    
    return index;
    
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

void displayData(const vector<int> data)
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


int main()
{
    //Random order test
    vector<int> data{4, 7, 2, 9, 8, 1, 7, 3, 5, 3};
    
    sortVectorViaSelection(data);
    displayData(data);
    
    //Should be 4
    int index = binarySearchOfVector(data, 4);
    
    cout << "The index of the value you are trying to find is "
    << index << endl;
    
    //Ascending order test
    vector<int> data1{1, 4, 4, 5, 6, 6, 7, 8, 9, 9};
    
    sortVectorViaSelection(data1);
    displayData(data1);
    
    //Should be 5
    index = binarySearchOfVector(data1, 6);
    
    cout << "The index of the value you are trying to find is "
    << index << endl;
    
    return 0;
}