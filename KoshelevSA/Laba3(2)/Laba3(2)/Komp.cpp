#include "Komp.h"
#include "fraction.h"
#include <iostream>

using namespace std;

Kompl::Kompl(const Kompl&tmp) {
	this->a = tmp.a;
	this->b = tmp.b;
}



Kompl::Kompl(fraction _first, fraction _second)
{
	this->a = _first;
	this->b = _second;

}





Kompl::Kompl()
{
	this->a = fraction(0, 1);
	this->b = fraction(0, 1);
}

void Kompl::Otv()
{
	int h1, h2;
	int c1, c2;
	h1 = this->a.GetCH();
	h2 = this->b.GetCH();
	c1 = this->a.GetZN();
	c2 = this->b.GetZN();


	cout << "Komlexnoe chislo=(" << h1 << "/" << c1 << ")+(i*" << h2 << "/" << c2 << ")" << endl;
}

Kompl Kompl::operator+(const Kompl & tmp) const
{
	Kompl res;
	res.a = this->a + tmp.a; //комплексное число выглядит как a+b*i
	res.b = this->b + tmp.b; //комплексное число выглядит как a+b*i
	return res;
}

Kompl & Kompl::operator=(const Kompl & tmp)
{
	
	this->a = tmp.a;  //a=4
	this->b = tmp.b;
	return *this;
}

Kompl Kompl::operator+(int tmp) 
{
	Kompl res;
	res = *this;
	res.a.SetCH(this->a.GetZN()*tmp + this->a.GetCH());
	return res;
}

Kompl Kompl::operator-(const Kompl & tmp) const
{

	Kompl res;
	res.a = this->a - tmp.a; 
	res.b = this->b - tmp.b; 
	return res;
}

Kompl Kompl::operator/(const Kompl & tmp) const
{
	Kompl res;
	res.a = (this->a*tmp.a + this->b*tmp.b) / (tmp.a*tmp.a + tmp.b*tmp.b);
	res.a = (tmp.a*this->b - tmp.b*this->a) / (tmp.a*tmp.a + tmp.b*tmp.b);
	return Kompl();
}

Kompl Kompl::operator*(const Kompl & tmp) const
{
	Kompl res;
	res.a = this->a*tmp.a - this->b*tmp.b;
	res.b = this->a*tmp.b - this->b*tmp.a;
	return res;
}

Kompl& Kompl::operator+=(const Kompl & tmp)
{
	*this = *this + tmp;
	return *this;
}

Kompl& Kompl::operator-=(const Kompl & tmp)
{
	*this = *this - tmp;
	return *this;
}

Kompl& Kompl::operator*=(const Kompl & tmp)
{
	*this = *this * tmp;
	return *this;
}

Kompl& Kompl::operator/=(const Kompl & tmp)
{
	*this = *this / tmp;
	return *this;
}

Kompl Kompl::operator-(int tmp) 
{
	Kompl res;
	res = *this;
	res.a.SetCH(this->a.GetCH() - this->a.GetZN()*tmp);
	return res;
}

Kompl Kompl::operator/(int tmp) 
{
	Kompl res;
	res = *this;
	res.a.SetZN(this->a.GetZN()*tmp);
		return res;
}

Kompl Kompl::operator*(int tmp)
{
	Kompl res;
	res = *this;
	res.a.SetCH(this->a.GetCH()*tmp);
		return res;
}

bool Kompl::operator!=(Kompl & tmp)
{
	int a,b;
	a = this->a.GetCH()*tmp.a.GetZN();
	b = tmp.a.GetCH()*this->a.GetZN();
	if (a != b)
		return true;
	else
		return false;
	
}

bool Kompl::operator>(Kompl & tmp)
{
	int a, b;
	a = this->a.GetCH()*tmp.a.GetZN();
	b = tmp.a.GetCH()*this->a.GetZN();
	if (a > b)
		return true;
	else
		return false;

	return false;
}

bool Kompl::operator<(Kompl & tmp)
{
	int a, b;
	a = this->a.GetCH()*tmp.a.GetZN();
	b = tmp.a.GetCH()*this->a.GetZN();
	if (a < b)
		return true;
	else
		return false;
}

bool Kompl::operator==(Kompl & tmp)
{
	int a, b;
	a = this->a.GetCH()*tmp.a.GetZN();
	b = tmp.a.GetCH()*this->a.GetZN();
	if (a == b)
		return true;
	else
		return false;
}

bool Kompl::operator>=(Kompl & tmp)
{
	int a, b;
	a = this->a.GetCH()*tmp.a.GetZN();
	b = tmp.a.GetCH()*this->a.GetZN();
	if (a >= b)
		return true;
	else
		return false;
}

bool Kompl::operator<=(Kompl & tmp)
{
	int a, b;
	a = this->a.GetCH()*tmp.a.GetZN();
	b = tmp.a.GetCH()*this->a.GetZN();
	if (a <= b)
		return true;
	else
		return false;
}

Kompl & Kompl::operator+=(int tmp)
{
	*this = *this + tmp;
	return *this;
}

Kompl & Kompl::operator-=(int tmp)
{
	*this = *this - tmp;
	return *this;
}

Kompl & Kompl::operator/=(int tmp)
{
	*this = *this / tmp;
	return *this;
}

Kompl & Kompl::operator*=(int tmp)
{
	*this = *this * tmp;
	return *this;
}

istream & operator>>(istream & in, Kompl & tmp)
{
	in >> tmp.a;
	in >> tmp.b;
	return in;
}

ostream & operator<<(ostream & out, Kompl & tmp)
{
	out << tmp.a.GetCH() << "/" << tmp.a.GetZN() << "+" << tmp.b.GetCH() << "/" << tmp.b.GetZN()<<"*i";
	return out;
}










Kompl::~Kompl()
{
	this->a = fraction(0, 1);
	this->b = fraction(0, 1);
}


