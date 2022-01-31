// ***** Node.h *****
// for binary search tree

class Node
{
public:
   Node (int el);

   //  each node is shown:  info (left's info) (right's info)
   void  write (ostream& outfile) const;
   
   
   int info;
 
   Node *left, *right;    //left child, right child
};

ostream& operator << (ostream& outfile, const Node& node);