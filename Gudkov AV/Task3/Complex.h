#include "Frac.h"
class Complex {
private:
	fraction Re;
	fraction Im;
public:
	Complex();
	~Complex();
	void scan();
	friend ostream& operator<<(ostream& out, Complex& tmp);
	friend istream& operator>>(istream& in, Complex& tmp);
	Complex& operator=(const Complex& tmp);
	Complex operator*(Complex& tmp);
	Complex operator+(Complex& tmp);
	Complex operator-(Complex& tmp);
	Complex operator/(Complex& tmp);
	Complex operator*(int tmp);
	Complex operator/(int tmp);
	Complex operator+(int tmp);
	Complex operator-(int tmp);
	bool operator>(Complex& tmp);
	bool operator<(Complex& tmp);
	bool operator==(Complex& tmp);
	bool operator!=(Complex& tmp);
	bool operator>=(Complex& tmp);
	bool operator<=(Complex& tmp);
	Complex& operator+=(Complex& tmp);
	Complex& operator-=(Complex& tmp);
	Complex& operator/=(Complex& tmp);
	Complex& operator*=(Complex& tmp);
	Complex& operator+=(int tmp);
	Complex& operator-=(int tmp);
	Complex& operator/=(int tmp);
	Complex& operator*=(int tmp);
	


};
