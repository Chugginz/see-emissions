// @ CampsiteRecord.cpp

#include "CampsiteRecord.h"

CampsiteRecord::CampsiteRecord(){
    memset(this, 0, sizeof(CampsiteRecord)); 
    // overwrite all non-static memory in the record with zeros.
    number = 0;
    char placeHolder[desc_size] = "empty string";
    strncpy(description, placeHolder, desc_size);
    has_electric = false;
    rate = 0;
}

CampsiteRecord::CampsiteRecord(int number, const char description[], bool has_electric, double rate){
    memset(this, 0, sizeof(CampsiteRecord)); 
    // overwrite all non-static memory in the record with zeros.
    this->number = number;
    strncpy(this->description, description, desc_size);
    this->has_electric = has_electric;
    this->rate = rate;
}

/**
 * Read a site record from a delimited ASCII file, where
 * each field is separated by a '|' character.
 *
 * @param strm   input stream
 * @param site   site record to store resulting value into
 */
std::istream& from_ascii_file(std::istream& strm, CampsiteRecord& site){
    char delim;
    char buffer[6];  // used to catch "true" or "false"
    strm >> site.number >> delim;
    strm.getline( site.description, site.desc_size, '|' );
    strm.getline( buffer, 6, '|' );
    site.has_electric = tolower( buffer[0] ) == 't';  // true if the string started with 't'
    strm >> site.rate;
    return strm;
}

/**
 * stream insertion to print campsite records in a screen-friendly format.
 *
 * @param strm   output stream
 * @param site   site record to print
 */
std::ostream& operator<<(std::ostream& strm, const CampsiteRecord& site){
    strm << site.number      << ' ' << ( site.has_electric ? "[E]" : "[ ]" ) 
         << site.description << ' '
         << std::fixed << std::setprecision( 2 ) << "\t($" << site.rate << ")"
         << std::resetiosflags( std::ios::fixed | std::ios::showpoint );
    return strm;
}