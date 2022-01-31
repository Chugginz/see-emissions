/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   
 *
 * @remarks
 *      Course:        Object Oriented Programming
 *      Due Date:      3/7/2021
 *      Instructor:    Jason Causey
 *
 * @author  Christian Huggins
 * @date    March 1, 2021
 *******************************************************************************
**/

#include "OrderedMovieList.h"

int main(){
    OrderedMovieList movie_list;
    std::ifstream    movie_db {"movies.txt"};
    if( movie_db ) {
        while ( movie_db.good() ) {
          movie_list.insert( Movie{movie_db} ); 
        }
        movie_db.close();
        cout << "Alphabetical listing of movies available:\n"
             << movie_list << "\n\n";
    }
    else{
        cout << "file not found!\n";
    }
    //I have no clue why a segmentation fault is going off when trying to write
    return 0;
}