/**
 *******************************************************************************
 * @file    CampsiteDB.h
 * @brief   Header file used to hold the class CampsiteDB which means
 *          Campsite Data Base, that allows the management of a binary file 
 *          containing Campsite Records
 * 
 * @author  Christian Huggins
 * @date    April 25th, 2021
 *******************************************************************************
**/

#ifndef CAMPSITEDB_H
#define CAMPSITEDB_H

#include "Campsite.h"
#include<iostream>
    using std::ios;
#include<fstream>
#include<string>
#include<vector>
    using std::vector;
#include<cstdlib>
    using std::rand;
    
class CampsiteDB {
public:
    CampsiteDB(std::string filename);

    Campsite get_at_index( int index );
    Campsite get_next_sequential( );
    
    int get_record_count( );
    int get_current_index( bool write=false );
    
    void write_next_sequential(const Campsite& site);
    void list_records(std::ostream& strm = std::cout);
    void write_at_index(int index, const Campsite& site);
    //Homework
    void print_record(int index, std::ostream& strm = std::cout);
    void move_to_index(int index);
    void swap_records(int index_1, int index_2);
    
    std::vector<Campsite> get_range(int first_index, int last_index);
    Campsite get_random();
    /*
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