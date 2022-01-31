/**
 *******************************************************************************
 * @file    spILsort.cpp
 * @brief   Using given vectors, the program will then perform
 *          s bubble sort, sorting the numbers from greatest
 *          to least and display the before and after vectors.
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Thursday, April 9
 *      Instructor:    Nancy Draganjac
 *
 * @author  Christian Huggins
 * @date    April 9, 2020
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
 * @brief       This function performs a bubble sort that organizes
 *              the values from largest to smallest
 *
 * @detailed    Requires a vector in which the data will be sorted
 *              from largest to smallest by comparison
 *              
 * @param      list     Vector data is needed as a parameter
 *                      so its data can be read off of it
**/

void descendingBubbleSort(vector<int> &list)
{
    int counter = 0;
    int max = list.size();
    bool swap = true;
    
    while (swap == true)
    {
        swap = false;
        for (int i = 0; i <= max - 2; i++)
        {
            if (list.at(i) < list.at(i + 1))
            {
                int temp = list.at(i);
                list.at(i) = list.at(i + 1);
                list.at(i + 1) = temp;
                swap = true;
            }
        }
        
        counter++;
    }
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
    //random testing
    vector<int> list;
    list.push_back(4);
    list.push_back(7);
    list.push_back(2);
    list.push_back(9);
    list.push_back(1);
    list.push_back(1);
    list.push_back(6);
    list.push_back(4);
    list.push_back(7);
    list.push_back(2);
    list.push_back(9);
    list.push_back(1);
    list.push_back(5);
    list.push_back(6);
    list.push_back(8);
    
    //ascending order
    vector<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(2);
    list1.push_back(3);
    list1.push_back(5);
    list1.push_back(5);
    list1.push_back(5);
    list1.push_back(6);
    list1.push_back(7);
    list1.push_back(7);
    list1.push_back(8);
    list1.push_back(8);
    list1.push_back(9);
    list1.push_back(9);
    list1.push_back(9);
    
    //descending order
    vector<int> list2;
    list2.push_back(9);
    list2.push_back(9);
    list2.push_back(9);
    list2.push_back(8);
    list2.push_back(8);
    list2.push_back(7);
    list2.push_back(7);
    list2.push_back(6);
    list2.push_back(5);
    list2.push_back(5);
    list2.push_back(5);
    list2.push_back(3);
    list2.push_back(2);
    list2.push_back(2);
    list2.push_back(1);
    
    //Output for random test
    cout << "Random before: " << endl;
    displayData(list);
    
    descendingBubbleSort(list);
    
    cout << "Random after: " << endl;
    displayData(list);
    
    //Output for ascending test
    cout << "Ascending before: " << endl;
    displayData(list1);
    
    descendingBubbleSort(list1);
    
    cout << "Ascending after: " << endl;
    displayData(list1);
    
    //Output for descending test
    cout << "Descending before: " << endl;
    displayData(list2);
    
    descendingBubbleSort(list2);
    
    cout << "Descending after: " << endl;
    displayData(list2);
    
    return 0;
    
}
