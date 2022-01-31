// ***** main.cpp *****

#include "master.h"

int main (void)
{

   BST bst;

   int inputs[] = {15,4,20,17,19,16,22,23, 7,8};

   for (int i=0; i<sizeof(inputs)/sizeof(inputs[0]); i++) {
      bst.add(inputs[i]);
      cout << inputs[i] << " is added" << endl;
   }

   cout << "Tree:\n"<< bst << endl;

   bst.BSTswap(23);
   cout << "after swapped 23, Tree:\n" << bst << endl;
   bst.erase();

   cout << "rebuild the tree" << endl;
   for (int i=0; i<sizeof(inputs)/sizeof(inputs[0]); i++) {
      bst.add(inputs[i]);
      //cout << inputs[i] << " is added" << endl;
   }
   cout << "Tree:\n"<< bst << endl;

   bst.BSTswap(20);
   cout << "after swapped 20, Tree:\n" << bst << endl;
   bst.erase();

   cout << "rebuild the tree" << endl;
   for (int i=0; i<sizeof(inputs)/sizeof(inputs[0]); i++) {
      bst.add(inputs[i]);
      //cout << inputs[i] << " is added" << endl;
   }
   cout << "Tree:\n"<< bst << endl;

   bst.BSTswap(4);
   cout << "after swapped 4, Tree:\n" << bst << endl;
   bst.erase();

   cout << "rebuild the tree" << endl;
   for (int i=0; i<sizeof(inputs)/sizeof(inputs[0]); i++) {
      bst.add(inputs[i]);
      //cout << inputs[i] << " is added" << endl;
   }
   cout << "Tree:\n"<< bst << endl;
   
   bst.BSTswap(15);
   cout << "after swapped 15, Tree:\n" << bst << endl;
   bst.erase();

   return 0;
}
