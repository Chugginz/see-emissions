/**
 * @file    Foo.h
 *
 * @brief   Defines a generic `Foo` object.
 */
#ifndef FOO_H
#define FOO_H

#include <iostream>
#include <string>

/**
 * @brief       `Foo` will report to stdout whenever objects are
 *              constructed or destroyed.
 * @detailed    `Foo` is useful for testing templated containers or
 *              any code where tracking individual object instances
 *              over time is important.
 *              The objects are default-constructible, copy-safe,
 *              and can provide their unique serial number, and
 *              print identifying information to an output stream.
 */
class Foo {
public:
    Foo( const std::string& = "" );
    Foo( const Foo& f );
    ~Foo( );
    int         serial( ) const;
    std::string tag( ) const;
    void        tag( std::string tag );
    Foo&        operator=( const Foo& f );
    static void suppress_output( bool setting = true );

private:
    static int  _count;
    static bool _quiet;
    int         _serial;
    std::string _tag;
    void        copy_from( const Foo& f, std::string who = "" );
    void        report( std::string who ) const;
};

std::ostream& operator<<( std::ostream&, const Foo& );

#endif
