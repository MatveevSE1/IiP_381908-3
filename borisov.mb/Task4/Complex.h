#pragma once
#include "Fraction.h"
class Complex
{
private:
	Fraction* Re;
	Fraction* Im;
public:
	Complex(Fraction *_Re, Fraction *_Im);
	Complex();
	Complex(const Complex* tmp);
	Complex(const Complex& tmp);
	~Complex();
	void show_complex();
	void ComplexMulti(const Complex* tmp, int* _num, int* _den, int test) const;
	Complex& operator=(const Complex* tmp);
	Complex operator+(const Complex* tmp) const;
	Complex operator-(const Complex* tmp) const;
	Complex operator*(const Complex* tmp) const;
	Complex operator/(const Complex* tmp) const;
	Complex& operator++();
	Complex& operator--();
	friend std::ostream& operator<<(std::ostream& out, const Complex* tmp);
	friend std::istream& operator>>(std::istream& in, Complex* tmp);
};

