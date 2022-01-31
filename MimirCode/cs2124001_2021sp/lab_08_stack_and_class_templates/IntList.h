// @ IntList.h

#ifndef INTLIST_H
#define INTLIST_H

#include "IntNode.h"

class IntList {
public:
    IntList( ) = default;
    ~IntList( );
    bool is_empty( ) const;
    void add_front( int newData );
    int  remove_front( );
    void write( ostream& outfile ) const;

    // disallow copies by marking the following as "delete":
    IntList( const IntList& ) = delete;
    IntList& operator=( const IntList& ) = delete;

private:
    IntNode* head = nullptr;
};
ostream& operator<<( ostream& outfile, const IntList& list );

#endif