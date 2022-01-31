// ***** Two3T.cpp *****

#include "master.h"

Two3T::Two3T (void)
{
   root = nullptr;
}

Two3T::~Two3T (void)
{
   erase ();

   return;
}

// erase the tree
// call postOrderDeletion to erase 
void Two3T::erase (void)
{
   cout << "Two3T::erase\n";

   postOrderDeletion(root);
   root = nullptr;
   
   return;
}
void Two3T::postOrderDeletion (Node *p) 
{
   if (p!=nullptr) {
      for (int i=0; i<p->keyTally; i++)
      {
         postOrderDeletion(p->child[i]);
      }
      delete (p);
   }
   return;
}


//add a new key to the tree
//el: the key to insert to the tree
// return true if sucessful
//assume no duplicate data will be inserted
bool Two3T::add(int el) {
   Node* curr = root;
   Node* tmp = nullptr;

   //empty tree
   if (root == nullptr) {
      root = new Node();
      root->keyTally = 1;
      root->leaf = true;
      root->keys[0]=el;
   }
   else {
      int returnKey;   // to keep the key for new root if node splits

      // recursively insert into the child
      tmp = add_recursion(curr, el, returnKey);
      if (tmp != nullptr) {  //if split in the child
         curr = new Node();
         curr->keyTally = 1;
         curr->leaf = false;
         curr->keys[0]=returnKey;
         curr->child[0]=root;
         curr->child[1]=tmp;
         root = curr;
      }
   }

   return true;
}   


// a recursive function to insert to the tree 
// el: the key to insert into this node
// returnKey: the key to insert to parent if current node splits  (return to the calling function)
// return: (Node *)  the newly created node if current node splits
Node* Two3T::add_recursion(Node* curr, int el, int &returnKey) {
   Node *tmp = nullptr;
     
   if (!curr->leaf)  {  // continue to the child
      int currentIndex=0;

      // currentIndex is where first key > el (which makes child[currentIndex] where the child to search for el)
      for (currentIndex=0; currentIndex < curr->keyTally && el > curr->keys[currentIndex]; currentIndex++)
         ;
      tmp = add_recursion(curr->child[currentIndex], el, returnKey);
      if (tmp==nullptr)  // no split from the child
         return tmp;
      else { // get key from split
         int newReturnedKey=returnKey;
         tmp = curr->insertItem(newReturnedKey, tmp, returnKey);
         return tmp;
      }

   }
   else {
         //int newReturnedKey=el;
         tmp = curr->insertItem(el, tmp, returnKey);
         return tmp;  
   }

}  
bool Two3T::find(int el) const {
   Node* curr = root;
   bool  found=false, done = false;
   int currentIndex;
   
   if (curr == nullptr)
      return false; 
   
   while (!done) {

      // search in current node
      // currentIndex is where the key == el or  
      //           first key > el (which makes child[currentIndex] where the child to search for el)
      for (currentIndex=0; currentIndex < curr->keyTally && el > curr->keys[currentIndex]; currentIndex++)
          ;
      
      
      if (currentIndex < curr->keyTally && curr->keys[currentIndex]==el)  // found
      {
         found=true;
         done = true;
      }
      else if (curr->leaf)   // if already at leaf node, not found
         done = true; //not found
      else  //continue to the child
         curr = curr->child[currentIndex];
   }
      
   return found;
}   

void Two3T::write (ostream& outfile) const
{

   //to print for each node by in order
   //  each node is shown:  info (left's info) (right's info)
   outfile << "Print tree preorder" << endl;
   
   preOrderWrite(outfile, root);
   //outfile << "Done Printing tree preorder" << endl;
   
   return;
}   

void Two3T::preOrderWrite (ostream& outfile, Node *p) const 
{
   if (p!= nullptr) {
      outfile << *p << endl;
      //outfile << "p->keyTally=" << p->keyTally << endl;
      if (!p->leaf) {  // if not leaf, print the children
         for (int i=0; i<=p->keyTally; i++) {
            preOrderWrite(outfile, p->child[i]);
         }
      }
   }
   return;
}

ostream& operator << (ostream& outfile, const Two3T& list)
{
   list.write (outfile);

   return outfile;
}