// ***** SkipList.h *****

class SkipList
{
public:       
   SkipList (void);

   ~SkipList (void);

   void erase(void);

   bool eraseNode(int el);

   //return false if nullptr is given to add
   bool add (Node* newNode);

   //return false if not found
   bool find(int el) const;    

   /*
   bool  erase (int el);
   */
   void write (ostream& outfile) const;

private:
   Node* head[MaxNumberOfLists];
   int   nLevelsUsed;  //the current number of levels used

   Node* addNext(Node* newNode, Node* prev, int currlevel);  //helper for add method, not necessary for the project
};

ostream& operator << (ostream& outfile, const SkipList& list);