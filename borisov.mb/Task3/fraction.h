#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

class Fraction {
	//Fields
private:
	int numerator;
	int denominator;
public:
	//Constructor
	Fraction(int _num, int _den);
	Fraction(const Fraction& tmp);
	Fraction(int a);
	Fraction() {
		this->numerator = 0;
		this->denominator = 0;
	}
	//Get
	int getNum() const;
	int getDen() const;
	//Set
	void setNum(int newNum);
	void setDen(int newDen);
	//Other Methods
	void addition(Fraction tmp, int* _num, int* _den) const;
	void substraction(Fraction tmp, int* _num, int* _den) const;
	void multiplication(Fraction tmp, int* _num, int* _den) const;
	void division(Fraction tmp, int* _num, int* _den) const;
	void degree(int* _num, int* _den) const;
	void show_fraction();
	void record(int _num, int _den);
	friend std::istream& operator>> (std::istream& in, Fraction& tmp);
	bool operator==(const Fraction& tmp) const;
	bool operator>(const Fraction& tmp) const;
	Fraction operator+(const Fraction& tmp) const;
	Fraction operator*(const Fraction& tmp) const;
	~Fraction() {
	}

};
