#include "Complex.h"

Complex::Complex()
{
	this->Re = fraction(0, 1);
	this->Im = fraction(0, 1);
}

Complex::~Complex()
{
	this->Re = fraction(0, 1);
	this->Im = fraction(0, 1);
}

void Complex::scan()
{
	int c, d;
    cout << "Введите первую дробь" << endl;
    cout << "Введите числитель" << endl;
    cin >> c;
    cout << "Введите знаменатель" << endl;
    do
    {
        cin >> d;
        if (d == 0)
            cout << "Нельзя так" << endl;
    } while (d == 0);
    this->Re = fraction(c,d);
    cout << "Введите Вторую дробь" << endl;
    cout << "Введите числитель" << endl;
    cin >> c;
    cout << "Введите знаменатель" << endl;
    do
    {
        cin >> d;
        if (d == 0)
            cout << "Нельзя так" << endl;
    } while (d == 0);
    this->Im = fraction(c, d);
}

Complex& Complex::operator=(const Complex& tmp)
{
    this->Re = tmp.Re;
    this->Im= tmp.Im;
    return *this;

}

Complex Complex::operator*(Complex& tmp)
{
    Complex res;
    fraction newRe, newIm, newRe1, newIm1;
    newRe = this->Re * tmp.Re;
    newIm = this->Im * tmp.Im;
    newRe1 = this->Re * tmp.Im;
    newIm1 = this->Im * tmp.Re;
    res.Re = newRe - newIm;
    res.Im = newRe1 + newIm1;
    return res;
}

Complex Complex::operator+(Complex& tmp)
{
    Complex res;
    fraction newRe, newIm;
    newRe = this->Re + tmp.Re;
    newIm = this->Im + tmp.Im;
    res.Re = newRe;
    res.Im = newIm;
    return res;
}

Complex Complex::operator-(Complex& tmp)
{
    Complex res;
    fraction newRe, newIm;
    newRe = this->Re - tmp.Re;
    newIm = this->Im - tmp.Im;
    res.Re = newRe;
    res.Im = newIm;
    return res;
}

Complex Complex::operator/(Complex& tmp)
{
    Complex res;
    fraction newRe, newIm, newRe1, newIm1, newRe2, newIm2, newa, newb, newc;
    newRe = this->Re * tmp.Re;
    newIm = this->Im * tmp.Im;
    newRe1 = tmp.Re * tmp.Re;
    newIm1 = tmp.Im * tmp.Im;

    newRe2 = this->Re * tmp.Im;
    newIm2 = this->Im * tmp.Re;
    newa = newRe + newIm;
    newb = newRe1 + newIm1;
    newc = newIm2 - newRe2;
    res.Re = newa / newb;
    res.Im = newc / newb;

    return res;
}

Complex Complex::operator*(int tmp) 
{
    Complex a;
    a = *this;
    a.Re.SetChisl(this->Re.GetChisl() * tmp);
    return a;
}

Complex Complex::operator/(int tmp)
{
    Complex a;
    a = *this;
    a.Re.SetChisl(this->Re.GetChisl() / tmp);
    return a;
}

Complex Complex::operator+(int tmp)
{
    Complex a;
    a = *this;
    a.Re.SetChisl(this->Re.GetChisl() + tmp*this->Re.GetZnam());
    return a;
}

Complex Complex::operator-(int tmp)
{
    Complex a;
    a = *this;
    a.Re.SetChisl(this->Re.GetChisl() - tmp * this->Re.GetZnam());
    return a;
}

bool Complex::operator>(Complex& tmp)
{
    int n,m;
    n = this->Re.GetChisl() * tmp.Re.GetZnam();
    m = this->Re.GetZnam() * tmp.Re.GetChisl();
    if (n > m)
        return true;
    else

    return false;
}

bool Complex::operator<(Complex& tmp)
{
    int n, m;
    n = this->Re.GetChisl() * tmp.Re.GetZnam();
    m = this->Re.GetZnam() * tmp.Re.GetChisl();
    if (n < m)
        return true;
    else

        return false;
}
bool Complex::operator==(Complex& tmp)
{
    int n, m;
    n = this->Re.GetChisl() * tmp.Re.GetZnam();
    m = this->Re.GetZnam() * tmp.Re.GetChisl();
    if (n == m)
        return true;
    else

        return false;
}
bool Complex::operator!=(Complex& tmp)
{
    int n, m;
    n = this->Re.GetChisl() * tmp.Re.GetZnam();
    m = this->Re.GetZnam() * tmp.Re.GetChisl();
    if (n != m)
        return true;
    else

        return false;
}
bool Complex::operator>=(Complex& tmp)
{
    int n, m;
    n = this->Re.GetChisl() * tmp.Re.GetZnam();
    m = this->Re.GetZnam() * tmp.Re.GetChisl();
    if (n >= m)
        return true;
    else

        return false;
}
bool Complex::operator<=(Complex& tmp)
{
    int n, m;
    n = this->Re.GetChisl() * tmp.Re.GetZnam();
    m = this->Re.GetZnam() * tmp.Re.GetChisl();
    if (n <= m)
        return true;
    else

        return false;
}
Complex& Complex::operator+=(Complex& tmp)
{
    fraction newRe, newIm;
    newRe = this->Re + tmp.Re;
    newIm = this->Im + tmp.Im;
    this->Re = newRe;
    this->Im = newIm;
    return *this;
}
Complex& Complex::operator-=(Complex& tmp)
{
    fraction newRe, newIm;
    newRe = this->Re - tmp.Re;
    newIm = this->Im - tmp.Im;
    this->Re = newRe;
    this->Im = newIm;
    return *this;
}
Complex& Complex::operator/=(Complex& tmp)
{
    *this = *this / tmp;

    return *this;
}
Complex& Complex::operator*=(Complex& tmp)
{
    *this = *this * tmp;
        return *this;
}
Complex& Complex::operator+=(int tmp)
{
    *this = *this + tmp;
    return *this;
}
Complex& Complex::operator-=(int tmp)
{
    *this = *this - tmp;
    return *this;
}
Complex& Complex::operator/=(int tmp)
{
    *this = *this / tmp;
    return *this;
}
Complex& Complex::operator*=(int tmp)
{
    *this = *this * tmp;
    return *this;

}
ostream& operator<<(ostream& out, Complex& tmp)
{
    out << tmp.Re.GetChisl()<<"/"<< tmp.Re.GetZnam()<<"+"<<tmp.Im.GetChisl()<<"/"<< tmp.Im.GetZnam()<<"*i";
    return out;
}

istream& operator>>(istream& in, Complex& tmp)
{
    cout << "Введите целую часть" << endl;
    in >> tmp.Re;
    cout << "Введите мнимую часть" << endl;
    in >> tmp.Im;
    return in;

}
