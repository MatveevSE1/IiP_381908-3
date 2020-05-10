#include "Fraction.h"
using namespace std;
//Constructor
Fraction::Fraction(const Fraction& tmp) {
	this->numerator = tmp.numerator;
	this->denominator = tmp.denominator;
	cout << "CONSTRUCTOR COPY &" << this << endl;

}
Fraction::Fraction(const Fraction* tmp) {
	this->numerator = tmp->numerator;
	this->denominator = tmp->denominator;
	cout << "CONSTRUCTOR COPY *" << this << endl;

}
Fraction::Fraction(int _a, int _b) {
	this->numerator = _a;
	this->denominator = _b;
	cout << "CONSTRUCTOR PARAM" << this << endl;

}

//Get
int Fraction::getNum() const {
	return this->numerator;
}

int Fraction::getDen() const {
	return this->denominator;
}

//Set
void Fraction::setNum(int _Num) {
	this->numerator = _Num;
}

void Fraction::setDen(int _Den) {
	this->denominator = _Den;
}

//Other Methods
void Fraction::show_fraction() {
	cout << this->numerator << "/" << this->denominator << endl;
}

void Fraction::addition(Fraction tmp, int* _num, int* _den) const { // +
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

std::istream& operator>>(std::istream& in, Fraction* tmp) {
	int temp;
	cout << "Enter numerator: " << endl;
	in >> temp;
	tmp->setNum(temp);
	cout << "Enter denumerator: " << endl;
	in >> temp;
	tmp->setDen(temp);
	return in;
}

Fraction& Fraction::operator=(const Fraction& tmp) {
	this->numerator = tmp.numerator;
	this->denominator = tmp.denominator;
	return *this;
}

Fraction Fraction::operator+(const Fraction& tmp) const {
	int NumF;
	int NumS;
	int NumSum;
	int Den;
	if (this->denominator == tmp.denominator) {
		NumSum = this->numerator + tmp.numerator;
		Den = tmp.denominator;
	}
	else {
		NumF = this->numerator * tmp.denominator;
		NumS = tmp.numerator * this->denominator;
		NumSum = NumF + NumS;
		Den = this->denominator * tmp.denominator;
	}
	Fraction TEMP = new Fraction(NumSum, Den);
	return TEMP;
}

Fraction Fraction::operator-(const Fraction& tmp) const {
	int NumF;
	int NumS;
	int NumSub;
	int Den;
	if (this->denominator == tmp.denominator) {
		NumSub = this->numerator - tmp.numerator;
		Den = tmp.denominator;
	}
	else {
		NumF = this->numerator * tmp.denominator;
		NumS = tmp.numerator * this->denominator;
		NumSub = NumF - NumS;
		Den = this->denominator * tmp.denominator;
	}
	Fraction TEMP = new Fraction(NumSub, Den);
	return TEMP;

}

