#ifndef STUDENT_H
#define STUDENT_H
/**
 * Definition of the Student class.
 * Provided as part of the Composition of Objects lab.
 */

#include <iostream>
#include <string>
#include <vector>

class Student {
public:
    Student( ) = default;
    Student( std::string name, int id );
    ~Student( );

    std::string get_name( ) const;
    int         get_id( ) const;
    double      get_exam_score( int exam_number ) const;
    double      get_average( ) const;
    double      get_exam_count( ) const;
    char        get_letter_grade( ) const;
    void        set_name( std::string name );
    void        set_id( int id );
    void        set_exam_score( int exam_number, double score );
    void        add_exam_score( double score );

    std::ostream& write( std::ostream& strm = std::cout ) const;

private:
    std::string         _name;
    int                 _id{0};
    std::vector<double> _exams;
};

#endif