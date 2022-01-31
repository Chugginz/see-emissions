// ***** Node.cpp *****

#include "master.h"

Node::Node (int el) 
{
   info = el;
   numOfNextPtrs=mySeq();                 // to get the number of next pointers
   next = new Node*[numOfNextPtrs];       //to have next[numOfNextPtrs]
   for (int i=0; i<numOfNextPtrs; i++)    //initialization
      next[i] = nullptr;
}

Node::~Node(void) {
   //cout << "info=" <<info << " is deleted\n";
   delete[] next;
}

//generate the sequence of layers in each node for the perfect skip list if data were sorted
int Node::mySeq() const {
   static int calledTimes=0;  //number of times this method being called
   int i;

   calledTimes++;

   for (i=1; i<MaxNumberOfLists; i++){
      if ( calledTimes%(1<<i) != 0 )  //found
         break;        
   }
   return i;  //1,2,1,3,1,2,1,4,1,2,1,3, ..

}


void Node::write (ostream& outfile) const
{
   outfile << setw(10) << info; 

   for (int i=0; i<numOfNextPtrs; i++){   //each value of the next pointed to
      if (next[i] != nullptr)
         outfile << '(' << setw(5) << next[i]->info << ')';
      else
         outfile << "( --- )";
   }

   return;
}

ostream& operator << (ostream& outfile, const Node& node)
{
   node.write (outfile);

   return outfile;
}