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
    ~Foo( );
    int         serial( ) const;
    std::string tag( ) const;

private:
    static int  _count;
    int         _serial;
    std::string _tag;
};

std::ostream& operator<<( std::ostream&, const Foo& );

#endif
