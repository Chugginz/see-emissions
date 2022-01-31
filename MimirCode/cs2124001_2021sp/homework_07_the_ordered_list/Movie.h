/**
 *******************************************************************************
 * @file    movie.h
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

#ifndef MOVIE_H
#define MOVIE_H

#include<iostream>
    using std::cout;
    using std::cin;
    using std::endl;
#include <string>
#include <vector>    
#include <iomanip>
#include <fstream>
#include <sstream>

struct Movie {
    std::string title;              /// Movie title
    unsigned short year;            /// Movie release year
    std::string director;           /// Director's name
    std::string rating;             /// Movie audience rating

    Movie(std::istream& infile);  /// construct given an input stream
    std::ostream& write(std::ostream& outfile) const;
};
std::ostream& operator<<(std::ostream& outfile, const Movie& movie);

#endif