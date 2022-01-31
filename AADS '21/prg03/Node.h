// ***** Node.h *****

class Node
{
public:
   Node (int el);
   ~Node(void);

   void  write (ostream& outfile) const;
   
   int  info;
   Node **next;         // dynamic array as Node* next[numOfNextPtrs];  an array of Node* for next
   int numOfNextPtrs;   // number of next pointers 
   int mySeq() const;   // for the size of the array of next-pointers in the sequence for a perfect Skip List
};

ostream& operator << (ostream& outfile, const Node& node);