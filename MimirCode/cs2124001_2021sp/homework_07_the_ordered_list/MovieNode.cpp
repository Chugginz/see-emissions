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

#include "MovieNode.h"

Movie MovieNode::get_movie() const {
    return payload;
}

MovieNode* MovieNode::get_next() const{
    return next;
}

void MovieNode::set_next(MovieNode* node){
    next = node;
}

std::ostream& MovieNode::write(std::ostream& fout) const{
    payload.write(fout);
    
    return fout;
}

bool MovieNode::operator<(const MovieNode& rhs) const{
    bool result = false;
    if (payload.title < rhs.payload.title)
        result = true;
    
    return result;
}

std::ostream& operator<<(std::ostream& fout, const MovieNode& node){
    node.write(fout);
    
    return fout;
}

MovieNode::~MovieNode(){
    std::cout << "deleting " << payload.title << std::endl;
}