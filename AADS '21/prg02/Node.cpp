// ***** Node.cpp *****

#include "master.h"

Node::Node (void)
{
   next = nullptr;
}

Node::Node (int el, Node *ptr) //=nullptr)
{
   info = el;
   next = ptr;

}

// display a node to an ostream
//   the contents of a node is info and 
//      next->info  if next is valid
//      ( --- )  if next is not valid
void Node::write (ostream& outfile) const
{
   outfile << setw(10) << info; 

   if (next != nullptr)
      outfile << '(' << setw(5) << next->info << ')';
   else
      outfile << "( --- )";

   return;
}

ostream& operator << (ostream& outfile, const Node& node)
{
   node.write (outfile);

   return outfile;
}