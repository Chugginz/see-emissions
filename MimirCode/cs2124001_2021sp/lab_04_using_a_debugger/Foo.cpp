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
    if ( !_quiet ) report( "c-tor" );
}

/**
 * copy c-tor for `Foo` signals when copy is being made.
 */
Foo::Foo( const Foo& f ) {
    copy_from( f, "cp-c-tor" );
}

/**
 * d-tor for `Foo` reports the object's demise to stdout
 */
Foo::~Foo( ) {
    if ( !_quiet ) report( "d-tor" );
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

/**
 * Change this Foo element's tag to `tag`.
 *
 * @param tag new value for the tag on this Foo
 */
void Foo::tag( std::string tag ) {
    _tag = tag;
}

/**
 * copy into the current object from `f`
 * @param f   template to copy from
 * @param who the method (event) causing the copy to occur
 */
void Foo::copy_from( const Foo& f, std::string who ) {
    _serial = ++_count;
    _tag    = f._tag;
    if ( !_quiet ) report( who );
}

/**
 * report an action taken by `who` on the current object
 * @param who name (and perhaps description) of the action's trigger
 *            event (method).
 */
void Foo::report( std::string who ) const {
    std::cout << "*  " << who << " - Foo S#: " << _serial
              << ( _tag.length( ) > 0 ? " Tag: " : "" ) << _tag << "\n";
}

/// Number of `Foo` objects in existence.
int Foo::_count = 0;

/// Flag determining whether the Foo objects will squack with c-tor
/// and d-tor messages.
bool Foo::_quiet = false;

/**
 * Calling suppress_output will stop the messages from the
 * Foo c-tor and d-tor; calling with the argument "false" will
 * restore this output.
 *
 * @param f [description]
 * @return [description]
 */
void Foo::suppress_output( bool setting ) {
    _quiet = setting;
}

/**
 * assignment operator
 * @param   f   the object to use as a template
 * @returns     returns this modified object.
 */
Foo& Foo::operator=( const Foo& f ) {
    if ( !_quiet ) report( "overwritten during assign" );
    copy_from( f, "operator=" );
    return *this;
}

/**
 * stream insertion operator allowing a Foo object to be printed
 * into a `std::ostream`
 * @param   s   stream to write the object into
 * @param   f   Foo object to write into the stream
 * @return  the modified stream `s` is returned
 */
std::ostream& operator<<( std::ostream& s, const Foo& f ) {
    return s << "[Foo #" << f.serial( )
             << ( f.tag( ).length( ) > 0 ? " tag: \"" + f.tag( ) + "\"" : std::string{} )
             << "]";
}
