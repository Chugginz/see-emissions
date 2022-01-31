/**
 *******************************************************************************
 * @file    MovieNode.h
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

#ifndef MOVIENODE_H
#define MOVIENODE_H

#include "Movie.h"

class MovieNode {
public:
    //Constructor
    MovieNode(const Movie& new_movie) : payload{new_movie} {};
    //Accessors
    Movie         get_movie() const;
    MovieNode*    get_next() const;
    std::ostream& write(std::ostream& fout) const;
    //Mutator
    void          set_next(MovieNode* node);
    //Overloaded Operators
    bool operator<(const MovieNode& rhs) const;
    //Deconstructor
    ~MovieNode();
private:
    //Attributes
    Movie      payload;
    MovieNode* next = nullptr;
};

std::ostream& operator<<(std::ostream& fout, const MovieNode& node);

#endif