// ***** LinkedList.h *****
// ***** unordered *****

class LinkedList
{
public:       
   LinkedList (void);

   ~LinkedList (void);

   //erase all the nodes in the linked list
   void eraseAll();
   
   //output the data in the linked list
   void write (ostream& outfile) const;

   //add a new node to the head
   //return false if nullptr is given to add
   bool addAtHead (Node* newHead);

   //add a new node to the tail
   //return false if nullptr is given to add
   bool addAtTail (Node* newTail);

   //remove the head node, and return it
   Node* removeFromHead (void);

   //erase a node with certian value 
   //assume no duplicate data in the linked list
   bool  erase (int el);

private:
   Node * head,
        * tail;
};

ostream& operator << (ostream& outfile, const LinkedList& list);