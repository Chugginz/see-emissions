// ***** Two3T.h *****

class Two3T
{
public:       
   Two3T (void);

   ~Two3T (void);

   // add new element to the tree for new data
   // if duplicate data, no add
   // false if duplicate; true otherwise
   bool add (int el);

   //return true if found; false otherwise
   bool find(int el) const;    

   //erase all the nodes and clean all the pointers.
   void erase (void);

   void write (ostream& outfile) const;

private:
   Node* root;   
   void postOrderDeletion(Node *);   
   void preOrderWrite(ostream& outfile, Node *p) const;   
   Node* add_recursion(Node* curr, int el, int &returnKey);    
};

ostream& operator << (ostream& outfile, const Two3T& list);