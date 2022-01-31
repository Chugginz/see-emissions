// ***** BST.h *****

class BST
{
public:       
   BST (void);

   ~BST (void);

   // add new element to the tree for new data
   // if duplicate data, no add
   // false if duplicate; true otherwise
   bool add (int el);

   //return true if found; false otherwise
   bool find(int el) const;    

   //erase the node with value el
   //return true if found and erase it.
   //bool erase (int el);

   //erase all the nodes and clean all the pointers.
   void erase (void);

   // swap node with its predecessor or successor
   // find the el
   // if not found returns false
   // if found:
   // if it has left child, swap with its predecessor, and return true
   // else if it has right child, swap with its successor, and return true
   // else return false  
   bool BSTswap(int el);

   void write (ostream& outfile) const;

private:
   Node* root;   
   void postOrderDeletion(Node *);   
   void inOrderWrite(ostream& outfile, Node *p) const;       
};

ostream& operator << (ostream& outfile, const BST& list);