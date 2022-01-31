/**
 * Implementation for the Student class,
 * provided as part of the Composition of Objects lab.
 */
#include "Student.h"
#include <iomanip>

/**
 * Construct a student given the name and ID number
 *
 * @param name student name
 * @param id   student ID number
 */
Student::Student( std::string name, int id ) : _name{name}, _id{id} {}

/**
 * Provides output on stderr when student leaves scope for
 * debugging purposes only.
 */
Student::~Student( ) {
    std::cerr << "Student " << _name << " (" << _id << ") leaving scope."
              << std::endl;
}

/**
 * Accessor for student's name.
 *
 * @return student's name
 */
std::string Student::get_name( ) const {
    return _name;
}

/**
 * Accessor for student ID.
 *
 * @return student's ID
 */
int Student::get_id( ) const {
    return _id;
}

/**
 * Accessor for a particular exam score, given the exam number,
 * which starts counting from 1.
 *
 * @param exam_number  Exam number (Natural number, starts at 1.)
 * @return  the score of exam number `exam_number`
 */
double Student::get_exam_score( int exam_number ) const {
    return _exams.at( exam_number - 1 );
}

/**
 * Mutator allowing the student name to be changed.
 *
 * @param name new name for the student
 */
void Student::set_name( std::string name ) {
    _name = name;
}

/**
 * Mutator allowing the student ID to be changed.
 *
 * @param id new ID number for the student
 */
void Student::set_id( int id ) {
    _id = id;
}

/**
 * Mutator allowing a selected exam score to be updated, given
 * the exam number (starting from 1) and the new score.
 *
 * @param exam_number  Exam number (Natural number, starts at 1.)
 * @param score the updated score to store
 */
void Student::set_exam_score( int exam_number, double score ) {
    _exams.at( exam_number - 1 ) = score;
}

/**
 * Adds a new exam score for the student, as the last of their
 * exams.
 *
 * @param score value of new score to add
 */
void Student::add_exam_score( double score ) {
    _exams.push_back( score );
}

/**
 * Accessor for the student's overall exam average.
 *
 * @remarks The exam average is assumed to be 100% if
 *          no exams have been entered yet.
 *
 * @return student's current exam average
 */
double Student::get_average( ) const {
    auto sum{0.0};
    for ( const auto& score : _exams ) { sum += score; }
    return _exams.size( ) > 0 ? sum / _exams.size( ) : 100.0;
}

/**
 * Accessor for the number of exams the student has
 * taken.
 *
 * @return the number of exams stored for this student
 */
double Student::get_exam_count( ) const {
    return _exams.size( );
}

/**
 * Accessor for the student's current letter grade.
 *
 * @remarks Uses the scale:
 *          >= 90    : A
 *          [80, 90) : B
 *          [70, 80) : B
 *          [60, 70) : B
 *          < 60     : F
 *
 * @return [description]
 */
char Student::get_letter_grade( ) const {
    auto grade = 'F';
    auto avg   = get_average( );
    if ( avg >= 90.0 )
        grade = 'A';
    else if ( avg >= 80.0 )
        grade = 'B';
    else if ( avg >= 70.0 )
        grade = 'C';
    else if ( avg >= 60.0 )
        grade = 'D';
    return grade;
}

/**
 * Writes a string describing the student (name, ID, average, and letter
 * grade) to the stream specified by `strm`.  The default is stdout.
 *
 * @param strm stream to write into (default = stdout)
 * @return the modified stream `strm` is returned
 */
std::ostream& Student::write( std::ostream& strm ) const {
    strm << _name << " (" << _id << ") : " << std::fixed
         << std::setprecision( 2 ) << get_average( ) << " : "
         << get_letter_grade( );
    return strm;
}
