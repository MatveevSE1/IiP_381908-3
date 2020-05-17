#include "Komp.h"
#include "fraction.h"
#include <iostream>

using namespace std;

Komp::Komp(const Komp&tmp) {
	this->a = tmp.a;
	this->b = tmp.b;
}



Komp::Komp(fraction _first, fraction _second)
{
	this->a = _first;
	this->b = _second;

}





Komp::Komp()
{
	this->a = fraction(0, 1);
	this->b = fraction(0, 1);
}

void Komp::Otv()
{
	int h1, h2;
	int c1, c2;
	h1 = this->a.GetCH();
	h2 = this->b.GetCH();
	c1 = this->a.GetZN();
	c2 = this->b.GetZN();


	cout << "Komlexnoe chislo=(" << h1 << "/" << c1 << ")+(i*" << h2 << "/" << c2 << ")" << endl;
}

Komp & Komp::operator=(const Komp & tmp)
{
	this->a = tmp.a;
	this->b = tmp.b;
	return*this;
}

Komp::~Komp()
{
	this->a = fraction(0, 1);
	this->b = fraction(0, 1);
}