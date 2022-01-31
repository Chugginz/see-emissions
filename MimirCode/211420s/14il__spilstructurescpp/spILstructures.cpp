/**
 *******************************************************************************
 * @file    spILstructures.cpp
 * @brief   Receiving player data and sorting it in order of jersey
 *          number while also adding all goals to display total
 *          goals
 *
 * @remarks
 *      Course:        Computer Science 2114, Spring 2020
 *      Due Date:      Thursday, April 23
 *      Instructor:    Nancy Draganjac
 *
 * @author  Christian Huggins
 * @date    April 23, 2020
 *******************************************************************************
**/

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
    
#include<string>
    using std::string;
    
#include<vector>
    using std::vector;
    
#include<iomanip>
    using std::setw;
    using std::left;
    using std::right;

struct playerData
    {
        string name;
        int jerseyNumber, goalsMade;
    };

void getData(vector<playerData> &data)
{
    string firstName, lastName;
    int jerseyNumber, goalsMade;
    
    while (firstName != "zzz")
    {
        cout << "Enter the player's first name (zzz to end): ";
        cin >> firstName;
        if (firstName != "zzz")
        {
            cout << "Enter player's last name: ";
            cin >> lastName;
            do
            {
                cout << "Enter player's jersey number (0 to 99): ";
                cin >> jerseyNumber;
            }   while (jerseyNumber > 99 || jerseyNumber < 0);
            do
            {
                cout << "Enter number of goals made by players: ";
                cin >> goalsMade;
            }   while (goalsMade < 0);
            
            playerData player;
            player.name = lastName + ", " + firstName;
            player.jerseyNumber = jerseyNumber;
            player.goalsMade = goalsMade;
            
            data.push_back(player);
        }
    }
}

void descendingBubbleSort(vector<playerData> &data)
{
    int counter = 0;
    int max = data.size();
    bool swap = true;
    
    while (swap == true)
    {
        swap = false;
        for (int i = 0; i <= max - 2; i++)
        {
            int jerseyNumber1 = data[i].jerseyNumber;
            int jerseyNumber2 = data[i + 1].jerseyNumber;
            
            if (jerseyNumber1 > jerseyNumber2)
            {
                string temp1 = data[i].name;
                int temp2, temp3;
                temp2 = data[i].jerseyNumber;
                temp3 = data[i].goalsMade;
                
                data[i].name = data[i + 1].name;
                data[i].jerseyNumber = data[i + 1].jerseyNumber;
                data[i].goalsMade = data[i + 1].goalsMade;
                data[i + 1].name = temp1;
                data[i + 1].jerseyNumber = temp2;
                data[i + 1].goalsMade = temp3;
                swap = true;
            }
        }
        
        counter++;
    }
}

void displayData(vector<playerData> data)
{
    int counter = 0;
    int size = data.size();
    int totalGoals = 0;
    
    cout << endl << setw(20) << left << "Player Name" << setw(15) 
    << right << "Jersey Number" << setw(7) << "Goals" << endl
    << "------------------------------------------" << endl;
    while (counter < size)
    {
        cout << setw(20) << left << data[counter].name << setw(15) 
        << right << data[counter].jerseyNumber << setw(7) 
        << data[counter].goalsMade << endl;
    
        counter++;
    }
    
    counter = 0;
    while (counter < size)
    {
        totalGoals += data[counter].goalsMade;
        counter++;
    }
    
    cout << endl << "Total Goals: " << totalGoals << endl;
}

int main()
{
    vector<playerData> data;
    
    getData(data);
    descendingBubbleSort(data);
    displayData(data);
    
    return 0;
}






