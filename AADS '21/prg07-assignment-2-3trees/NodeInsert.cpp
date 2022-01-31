// ***** NodeInsert.cpp *****

#include "master.h"

// to insert an integer and its right child to the node. 
// el: the key to insert into this node
// rChild: the pointer of the child (only for non-leaf node) to insert
// returnKey: the key to insert to parent if current node splits  (return to the calling function)
// return: (Node *)  the newly created node if current node splits
Node* Node::insertItem(int el, Node *rChild, int &returnKey) {
      Node *newNode=nullptr;


      return newNode;
}

// split the current node when insert an integer and its right child to the node. 
// el: the key to insert into the current node and cause to split
// rChild: the pointer of the child (only for non-leaf node) to insert
// returnKey: the key to insert to parent after splits  (return to the calling function)
// return: (Node *)  the newly created node after splits
Node* Node::split(int el, Node *rChild, int &returnKey) {
      Node * newNode = new Node();












      return newNode;

}
