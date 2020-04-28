#pragma once

#include<iostream>
#include "fraction.h"


class Komp
{
public:
	Komp(const Komp & tmp);
	Komp(fraction _first, fraction _second);

	Komp();
	void Otv();
	Komp& operator = (const Komp& tmp);
	~Komp();

private:
	fraction a;
	fraction b;


};
