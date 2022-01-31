// ***** Node.h *****
// for binary search tree

class Node
{
public:
   Node ();

   // to insert an integer and its right child to the node. 
   // el: the key to insert into this node
   // rChild: the pointer of the child (only for non-leaf node) to insert
   // returnKey: the key to insert to parent if current node splits  (return to the calling function)
   // return: (Node *)  the newly created node if current node splits
   Node* insertItem(int el, Node *rChild, int &returnKey);

   //  each node is shown:  (left's keys[0])keys[0](middle's keys[0]) keys[1] (right's key[0])
   void  write (ostream& outfile) const;
   
   bool leaf;   //true or false
   int keyTally;  // 1 or 2
   int keys[MAX_KEY_NUM];   // data
   Node *child[MAX_KEY_NUM+1];  //0:left, 1:middle, 2:right

private:
   Node* split(int el, Node *rChild, int &returnKey);
};

ostream& operator << (ostream& outfile, const Node& node);