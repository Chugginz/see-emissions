// ***** main.cpp *****

#include "master.h"

int main (void)
{

   int inputs[] = {5,7,8,10,12,17,19,22,28,31,33,35,42,51,59};

   SkipList list1;
   Node* node;
     
   for (int i=0; i<sizeof(inputs)/sizeof(inputs[0]); i++) {
      node = new Node(inputs[i]);  

      //cout << *node << endl;
      //delete node;

      list1.add(node);
      cout << "list1:\n"<< list1 << endl;
   }

   list1.find(33);
   list1.find(70);
   list1.find(10);

   return 0;
}
