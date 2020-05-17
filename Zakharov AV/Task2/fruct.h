#pragma once
class fraction
{

private:
	int chisl;
	int znam;
public:
	fraction();
	fraction(int a, int b);
	int GetCH();
	void SetCH(int a);
	int GetZN();
	void SetZN(int a);
	void Proizv(fraction _first, fraction _second);
	void Shastn(fraction _first, fraction _second);
	void Sum(fraction _first, fraction _second);
	void Razn(fraction _first, fraction _second);

};
