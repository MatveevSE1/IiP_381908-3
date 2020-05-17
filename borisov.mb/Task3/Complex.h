#pragma once
#include "fraction.h"
using namespace std;


class Complex {
private:
	Fraction Re;
	Fraction Im;
public:
	Complex(Fraction _Re, Fraction _Im); //Re+Im*i
	Complex();
	Complex(const Complex& tmp);
	~Complex();
	void ComplexMulti(Complex tmp, int* _num, int* _den, int test) const;
	Complex& operator=(const Complex& tmp);
	Complex operator+(const Complex& tmp) const;
	Complex operator-(const Complex& tmp) const;
	Complex operator*(const Complex& tmp) const; //
	Complex operator/(const Complex& tmp) const; //
	Complex operator^(const int& tmp) const; //
	Complex operator%(const int& tmp) const;	
	Complex& operator+=(const Complex& tmp);
	Complex& operator+=(int tmp);
	Complex& operator-=(const Complex& tmp);
	Complex& operator-=(int tmp);
	Complex& operator*=(const Complex& tmp);
	Complex& operator*=(int tmp);
	Complex& operator/=(const Complex& tmp);
	Complex& operator/=(int tmp);
	Complex& operator%=(int tmp);
	Complex& operator++(); //
	Complex& operator++(int);
	Complex& operator--(); //
	Complex& operator--(int);
	friend std::ostream& operator<<(std::ostream& out, Complex& tmp);
	friend std::istream& operator>>(std::istream& in, Complex& tmp);
	bool operator==(const Complex& tmp) const;
	bool operator!=(const Complex& tmp) const;
	bool operator>(const Complex& tmp) const;
	bool operator<(const Complex& tmp) const;
	void show_complex(); 
};
