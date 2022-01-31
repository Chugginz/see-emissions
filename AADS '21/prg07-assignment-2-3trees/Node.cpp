// ***** Node.cpp *****

#include "master.h"

Node::Node () 
{
      //note that keyTally <= MAX_KEY_NUM

}

//  print out a node
//  each node is shown by:  (left's keys[0]) keys[0] (middle's keys[0]) keys[1] (right's keys[0])
//  for leaf node, it shows: (-----) keys[0] (-----) keys[1] (-----)
//  for one-node, it shows: (left's keys[0]) keys[0] (middle's keys[0])      (      )
void Node::write (ostream& outfile) const
{
      int i;
      for (i=0; i<keyTally; i++)
      {
            //for child [0]
            if (leaf)
                  outfile << "(-----) ";
            else
                  outfile << "(" << setw(5) << child[i]->keys[0] << ") "; 
                  //print child's first key

            outfile << setw(5) << keys[i] << " ";            
      }
      //for child [i]
      if (leaf)
            outfile << "(-----) ";
      else
            outfile << "(" << setw(5) << child[i]->keys[0] << ") "; 
            //print child's first key

      i++;

      for (; i<=MAX_KEY_NUM; i++)
      {
            outfile << "      (     )" << " ";           
      }


   //outfile << endl;

   return;
}

ostream& operator << (ostream& outfile, const Node& node)
{
   node.write (outfile);

   return outfile;
}