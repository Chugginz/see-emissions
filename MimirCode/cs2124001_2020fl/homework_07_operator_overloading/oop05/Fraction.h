// @ Fraction.h

class Fraction {
public:
    Fraction (int n, int d);
    void write (std::ostream& strm=std::cout) const;
    Fraction add (int i) const;
    Fraction operator+ (int i) const;
    Fraction operator+ (const Fraction& op2) const;
    //Homework Beginning
    //Subrtraction
    Fraction operator- (int i) const;
    Fraction operator- (const Fraction& op2) const;
    Fraction operator- (int i, const Fraction& op2) const;
    //Unary Subtraction
    Fraction operator- () const;
    //Multiplication
    Fraction operator* (int i) const;
    Fraction operator* (const Fraction& op2) const;
    //Division
    Fraction operator/ (int i) const;
    Fraction operator/ (const Fraction& op2) const;
    //Less Than
    bool operator< (int i) const;
    bool operator< (const Fraction& op2) const;
    bool operator< (int i, const Fraction& op2) const;
    //Greater Than
    bool operator> (int i) const;
    bool operator> (const Fraction& op2) const;
    bool operator> (int i, const Fraction& op2) const;
    //Less Than or Equal to
    bool operator<= (int i) const;
    bool operator<= (const Fraction& op2) const;
    bool operator<= (int i, const Fraction& op2) const;
    //Greater Than or Equal to
    bool operator>= (int i) const;
    bool operator>= (const Fraction& op2) const;
    bool operator>= (int i, const Fraction& op2) const;
    //Equal to
    bool operator== (int i) const;
    bool operator== (const Fraction& op2) const;
    bool operator== (int i, const Fraction& op2) const;
    //Not Equal to
    bool operator!= (int i) const;
    bool operator!= (const Fraction& op2) const;
    bool operator!= (int i, const Fraction& op2) const;
private:
    int numerator   = 0;
    int denominator = 1;
    void reduce();
};

Fraction operator+ (int i, const Fraction& f);
std::ostream& operator<< (std::ostream& outfile, const Fraction& f);