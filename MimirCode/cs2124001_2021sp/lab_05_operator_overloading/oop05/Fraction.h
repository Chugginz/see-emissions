// @ Fraction.h

class Fraction {
public:
    Fraction (int n, int d);
    void write (std::ostream& strm=std::cout) const;
    Fraction add (int i) const;
    Fraction operator+ (int i) const;
    Fraction operator+ (const Fraction& op2) const;
private:
    int numerator   = 0;
    int denominator = 1;
    void reduce();
    friend Fraction operator+ (int i, const Fraction& f);
    friend std::ostream& operator<< (std::ostream& outfile, const Fraction& f);
};