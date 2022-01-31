// @ StudentArrayV4.h

#ifndef STUDENTARRAYV4_H
#define STUDENTARRAYV4_H

class StudentArrayV4 {  // version 4: dynamic array of object pointers
public:
    StudentArrayV4( );
    ~StudentArrayV4( );
    void      add( const Student& new_student );
    int       add_all_from( istream& infile );
    ostream&  write( ostream& outfile=cout ) const;
    void      add_from( istream& infile );

private:
    Student** members            = nullptr;
    int       number_of_students = 0;
    int       physicalArraySize  = 0;
};

#endif