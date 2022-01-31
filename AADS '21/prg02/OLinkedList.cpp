// ***** OLinkedList.cpp *****
// ***** ordered *****

#include "master.h"

OLinkedList::OLinkedList (void)
{
   head = nullptr;

   return;
}

OLinkedList::~OLinkedList (void)
{
   erase ();

   return;
}

//erase all nodes
void OLinkedList::erase (void)
{
   cout << "OLinkedList::erase\n";

   while (head)
   {
      Node* nextHead = head->next;
      delete head;
      head = nextHead;
   }

   return;
}



// To remove the node with given value from the list
// input: int el 
// output: bool to indicate el deleted or not (not exist)
/*
bool LinkedList::erase (int el)
{


}
*/


void OLinkedList::write (ostream& outfile) const
{

   Node* current = head;
   while (current != nullptr)
   {
      outfile << *current << endl;
      current = current->next;
   }

   return;
}   

ostream& operator << (ostream& outfile, const OLinkedList& list)
{
   list.write (outfile);

   return outfile;
}