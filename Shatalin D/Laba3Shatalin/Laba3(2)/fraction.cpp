#include "fraction.h"
#include <iostream>
using namespace std;

fraction::fraction()
{
	this->chisl = 0;
	this->znam = 1;
}

fraction::fraction(int a, int b)
{
	this->chisl = a;
	this->znam = b;
}

int fraction::GetCH()
{
	return this->chisl;
}

void fraction::SetCH(int a)
{
	this->chisl = a;

}


int fraction::GetZN()
{
	return this->znam;
}

void fraction::SetZN(int a)
{
	this->znam = a;
}

void fraction::Proizv(fraction _first, fraction _second)
{

	if (_first.chisl * _second.chisl % _first.znam * _second.znam == 0 
		) {

		cout << "Произведение =" << _first.chisl * _second.chisl / _first.znam * _second.znam << endl;
	}
	else
		cout << "Произведение =" << _first.chisl * _second.chisl << "/" << _first.znam * _second.znam << endl;
	
}

void fraction::Shastn(fraction _first, fraction _second)
{

	cout << "Частное =" << _first.chisl * _second.chisl << "/" << _first.znam * _second.znam << endl;
}

void fraction::Sum(fraction _first, fraction _second)
{

	int b11;
	b11 = _first.znam * _second.znam;
	_first.chisl = _first.chisl * _second.znam;
	_second.chisl = _second.chisl * _first.znam;




	cout << "Сумма =" << _first.chisl + _second.chisl << "/" << b11 << endl;

}

void fraction::Razn(fraction _first, fraction _second)
{
	int b11;
	b11 = _first.znam * _second.znam;
	_first.chisl = _first.chisl * _second.znam;
	_second.chisl = _second.chisl * _first.znam;

	cout << "Разность =" << _first.chisl - _second.chisl << "/" << b11 << endl;
}

fraction fraction::operator+(const fraction& tmp) const
{
	fraction res;
	res.znam = this->znam * tmp.znam;
	res.chisl = this->chisl * tmp.znam+this->znam*tmp.chisl;
	return res;
}

fraction fraction::operator-(const fraction& tmp) const
{
	fraction res;
	res.znam = this->znam * tmp.znam;
	res.chisl = this->chisl * tmp.znam - this->znam * tmp.chisl;
	return res;
}

fraction fraction::operator*(const fraction& tmp) const
{
	fraction res;
	res.znam = this->znam * tmp.znam;
	res.chisl = this->chisl * tmp.chisl;
	return res;
}

fraction fraction::operator/(const fraction& tmp) const

{
	fraction res;
	res.znam = this->znam * tmp.chisl;
	res.chisl = this->chisl * tmp.znam;
	return res;
}

istream& operator>>(istream& in, fraction& tmp)
{
	int r, f;
	in >> r;
	in >> f;
	tmp.SetCH(r);
	tmp.SetZN(f);
	return in;
}
