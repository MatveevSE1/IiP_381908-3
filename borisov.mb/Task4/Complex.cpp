#include "Complex.h"

//CONSTRUCTOR
Complex::Complex(Fraction* _Re, Fraction* _Im) {
	this->Re = new Fraction(_Re);
	this->Im = new Fraction (_Im);
}

//DEFAULT CONSTRUCTOR
Complex::Complex() {
	this->Re = new Fraction(0, 1);
	this->Im = new Fraction(0, 1);
}

//COPY CONSTRUCTOR
Complex::Complex(const Complex* tmp) {
	this->Re = tmp->Re;
	this->Im = tmp->Im;
}

Complex::Complex(const Complex& tmp) {
	this->Re = tmp.Re;
	this->Im = tmp.Im;
}

Complex::~Complex() {
}


//PRINT
void Complex::show_complex() {
	int ImNum = this->Im->getNum();
	int ImDen = this->Im->getDen();
	int ReNum = this->Re->getNum();
	int ReDen = this->Re->getDen();
	cout << ReNum << "/" << ReDen << " + (" << ImNum << "/" << ImDen << ")i" << endl;
}

//OVERLOAD OF =
Complex& Complex::operator=(const Complex* tmp) {
	this->Re = tmp->Re;
	this->Im = tmp->Im;
	return *this;
}

//OVERLOAD OF +
Complex Complex::operator+(const Complex* tmp) const {
	Fraction RESULTRE = new Fraction();
	RESULTRE = *this->Re + tmp->Re;
	Fraction RESULTIM = new Fraction();
	RESULTIM = *this->Im + tmp->Im;
	Complex TEMP = new Complex(&RESULTRE, &RESULTIM);
	return TEMP;
}

//OVERLOAD OF -
Complex Complex::operator-(const Complex* tmp) const {
	Fraction RESULTRE = new Fraction();
	RESULTRE = *this->Re - tmp->Re;
	Fraction RESULTIM = new Fraction();
	RESULTIM = *this->Im - tmp->Im;
	Complex TEMP = new Complex(&RESULTRE, &RESULTIM);
	return TEMP;
}

Complex Complex::operator*(const Complex* tmp) const {
	int ReNum, ReDen;
	int ReImNum, ReImDen;
	int ImReNum, ImReDen;
	int ImNum, ImDen;
	int fNum, fDen;
	int sNum, sDen;
	ComplexMulti(tmp, &ReNum, &ReDen, 1); //First Re * Second Re
	ComplexMulti(tmp, &ReImNum, &ReImDen, 2); //First Re * Second Im
	ComplexMulti(tmp, &ImReNum, &ImReDen, 3); //First Im * Second Re
	ComplexMulti(tmp, &ImNum, &ImDen, 4); //First Im * Second Im

	if (ReDen == ImNum) { //ReNum
		fNum = ReNum - ImNum;
		fDen = ReDen;
	}
	else {
		fNum = (ReNum * ImDen) - (ReDen * ImNum);
		fDen = ReDen * ImDen;
	}

	if (ReImDen == ImReDen) {
		sNum = ReImNum + ImReNum;
		sDen = ReImDen;
	}
	else {
		sNum = (ReImNum * ImReDen) + (ImReNum * ReImDen);
		sDen = ReImDen * ImReDen;
	}
	Fraction RESULTRE = new Fraction(fNum, fDen);
	Fraction RESULTIM = new Fraction(sNum, sDen);
	Complex TEMP = new Complex(&RESULTRE, &RESULTIM);
	return TEMP;
}
//OVERLOAD OF /
Complex Complex::operator/(const Complex* tmp) const {
	int num, den, num1, den1;
	//FIRST HALF
	this->Re->multiplication(*tmp->Re, &num, &den);	//First Re * Second Re
	Fraction first(num, den);						//Record result to the fraction first
	this->Im->multiplication(*tmp->Im, &num, &den);    //First Im * Second Im
	Fraction second(num, den);						//Record result to the fraction second
	tmp->Re->degree(&num, &den);						//Prepare for denominator. Get Second Re to higher degree
	Fraction third(num, den);						//Record result to the fraction third
	tmp->Im->degree(&num, &den);						//Get Second Im to higher degree
	Fraction fouth(num, den);						//Record result to the fraction fouth
	first.addition(second, &num, &den);				//Addition of first and second objects
	Fraction fNum(num, den);						//Result of numerator of first half
	third.addition(fouth, &num, &den);				//Addition if third and fourth objects
	Fraction fDen(num, den);						//Result of denominator of first half
	fNum.division(fDen, &num, &den);				// Result of fraction of first half
	Fraction fResult(num, den);						//Record to fraction fResult
	//SECOND HALF
	tmp->Re->multiplication(*this->Im, &num1, &den1);	//Second Re * First Im
	Fraction sfirst(num1, den1);					//Record result
	this->Re->multiplication(*tmp->Im, &num1, &den1);	//First Re * Second Im
	Fraction ssecond(num1, den1);					//Record result
	sfirst.substraction(ssecond, &num1, &den1);		//sfirst - ssecond
	Fraction sNum(num1, den1);						//Record result of numerator of second half
	sNum.division(fDen, &num1, &den1);				//Result of fraction of second half
	Fraction RESULTRE = new Fraction(num, den);						//temp object of Re
	Fraction RESULTIM = new Fraction(num1, den1);						//Temp object of Im
	Complex TEMP = new Complex(&RESULTRE, &RESULTIM);
	return TEMP;
}

//OVERLOAD OF ++
Complex& Complex::operator++() {
	int num = this->Re->getNum();
	this->Re->setNum(num += this->Re->getDen());
	return *this;
}

//OVERLOAD OF --
Complex& Complex::operator--() {
	int num = this->Re->getNum();
	this->Re->setNum(num -= this->Re->getDen());
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Complex* tmp) {
	int ReNum = tmp->Re->getNum();
	int ReDen = tmp->Re->getDen();
	int ImNum = tmp->Im->getNum();
	int ImDen = tmp->Im->getDen();
	out << ReNum << "/" << ReDen << "+(" << ImNum << "/" << ImDen << ")i" << endl;
	return out;
}

std::istream& operator>>(std::istream& in, Complex* tmp) {
	cout << "Enter real part" << endl;
	in >> tmp->Re;
	cout << "Enter imaginary part" << endl;
	in >> tmp->Im;
	return in;
}



//COMPLEX MULTIPLICATION
void Complex::ComplexMulti(const Complex *tmp, int* _num, int* _den, int test) const {
	if (test == 1) {
		*_num = this->Re->getNum() * tmp->Re->getNum();
		*_den = this->Re->getDen() * tmp->Re->getDen();
	}
	if (test == 2) {
		*_num = this->Re->getNum() * tmp->Im->getNum();
		*_den = this->Re->getDen() * tmp->Im->getDen();
	}
	if (test == 3) {
		*_num = this->Im->getNum() * tmp->Re->getNum();
		*_den = this->Im->getDen() * tmp->Re->getDen();
	}
	if (test == 4) {
		*_num = this->Im->getNum() * tmp->Im->getNum();
		*_den = this->Im->getDen() * tmp->Im->getDen();
	}
}


