// @CampsiteDB.h

#ifndef CAMPSITEDB_H
#define CAMPSITEDB_H

#include "Campsite.h"
#include<iostream>
    using std::ios;
#include<fstream>
#include<string>

class CampsiteDB {
public:
    CampsiteDB(std::string filename);

    Campsite get_at_index( int index );
    Campsite get_next_sequential( );
    
    int get_record_count( );
    int get_current_index( bool write=false );
    
    void write_next_sequential(const Campsite& site);
    void list_records( std::ostream& strm = std::cout );
    void write_at_index( int index, const Campsite& site );
    /*
    void print_record( int index, std::ostream& strm = std::cout );
    
    // This object is non-copyable
    CampsiteDB(const CampsiteDB&)            = delete;  
    CampsiteDB& operator=(const CampsiteDB&) = delete;  
    */

private:
    // private methods:
    void _create_file( );
    bool _open_file( );
    // attributes
    std::string  _filename;
    std::fstream _file;
};

#endif