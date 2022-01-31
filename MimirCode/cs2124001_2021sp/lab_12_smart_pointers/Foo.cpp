/**
 * @file        Foo.cpp
 *
 * @brief       Implementations for the generic Foo class.
 *
 * @detailed    Foo is simply designed to report when constructed and
 *              destroyed, and each Foo object has a unique serial
 *              number, so they can be tracked.
 */
#include "Foo.h"

/**
 * c-tor for `Foo` that allows an optional string "tag" to be
 * attached in addition to the serial number of the object.
 * The construction of the object will be announced to stdout.
 */
Foo::Foo( const std::string& tag ) : _serial{++_count}, _tag{tag} {
    // If tag is empty, set it to the serial number
    std::cout << "*  c-tor - Foo S#: " << _serial
              << ( _tag.length( ) > 0 ? " Tag: " : "" ) << _tag << "\n";
}

/**
 * d-tor for `Foo` reports the object's demise to stdout
 */
Foo::~Foo( ) {
    std::cout << "*  d-tor - Foo S#: " << _serial
              << ( _tag.length( ) > 0 ? " Tag: " : "" ) << _tag << "\n";
}

/**
 * get the serial number for this `Foo` instance
 * @return serial number is returned
 */
int Foo::serial( ) const {
    return _serial;
}

/**
 * get the tag string associated with this `Foo` instance
 * @return the tag is returned
 */
std::string Foo::tag( ) const {
    return _tag;
}

/// Number of `Foo` objects in existence.
int Foo::_count = 0;

/**
 * stream insertion operator allowing a Foo object to be printed
 * into a `std::ostream`
 * @param   s   stream to write the object into
 * @param   f   Foo object to write into the stream
 * @return  the modified stream `s` is returned
 */
std::ostream& operator<<( std::ostream& s, const Foo& f ) {
    return s << "[Foo instance #" << f.serial( ) << "]";
}
