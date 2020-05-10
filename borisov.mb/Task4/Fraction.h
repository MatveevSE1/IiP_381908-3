#pragma once
#include <iostream>
using namespace std;
class Fraction
{
	//Fields
private:
	int numerator;
	int denominator;
public:
	//Constructor
	Fraction(int _num, int _den);
	Fraction(const Fraction& tmp);
	Fraction(const Fraction* tmp);
	Fraction() {
		this->numerator = 1;
		this->denominator = 1;
		cout << "CONSTRUCTOR DEFAULT" << this << endl;

	}
	~Fraction() {
		cout << "DESTRUCTOR" << this << endl;
	}
	//Get
	int getNum() const;
	int getDen() const;
	//Set
	void setNum(int _Num);
	void setDen(int _Den);
	//Other Methods
	void addition(Fraction tmp, int* _num, int* _den) const;
	void substraction(Fraction tmp, int* _num, int* _den) const;
	void multiplication(Fraction tmp, int* _num, int* _den) const;
	void division(Fraction tmp, int* _num, int* _den) const;
	void degree(int* _num, int* _den) const;
	void show_fraction();
	void record(int _num, int _den);
	Fraction& operator=(const Fraction& tmp);
	Fraction operator+(const Fraction& tmp) const;
	Fraction operator-(const Fraction & tmp) const;
	friend std::istream& operator>>(std::istream& in, Fraction* tmp);
};
