// @ CampsiteDB.cpp

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
    CampsiteRecord tempRecord = site.get_record();
    _file.write(reinterpret_cast<char*>(&tempRecord), sizeof(CampsiteRecord));
}

Campsite CampsiteDB::get_next_sequential( ){
    CampsiteRecord tempRecord;
    _file.read(reinterpret_cast<char*>(&tempRecord), sizeof(CampsiteRecord));
    Campsite site(tempRecord);
    
    return site;
}

int CampsiteDB::get_record_count( ){
    _file.seekp(0, ios::end);
    int size = _file.tellg();
    int count = size / sizeof(CampsiteRecord);
    
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
    _file.clear();
    int offset = index * sizeof(CampsiteRecord);
    _file.seekg(offset, ios::beg);
    
    return get_next_sequential();
}

void CampsiteDB::write_at_index( int index, const Campsite& site ){
    _file.clear();
    int offset = index * sizeof(CampsiteRecord);
    _file.seekg(offset, ios::beg);
    
    return write_next_sequential(site);
}
/*
void print_record( int index, std::ostream& strm = std::cout ){
}
*/