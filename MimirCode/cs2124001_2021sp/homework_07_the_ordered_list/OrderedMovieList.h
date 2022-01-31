/**
 *******************************************************************************
 * @file    OrderedMovieList.h
 * @brief   
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      3/7/2021
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    March 7, 2021
 *******************************************************************************
**/

#ifndef ORDERED_MOVIE_LIST_H
#define ORDERED_MOVIE_LIST_H

#include "MovieNode.h"

class OrderedMovieList {
public:
    //Constructor
    OrderedMovieList() = default;
    //Accessor
    std::ostream& write(std::ostream& fout) const;
    bool is_empty() const;
    //Mutators
    Movie remove_front();
    void erase();
    void insert(const Movie& new_movie);
    //Destructor
    ~OrderedMovieList();
private:
    //Attributes
    MovieNode* head = nullptr;
    
};

std::ostream& operator<<(std::ostream& fout, const OrderedMovieList& list);

#endif