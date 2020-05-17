#pragma once

#include <iostream>
using namespace std;

class fraction

{
private:
	int chisl;
	int znam;
public:
	int GetCH();
	void SetCH(int a);
	int GetZN();
	void SetZN(int a);
	void Proizv(int a1, int b1, int a2, int b2);
	void Shastn(int a1, int b1, int a2, int b2);
	void  Sum(int a1, int b1, int a2, int b2);
	void Razn(int a1, int b1, int a2, int b2);
};