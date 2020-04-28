#include "Header.h"

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

void fraction::Proizv(int a1, int b1, int a2, int b2)
{
	cout << "proizvedenie =" << a1 * a2 << "/" << b1 * b2 << endl;

}

void fraction::Shastn(int a1, int b1, int a2, int b2)
{
	cout << "chastnoe =" << a1 * b2 << "/" << b1 * a2 << endl;
}

void fraction::Sum(int a1, int b1, int a2, int b2)
{
	
	int b11;
		b11 = b1 * b2;
		a1 = a1 * b2;
		a2 = a2 * b1;
	

	

	cout << "summa =" << a1 + a2 << "/" << b11 << endl;

}

void fraction::Razn(int a1, int b1, int a2, int b2)
{
	int b11;
	b11 = b1 * b2;
	a1 = a1 * b2;
	a2 = a2 * b1;
	cout << "raznost' =" << a1 - a2 << "/" << b11 << endl;
}


