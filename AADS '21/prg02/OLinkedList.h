// ***** OLinkedList.h *****
// ***** ordered *****

class OLinkedList
{
public:       
   OLinkedList (void);

   ~OLinkedList (void);

   //erase all nodes
   void erase(void);

   //return false if nullptr is given to add
   bool add (Node* newHead);

   /*
   bool  erase (int el);
   */
void write (ostream& outfile) const;

private:
   Node* head;
};

ostream& operator << (ostream& outfile, const OLinkedList& list);