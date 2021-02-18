//
// Created by Chris Hartman on 2/18/21.
//

#include "Rational.hpp"
Rational::Rational(int num, int den) : _numerator(num), _denominator(den) {
}

std::ostream &operator<<(std::ostream &os, const Rational &rhs) {
   return os << rhs._numerator << "/" << rhs._denominator;
}

Rational operator+(const Rational &lhs, const Rational &rhs) {
   //a/b + c/d = (ad+bc)/ad
   return Rational(lhs._numerator * rhs._denominator + rhs._numerator * lhs._denominator, lhs._denominator * rhs._denominator);
}

Rational & Rational::operator+=(const Rational &rhs) {
   _numerator = _numerator * rhs._denominator + rhs._numerator * _denominator;
   _denominator *= rhs._denominator;
   return *this;
}