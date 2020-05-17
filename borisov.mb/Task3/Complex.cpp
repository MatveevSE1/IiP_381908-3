#include "Complex.h"

//CONSTRUCTOR
Complex::Complex(Fraction _Re, Fraction _Im) {
	this->Re = _Re;
	this->Im = _Im;
}

//DEFAULT CONSTRUCTOR
Complex::Complex() {
	this->Re = Fraction(0);
	this->Im = Fraction(0);
}

//COPY CONSTRUCTOR
Complex::Complex(const Complex& tmp) {
	this->Re = tmp.Re;
	this->Im = tmp.Im;
}
//DESTRUCTOR
Complex::~Complex() {
	this->Re = Fraction(0);
	this->Im = Fraction(0);
}

//COMPLEX MULTIPLICATION
void Complex::ComplexMulti(Complex tmp, int* _num, int* _den, int test) const{
	if (test == 1) {
		*_num = this->Re.getNum() * tmp.Re.getNum();
		*_den = this->Re.getDen() * tmp.Re.getDen();
	}
	if (test == 2) {
		*_num = this->Re.getNum() * tmp.Im.getNum();
		*_den = this->Re.getDen() * tmp.Im.getDen();
	}
	if (test == 3) {
		*_num = this->Im.getNum() * tmp.Re.getNum();
		*_den = this->Im.getDen() * tmp.Re.getDen();
	}
	if (test == 4) {
		*_num = this->Im.getNum() * tmp.Im.getNum();
		*_den = this->Im.getDen() * tmp.Im.getDen();
	}
}

//OVERLOAD OF =
Complex& Complex::operator=(const Complex& tmp)
{
	this->Re = tmp.Re;
	this->Im = tmp.Im;
	return *this;
}

//OVERLOAD OF +
Complex Complex::operator+(const Complex& tmp) const{	
	int ImDen = 0;
	int ImNumSum = 0;
	int ReDen = 0;
	int ReNumSum = 0;
	if (this->Re.getDen() == tmp.Re.getDen()) {
		ReNumSum = this->Re.getNum() + tmp.Re.getNum();
		ReDen = tmp.Re.getDen();
	}
	else {
		int ReNum1 = this->Re.getNum() * tmp.Re.getDen();
		int ReNum2 = tmp.Re.getNum() * this->Re.getDen();
		ReNumSum = ReNum1 + ReNum2;
		ReDen = this->Re.getDen() * tmp.Re.getDen();
	}

	if (this->Im.getDen() == tmp.Im.getDen()) {
		ImNumSum = this->Im.getNum() + tmp.Im.getNum();
		ImDen = tmp.Im.getDen();
	}
	else {
		int ImNum1 = this->Im.getNum() * tmp.Im.getDen();
		int ImNum2 = tmp.Im.getNum() * this->Im.getDen();
		ImNumSum = ImNum1 + ImNum2;
		ImDen = this->Im.getDen() * tmp.Im.getDen();
	}
	Fraction TEMP1(ReNumSum, ReDen);
	Fraction TEMP2(ImNumSum, ImDen);
	Complex TEMP(TEMP1, TEMP2);
	return TEMP;
}

//OVERLOAD OF -
Complex Complex::operator-(const Complex& tmp) const {
	int ImDen = 0;
	int ImNumSub = 0;
	int ReDen = 0;
	int ReNumSub = 0;
	if (this->Re.getDen() == tmp.Re.getDen()) {
		ReNumSub = this->Re.getNum() + tmp.Re.getNum();
		ReDen = tmp.Re.getDen();
	}
	else {
		int ReNum1 = this->Re.getNum() * tmp.Re.getDen();
		int ReNum2 = tmp.Re.getNum() * this->Re.getDen();
		ReNumSub = ReNum1 - ReNum2;
		ReDen = this->Re.getDen() * tmp.Re.getDen();
	}

	if (this->Im.getDen() == tmp.Im.getDen()) {
		ImNumSub = this->Im.getNum() - tmp.Im.getNum();
		ImDen = tmp.Im.getDen();
	}
	else {
		int ImNum1 = this->Im.getNum() * tmp.Im.getDen();
		int ImNum2 = tmp.Im.getNum() * this->Im.getDen();
		ImNumSub = ImNum1 - ImNum2;
		ImDen = this->Im.getDen() * tmp.Im.getDen();
	}
	Fraction TEMP1(ReNumSub, ReDen);
	Fraction TEMP2(ImNumSub, ImDen);
	Complex TEMP(TEMP1, TEMP2);
	return TEMP;
}

//OVERLOAD OF *
Complex Complex::operator*(const Complex& tmp) const{
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
	Fraction TEMP1(fNum, fDen);
	Fraction TEMP2(sNum, sDen);
	Complex TEMP(TEMP1, TEMP2);
	return TEMP;
}

//OVERLOAD OF /
Complex Complex::operator/(const Complex& tmp) const{
	int num, den, num1, den1;
	//FIRST HALF
	this->Re.multiplication(tmp.Re, &num, &den);	//First Re * Second Re
	Fraction first(num, den);						//Record result to the fraction first
	this->Im.multiplication(tmp.Im, &num, &den);    //First Im * Second Im
	Fraction second(num, den);						//Record result to the fraction second
	tmp.Re.degree(&num, &den);						//Prepare for denominator. Get Second Re to higher degree
	Fraction third(num, den);						//Record result to the fraction third
	tmp.Im.degree(&num, &den);						//Get Second Im to higher degree
	Fraction fouth(num, den);						//Record result to the fraction fouth
	first.addition(second, &num, &den);				//Addition of first and second objects
	Fraction fNum(num, den);						//Result of numerator of first half
	third.addition(fouth, &num, &den);				//Addition if third and fourth objects
	Fraction fDen(num, den);						//Result of denominator of first half
	fNum.division(fDen, &num, &den);				// Result of fraction of first half
	Fraction fResult(num, den);						//Record to fraction fResult
	//SECOND HALF
	tmp.Re.multiplication(this->Im, &num1, &den1);	//Second Re * First Im
	Fraction sfirst(num1, den1);					//Record result
	this->Re.multiplication(tmp.Im, &num1, &den1);	//First Re * Second Im
	Fraction ssecond(num1, den1);					//Record result
	sfirst.substraction(ssecond, &num1, &den1);		//sfirst - ssecond
	Fraction sNum(num1, den1);						//Record result of numerator of second half
	sNum.division(fDen, &num1, &den1);				//Result of fraction of second half
	Fraction TEMP1(num, den);						//temp object of Re
	Fraction TEMP2(num1, den1);						//Temp object of Im
	Complex TEMP(TEMP1, TEMP2);
	return TEMP;
}

Complex Complex::operator^(const int& tmp) const{
	int ReNum = this->Re.getNum();
	int ReDen = this->Re.getDen();
	int ImNum = this->Im.getNum();
	int ImDen = this->Im.getDen();
	int ReNumTmp = ReNum;
	int ReDenTmp = ReDen;
	int ImNumTmp = ImNum;
	int ImDenTmp = ImDen;
	if (tmp == 0) {
		ReNum = 1;
		ReDen = 1;
		ImNum = 1;
		ImDen = 1;
	}
	else {
		for (int i = 1; i < tmp; i++) {
			ReNum *= ReNumTmp;
			ReDen *= ReDenTmp;
			ImNum *= ImNumTmp;
			ImDen *= ImDenTmp;
		}
	}
	Fraction TEMP1(ReNum, ReDen);
	Fraction TEMP2(ImNum, ImDen);
	Complex TEMP(TEMP1, TEMP2);
	return TEMP;
}

Complex Complex::operator%(const int& tmp) const{
	int ReNum = this->Re.getNum() % tmp;
	int ReDen = this->Re.getDen() % tmp;
	int ImNum = this->Im.getNum() % tmp;
	int ImDen = this->Im.getDen() % tmp;
	Fraction TEMP1(ReNum, ReDen);
	Fraction TEMP2(ImNum, ImDen);
	Complex TEMP(TEMP1, TEMP2);
	return TEMP;
}

Complex& Complex::operator+=(const Complex& tmp) {
	int ImDen = 0;
	int ImNumSum = 0;
	int ReDen = 0;
	int ReNumSum = 0;
	if (this->Re.getDen() == tmp.Re.getDen()) {
		ReNumSum = this->Re.getNum() + tmp.Re.getNum();
		ReDen = tmp.Re.getDen();
	}
	else {
		int ReNum1 = this->Re.getNum() * tmp.Re.getDen();
		int ReNum2 = tmp.Re.getNum() * this->Re.getDen();
		ReNumSum = ReNum1 + ReNum2;
		ReDen = this->Re.getDen() * tmp.Re.getDen();
	}

	if (this->Im.getDen() == tmp.Im.getDen()) {
		ImNumSum = this->Im.getNum() + tmp.Im.getNum();
		ImDen = tmp.Im.getDen();
	}
	else {
		int ImNum1 = this->Im.getNum() * tmp.Im.getDen();
		int ImNum2 = tmp.Im.getNum() * this->Im.getDen();
		ImNumSum = ImNum1 + ImNum2;
		ImDen = this->Im.getDen() * tmp.Im.getDen();
	}
	Fraction TEMP1(ReNumSum, ReDen);
	Fraction TEMP2(ImNumSum, ImDen);
	this->Re = Fraction(TEMP1);
	this->Im = Fraction(TEMP2);
	return *this;
}

Complex& Complex::operator+=(int tmp) {
	int TmpNum = tmp;
	int TmpDen = 1;
	int ReDen = 0;
	int ReNumSum = 0;
	if (this->Re.getDen() == TmpDen) {
		ReNumSum = this->Re.getNum() + TmpNum;
		ReDen = TmpDen;
	}
	else {
		int ReNum1 = this->Re.getNum() * TmpDen;
		int ReNum2 = TmpNum * this->Re.getDen();
		ReNumSum = ReNum1 + ReNum2;
		ReDen = this->Re.getDen() * TmpDen;
	}
	Fraction TEMP1(ReNumSum, ReDen);
	this->Re = Fraction(TEMP1);
	return *this;
}

Complex& Complex::operator-=(const Complex& tmp) {
	int ImDen = 0;
	int ImNumSub = 0;
	int ReDen = 0;
	int ReNumSub = 0;
	if (this->Re.getDen() == tmp.Re.getDen()) {
		ReNumSub = this->Re.getNum() + tmp.Re.getNum();
		ReDen = tmp.Re.getDen();
	}
	else {
		int ReNum1 = this->Re.getNum() * tmp.Re.getDen();
		int ReNum2 = tmp.Re.getNum() * this->Re.getDen();
		ReNumSub = ReNum1 - ReNum2;
		ReDen = this->Re.getDen() * tmp.Re.getDen();
	}

	if (this->Im.getDen() == tmp.Im.getDen()) {
		ImNumSub = this->Im.getNum() - tmp.Im.getNum();
		ImDen = tmp.Im.getDen();
	}
	else {
		int ImNum1 = this->Im.getNum() * tmp.Im.getDen();
		int ImNum2 = tmp.Im.getNum() * this->Im.getDen();
		ImNumSub = ImNum1 - ImNum2;
		ImDen = this->Im.getDen() * tmp.Im.getDen();
	}
	Fraction TEMP1(ReNumSub, ReDen);
	Fraction TEMP2(ImNumSub, ImDen);
	this->Re = Fraction(TEMP1);
	this->Im = Fraction(TEMP2);
	return *this;
}

Complex& Complex::operator-=(int tmp) {
	int TmpNum = tmp;
	int TmpDen = 1;
	int ImNumSub = 0;
	int ReDen = 0;
	int ReNumSub = 0;
	if (this->Re.getDen() == TmpDen) {
		ReNumSub = this->Re.getNum() + TmpNum;
		ReDen = TmpDen;
	}
	else {
		int ReNum1 = this->Re.getNum() * TmpDen;
		int ReNum2 = TmpNum * this->Re.getDen();
		ReNumSub = ReNum1 - ReNum2;
		ReDen = this->Re.getDen() * TmpDen;
	}
	Fraction TEMP1(ReNumSub, ReDen);
	this->Re = Fraction(TEMP1);
	return *this;
}

Complex& Complex::operator*=(const Complex& tmp) {
	int ReNum, ReDen;
	int ReImNum, ReImDen;
	int ImReNum, ImReDen;
	int ImNum, ImDen;
	int fNum, fDen;
	int sNum, sDen;
	ComplexMulti(tmp, &ReNum, &ReDen, 1);
	ComplexMulti(tmp, &ReImNum, &ReImDen, 2);
	ComplexMulti(tmp, &ImReNum, &ImReDen, 3);
	ComplexMulti(tmp, &ImNum, &ImDen, 4);

	if (ReDen == ImDen) {
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
	Fraction TEMP1(fNum, fDen);
	Fraction TEMP2(sNum, sDen);
	this->Re = Fraction(TEMP1);
	this->Im = Fraction(TEMP2);
	return *this;
}

Complex& Complex::operator*=(int tmp) {
	Fraction TEMP1(this->Re.getNum() * tmp, this->Re.getDen());
	Fraction TEMP2(this->Im.getNum() * tmp, this->Re.getDen());
	this->Re = Fraction(TEMP1);
	this->Im = Fraction(TEMP2);
	return *this;
}

Complex& Complex::operator/=(const Complex& tmp) {
	int num, den, num1, den1;
	//FIRST HALF
	this->Re.multiplication(tmp.Re, &num, &den);	//First Re * Second Re
	Fraction first(num, den);						//Record result to the fraction first
	this->Im.multiplication(tmp.Im, &num, &den);    //First Im * Second Im
	Fraction second(num, den);						//Record result to the fraction second
	tmp.Re.degree(&num, &den);						//Prepare for denominator. Get Second Re to higher degree
	Fraction third(num, den);						//Record result to the fraction third
	tmp.Im.degree(&num, &den);						//Get Second Im to higher degree
	Fraction fouth(num, den);						//Record result to the fraction fouth
	first.addition(second, &num, &den);				//Addition of first and second objects
	Fraction fNum(num, den);						//Result of numerator of first half
	third.addition(fouth, &num, &den);				//Addition if third and fourth objects
	Fraction fDen(num, den);						//Result of denominator of first half
	fNum.division(fDen, &num, &den);				// Result of fraction of first half
	Fraction fResult(num, den);						//Record to fraction fResult
	//SECOND HALF
	tmp.Re.multiplication(this->Im, &num1, &den1);	//Second Re * First Im
	Fraction sfirst(num1, den1);					//Record result
	this->Re.multiplication(tmp.Im, &num1, &den1);	//First Re * Second Im
	Fraction ssecond(num1, den1);					//Record result
	sfirst.substraction(ssecond, &num1, &den1);		//sfirst - ssecond
	Fraction sNum(num1, den1);						//Record result of numerator of second half
	sNum.division(fDen, &num1, &den1);				//Result of fraction of second half
	Fraction TEMP1(num, den);						//temp object of Re
	Fraction TEMP2(num1, den1);						//Temp object of Im
	this->Re = Fraction(TEMP1); 
	this->Im = Fraction(TEMP2);
	return *this;
}

Complex& Complex::operator/=(int tmp) {
	Fraction TEMP1(this->Re.getNum(), this->Re.getDen() * tmp);
	Fraction TEMP2(this->Im.getNum(), this->Im.getDen() * tmp);
	this->Re = Fraction(TEMP1);
	this->Im = Fraction(TEMP2);
	return *this;
}

Complex& Complex::operator%=(int tmp) {
	return *this;
}

Complex& Complex::operator++() {
	int num = this->Re.getNum();
	this->Re.setNum(num += this->Re.getDen());
	return *this;
}

Complex& Complex::operator++(int) {
	int num = this->Re.getNum(); 
	Complex temp(Re, Im);
	this->Re.setNum(num += this->Re.getDen());
	return temp;
}

Complex& Complex::operator--() {
	int num = this->Re.getNum();
	this->Re.setNum(num -= this->Re.getDen());
	return *this;
}

Complex& Complex::operator--(int) {
	int num =this->Re.getNum();
	Complex temp(Re, Im);
	this -> Re.setNum(num -= this->Re.getDen());
	return temp;
}

std::ostream& operator<<(std::ostream& out, Complex& tmp) {
	out << tmp.Re.getNum() << "/" << tmp.Re.getDen() << " + (" << tmp.Im.getNum() << "+" << tmp.Im.getDen() << ")i" << endl;
	return out;
}

std::istream& operator>>(std::istream& in, Complex& tmp) {
	cout << "Enter real part" << endl;
	in >> tmp.Re;
	cout << "Enter imaginary part" << endl;
	in >> tmp.Im;
	return in;
}

bool Complex::operator==(const Complex& tmp) const {
	Fraction thisX = this->Re * this->Re;
	Fraction thisY = this->Im * this->Im;
	Fraction thisXY = thisX + thisY;
	Fraction tmpX = tmp.Re * tmp.Re;
	Fraction tmpY = tmp.Im * tmp.Im;
	Fraction tmpXY = tmpX * tmpY;
	if (thisXY == tmpXY)
		return true;
	else
		return false;
}

bool Complex::operator!=(const Complex& tmp) const {
	Fraction thisX = this->Re * this->Re;
	Fraction thisY = this->Im * this->Im;
	Fraction thisXY = thisX + thisY;
	Fraction tmpX = tmp.Re * tmp.Re;
	Fraction tmpY = tmp.Im * tmp.Im;
	Fraction tmpXY = tmpX * tmpY;
	if (thisXY == tmpXY)
		return false;
	else
		return true;
}

bool Complex::operator>(const Complex& tmp) const {
	Fraction thisX = this->Re * this->Re;
	Fraction thisY = this->Im * this->Im;
	Fraction thisXY = thisX + thisY;
	Fraction tmpX = tmp.Re * tmp.Re;
	Fraction tmpY = tmp.Im * tmp.Im;
	Fraction tmpXY = tmpX * tmpY;
	if (thisXY > tmpXY)
		return true;
	else
		return false;
}

bool Complex::operator<(const Complex& tmp) const {
	Fraction thisX = this->Re * this->Re;
	Fraction thisY = this->Im * this->Im;
	Fraction thisXY = thisX + thisY;
	Fraction tmpX = tmp.Re * tmp.Re;
	Fraction tmpY = tmp.Im * tmp.Im;
	Fraction tmpXY = tmpX * tmpY;
	if (thisXY > tmpXY)
		return false;
	else
		return true;
}



void Complex::show_complex() {
	int ImNum = this->Im.getNum();
	int ImDen = this->Im.getDen();
	int ReNum = this->Re.getNum();
	int ReDen = this->Re.getDen();
	cout << ReNum << "/" << ReDen << " + (" << ImNum << "/" << ImDen << ")i" << endl;
}
