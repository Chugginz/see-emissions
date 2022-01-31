// ***** OLinkedList.cpp *****
// ***** ordered *****

#include "master.h"

// add node to the list with info in ascending order 
// input: Node* newNode
// output: true if newNode is valide
//         false, otherwize 
bool OLinkedList::add(Node* newNode)
{
   // If there is no head, initialize one and it's next
   if (head == nullptr){
      // Initialize head to be the new node
      head = newNode;
      // Set the next to nullptr for future additions
      head->next = nullptr;
   } else{
      // Initialize a current pointer
      Node* current = head;
      // Initialize a previous pointer
      Node* previous = head;
      // Initialize boolean flag for when list is ordered
      bool ordered = false;

      // If the head is greater than the new node, make new node head
      if (head->info > newNode->info){
         // Set the new node's next to point to the current head
         newNode->next = head;
         // Set the new head to be the new node
         head = newNode;
         // Set ordered to true
         ordered = true;
      }

      // While the flag is not true
      while (ordered == false){
         // If the current (head initial) is less than the new node
         if (current->info < newNode->info){
            // If the next value is nullptr
            if (current->next == nullptr){
               // Set the current's next to the new node value
               current->next = newNode;
               // Set the boolean flag to true
               ordered = true;
            }
            else{
               // Set previous to the current
               previous = current;
               // Set current to the next
               current = current->next;
            }
         } else{
            // new node's next is set to the current pointer
            newNode->next = current;
            // set the previous pointer's next to point to new node
            previous->next = newNode;
            // Set boolean flag to true for ordered
            ordered = true;
         }
      }
   }
   
   return newNode == nullptr;
}
