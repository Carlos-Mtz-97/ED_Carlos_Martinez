 /*
 * rational.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

#include "exception.h"
#include <string>
#include <sstream>

class Rational {
private:
	int numerator;
	int denominator;

	void normalize();

public:
	Rational();
	Rational(int);
	Rational(int, int);
	Rational(const Rational&);

	int getNumerator() const;
	int getDenominator() const;
	std::string toString() const;

	void operator=   (const Rational&);
	void operator+=  (const Rational&);

	operator double () const;
};

Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int num){
    numerator = num;
    denominator = 1;
}

Rational::Rational(int num, int dem){  
  numerator = num;
  denominator = dem;
  normalize();    
}

int Rational::getNumerator() const {
	return numerator;
}

int Rational::getDenominator() const {
	return denominator;
}

std::string Rational::toString() const {
	std::stringstream aux;
	aux << numerator << "/" << denominator;
	return aux.str();
}

Rational::operator double () const {
	return numerator / (double)denominator;
}

//Greatest common divisor
int gcd(int a, int b) {
	int aux;

	while (b != 0) {
		aux = b;
		b = a % b;
		a = aux;
	}
	return a;
}

void Rational::normalize() {
  int aux = 0;
  int aux_sign = 1;
  if (denominator == 0) {
		throw RangeError();
	}
  if (numerator < 0 || denominator < 0)
    aux_sign = -1;
  if (numerator < 0 && denominator < 0)
    aux_sign = 1;
  
  aux = gcd(numerator,denominator);
  
  numerator = abs(numerator / aux) * aux_sign;
  denominator = abs(denominator / aux);
  
}

void Rational::operator= (const Rational &right) {
  numerator = right.numerator;
  denominator = right.denominator;
}

void Rational::operator+= (const Rational &right) {
  int aux;
  aux = denominator * right.denominator;
  numerator = numerator * (aux / denominator) + right.numerator * (aux / right.denominator);
  denominator = aux;
  normalize();
}

Rational operator+ (const Rational &left, const Rational &right) {
  int num = 0;
  int dem = 0;
  dem = left.getDenominator() * right.getDenominator();
  num = left.getNumerator() * (dem / left.getDenominator()) + right.getNumerator() * (dem / right.getDenominator());

  return Rational(num,dem);
}

Rational operator- (const Rational &left, const Rational &right) {
	int num = 0;
  int dem = 0;
  dem = left.getDenominator() * right.getDenominator();
  num = left.getNumerator() * (dem / left.getDenominator()) - right.getNumerator() * (dem / right.getDenominator());

  return Rational(num,dem);
}

Rational operator- (const Rational &right) {
  int num = right.getNumerator() * -1;
	return Rational(num, right.getDenominator());
}

bool operator== (const Rational &left, const Rational &right) {
  int aux1;
  int aux2;

  aux1 = left.getNumerator() * right.getDenominator();
  aux2 = left.getDenominator() * right.getNumerator();

  if(aux1 == aux2){
	  return true;
  }  
  return false;
}

bool operator<  (const Rational &left, const Rational &right) {
  if((double)left < (double)right){
	  return true;
  }
  return false;
}

#endif /* RATIONAL_H_ */
