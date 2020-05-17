#pragma once
#include<iostream>
#include "fraction.h"



class Kompl
{
public:
	Kompl& operator=(const Kompl& tmp);
	Kompl& operator+=(int tmp);
	Kompl& operator-=(int tmp);
	Kompl& operator/=(int tmp);
	Kompl& operator*=(int tmp);
	Kompl operator+(int tmp);
	Kompl operator-(int tmp);
	Kompl operator/(int tmp);
	Kompl operator*(int tmp);
	Kompl operator+(const Kompl& tmp)const;
	Kompl operator-(const Kompl& tmp)const;
	Kompl operator/(const Kompl& tmp)const;
	Kompl operator*(const Kompl& tmp)const;
	Kompl& operator+=(const Kompl& tmp);
	Kompl& operator-=(const Kompl& tmp);
	Kompl& operator*=(const Kompl& tmp);
	Kompl& operator/=(const Kompl& tmp);
	bool operator!=(Kompl& tmp);
	bool operator>(Kompl& tmp);
	bool operator<(Kompl& tmp);
	bool operator==(Kompl& tmp);
	bool operator>=(Kompl& tmp);
	bool operator<=(Kompl& tmp);
	friend istream& operator>>(istream& in, Kompl& tmp);
	friend ostream& operator<<(ostream& out, Kompl& tmp);

	

	Kompl(const Kompl & tmp);
	Kompl(fraction _first, fraction _second);

	Kompl();
	void Otv();
	~Kompl();

private:
	fraction a;
	fraction b;
};
