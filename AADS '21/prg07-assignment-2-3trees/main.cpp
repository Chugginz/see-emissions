// ***** main.cpp *****

#include "master.h"

int main (void)
{

   Two3T ttt;  // a 2-3 tree

   int inputs[] = {15,4,20,17,19,16,22,23, 7,8};

   // insert data to the 2-3-tree
   for (int i=0; i<sizeof(inputs)/sizeof(inputs[0]); i++) {
      cout << inputs[i] << " is adding" << endl;
      ttt.add(inputs[i]);
      //cout << inputs[i] << " is added" << endl;
      cout << "Tree:\n"<< ttt << endl;
   }

   /*
   //try to find all the data.  Only print not found for debug.
   for (int i=0; i<sizeof(inputs)/sizeof(inputs[0]); i++) {
      cout << inputs[i] << " to find" << endl;
      if (!ttt.find(inputs[i]) )
          cout << "Not found !!!!!!" << endl;
   }

   //try some unexisting data
   // print only "found" which should not happen.
   cout << "Try unexisting data " << endl;      
   int unexisting[] = {13,5,21,18,30, 1};

   for (int i=0; i<sizeof(unexisting)/sizeof(unexisting[0]); i++) {
      cout << unexisting[i] << " to find" << endl;
      if (ttt.find(unexisting[i]) )
         cout << "found !!!!!!" << endl;
   }
   */
   cout << "Tree:\n"<< ttt << endl;

   //ttt.erase();

   return 0;
}
