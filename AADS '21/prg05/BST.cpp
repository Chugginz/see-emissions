// ***** BST.cpp *****

#include "master.h"

BST::BST (void)
{
   root = nullptr;
}

BST::~BST (void)
{
   erase ();

   return;
}

void BST::erase (void)
{
   cout << "BST::erase\n";

   postOrderDeletion(root);
   root = nullptr;
   
   return;
}
void BST::postOrderDeletion (Node *p) 
{
   if (p!=nullptr) {
      postOrderDeletion(p->left);
      postOrderDeletion(p->right);
      delete (p);
   }
   return;
}

bool BST::add(int el) {
   Node* curr = root;
   Node* prev = nullptr;

   while (curr != nullptr) {
      prev = curr;
      if (curr->info == el)  //duplicate
         return false;
      else if (el < curr->info)
         curr = curr->left;
      else // el > curr->info
         curr = curr->right;
   }

   if (root == nullptr)  { //empty tree
      root = new Node(el);
   } else if (el < prev->info) {
      prev->left = new Node(el);
   } else {
      prev->right = new Node(el);
   }

   return true;
}   

bool BST::find(int el) const {
   Node* curr = root;
   while (curr != nullptr) {
      if (curr->info == el)  //found
         return true;
      else if (el < curr->info)
         curr = curr->left;
      else // el > curr->info
         curr = curr->right;
   }
   return false;
}   

void BST::write (ostream& outfile) const
{

   //to print for each node by in order
   //  each node is shown:  info (left's info) (right's info)
   outfile << "Print node inorder" << endl;
   
   inOrderWrite(outfile, root);

   return;
}   

void BST::inOrderWrite (ostream& outfile, Node *p) const 
{
   if (p!= nullptr) {
      inOrderWrite(outfile, p->left);
      outfile << *p << endl;
      inOrderWrite(outfile, p->right);
   }
   return;
}

ostream& operator << (ostream& outfile, const BST& list)
{
   list.write (outfile);

   return outfile;
}