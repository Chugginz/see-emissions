/**
 * @file MenuItem.h
 * @brief Defines the MenuItem class, representing a menu item in a restaurant.
 */
#ifndef MENUITEM_H
#define MENUITEM_H

#include <iomanip>
#include <iostream>
#include <string>

/**
 * MenuItem represents an item on a restaurant menu.
 */
class MenuItem {
public:
    /**
     * Construct a new Menu Item object
     *
     * @param name      name of the item
     * @param price     price each
     * @param quantity  quantity ordered
     */
    MenuItem( std::string name, double price, int quantity = 1 )
        : name{ name }, price{ price }, quantity{ quantity } {}

    /**
     * Get the name of the MenuItem
     *
     * @return std::string the name is returned
     */
    std::string get_name() const { return name; }

    /**
     * Get the price of the MenuItem
     *
     * @return double the price is returned
     */
    double get_price() const { return price; }

    /**
     * Get the quantity of the MenuItem ordered/sold
     *
     * @return int the quantity is returned
     */
    int get_quantity() const { return quantity; }

    /**
     * Set the name of the MenuItem
     *
     * @param name the updated name for the MenuItem
     */
    void set_name( std::string name ) { this->name = name; }

    /**
     * Set the price of the MenuItem
     *
     * @param price the updated price of the MenuItem
     */
    void set_price( double price ) { this->price = price; }

    /**
     * Set the quantity of the MenuItem
     *
     * @param quantity the updated quantity of this item ordere/sold
     */
    void set_quantity( int quantity ) { this->quantity = quantity; }

    /**
     * Support addition with a double on the right
     *
     * @param rhs       a double value to add to this item's value
     * @return double   total value (price * quantity) + right hand side
     */
    double operator+( double rhs ) const { return price * quantity + rhs; }

    /**
     * Support addition with another MenuItem object
     *
     * @param rhs       a second MenuItem whose value should be added to this
     *                  one
     * @return double   total value (price * quantity) + right hand side total
     *                  value
     */
    double operator+( const MenuItem& rhs ) const {
        return *this + ( rhs + 0.0 );  // hands off to double-on-right version.
    }

    /**
     * Print this item to a stream.
     *
     * @param strm the stream to print this item into
     */
    void print( std::ostream& strm ) const {
        // save initial stream flags
        std::ios_base::fmtflags orig_flags( strm.flags() );
        strm << std::setprecision( 2 ) << std::fixed;
        strm << name << ": " << quantity << " @ $" << price;
        strm.flags( orig_flags );  // restore original settings
    }

private:
    std::string name;      /// name of the MenuItem
    double      price;     /// price each for the MenuItem
    int         quantity;  /// quantity of this item ordered/sold
};

/**
 * @brief   Allows addition of a double to MenuItem.
 * @details MenuItem's total value is defined as its price * quantity.  This
 *          operator is defined in support of the accumulate function, so that
 *          a running total of items in a container can be easily determined.
 *
 * @param lhs       a floating-point value to add the item's total value
 * @param rhs       the menu item whose total should be added
 * @return double
 */
inline double operator+( double lhs, const MenuItem& rhs ) {
    return rhs + lhs;
}

/**
 * Allows a MenuItem to be printed to a stream with the << operator.
 *
 * @param strm the stream to print the item into
 * @param item the MenuItem to print
 * @return std::ostream& the stream is passed through to allow chaining <<
 */
inline std::ostream& operator<<( std::ostream& strm, const MenuItem& item ) {
    item.print( strm );
    return strm;
}

#endif  // !MENUITEM_H