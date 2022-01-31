// ***** Node.h *****

class Node
{
public:
   Node (void);
   Node (int el, Node *ptr = nullptr);

   void  write (ostream& outfile) const;
   int  info;
   Node *next;

};

ostream& operator << (ostream& outfile, const Node& node);