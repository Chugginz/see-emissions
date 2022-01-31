// @ IntNode.h

#ifndef INTNODE_H
#define INTNODE_H

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
    using std::ostream;
#include <string>
    using std::string;
#include <vector>    
#include <iomanip>
#include <fstream>
    using std::ifstream;

class IntNode {
public:
    IntNode(int new_value);
    int      get_data( ) const;
    void     set_next( IntNode* new_next );
    IntNode* get_next( ) const;
    void     debug_write( ostream& outfile ) const;

private:
    int      payload;
    IntNode* next = nullptr;
};

ostream& operator<<( ostream& outfile, const IntNode& node );

#endif