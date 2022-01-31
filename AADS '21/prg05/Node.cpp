// ***** Node.cpp *****

#include "master.h"

Node::Node (int el) 
{
   info = el;
   left=right=nullptr;
}

//  each node is shown:  info (left's info) (right's info)
void Node::write (ostream& outfile) const
{
   outfile << setw(5) << info << " "; 

   if (left != nullptr) {
         outfile << "(" << setw(5) << left->info << ") ";
   }
   else {
         outfile << "(-----) ";
   }
   if (right != nullptr) {
         outfile << "(" << setw(5) << right->info << ") ";
   }
   else {
         outfile << "(-----) ";
   }   
   //outfile << endl;

   return;
}

ostream& operator << (ostream& outfile, const Node& node)
{
   node.write (outfile);

   return outfile;
}