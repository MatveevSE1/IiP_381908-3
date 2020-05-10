#include "Complex.h"


int main()
{

	Fraction First = new Fraction();
	Fraction Second = new Fraction();
	Fraction Third = new Fraction();
	Fraction Fouth = new Fraction();
	cout << "FIRST COMPLEX: " << endl;
	cin >> &First;
	cin >> &Second;
	cout << "SECOND COMPLEX: " << endl;
	cin >> &Third;
	cin >> &Fouth;
	Complex FIRSTCOMPLEX = new Complex(&First, &Second);
	Complex* SECONDCOMPLEX = new Complex(&Third, &Fouth);
	Complex RESULT = new Complex();
	cout << "FIRST COMPLEX: " << endl;
	cout << &FIRSTCOMPLEX;
	cout << "SECOND COMPLEX: " << endl;
	cout << SECONDCOMPLEX;
	cout << "===OVERLOAD OF +===" << endl;
	RESULT = FIRSTCOMPLEX + SECONDCOMPLEX;
	cout << &RESULT;
	cout << "===OVERLOAD OF -===" << endl;
	RESULT = FIRSTCOMPLEX - SECONDCOMPLEX;
	cout << &RESULT;
	cout << "===OVERLOAD OF *===" << endl;
	RESULT = FIRSTCOMPLEX * SECONDCOMPLEX;
	cout << &RESULT;
	cout << "===OVERLOAD OF /===" << endl;
	RESULT = FIRSTCOMPLEX / SECONDCOMPLEX;
	cout << &RESULT;


}
