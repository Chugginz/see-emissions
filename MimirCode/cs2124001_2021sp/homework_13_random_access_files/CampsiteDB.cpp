/**
 *******************************************************************************
 * @file    CampsiteDB.cpp
 * @brief   Implementation file used to hold the methods of class CampsiteDB 
 *          which means Campsite Data Base, that allows the management of a 
 *          binary file containing Campsite Records
 * 
 * @author  Christian Huggins
 * @date    April 25th, 2021
 *******************************************************************************
**/

#include "CampsiteDB.h"

/**
 * @brief       This is the constructor for campsite database
 *
 * @detailed    Given a filename, the constructor will check if the file
 *              can be opened. If it can't, then create a file, 
 *              and check if it can open then.
 *              
 * @param       std::string filename    The file name being assigned to the
 *                                      object's _filename
**/

CampsiteDB::CampsiteDB(std::string filename){
    //Assign class _filename to be parameter filename
    _filename = filename;
    //If the file can not be opened
    if (_open_file() == false){
        //Create the file
        _create_file();
        //If the file still can not be opened
        if (_open_file() == false)
            //Throw a runtime error
            throw std::runtime_error("Unable to create the database.");
    }
}

/**
 * @brief       Opens a file
 *
 * @detailed    Taking the class's filename, open the file, set the put
 *              marker at the end, and return the result of if the
 *              file is open or not
 *              
 * @return      Returns a boolean, telling whether or not the file is open
**/

bool CampsiteDB::_open_file(){
    //Let user know file is trying to be opened
    std::cout << "trying to open file\n";
    //Open file in binary mode
    _file.open(_filename, ios::in | ios::out | ios::binary);
    //Place put marker at the end of the file
    _file.seekp(0, ios::end);
    //Initialize result to the result of if the file is open or not
    bool result = _file.is_open();
    
    return result;
}

/**
 * @brief       Create a file
 *
 * @detailed    Create a file using the class's file name and then close it
**/

void CampsiteDB::_create_file(){
    std::fstream _file{_filename, ios::out};
    _file.close();
}

/**
 * @brief       This writes the site to the next location
 *
 * @detailed    Given a site, the function creates a temporary record for the
 *              record in the given site. It then writes this record to the file
 *              
 * @param       const Campsite& site    The site used to access the record
 *                                      being written to the file
**/

void CampsiteDB::write_next_sequential(const Campsite& site){
    //Initalize a temporary record to be the record in the site parameter
    CampsiteRecord tempRecord = site.get_record();
    //Write the record to the file
    _file.write(reinterpret_cast<char*>(&tempRecord), sizeof(CampsiteRecord));
}

/**
 * @brief       This gets the site from the next location
 *
 * @detailed    This function creates a record, reads the data from the file
 *              into the record, then it creates a site given the record and
 *              returns the site
 *              
 * @return      Returns a site containing the recently read record
**/

Campsite CampsiteDB::get_next_sequential(){
    //Initalize a record
    CampsiteRecord record;
    //Read the record from the site and stores it into record
    _file.read(reinterpret_cast<char*>(&record), sizeof(CampsiteRecord));
    //Initalize a site object with the newly read record
    Campsite site(record);
    
    return site;
}

/**
 * @brief       This gets the record count
 *
 * @detailed    By taking the get marker to the end of the file and storing
 *              the number of bytes, the function divides that number by
 *              the # of bytes in a Campsite Record to get the total number of
 *              records
 *              
 * @return      Returns the number of records in the file
**/

int CampsiteDB::get_record_count( ){
    //Mark location of get marker
    int position = _file.tellg();
    //Set get marker to end of file
    _file.seekg(0, ios::end);
    //Initalize size to be the byte number of tellg
    int size = _file.tellg();
    //Initalize count to be the size divided by the size of a campsite record
    int count = size / sizeof(CampsiteRecord);
    //Reset location of get marker to origin
    _file.seekg(position, ios::beg);
    
    return count;
}

/**
 * @brief       This gets the current index
 *
 * @detailed    Given whether or not the index for writing is desired, the
 *              function will either get the get marker or the put marker
 *              location and return that divided by the size of a campsite
 *              record to give the index
 *              
 * @param       bool write          Boolean of true or false used to denote
 *                                  whether write index is being searched for
 *                                  or not
 * 
 * @return      Returns an integer that is the current index of either the
 *              read or write index
**/

int CampsiteDB::get_current_index(bool write){
    //Initalize index
    int index;
    //If the write index is not being looked for
    if (write == false)
        //Set index equal to the get marker location divided by the
        // size of a campsite record
        index = _file.tellg() / sizeof(CampsiteRecord);
    else
        //Set index equal to the put marker location divided by the
        // size of a campsite record
        index = _file.tellp() / sizeof(CampsiteRecord);
    
    return index;
}

/**
 * @brief       This lists all of the records in the file
 *
 * @detailed    Given a stream, this function while the file is still okay,
 *              reads each site using the get next sequential. It then reads
 *              the site into the stream. It then clears all flags and sets the
 *              get marker back to the beginning
 *              
 * @param       std::ostream& strm      Stream having sites read into it
**/

void CampsiteDB::list_records(std::ostream& strm){
    //Clear file flags
    _file.clear();
    //Set get marker to the beginning
    _file.seekg(0, ios::beg);
    //While the file is good
    while (_file.good()){
        //Get the next sequential site
        Campsite site = get_next_sequential();
        //If the file is still good
        if (_file.good())
            //Read this site into the stream
            strm << site << "\n";
    }
    //Clear the file flags
    _file.clear();
    //Set the get marker back to the beginning
    _file.seekg(0, ios::beg);
}

/**
 * @brief       This gets the site at the current index
 *
 * @detailed    Given the index, and that it is a valid index, the function
 *              gets the site at the index by placing the get marker there.
 *              It then returns the get next sequential site.
 *              
 * @param       int index       The index used to determine which site is wanted
 * 
 * @return      Returns a site at the index desired
**/

Campsite CampsiteDB::get_at_index(int index){
    //If the index is valid
    if (index < get_record_count() && index >= 0){
        //Clear file flags
        _file.clear();
        //Initalize offset to be the index times the number of bytes in a
        // campsite record
        int offset = index * sizeof(CampsiteRecord);
        //Set the get marker to the offset starting from the beginning
        _file.seekg(offset, ios::beg);
    }
    else
        //Throw an error that the index is out of the bounds
        throw std::length_error("Index outside of scope (get at)");
    
    return get_next_sequential();
}

/**
 * @brief       This writes at the current index
 *
 * @detailed    Given the index, and that it is a valid index, the function
 *              writes the site at the index by placing the put marker there.
 *              
 * @param       int index               The index that is wanted to be written
 *                                      at
 * 
 * @param       const Campsite& site    The site wanted to be written at the
 *                                      current index
**/

void CampsiteDB::write_at_index(int index, const Campsite& site){
    //If the index is valid
    if (index < get_record_count() && index >= 0){
        //Clear file flags
        _file.clear();
        //Initalize offset to be the index times the number of bytes in a
        // campsite record
        int offset = index * sizeof(CampsiteRecord);
        //Set the put marker to the offset starting from the beginning
        _file.seekp(offset, ios::beg);
        //Write the next sequential
        write_next_sequential(site);
    }
    else
        //Throw an error that the index is out of the bounds
        throw std::length_error("Index outside of scope (write at)");
}

/**
 * @brief       This prints a record
 *
 * @detailed    Given the index, and that it is a valid index, the function
 *              calls the get at index function. If not, an error is thrown.
 *              
 * @param       int index               The index that is wanted to be read
 *                                      at
 * 
 * @param       std::ostream& strm      The stream being read into
**/

void CampsiteDB::print_record(int index, std::ostream& strm){
    //If the index is valid
    if (index < get_record_count() && index >= 0)
        //Read the file at that index into the stream
        strm << get_at_index(index);
    else
        //Throw an error that the index is out of the bounds
        throw std::length_error("Index outside of scope (print)");
}

/**
 * @brief       This moves the markers to the index
 *
 * @detailed    Given the index, and that it is a valid index, the function
 *              moves both markers to the desired index.
 *              
 * @param       int index               The index that is wanted to be written
 *                                      at
**/

void CampsiteDB::move_to_index(int index){
    //If index is valid
    if (index <= get_record_count() && index >= 0){
        //Initalize offset to be the index times the number of bytes in a
        // campsite record
        int offset = index * sizeof(CampsiteRecord);
        //Set the get marker to the offset starting from the beginning
        _file.seekg(offset, ios::beg);
        //Set the put marker to the offset starting from the beginning
        _file.seekp(offset, ios::beg);
    }
    else
        //Throw an error that the index is out of the bounds
        throw std::length_error("Index outside of scope (move to)");
}

/**
 * @brief       This swaps records in the file
 *
 * @detailed    Given the two indexes and that they are both valid, create sites
 *              for each record at its index value. Then the record of each is
 *              stored in a campsire record object. The put markers are put at
 *              at the new indexes, and then the records written in there
 *              
 * @param       int index_1         The first index value of the first desired
 *                                  record
 * 
 * @param       int index_2         The second index value of the second desired
 *                                  record
**/

void CampsiteDB::swap_records(int index_1, int index_2){
    //If indexes are valid
    if (index_1 < get_record_count() && index_1 >= 0 
        && index_2 < get_record_count() && index_2 >= 0){
        //Initalize site1 to be site read at the first index
        Campsite site1 = get_at_index(index_1);
        //Initalize site2 to be site read at the second index
        Campsite site2 = get_at_index(index_2);
        //Initalize record1 to be the record of the first site
        CampsiteRecord record1 = site1.get_record();
        //Initalize record2 to be the record of the second site
        CampsiteRecord record2 = site2.get_record();
        //Set the put marker at the location of the first index
        _file.seekp(index_1 * sizeof(CampsiteRecord), ios::beg);
        //Write the second record to the location
        _file.write(reinterpret_cast<char*>(&record2), sizeof(CampsiteRecord));
        //Set the put marker at the location of the second index
        _file.seekp(index_2 * sizeof(CampsiteRecord), ios::beg);
        //Write the first record to the location
        _file.write(reinterpret_cast<char*>(&record1), sizeof(CampsiteRecord));
    }
    else
        //Throw an error that the index is out of the bounds
        throw std::length_error("Index outside of scope (swap)");
}

/**
 * @brief       This gets the range between the first and last indexes
 *
 * @detailed    Given the two indexes and that they are both valid, create a
 *              for loop that stores each site in between the two indexes
 *              into a vector of Campsites. The vector is then returned
 *              
 * @param       int first_index     The starting index for the vector of
 *                                  Campsites
 * 
 * @param       int last_index      The last index for the vector of Campsites
 * 
 * @return      Returns a vector of Campsites containing the Campsites in
 *              between the range of indexes
**/

std::vector<Campsite> CampsiteDB::get_range(int first_index, int last_index){
    //Initalize site of type Campsite
    Campsite site;
    //Initalize campVect as a vector of Campsites
    vector<Campsite> campVect;
    
    //If the indexes are valid
    if (first_index < get_record_count() && first_index >= 0 
        && last_index < get_record_count() && last_index >= 0){
        //Set i to the first index, and while i is less than the last index,
        // increment i
        for (int i = first_index; i < last_index; i++){
            //Set site to be the site at the index
            site = get_at_index(i);
            //Add the new site to the vector
            campVect.push_back(site);
        }
    }
    else
        //Throw an error that the index is out of the bounds
        throw std::length_error("Index outside of scope (get_range)");
        
    return campVect;
}

/**
 * @brief       Gets a random Campsite
 *
 * @detailed    Using a random number generator, a random index will be found.
 *              The loop will continue to do this while the index is larger
 *              than the record count or less than 0
 *
 * @return      Returns a random Campsite object
**/

Campsite CampsiteDB::get_random(){
    //Initalize index
    int index;
    //Initalize record count for speed purposes
    int record_count = get_record_count();
    do{
        //Set index to be a random number modulated by the record count
        index = rand() % record_count;
        //Continue to do this while the index is greater than or equal to
        // the record_count or less than 0
    } while (index >= record_count || index < 0);
    
    return get_at_index(index);
}