// @ StudentArrayV3.h

#ifndef STUDENTARRAYV3_H
#define STUDENTARRAYV3_H

#include "Student.h"

class StudentArrayV3 {  // version 3: automatic array of object pointers
public:
    StudentArrayV3( );
    ~StudentArrayV3( );
    void add( );
    void write( );

    const static int max_array_size = 1000;

private:
    Student* members[max_array_size];
    int      number_of_students = 0;
};

#endif