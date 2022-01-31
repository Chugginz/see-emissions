// @ intList.h

#ifndef INTLIST_H
#define INTLIST_H

#include<iostream>
#include "intNode.h"

class IntList {
public:
    IntList( ) = default;
    ~IntList( );
    bool is_empty( ) const;
    void add_front( int newData );
    int  remove_front( );
    void write(std::ostream& outfile ) const;

    // disallow copies by marking the following as "delete":
    IntList( const IntList& ) = delete;
    IntList& operator=( const IntList& ) = delete;

private:
    IntNode* head = nullptr;
};

std::ostream& operator<<(std::ostream& outfile, const IntList& list );

#endif