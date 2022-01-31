#include "Foo.h"
#include <iostream>
#include <string>

void print( const Foo* begin, const Foo* end, const std::string& sep = ", ",
            std::ostream& strm = std::cout );
void sort( Foo* const begin, Foo* const end );
void reverse( Foo* begin, Foo* end );
Foo* search( const std::string& tag, const Foo* begin, const Foo* end );

int main( ) {
    Foo::suppress_output( );
    {  // Since this whole thing will repeat, create an artificial scope block
        const int size = 15;
        char      c1   = 'a';
        char      c2   = 'a';

        Foo test_array[size];
        for ( auto& foo : test_array ) {
            foo.tag( std::string{c1} + c2 );
            c1 = 'a' + ( c1 - 'a' + 7 ) % 26;
            c2 = 'a' + ( c2 - 'a' + 5 ) % 26;
        }

        std::cout << "Original values: \n";
        print( test_array, test_array + size );
        std::cout << "\n" << std::endl;

        sort( test_array, test_array + size );
        std::cout << "Sorted values: \n";
        print( test_array, test_array + size );
        std::cout << "\n" << std::endl;

        reverse( test_array, test_array + size );
        std::cout << "Reversed values: \n";
        print( test_array, test_array + size );
        std::cout << "\n" << std::endl;

        sort( test_array, test_array + size );
        std::cout << "Re-Sorted values (after reverse): \n";
        print( test_array, test_array + size );
        std::cout << "\n" << std::endl;

        // Brute force search for all 2-letter combos:
        for ( char first = 'a'; first <= 'z'; ++first ) {
            for ( char second = 'a'; second <= 'z'; ++second ) {
                std::string target{first};
                target += second;
                if ( search( target, test_array, test_array + size ) ) {
                    std::cout << "Found " << target << "\n";
                }
            }
        }
        std::cout << std::endl;
    }
    {  // The second time through the array will be a little larger.
        const int size = 20;
        char      c1   = 'a';
        char      c2   = 'a';

        Foo test_array[size];
        for ( auto& foo : test_array ) {
            foo.tag( std::string{c1} + c2 );
            c1 = 'a' + ( c1 - 'a' + 7 ) % 26;
            c2 = 'a' + ( c2 - 'a' + 5 ) % 26;
        }

        std::cout << "Original values: \n";
        print( test_array, test_array + size );
        std::cout << "\n" << std::endl;

        sort( test_array, test_array + size );
        std::cout << "Sorted values: \n";
        print( test_array, test_array + size );
        std::cout << "\n" << std::endl;

        reverse( test_array, test_array + size );
        std::cout << "Reversed values: \n";
        print( test_array, test_array + size );
        std::cout << "\n" << std::endl;

        sort( test_array, test_array + size );
        std::cout << "Re-Sorted values (after reverse): \n";
        print( test_array, test_array + size );
        std::cout << "\n" << std::endl;

        // Brute force search for all 2-letter combos:
        for ( char first = 'a'; first <= 'z'; ++first ) {
            for ( char second = 'a'; second <= 'z'; ++second ) {
                std::string target{first};
                target += second;
                if ( search( target, test_array, test_array + size ) ) {
                    std::cout << "Found " << target << "\n";
                }
            }
        }
        std::cout << std::endl;
    }
    return 0;
}

/**
 * Print all values in the Foo array range [begin,end)
 *
 * @param begin pointer to the first element to print
 * @param end   pointer to the byte following the last element
 * @param sep   string that should separate array elements [default ", "]
 * @param strm  stream that the output should be directed to [default `cout`]
 */
void print( const Foo* begin, const Foo* end, const std::string& sep,
            std::ostream& strm ) {
    for ( ; begin != end; ++begin ) {
        strm << ( *begin ) << ( ( begin + 1 ) != end ? sep : std::string{""} );
    }
}

/**
 * Performs a bubble sort on the section of a Foo array in the
 * range [begin,end).
 *
 * @param begin [description]
 * @param end [description]
 */
void sort( Foo* const begin, Foo* const end ) {
    bool did_swap = false;
    int  pass     = 0;

    do {
        did_swap = false;
        for ( auto current = begin; current != end - pass - 1; ++current ) {
            if ( current->tag( ) > ( current + 1 )->tag( ) ) {
                auto temp        = *current;
                *current         = *( current + 1 );
                *( current + 1 ) = temp;
                did_swap         = true;
            }
        }
        ++pass;
    } while ( did_swap );
}

/**
 * reverse the array values in range [begin,end)
 *
 * @param begin pointer to first element to reverse
 * @param end   pointer to byte following last element.
 */
void reverse( Foo* begin, Foo* end ) {
    --end;
    while ( (begin != end) && (end != begin - 1) ) {
        auto temp = *begin;
        *begin    = *end;
        *end      = temp;
        ++begin;
        --end;
    }
}

/**
 * Search for a tag in a Foo array within the range [begin,end);
 * a pointer to an object with the matching tag is returned if
 * it is found, otherwise `nullptr` is returned.
 *
 * @param tag    tag to search for
 * @param begin  first element in the range to search
 * @param end    pointer to the next byte following the range to search
 * @return       pointer to the element matching `tag`, or `nullptr` if
 *               no matching element was found
 */
Foo* search( const std::string& tag, const Foo* begin, const Foo* end ) {
    const Foo* result = nullptr;
    const Foo* mid    = nullptr;
    --end; // End and Beginning not meeting
    while ( (result == nullptr) && (begin != end) && (begin != end - 1) ) {
        mid = begin + ( end - begin ) / 2;
        if ( mid->tag( ) == tag ) {
            result = mid;
        } else if ( tag < mid->tag( ) ) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    return const_cast<Foo*>( result );
}
