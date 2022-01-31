/**
 * @file bill_generator.cpp
 * @brief Provides functionality to generate random bills for development and
 *        testing.
 */
#ifndef BILL_GENERATOR_H
#define BILL_GENERATOR_H

#include "Bill.h"
#include "MenuItem.h"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>

/**
 * @brief Generates a vector of random `Bill` objects, given the numbe
 *        of bills to generate and the name of a text file containing
 *        menu item names (one per line).
 *
 * @param number_of_bills the number of bills to add to the returned vector
 * @param food_names_file file name of a text file containing menu item names,
 *                        one per line
 * @param random_seed     a seed value for deterministic random sequence
 *                        generation, to support reproducible sequences.  Set to
 *                        -1 to seed with system time (non-reproducible).
 *                        Defaults to seeding with time.
 *
 * @return std::vector<Bill> a vector with `number_of_bills` of random data is
 *                           returned
 */
std::vector<Bill> generate_random_bills( int         number_of_bills,
                                         std::string food_names_file,
                                         int         random_seed = -1 ) {
    static bool seeded = false;
    if ( random_seed >= 0 ) {  // See if we have seeded previously or if user
                               // wants to specify a seed.
        srand( random_seed );  // ensure we only see once in the entire run of
                               // the program unless the user "asks" to re-seed.
    } else if ( !seeded ) {
        srand( time( 0 ) );
    }
    seeded = true;

    std::ifstream fin{ food_names_file };
    if ( !fin ) {
        throw std::runtime_error{ std::string{ "Could not open file: " }
                                  + food_names_file };
    }
    std::vector<std::string> all_names;
    while ( fin ) {
        std::string next_name;
        getline( fin, next_name );
        if ( fin ) { all_names.push_back( next_name ); }
    }
    int number_of_names = all_names.size();

    std::vector<Bill> bills;
    for ( int i = 0; i < number_of_bills; ++i ) {
        Bill new_bill;
        // between 1 and 12 items per Bill.
        // odds of adding more items decrease, favoring fewer items.
        int n_items = 1;
        if ( rand() % 100 >= 10 ) n_items += rand() % 6;
        if ( rand() % 100 >= 50 ) n_items += rand() % 4;
        if ( rand() % 100 >= 80 ) n_items += rand() % 4;

        for ( int j = 0; j < n_items; ++j ) {
            std::string name  = all_names.at( rand() % number_of_names );
            double      price = ( rand() % 3301 + 99 ) / 100.0;  // .99 to 33.00
            // 1, 2, or 3, with 1 most likely:
            int quantity = 1;
            if ( rand() % 100 >= 75 ) quantity += rand() % 2;
            if ( rand() % 100 >= 85 ) quantity += rand() % 2;
            new_bill.add_item( MenuItem{ name, price, quantity } );
        }
        bills.push_back( new_bill );
    }
    return bills;
}

std::vector<Bill> random_gratuities_and_paid( std::vector<Bill> bills ) {
    // Add some tips and pay some bills:
    for ( int i = 0; i < bills.size() * ( ( rand() % 90 + 10 ) / 100.0 );
          ++i ) {
        int idx = rand() % bills.size();
        bills.at( idx ).set_gratuity_pct( rand() % 18 + 10 );
        if ( rand() % 100 >= 20 ) bills.at( idx ).mark_as_paid();
    }
    return bills;
}

#endif  // !BILL_GENERATOR_H