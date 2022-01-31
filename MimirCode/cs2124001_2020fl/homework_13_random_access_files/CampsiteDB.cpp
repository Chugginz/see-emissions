/**
 *******************************************************************************
 * @file    CampsiteDB.cpp
 * @brief   Implementation file used to hold the methods of class CampsiteDB 
 *          which means Campsite Data Base, that allows the management of a 
 *          binary file containing Campsite Records
 * 
 * @author  Christian Huggins
 * @date    December 9th, 2020
 *******************************************************************************
**/

#include "CampsiteDB.h"

CampsiteDB::CampsiteDB(std::string filename){
    _filename = filename;
    if (_open_file() == false){
        _create_file();
        if (_open_file() == false)
            throw std::runtime_error("Unable to create the database.");
    }
}


bool CampsiteDB::_open_file(){
    bool result = true;
    
    try{
        _file.open(_filename, ios::out | ios::in | ios::binary);
    }
    catch(...){
        result = false;
    }
    
    return result;
}

void CampsiteDB::_create_file(){
    std::fstream _filename;
}

void CampsiteDB::write_next_sequential( const Campsite& site ){
    int size = get_record_count() * sizeof(CampsiteRecord);
    if (_file.tellp() <= size){
        CampsiteRecord tempRecord = site.get_record();
        _file.write(reinterpret_cast<char*>(&tempRecord), 
            sizeof(CampsiteRecord));
    }
    else  
        throw std::length_error ("Pointer not at correct location (write)");
}

Campsite CampsiteDB::get_next_sequential( ){
    int size = get_record_count() * sizeof(CampsiteRecord);
    Campsite site;
    if (_file.tellg() <= size){
        CampsiteRecord tempRecord;
        _file.read(reinterpret_cast<char*>(&tempRecord), sizeof(CampsiteRecord));
        Campsite temp(tempRecord);
        site = temp;
    }
    else
        throw std::length_error ("Pointer not at correct location (get)");
    
    return site;
}

int CampsiteDB::get_record_count( ){
    int currentPlace = _file.tellg();
    _file.seekg(0, ios::end);
    int size = _file.tellg();
    int count = size / sizeof(CampsiteRecord);
    _file.seekg(currentPlace, ios::beg);
    
    return count;
}

int CampsiteDB::get_current_index(bool write){
    int index;
    if (write == false)
        index = _file.tellg() / sizeof(CampsiteRecord);
    else
        index = _file.tellp() / sizeof(CampsiteRecord);
    
    return index;
}

void CampsiteDB::list_records(std::ostream& strm){
    _file.clear();
    _file.seekg(0, ios::beg);
    while (_file.good()){
        Campsite site = get_next_sequential();
        if (_file.good())
            write_next_sequential(site);
        strm << "\n";
    }
    _file.clear();
    _file.seekg(0, ios::beg);
}

Campsite CampsiteDB::get_at_index(int index){
    std::cout << get_record_count();
    if (index < get_record_count() - 1 && index >= 0){
        _file.clear();
        int offset = index * sizeof(CampsiteRecord);
        _file.seekg(offset, ios::beg);
    }
    else
        throw std::length_error ("Index outside of scope (get at)");
    
    return get_next_sequential();
}

void CampsiteDB::write_at_index( int index, const Campsite& site ){
    int record_num = get_record_count();
    if (index <= record_num && index >= 0){
        _file.clear();
        int offset = index * sizeof(CampsiteRecord);
        _file.seekp(offset, ios::beg);
    }
    else
        throw std::length_error ("Index outside of scope (write at)");
    
    return write_next_sequential(site);
}

void CampsiteDB::print_record(int index, std::ostream& strm){
    if (index < get_record_count() && index >= 0)
        strm << get_at_index(index);
    else
        throw std::length_error ("Index outside of scope (print)");
}

void CampsiteDB::move_to_index(int index){
    if (index <= get_record_count() && index >= 0){
        int new_index = index * sizeof(CampsiteRecord);
        _file.seekg(new_index, ios::beg);
        _file.seekp(new_index, ios::beg);
    }
    else
        throw std::length_error ("Index outside of scope (move to)");
}

void CampsiteDB::swap_records(int index_1, int index_2){
    int recordNum = get_record_count();
    if (index_1 < recordNum && index_1 >= 0 
        && index_2 < recordNum && index_2 >= 0){
        Campsite site1 = get_at_index(index_1);
        Campsite site2 = get_at_index(index_2);
        CampsiteRecord record1 = site1.get_record();
        CampsiteRecord record2 = site2.get_record();
        _file.seekp(index_1 * sizeof(CampsiteRecord), ios::beg);
        _file.write(reinterpret_cast<char*>(&record2), sizeof(CampsiteRecord));
        _file.seekp(index_2 * sizeof(CampsiteRecord), ios::beg);
        _file.write(reinterpret_cast<char*>(&record1), sizeof(CampsiteRecord));
    }
    else throw std::length_error ("Index outside of scope (swap)");
}

std::vector<Campsite> CampsiteDB::get_range(int first_index, int last_index){
    int recordNum = get_record_count();
    Campsite site;
    vector<Campsite> campVect;
    
    if (first_index < recordNum && first_index >= 0 
        && last_index < recordNum && last_index >= 0){
        for (int i = first_index; i < last_index; i++){
            site = get_at_index(i);
            campVect.push_back(site);
        }
    }
    else
        throw std::length_error ("Index outside of scope (get_range)");
        
    return campVect;
}

Campsite CampsiteDB::get_random(){
    int index = 0;
    do{
        index = rand() % get_record_count();
    } while (index >= get_record_count() || index < 0);
    
    return get_at_index(index);
}