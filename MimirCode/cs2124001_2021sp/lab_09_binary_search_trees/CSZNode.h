// @ CSZNode.h

#ifndef CSZNODE_H
#define CSZNODE_H

#include<iostream>
#include "CityStateZip.h"

class CSZNode {
public:
    CSZNode( const CityStateZip& data ) : payload{data} {};
    void         set_left( CSZNode* new_left );
    void         set_right( CSZNode* new_right );
    CityStateZip get_data( ) const;
    CSZNode*     get_left( ) const;
    CSZNode*     get_right( ) const;

    void write( std::ostream& fout ) const;
    bool operator<(const CSZNode& op2) const;

private:
    CityStateZip payload;
    CSZNode*     left  = nullptr;
    CSZNode*     right = nullptr;
};

std::ostream& operator<<( std::ostream& fout, const CSZNode& n);

#endif