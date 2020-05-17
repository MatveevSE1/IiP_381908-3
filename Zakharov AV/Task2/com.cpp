
#include "com.h"
#include "fruct.h"
#include <iostream>

using namespace std;

Complex::Complex(const Complex& tmp) {
	this->a = tmp.a;
	this->b = tmp.b;
}



Complex::Complex(fraction _first, fraction _second)
{
	this->a = _first;
	this->b = _second;

}

Complex::Complex()
{
	this->a = fraction(0, 1);
	this->b = fraction(0, 1);
}

void Complex::Otv()
{
	int h1, h2;
	int c1, c2;
	h1 = this->a.GetCH();
	h2 = this->b.GetCH();
	c1 = this->a.GetZN();
	c2 = this->b.GetZN();


	cout << "Комплексное число=" << h1 << "/" << c1 << "+i*" << h2 << "/" << c2 << endl;
}

Complex& Complex::operator=(const Complex& tmp)
{
	this->a = tmp.a;
	this->b = tmp.b;
	return*this;
}

Complex::~Complex()
{
	this->a = fraction(0, 1);
	this->b = fraction(0, 1);
}