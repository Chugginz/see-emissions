/**
 * @file Bill.cpp
 * @brief Implementations of methods/functions related to class Bill
 */
#include "Bill.h"
#include "ItemArray.h"
#include "MenuItem.h"

#include <cmath>
#include <iomanip>
#include <numeric>

/**
 * add an item to the customer's bill
 *
 * @param item new item to add
 */
void Bill::add_item( const MenuItem& item ) {
    items.push_back( item );
}

/**
 * directly set a gratuity amount in dollars
 *
 * @throw std::range_error is thrown if the amount is negative.
 * @param amount the exact amount of gratuity to add to the bill
 */
void Bill::set_gratuity_amount( double amount ) {
    if ( amount < 0 )
        throw std::range_error{ "Negative gratuity is not allowed." };
    gratuity = amount;
}

/**
 * add a gratuity as a percentage, applied to the subtotal
 * @details The gratuity amount should be rounded to the nearest cent.
 *
 * @throw std::range_error is thrown if the percentage is negative.
 * @param percent the percent gratuity to add, expressed as e.g. 20.0
 */
void Bill::set_gratuity_pct( double percent ) {
    if ( percent < 0 )
        throw std::range_error{ "Negative gratuity is not allowed." };
    gratuity
        = static_cast<int>( ( percent / 100.0 ) * get_subtotal() * 100 + 0.5 )
          / 100.0;
}

/**
 * mark the bill as paid
 */
void Bill::mark_as_paid() {
    paid = true;
}

/**
 * get a copy of the items associated with this bill
 *
 * @return ItemArray a copy of the items on this bill
 */
ItemArray Bill::get_items() const {
    return items;
}

/**
 * determine whether the bill is paid or not
 *
 * @return true  if the bill was paid
 * @return false if the bill was not paid
 */
bool Bill::is_paid() const {
    return paid;
}

/**
 * get the total amount of this customer's bill
 *
 * @return double the total amount is returned, including tax and gratuity
 */
double Bill::get_total() const {
    return get_subtotal() + get_tax() + get_gratuity();
}

/**
 * get the subtotal of all items on this bill
 *
 * @return double the subtotal is returned (no tax or gratuity)
 */
double Bill::get_subtotal() const {
    return std::accumulate( items.cbegin(), items.cend(), 0.0 );
}

/**
 * get the amount of sales tax required for this bill
 * @details the tax amount is rounded up to the nearest cent
 *
 * @return double sales tax amount is returned
 */
double Bill::get_tax() const {
    // Rounds tax up to next cent (e.g. 1.143 --> 1.15)
    return ceil( tax_rate * get_subtotal() * 100.0 ) / 100.0;
}

/**
 * get the amount of gratuity the customer wants to add to the bill
 *
 * @return double the amount of gratuity (in dollars) is returned
 */
double Bill::get_gratuity() const {
    return gratuity;
}

/**
 * print the bill (if not paid) or recept (if paid)
 *
 * @param strm the stream that the bill/receipt should be printed to
 */
void Bill::print( std::ostream& strm ) const {
    const int desc_width  = 52;
    const int price_width = 7;

    // save initial stream flags
    std::ios_base::fmtflags orig_flags( strm.flags() );

    strm << ( ( !paid ) ? "Bill:\n" : "Receipt (PAID - Thank you!)\n" );

    for ( int i = 0; i < desc_width + price_width + 1; ++i ) { strm << '-'; }
    strm << "\n";
    if ( items.size() < 1 ) { strm << "\tNo items ordered.\n"; }
    strm << std::showpoint << std::fixed << std::setprecision( 2 );
    for ( const auto& item : items ) {
        for ( int i = 0; i < item.get_quantity(); ++i ) {
            strm << std::setw( desc_width ) << std::left << item.get_name()
                 << "$" << std::right << std::setw( price_width )
                 << item.get_price();
            strm << "\n";
        }
    }
    for ( int i = 0; i < desc_width + price_width + 1; ++i ) { strm << '-'; }
    strm << "\n";
    strm << std::left << std::setw( desc_width ) << "Subtotal:"
         << "$" << std::right << std::setw( price_width ) << get_subtotal()
         << "\n";
    strm << std::left << std::setw( desc_width ) << "Tax: "
         << "$" << std::right << std::setw( price_width ) << get_tax() << "\n";
    if ( get_gratuity() > 0 ) {
        strm << std::left << std::setw( desc_width ) << "Gratuity: "
             << "$" << std::right << std::setw( price_width ) << get_gratuity()
             << "\n";
    }
    strm << std::left << std::setw( desc_width ) << "Total: "
         << "$" << std::right << std::setw( price_width ) << get_total()
         << "\n";

    strm.flags( orig_flags );  // restore original settings
}

/**
 * @brief checks to see if two bills are equal
 * @details equality is defined as all items match in name and
 *          quantity, and the price and gratuity are equal
 *          (to the cent), and the paid flags match.
 * @param rhs       other bill to compare to
 * @return true     if bills are equal, true is returned
 * @return false    if bills are not equal, false is returned.
 */
bool Bill::operator==( const Bill& rhs ) const {
    // check the easy things first: paid flag and gratuity
    bool equal = paid == rhs.paid;
    if ( fabs( get_gratuity() - rhs.get_gratuity() ) >= 0.005 ) equal = false;
    // items arrays must match in size
    equal = equal && ( items.size() == rhs.items.size() );
    // Check all items for equality of name, price, and quantity
    for ( auto i = 0 * items.size(); equal && i < items.size(); ++i ) {
        if ( items[i].get_name() != rhs.items[i].get_name() )
            equal = false;
        else if ( fabs( items[i].get_price() - rhs.items[i].get_price() )
                  >= 0.005 )
            equal = false;
        else if ( items[i].get_quantity() != rhs.items[i].get_quantity() )
            equal = false;
    }
    // At this point, the equal flag is only true if they are really equal.
    return equal;
}

/**
 * @brief checks to see if two bills are  unequal
 * @details see the operator== definition for equality
 *          definition for Bill.
 * @param rhs       other bill to compare to
 * @return true     if bills are unequal, true is returned
 * @return false    if bills are equal, false is returned.
 */
bool Bill::operator!=( const Bill& rhs ) const {
    return !( *this == rhs );
}

/**
 * support stream insertion, printing the bill/recipt to the stream on the left
 *
 * @param strm the stream to print the bill/receipt into
 * @param bill the bill that should be printed
 * @return std::ostream& the stream is returned to facilitate cascading <<
 *                       operations
 */
std::ostream& operator<<( std::ostream& strm, const Bill& bill ) {
    bill.print( strm );
    return strm;
}
