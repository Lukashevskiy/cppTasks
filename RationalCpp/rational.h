#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED
#include <istream>

using namespace std;
class Rational{
public:
    //чеслитель
    int numer;
    //знаменатель
    int denom;

    //конструкторы
    Rational();
    explicit Rational(int number);
    Rational(int n, int d);

    //переопределение операторов
    Rational& operator =(const Rational& r);

    Rational& operator +=(const Rational& r);
    Rational& operator +(const Rational& r) const;

    Rational& operator -(const Rational& r) const;
    Rational operator -() const;
    Rational& operator -=(const Rational& r);

    Rational& operator *=(const Rational& r);
    Rational& operator *(const Rational& r) const;

    Rational& operator /=(const Rational& r);
    Rational& operator /(const Rational& r) const;

    Rational& operator ++();
    Rational operator ++(int);

    Rational& operator --();
    Rational operator --(int);

    bool operator ==(const Rational& r) const;

    bool operator !=(const Rational& r) const;

    bool operator >=(const Rational& r) const;
    bool operator <=(const Rational& r) const;

    bool operator >(const Rational& r) const;
    bool operator <(const Rational& r) const;

    explicit operator int() const;
    explicit operator double() const;

    friend istream& operator >>(istream& in, Rational& r);
    friend ostream& operator << (ostream& out, const Rational& r);

    //функция сокращения дроби
    void simplify();
};

#endif // RATIONAL_H_INCLUDED
