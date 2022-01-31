/**
 *******************************************************************************
 * @file    spILfileIO.cpp
 *
 * Four exams scores and the exams' points possible are obtained via console 
 * input as integers.  The average is calculated based on the sum of the scores 
 * earned divided by the sum of the points possible. //add more details 
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      19, February 2020
 *      Instructor:    Draganjac
 *
 * @author  Christian Huggins
 * @date    2/28/20
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
    
#include<fstream>
    using std::ofstream;
    using std::ifstream;
    using std::ios;

int main()
{
    float scores, pointsPossible, score, points;
    
    cout << "Enter your first score: ";
    cin >> scores;
    cout << "Enter your first points possible: ";
    cin >> pointsPossible;
    cout << "Enter your second score: ";
    cin >> score;
    cout << "Enter your second points possible: ";
    cin >> points;
    
    pointsPossible += points;
    scores += score;
    
    cout << "Enter your third score: ";
    cin >> score;
    cout << "Enter your third points possible: ";
    cin >> points;
    
    pointsPossible += points;
    scores += score;
    
    cout << "Enter your fourth score: ";
    cin >> score;
    cout << "Enter your fourth points possible: ";
    cin >> points;
    
    pointsPossible += points;
    scores += score;
    
    scores = scores / 4;
    pointsPossible = pointsPossible / 4;
    
    float averageGrade;
    
    averageGrade = (scores / pointsPossible) * 100;
    
    ofstream data;
    data.open("03ILdata.txt", ios::app);
    
    data << averageGrade;
    
    data.close();
    
    ifstream ILdata;
    ILdata.open("03ILdata.txt", ios::in);
    
    float final, lab, classAverage;
    
    ILdata >> final;
    ILdata >> lab;
    
    classAverage = (final * .17) + (lab * .33) + (averageGrade * .5);
    
    cout << "Your grade average is " << classAverage << endl;
    
    ILdata.close();
    
    return 0;
}

