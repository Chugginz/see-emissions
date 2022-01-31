/**
 *******************************************************************************
 * @file    movie.cpp
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

#include "Movie.h"

Movie::Movie(std::istream& infile){
    std::string line;
    std::string string_year;
    
    getline(infile, title, '|');
    getline(infile, string_year, '|');
    getline(infile, director, '|');
    getline(infile, rating);
    
    std::istringstream strm_year(string_year);
    strm_year >> year;
}

std::ostream& Movie::write(std::ostream& fout) const{
    fout << std::setiosflags(std::ios::left);
    fout << title << " (" << year << ") " << rating << " - " << director 
    << endl;
    fout << std::resetiosflags(std::ios::left);
    
    return fout;
}

std::ostream& operator<<(std::ostream& fout, const Movie& movie){
    movie.write(fout);
    
    return fout;
}