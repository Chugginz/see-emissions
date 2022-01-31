/**
 * @file Bill.h
 * @brief Defines the Bill class, representing a bill / receipt for a
 *        restaurant.
 */
#ifndef BILL_H
#define BILL_H

#include "ItemArray.h"
#include "MenuItem.h"

#include <iostream>

class Bill {
public:
    Bill() = default;
    void      add_item( const MenuItem& item );
    void      set_gratuity_amount( double amount );
    void      set_gratuity_pct( double percent );
    void      mark_as_paid();
    ItemArray get_items() const;
    bool      is_paid() const;
    double    get_total() const;
    double    get_subtotal() const;
    double    get_tax() const;
    double    get_gratuity() const;
    void      print( std::ostream& strm = std::cout ) const;
    bool      operator==( const Bill& rhs ) const;
    bool      operator!=( const Bill& rhs ) const;

    static constexpr double tax_rate = 0.085;

private:
    ItemArray items;
    bool      paid     = false;
    double    gratuity = 0.0;
};

std::ostream& operator<<( std::ostream& strm, const Bill& bill );

#endif  // !BILL_H