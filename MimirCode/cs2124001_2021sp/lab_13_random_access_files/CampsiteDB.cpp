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
    std::cout << "trying to open file\n";
    _file.open(_filename, ios::in | ios::out | ios::binary);
    _file.seekp(0, ios::end);
    
    bool result = _file.is_open();
    
    return result;
}

void CampsiteDB::_create_file(){
    std::fstream _file{_filename, ios::out};
    _file.close();
}

void CampsiteDB::write_next_sequential( const Campsite& site ){
    CampsiteRecord tempRecord = site.get_record();
    _file.write(reinterpret_cast<char*>(&tempRecord), sizeof(CampsiteRecord));
}

Campsite CampsiteDB::get_next_sequential( ){
    CampsiteRecord record;
    _file.read(reinterpret_cast<char*>(&record), sizeof(CampsiteRecord));
    Campsite site(record);
    
    return site;
}

int CampsiteDB::get_record_count( ){
    //Mark location of g
    int position = _file.tellg();
    _file.seekg(0, ios::end);
    int size = _file.tellg();
    int count = size / sizeof(CampsiteRecord);
    //Reset location of g
    _file.seekg(position, ios::beg);
    
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
            strm << site << "\n";
    }
    _file.clear();
    _file.seekg(0, ios::beg);
}

Campsite CampsiteDB::get_at_index(int index){
    if (index < get_record_count() && index >= 0){
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
    if (index < record_num && index >= 0){
        _file.clear();
        int offset = index * sizeof(CampsiteRecord);
        _file.seekp(offset, ios::beg);
    }
    else
        throw std::length_error ("Index outside of scope (write at)");
    
    return write_next_sequential(site);
}

void CampsiteDB::print_record( int index, std::ostream& strm){
    if (index < get_record_count() && index >= 0)
        strm << get_at_index(index);
    else
        throw std::length_error ("Index outside of scope (print)");
}
