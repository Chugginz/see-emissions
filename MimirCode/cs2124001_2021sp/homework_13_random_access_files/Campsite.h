/**
 * @file Campsite.h
 *
 * Implementation for the Campsite class
 *
 * @remarks
 *     Provided as a resource for the "Random Access Files"
 *     laboratory (CS2124).
 */
#ifndef CAMPSITE_H
#define CAMPSITE_H

#include <iostream>
#include <string>

#include "CampsiteRecord.h"

class Campsite {
public:
    Campsite( ) = default;
    Campsite( int number, std::string description, bool has_electric, double rate );
    Campsite( const CampsiteRecord& r );

    CampsiteRecord get_record() const;
    int            get_number( ) const;
    std::string    get_description( ) const;
    bool           has_electric( ) const;
    bool           get_rate( ) const;

    void set_number( int number );
    void set_description( std::string description );
    void set_has_electric( bool flag );
    void set_rate( double rate );

    std::ostream& write(std::ostream& strm) const;
    std::istream& from_ascii_file(std::istream& strm);
    
private:
    CampsiteRecord _rec;
};

std::ostream& operator<< (std::ostream& strm, const Campsite& site);

#endif