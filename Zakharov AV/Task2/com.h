#pragma once
#include<iostream>
#include "fruct.h"


class Complex
{
public:
	Complex(const Complex& tmp);
	Complex(fraction _first, fraction _second);
	Complex();
	void Otv();
	Complex& operator = (const Complex& tmp);
	~Complex();

private:
	fraction a;
	fraction b;


};