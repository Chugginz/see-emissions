/**
 *******************************************************************************
 * @file    SkipListAdd.cpp
 * @brief   Implementation of Add and Search methods in skip list
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      9/29/2021
 *      Instructor:    Hung-Chi Su
 *
 * @author  Christian Huggins
 * @date    September 29th, 2021
 *******************************************************************************
**/

#include "master.h"

// add node to the list with info in ascending order  
bool SkipList::add(Node* newNode)
{
   // If there is no new node
   if (newNode == nullptr)
      // Return that the function did not add
      return false;  
    
   // If there is no head
   if (head[0] == nullptr){
      // Set the head to the new node
      head[0] = newNode;
      // Set the number of levels used to 1
      nLevelsUsed = 1;
   } else {
      // Create a current pointer to iterate through the skiplist
      Node* current = head[0];
      // Create a previous pointer for placement of new node
      Node* previous = head[0];
      // Create a flag for stopping the loop
      bool sorted = false;

      while (sorted == false){
         // If the head is greater than the new node
         if (head[0]->info > newNode->info){
            // Set the new node's next to what the first head pointer
            // is pointing at
            newNode->next[0] = head[0];
            // Set the first head pointer to point to the new node
            head[0] = newNode;
            // Set the result to sorted
            sorted = true;
         }
         // If current's info is greater than the new node's info
         else if (current == nullptr || current->info > newNode->info){
            // Set the previous node's next to the new node
            previous->next[0] = newNode;
            // Set the new node's next to the current node
            newNode->next[0] = current;
            // Set the flag to ordered
            sorted = true;
         } else {
            // Set the previous pointer to point to current
            previous = current;
            // Set the current pointer to be current's next
            current = current->next[0];
            }
         }
      }
    
    // Set current to initial head
    Node* current = head[0];
    // Set previous to initial head
    Node* previous = head[0];
    // Create a counter
    int counter;
    // While the previous counter is not nullptr
    while (previous != nullptr){
        // Set the counter to 0
        counter = 0;
        // While counter is less than the number of pointers array max
        while (counter < previous->numOfNextPtrs - 1){
            // Set current equal to the previous's next ptr at the counter
            current = previous->next[counter];
            // If the current ptr is not nullptr
            if (current != nullptr){
                // Set current equal to current's next
                current = current->next[counter];
                // Set previous's next at counter + 1 to the current space
                previous->next[counter + 1] = current;
            }
            // Increment counter
            counter++;
        }
        // If the previous ptr's num of next ptrs is a new high
        if (previous->numOfNextPtrs > nLevelsUsed){
            // Set the head at the next nLevelsUsed equal to the new high node
            head[nLevelsUsed] = previous;
            // Increment the nLevelsUsed variable
            nLevelsUsed++;
        }
        // Set previous equal to previous's next
        previous = previous->next[0];
    }
      
   return true;
}

// a helper function to add to a particular level, currLevel.
// not required
/*Node* SkipList::addNext(Node* newNode, Node* prev, int currLevel)  
{
    
}*/

bool SkipList::find(int el) const {
   // Initialize found for flag
   bool found = false;
   // Initialize n for keeping track of head marker
   int n = nLevelsUsed - 1;
   // Initialize current pointer
   Node* current = nullptr;
   // Initialize num for holding number of nexts
   int num;
   
   cout << "find for " << el << endl;

   // While n has not been fully checked and current has no been set
   while (n >= 0 && current == nullptr){
      // If the head's pointer at n is less than el, move to it
      if (head[n]->info <= el){
         // Set current at that head
         current = head[n];
         // Read out the level
         cout << "level: " << n << endl;
         // Read out the current level
         cout << "curr: " << *current << endl;
      } else
         // Decrement down a head pointer
         n--;
   }
   
   // Set the number of next pointers
   num = current->numOfNextPtrs - 1;
   
   // While the result has not be found and there is still a list to check
   while (found == false && num >= 0){
      // If the current info is the searched value
      if (current->info == el)
         // Searched value has been found
         found = true;
      else {
         // If the current's highest next pointer is less than or is el
         // and if current's highest next pointer is not nullptr
         if (current->next[num] != nullptr 
            && current->next[num]->info <= el){
            // Move the current to that
            current = current->next[num];
            // Reset the num
            num = current->numOfNextPtrs - 1;
            // Read out the level
            cout << "level: " << num << endl;
            // Read out the current level
            cout << "curr: " << *current << endl;
         } else
            // Decrement the number
            num--;
        }
   }  

   if (found == true)
        // Say it's found
        cout << "found: " << *current << endl;
    else
        // Say it's not found
        cout << "not found" << endl;

   return found;
}    