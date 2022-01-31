/**
 *******************************************************************************
 * @file    spILalgorithms.cpp
 * @brief   Managing average exam scores using STL
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Thursday, April 30
 *      Instructor:    Nancy Draganjac
 *
 * @author  Christian Huggins
 * @date    April 30, 2020
 *******************************************************************************
**/

#include<iostream>
    using std::endl;
    using std::cout;
    using std::cin;
    
#include<vector>
    using std::vector;
    
#include<numeric>
    using std::accumulate;
    
#include<algorithm>
    using std::copy;
    using std::min_element;
    using std::count;
    
    
void displayVector (const vector<double> &data)
{
    // Display the contents of the vector.
    for (double value : data)
        cout << " " << value;
    cout << endl;    
}

double calculateAverage(const vector<double> &data)
{
    double sum = accumulate(data.begin(), data.end(), 0);
    sum = sum / data.size();
    
    return sum;
}

void dropLowestScore(vector<double> &data)
{
    data.erase(min_element(data.begin(), data.end()));
}


int main()
{
    //Vector #1
    vector<double> data{100, 92, 78, 84, 90};
    displayVector(data);
    
    cout << "The average is: " << calculateAverage(data) << endl;
    cout << "The total number of perfect scores recorded is "
    << count(data.begin(), data.end(), 100) << endl;
    cout << "The total number of scores of 90 recorded is "
    << count(data.begin(), data.end(), 90) << endl;
    
    //Vector #2
    vector<double> copyData(3);
    copy(data.begin() + 1, data.end() - 1, copyData.begin());
    
    displayVector(copyData);
    dropLowestScore(copyData);
    displayVector(copyData);
    cout << "The average is: " << calculateAverage(copyData) << endl;
    cout << "The total number of perfect scores recorded is "
    << count(copyData.begin(), copyData.end(), 100) << endl;
    cout << "The total number of scores of 90 recorded is "
    << count(copyData.begin(), copyData.end(), 90) << endl;
    
    return 0;
}






