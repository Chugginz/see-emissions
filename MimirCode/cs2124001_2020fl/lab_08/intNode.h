// @ intNode.h

#ifndef INTNODE_H
#define INTNODE_H

#include<iostream>

class IntNode {
public:
    IntNode( int new_value );
    int      get_data( ) const;
    void     set_next( IntNode* new_next );
    IntNode* get_next( ) const;
    void     debug_write(std::ostream& outfile ) const;

private:
    int      payload;
    IntNode* next = nullptr;
};

std::ostream& operator<<(std::ostream& outfile, const IntNode& node);

#endif