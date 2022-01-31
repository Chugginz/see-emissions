// ***** main.cpp *****

#include "master.h"

int main (void)
{
   //ofstream DBG ("debug.txt");

   OLinkedList list1;
   list1.add (new Node (1));
   cout << "after add 1:\n" 
        << list1 << endl << endl;

   list1.add (new Node (2));
   cout << "after add 2:\n" 
        << list1 << endl << endl;
   list1.add (new Node (5));
   cout << "after add 5:\n" 
        << list1 << endl << endl;   

   list1.add (new Node (4));
   cout << "after add 4:\n" 
        << list1 << endl << endl;
   list1.add (new Node (3));
   cout << "after add 3:\n" 
        << list1 << endl << endl;

   list1.add (new Node (0));
   cout << "after add 0:\n" 
        << list1 << endl << endl;

   list1.add (new Node (6));
   cout << "list1 listings (0,1,2,3,4,5,6):\n" 
        << list1 << endl << endl;

   list1.erase ();
   cout << "list1 listings after erase:\n" 
        << list1 << endl << endl;

   //DBG.close ();

   return 0;
}