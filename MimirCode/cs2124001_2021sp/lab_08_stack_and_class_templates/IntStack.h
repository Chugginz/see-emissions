// @ IntStack.h

#ifndef INTSTACK_H
#define INTSTACK_H

#include "IntList.h"

class IntStack {
public:
    bool is_empty( ) const;
    void push( int operand );
    int  pop( );
    void debug_write( ostream& outfile ) const;

private:
    IntList list;
};
ostream& operator<<( ostream& outfile, const IntStack& stack );

#endif