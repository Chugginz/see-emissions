// ***** main.cpp *****

#include "master.h"

int main (void)
{
   LinkedList list1;
   list1.addAtHead (new Node (1));
   list1.addAtHead (new Node (2));
   list1.addAtTail (new Node (5));
   cout << "list1 listings (adding head: 1, head: 2 & tail: 3):\n" 
        << list1 << endl << endl;

   LinkedList list2;
   list2.addAtTail (new Node (1));
   list2.addAtTail (new Node (2));
   list2.addAtHead (new Node (3));
   cout << "list2 listings (adding tail: 1, tail: 2 & head: 3):\n"
        << list2 << endl << endl;

   Node* oldHead = list1.removeFromHead ();
   if (oldHead != 0)
      cout << "removed from head of list 1:\n" << *oldHead << endl
           << "list1:\n" << list1 << endl;
   else
      cout << "remove from head unsuccessful!\n";

   cout << "\nlist 2 to be erased!\n";
   list2.eraseAll ();
   cout << "list2 after eraseAll:\n" 
        << list2 << endl << endl;

   return 0;
}