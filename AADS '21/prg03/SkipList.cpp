// ***** SkipList.cpp *****

#include "master.h"

SkipList::SkipList (void)
{

   for (int i=0; i< MaxNumberOfLists; i++) {
      head[i] = nullptr;
   }
   nLevelsUsed = 0; 

}

SkipList::~SkipList (void)
{
   erase ();

   return;
}

void SkipList::erase (void)
{
   cout << "SkipList::erase\n";

   Node* tmp = head[0];  //use the layer-0 to remove nodes
   while (tmp)
   {
      Node* nextHead = tmp->next[0];
      delete tmp;
      tmp = nextHead;
   }

   // reset
   // clear the head[] 
   for (int i=0; i< nLevelsUsed; i++) {  
      head[i] = nullptr;
   }

   nLevelsUsed=0;

   return;
}


// To remove the node with given value from the list
// input: int el 
// output: bool to indicate el deleted or not (not exist)

bool SkipList::eraseNode(int el)
{
   // Initialize found for flag
   bool found = false;
   // Initialize n for keeping track of head marker
   int n = nLevelsUsed - 1;
   // Initialize current pointer
   Node* current = nullptr;
   // Create previous pointer
   Node* previous = nullptr;
   // Initialize num for holding number of nexts
   int num;
   
   cout << "find for " << el << endl;

   // While n has not been fully checked and current has no been set
   while (n >= 0 && current == nullptr){
      // If the head's pointer at n is less than el, move to it
      if (head[n]->info <= el){
         // Set current at that head
         current = head[n];
      } else
         // Decrement down a head pointer
         n--;
   }
   
   // Set the number of next pointers
   num = current->numOfNextPtrs - 1;
   
   // While the result has not be found and there is still a list to check
   while (found == false && num >= 0){
      // If the current info is the searched value
      if (current->info == el){
         // Searched value has been found
         found = true;
         // Delete the node
         if (current == head[n]){
            head[n] = current->next[0];
            delete current;
            current = nullptr;
         } else{
            previous->next[0] = current->next[0];
            delete current;
            current = nullptr;
         }
      } else {
         // If the current's highest next pointer is less than or is el
         // and if current's highest next pointer is not nullptr
         if (current->next[num] != nullptr 
            && current->next[num]->info <= el){
            // set previous to current
            previous = current;
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

   if (found == true){
      // While not all later nodes have not been restructured
      while (current != nullptr){
         // Run the sequence operation on the node
         current->mySeq();
         // Move to the next node
         current = current->next[0];
      }

   // Readjusting all next pointers
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
   }

   return found;
}


void SkipList::write (ostream& outfile) const
{

   Node* current = head[0];
   outfile << "current # of levels is " << nLevelsUsed << endl;
   while (current != nullptr)
   {
      outfile << *current << endl;
      current = current->next[0];
   }

   return;
}   

ostream& operator << (ostream& outfile, const SkipList& list)
{
   list.write (outfile);

   return outfile;
}