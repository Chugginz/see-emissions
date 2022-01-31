/**
 *******************************************************************************
 * @file    LinkedList.cpp
 * @brief   Implementation file for code in header file
 *
 * @remarks
 *      Course:        Alg & Adv Data Strucs
 *      Due Date:      09/01/2021
 *      Instructor:    Dr. Hung-Chi Su
 *
 * @author  Christian Huggins
 * @date    September 1st, 2021
 *******************************************************************************
**/

// ***** unordered *****

#include "master.h"

LinkedList::LinkedList (void)
{
   head = nullptr;
   tail = nullptr;

   return;
}

LinkedList::~LinkedList (void)
{
   eraseAll();

   return;
}

void LinkedList::eraseAll (void)
{
   cout << "LinkedList::eraseAll\n";

   while (head)   //when head is a valid node (not nullptr)
   {
      Node* nextHead = head->next;
      delete head;
      head = nextHead;
   }

   tail = nullptr;

   return;
}

//return the head and remove it from the list
Node* LinkedList::removeFromHead (void)
{
   Node* oldHead = head;
   if (oldHead != nullptr)
   {
      head = oldHead->next;
      if (head == nullptr)
         tail = nullptr;
      else // head != nullptr
         oldHead->next = nullptr;  // NOTE: oldHead already compared against nullptr!!!!!
   }
   /*  what to do if empty?
   else {

   }
   */
   return oldHead;
}

//return false if nullptr is given to add
bool LinkedList::addAtHead (Node* newHead)
{
   //If there is already a head
   if (head != nullptr)
      //Set new head's next to the current head
      newHead->next = head;
   else
      //Otherwise, a tail has not been established
      tail = newHead;
   
   //Set the head pointer to the new head
   head = newHead;

   //Return the new head if it does not equal nullptr
   return newHead != nullptr;
}

//return false if nullptr is given to add
bool LinkedList::addAtTail (Node* newTail)
{
   //If there is now tail
   if (tail == nullptr)
      //A head has not been established so set one
      head = newTail;
   else
      //Otherwise, set the old tail's next to point to the new tail
      tail->next = newTail;

   //Set the tail to point to new tail
   tail = newTail;

   //Return the new tail if it does not equal nullptr
   return newTail != nullptr;
}

// To remove the node with given value from the list
// input: int el 
// reunt: bool to indicate el deleted or not (not exist)
bool LinkedList::erase (int el)
{
   //Initialize current pointer that points to the beginning of the lis
   Node* current = head;
   //Initialize a previous pointer
   Node* previous;
   //Initialize a result of type bool as false initially
   bool result = false;

   //While the current pointer is not the desired value to be erased and
   // current is not nullptr
   while (current->info != el && current != nullptr){
      //Make the previous pointer point to the previous current
      previous = current;
      //Set the new current to be the next value
      current = current->next;
   }

   //If the info matches the desired value to be erased
   if (current->info == el){
      //Set the previous's node's next to point to current node's next
      previous->next = current->next;
      //Delete current
      delete current;
      //Set to nullptr so it's not accessed accidentally
      current = nullptr;
      //Set the result to true
      result = true;
   }

   //Self explanatory
   return result;
}

void LinkedList::write (ostream& outfile) const
{
   Node* current = head;
   while (current != nullptr)
   {
      outfile << *current << endl;
      current = current->next;
   }

   return;
}   

ostream& operator << (ostream& outfile, const LinkedList& list)
{
   list.write (outfile);

   return outfile;
}