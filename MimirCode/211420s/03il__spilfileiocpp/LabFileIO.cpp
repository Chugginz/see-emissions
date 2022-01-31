#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;


int main()
{
    float scores, pointsPossible, score, points;
    
    cout << "Enter your first score: ";
    cin >> scores;
    
    cout << "Enter your second score: ";
    cin >> score;
    
    scores += score;
    
    cout << "Enter your third score: ";
    cin >> score;
    
    scores += score;
    
    cout << "Enter your fourth score: ";
    cin >> score;
    
    scores += score;
    
    
    
    
    
    
        

    
    cout << "Enter your first points possible: ";
    cin >> pointsPossible;
    
    cout << "Enter your second points possible: ";
    cin >> points;
    
    pointsPossible += points;
    
    cout << "Enter your third points possible: ";
    cin >> points;
    
    pointsPossible += points;
    
    cout << "Enter your fourth points possible: ";
    cin >> points;
    
    pointsPossible += points;
    
    
    scores = scores / 4;
    pointsPossible = pointsPossible / 4;
    
    float averageGrade;
    
    averageGrade = (scores / pointsPossible) * 100;
    
    cout << "Your average score is " << averageGrade << endl;
    
    return 0;
}
