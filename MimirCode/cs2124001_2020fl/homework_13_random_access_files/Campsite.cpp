/**
 * @file Campsite.cpp
 *
 * Implementation for the Campsite class
 *
 * @remarks
 *     Provided as a resource for the "Random Access Files"
 *     laboratory (CS2124).
 */
#include "Campsite.h"

/**
 * Construct a Campsite given specific details.
 * @remark
 *     Campsite value constructor just sinks the values into the 
 *     CampsiteRecord.
 * 
 * @param number        campsite number
 * @param description   campsite description (will truncate if longer than 127 characters)
 * @param has_electric  true if the site has electricity, or false otherwise
 * @param rate          per-night rate for renting the site
 */
Campsite::Campsite( int number, std::string description, 
                    bool has_electric, double rate )
    : _rec{number, description.c_str( ), has_electric, rate} {}

/**
 * Construct a Campsite given a Campsite Record.
 * 
 * @param r  CampsiteRecord object to wrap.
 */
Campsite::Campsite( const CampsiteRecord& r ) 
    : _rec{r} {}

/**
 * access the CampsiteRecord being stored
 * 
 * @return  the current CampsiteRecord object
 */
CampsiteRecord Campsite::get_record() const {
    return _rec;
}

/**
 * access the site number
 *
 * @return the site number
 */
int Campsite::get_number( ) const {
    return _rec.number;
}

/**
 * access the site description
 *
 * @return the site description
 */
std::string Campsite::get_description( ) const {
    return std::string{_rec.description};
}

/**
 * access an indicator of whether or not the site has electricity
 *
 * @return true if the site has electricity, false otherwise
 */
bool Campsite::has_electric( ) const {
    return _rec.has_electric;
}

/**
 * access the site per-day rental rate
 *
 * @return the site per-day rental rate
 */
bool Campsite::get_rate( ) const {
    return _rec.rate;
}

/**
 * set the site's number
 * 
 * @param number  the new site number
 */
void Campsite::set_number( int number ) {
    _rec.number = number;
}

/**
 * @brief set the site's description
 * 
 * @detailed 
 *     Sets the site's description.  The description is limited 
 *     in length and can only store 127 printable characters; 
 *     if the provided description is longer than that limit,
 *     it will be truncated.
 * 
 * @param description  the new site description
 */
void Campsite::set_description( std::string description ) {
    // place a null terminator at the end
    _rec.description[CampsiteRecord::desc_size - 1] = '\0';
    // copy carefully -- leave the '\0' in place (re: the -1 on the length)
    strncpy( _rec.description, 
             description.c_str( ),
             CampsiteRecord::desc_size - 1 );
}

/**
 * set the site's electric status flag
 * 
 * @param flag  the new site "has electric" status (true if the site
 *              has electricity, false otherwise)
 */
void Campsite::set_has_electric( bool flag ) {
    _rec.has_electric = flag;
}

/**
 * set the site's per-night rental rate
 * 
 * @param rate  the new site per-night rental rate
 */
void Campsite::set_rate( double rate ) {
    _rec.rate = rate;
}

/**
 * reads campsite info from a delimited text file and replaces the
 * contents of the current object
 * 
 * @details 
 *     Read a site record from a delimited ASCII file stream, where
 *     each field is separated by a '|' character.
 *     The values from the file replace the current attributes of 
 *     this Campsite.
 * 
 * @param strm  the input stream to read from
 * @return      the modified stream is returned
 */
std::istream& Campsite::from_ascii_file(std::istream& strm){
    // Hand off to the standalone `from_ascii_file()` function defined 
    // in CampsiteRecord.h
    return ::from_ascii_file(strm, _rec);   
}

/**
 * Write the campsite info to an ASCII-encoded stream.
 * 
 * @param strm  stream to write to 
 * @return  the modified stream is returned
 */
std::ostream& Campsite::write(std::ostream& strm) const{
    return strm << _rec;
}

/**
 * Stream insertion to print a campsite to an ASCII-encoded stream.
 * 
 * @param strm  stream to write to 
 * @param site  campsite object to print
 * @return  the modified stream is returned
 */
std::ostream& operator<< (std::ostream& strm, const Campsite& site){
    return site.write(strm);
}

