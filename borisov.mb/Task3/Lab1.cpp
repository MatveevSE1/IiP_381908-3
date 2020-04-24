#include <iostream>
#include "fraction.h"
#include "Complex.h"

void entering(int* _num, int* _den) {
	do {
	cout << "Enter numerator: ";
	cin >> *_num;
	if (*_num == 0) {
		cout << "ERROR: NUMERATOR IS ZERO" << endl;
	}
	} while (*_num == 0);
	do {
		cout << "Enter denominator: ";
		cin >> *_den;
		if (*_den == 0) {
			cout << "ERROR: DENOMINATOR IS ZERO" << endl;
		}
	} while (*_den == 0);
}

int main()
{
	using namespace std;
	int num;
	int den;
	cout << "RE" << endl;
	entering(&num, &den);
	Fraction First(num, den);
	cout << "IM" << endl;
	entering(&num, &den);
	Fraction Second(num, den);
	Complex FirstComplex(First, Second);
	cout << "==========" << endl;
	cout << "RE" << endl;
	entering(&num, &den);
	Fraction Third(num, den);
	cout << "IM" << endl;
	entering(&num, &den);
	Fraction Fouth(num, den);
	Complex SecondComplex(Third, Fouth);
	cout << "==========" << endl;
	cout << "First: ";
	FirstComplex.show_complex();
	cout << "Second: ";
	SecondComplex.show_complex();
	cout << "==========" << endl;
	Complex ResultComplex = FirstComplex * SecondComplex;
	cout << "Resut of *";
	ResultComplex.show_complex();
	cout << "==========" << endl;
	ResultComplex = FirstComplex / SecondComplex;
	cout << "Resut of /";
	ResultComplex.show_complex();
	cout << "==========" << endl;
	cout << "Enter degree: " << endl;
	int degree;
	cin >> degree;
	ResultComplex = FirstComplex ^ degree;
	cout << "Resut of ^";
	ResultComplex.show_complex();
	cout << "==========" << endl;
	cout << "Number: ";
	FirstComplex.show_complex();
	cout << "Result of ++";
	FirstComplex++;
	FirstComplex.show_complex();
	cout << "==========" << endl;
	cout << "Number: ";
	FirstComplex.show_complex();
	cout << "Result of --";
	FirstComplex--;
	FirstComplex.show_complex();
}	

