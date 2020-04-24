#include "fraction.h"
using namespace std;
//Constructor
Fraction::Fraction(int _a) {
	this->numerator = 0;
	this->denominator = 1;
}
Fraction::Fraction(const Fraction& tmp) {
	this->numerator = tmp.numerator;
	this->denominator = tmp.denominator;
}
Fraction::Fraction(int _a, int _b) {
	this->numerator = _a;
	this->denominator = _b;
}

//Get
int Fraction::getNum() const {
	return this->numerator;
}

int Fraction::getDen() const {
	return this->denominator;
}

//Set
void Fraction::setNum(int newNum) {
	this->numerator = newNum;
}

void Fraction::setDen(int newDen) {
	this->denominator = newDen;
}

//Other Methods

void Fraction::show_fraction() {
	cout << this->numerator << "/" << this->denominator << endl;
}

void Fraction::addition(Fraction tmp, int * _num, int* _den) const { // +
	int Num1;
	int Num2;
	if (this->denominator == tmp.denominator) {
		*_num = this->numerator + tmp.numerator;
		*_den = tmp.denominator;
	}
	else {
		Num1 = this->numerator * tmp.denominator;
		Num2 = tmp.numerator * this->denominator;
		*_num = Num1 + Num2;
		*_den = this->denominator * tmp.denominator;
	}
}

void Fraction::substraction(Fraction tmp, int* _num, int* _den) const { // -
	int Num1;
	int Num2;
	if (this->denominator == tmp.denominator) {
		*_num = this->numerator - tmp.numerator;
		*_den = tmp.denominator;
	}
	else {
		Num1 = this->numerator * tmp.denominator;
		Num2 = tmp.numerator * this->denominator;
		*_num = Num1 - Num2;
		*_den = this->denominator * tmp.denominator;
	}
}

void Fraction::multiplication(Fraction tmp, int* _num, int* _den) const { // *
	*_num = this->numerator * tmp.numerator;
	*_den = this->denominator * tmp.denominator;
}

void Fraction::division(Fraction tmp, int* _num, int* _den) const { // /
	if (tmp.denominator == 0) {
		cout << "ERROR: SECOND FRACTION IS ZERO";
		return;
	}
	else {
		*_num = this->numerator * tmp.denominator;
		*_den = this->denominator * tmp.numerator;
	}
}

void Fraction::degree(int* _num, int* _den) const {
	*_num = this->numerator * this->numerator;
	*_den = this->denominator * this->denominator;
}

void Fraction::record(int _num, int _den) {
	this->numerator = _num;
	this->denominator = _den;
}

std::istream& operator>>(std::istream& in, Fraction& tmp) {
	int temp;
	cout << "Enter numerator: " << endl;
	in >> temp;
	tmp.setNum(temp);
	cout << "Enter denumerator: " << endl;
	in >> temp;
	tmp.setDen(temp);
	return in;
}

bool Fraction::operator==(const Fraction& tmp) const {
	if (this->denominator == tmp.denominator)
		return (this->numerator == tmp.denominator);
	else
		return (this->numerator * tmp.denominator == tmp.numerator * this->denominator);
}

Fraction Fraction::operator+(const Fraction& tmp) const {
	int num;
	int den;
	if (this->denominator == tmp.denominator) {
		num = this->numerator + tmp.numerator;
		den = tmp.denominator;
	}
	else {
		int Num1 = this->numerator * tmp.denominator;
		int Num2 = tmp.numerator * this->denominator;
		num = Num1 + Num2;
		den = this->denominator * tmp.denominator;
	}
	Fraction temp(num, den);
	return temp;
}
Fraction Fraction::operator*(const Fraction& tmp) const {
	int num = this->numerator * tmp.numerator;
	int den = this->denominator * tmp.denominator;
	Fraction temp(num, den);
	return temp;
}

bool Fraction::operator>(const Fraction& tmp) const {
	if ((this->numerator / this->denominator) > (tmp.numerator / tmp.denominator))
		return true;
	else
		return false;
}
