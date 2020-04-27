#include "Frac.h"

int found0(int c) {
	if (c == 0) {

		return 0;
	}
	else return 1;


}
void fraction::SetChisl(int n)
{
	this->chisl = n;
}

void fraction::SetZnam(int n)
{
	this->znam = n;
}

fraction::fraction(int i, int j)
{
	this->chisl = i;
	this->znam = j;
}
fraction::fraction()
{
	this->chisl = 0;
	this->znam = 1;
}
fraction::~fraction()
{
	this->chisl = 0;
	this->znam = 1;
}
int fraction::GetChisl()
{
	return this->chisl;
}

int fraction::GetZnam()
{
	return this->znam;
}

int fraction::Umn(fraction drob1, fraction drob2)
{
	int c;
	int d;
	c = drob1.GetChisl() * drob2.GetChisl();
	if (found0(c) == 0)
	{
		cout << "0";
		return 0;
	}
	else
	{
		d = drob1.GetZnam() * drob2.GetZnam();
		cout << c << '/' << d;
	}
	return 0;

}

fraction fraction::operator*(fraction& tmp)
{
	fraction res;

	int c;
	int d;
	c = this->GetChisl() * tmp.GetChisl();
	if (found0(c) == 0)
	{
		cout << "0";
		return res;
		
	}
	else
	{
		d = this->GetZnam() * tmp.GetZnam();
	}
	res.SetChisl(c);
	res.SetZnam(d);

	return res;
}

int fraction::Del(fraction drob1, fraction drob2)
{
	int c;
	int d;
	c = drob1.GetChisl() * drob2.GetZnam();
	if (found0(c) == 0)
	{
		cout << "0";
		return 0;
	}
	else
	{
		d = drob1.GetZnam() * drob2.GetChisl();
		cout << c << '/' << d;
	}
	return 0;
}

fraction fraction::operator/(fraction& tmp)
{
	int c;
	int d;
	fraction res;
	c = this->GetChisl() * tmp.GetZnam();
	if (found0(c) == 0)
	{
		cout << "0";
		return res;
	}
	else
	{
		d = this->GetZnam() * tmp.GetChisl();
	}
	res.SetChisl(c);
	res.SetZnam(d);
	return res;
}

int fraction::Sum(fraction drob1, fraction drob2)
{
	int c;
	int d;
	c = drob1.GetChisl() * drob2.GetZnam() + drob1.GetZnam() * drob2.GetChisl();
	if (found0(c) == 0)
	{
		cout << "0";
		return 0;
	}
	else
	{
		d = drob1.GetZnam() * drob2.GetZnam();
		cout << c << '/' << d;
	}
	return 0;
}

fraction fraction::operator-(fraction& tmp)
{
	int c;
	int d;
	fraction res;
	c = this->GetChisl() * tmp.GetZnam() - this->GetZnam() * tmp.GetChisl();
	if (found0(c) == 0)
	{
		cout << "0";
		return res;
	}
	else
	{
		d = this->GetZnam() * tmp.GetZnam();
	}
	res.SetChisl(c);
	res.SetZnam(d);
	return res;
}

int fraction::Vuch(fraction drob1, fraction drob2)
{
	int c;
	int d;
	c = drob1.GetChisl() * drob2.GetZnam() - drob1.GetZnam() * drob2.GetChisl();
	if (found0(c) == 0)
	{
		cout << "0";
		return 0;
	}
	else
	{
		d = drob1.GetZnam() * drob2.GetZnam();
		cout << c << '/' << d;

	}
	return 0;
}

fraction fraction::operator+(fraction& tmp)
{
	int c;
	int d;
	fraction res;
	c = this->GetChisl() * tmp.GetZnam() + this->GetZnam() * tmp.GetChisl();
	if (found0(c) == 0)
	{
		cout << "0";
		return res;
	}
	else
	{
		d = this->GetZnam() * tmp.GetZnam();
	}
	res.SetChisl(c);
	res.SetZnam(d);
	return res;
}

void fraction::Out()
{
	cout << this->GetChisl() << "/" << this->GetZnam()<<endl;
}

istream& operator>>(istream& in, fraction& tmp)
{
	int c, z;
	cout << "Введите дробь" << endl;
	cout << "Числитель" << endl;
	in >> c;
	tmp.SetChisl(c);
	cout << "Знаменатель" << endl;
	in >> z;
	tmp.SetZnam(z);
	return in;

}
