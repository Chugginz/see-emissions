/**
 *******************************************************************************
 * @file    spILvectors.cpp
 * @brief   Creating a list of scores, curving them, then creating a class 
 *          average with functions.
 *
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Thursday, April 2
 *      Instructor:    Nancy Draganjac
 *
 * @author  Christian Huggins
 * @date    Thursday, April 2
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
    
#include<vector>
    using std::vector;
    
#include<string>
    using std::string;
    
#include<fstream>
    using std::ofstream;
    using std::ifstream;
    using std::fstream;
    using std::ios;
    
void getAverages(vector<double> &average)
{
    int number = 0;
    
    while (number >= 0)
    {
        cout << "Enter a number to add to the average (negative to stop): ";
        cin >> number;
        
        if (number >= 0)
            average.push_back(number);
    }
}

void storeAverages(vector<double> average, string name)
{
    ofstream nameFile;
    nameFile.open(name);
    
    for (double data : average)
    {
        nameFile << data << endl;
    }
    
    nameFile.close();
}

void curveAverage(vector<double> &average, float curve)
{
    for (double counter = 0; counter < average.size(); counter++)
        average.at(counter) = average.at(counter) + curve;
}

double calculateClassAverage(vector<double> average)
{
    double counter = 0;
    double classAverage = 0;
    
    while (counter < average.size())
    {
        classAverage += average.at(counter);
        counter++;
    }
    
    classAverage = classAverage / counter;
    
    return classAverage;
}

int main()
{
    vector<double>average;
    
    getAverages(average);
    
    float curve;
    cout << "\nEnter a value to curve the class: ";
    cin >> curve;
    curveAverage(average, curve);
    
    double classAverage = calculateClassAverage(average);
    cout << "\nThe class average is " << classAverage << endl;
    
    string fileName;
    cout << "\nEnter a file name to use: ";
    cin >> fileName;
    storeAverages(average, fileName);
    
    return 0;
}


