/**
 * @file CityStateZip.h
 *
 * Defines a record containg the city name,
 * state, and ZIP code for a single city.
 * 
 * @remarks  This is a stand-alone header; no implementation file
 *           is required.
 */
#ifndef CITYSTATEZIP_H
#define CITYSTATEZIP_H

#include <iostream>
#include <string>

class CityStateZip {
public:
    CityStateZip( std::string city_name, 
                  std::string state_name,
                  unsigned int zip_code )
        : _city{city_name}, _state{state_name}, _zip{zip_code} {}

    /**
     * access the city name
     * 
     * @return city name
     */
    std::string  city ( ) const { return _city;  }

    /**
     * access the state name
     * 
     * @return state name
     */
    std::string  state( ) const { return _state; }

    /**
     * access the zip code
     * 
     * @return zip code
     */
    unsigned int zip  ( ) const { return _zip;   }

    /**
     * writes the city, state and zip to the specified stream in 
     * a standard format
     * 
     * @param  strm the output stream to write to
     * @return      `strm` is returned to allow chaining
     */
    std::ostream& write( std::ostream& strm ) const {
        return strm << _city << ", " << _state << " " << _zip;
    }

private:
    std::string  _city;     /// the name of the city
    std::string  _state;    /// the name of the state
    unsigned int _zip;      /// the ZIP code (postal code) for the city
};

/**
 * overloaded stream-insertion operator to allow printing
 * city, state ZIP to output streams in the usual way.
 * 
 * @param  strm the output stream to write to
 * @param  csz  a CityStateZip object to write to `strm`
 * @return      `strm` is returned to allow chaining
 */
inline std::ostream& operator<<( std::ostream& strm, const CityStateZip& csz ) {
    return csz.write( strm );
}

#endif