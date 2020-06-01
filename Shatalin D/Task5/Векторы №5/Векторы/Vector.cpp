#include "Vector.h"
#include<math.h>
int det = 0, step = -1;


void Minor(double** mas, double** p, int i, int j, int m)
{

	int ki, kj, ibreak, jbreak;
	ibreak = 0;
	for (ki = 0; ki < m - 1; ki++) {
		if (ki == i)
			ibreak = 1;
		jbreak = 0;
		for (kj = 0; kj < m - 1; kj++) {
			if (kj == j)
				jbreak = 1;
			p[ki][kj] = mas[ki + ibreak][kj + jbreak];
		}
	}
}

void PrintMatr(double** mas, int m) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
}
double Determinant(double** mas, int m, double* dres, int ii, bool three) {
	int  j, t, n;
	double d;
	double** p;
	p = new double* [m];
	for (int i = 0; i < m; i++)
		p[i] = new double[m];
	j = 0; d = 0;
	t = 1;
	n = m - 1;
	if (m < 1)
		cout << "Ошибка!";
	if (m == 1)
	{
		d = mas[0][0];
		return(d);
	}

	if (m == 2) {
		d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);

		if (three == true)
			dres[ii] = d;
		return(d);
	}
	if (m > 2) {
		for (int i = 0; i < m; i++) {
			Minor(mas, p, 0, i, m);
			d = d + (t * mas[0][i] * Determinant(p, n, dres, i, three));
			if (three == false)
				dres[ii] = d;
			t = -t;
		}
	}
	return(d);
}

Vector Vector::VecMult(Vector* Vec)
{
	bool three;
	if (Size == 3)
		three = true;
	else
		three = false;
	double** p;
	p = new double* [Size];
	for (int i = 0; i < Size; i++)
		p[i] = new double[Size];
	double* ttt = new double[Size];
	Vector result(Size);
	double d;
	double** tt = new double* [Size];

	for (int i = 0; i < Size; i++)
		tt[i] = new double[Size];

	for (int i = 0; i < Size; i++)
	{
		tt[0][i] = 1;
	}
	for (int i = 1; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			tt[i][j] = Vec[i].Data[j];
		}
	}

	Minor(tt, p, 0, 0, Size);
	Determinant(p, Size - 1, ttt, 0, three);

	d = ttt[0];
	Determinant(tt, Size, ttt, 0, three);
	for (int i = 1; i < Size; i++)
	{
		result.Data[0] = d;
		result.Data[i] = ttt[i];
	}

	return result;
}

void Vector::Random()
{
	for (int i = 0; i < this->Size; i++)
	{
		this->Data[i] = rand() % 9;
	}
}

int Vector::getsize()
{
	return this->Size;
}


Vector::Vector()
{
	Data = new double[3];
	Size = 3;
	for (int i = 0; i < Size; i++)
	{
		Data[i] = 0;
	}


}

Vector::Vector(int _size, double* _data)
{
	if (_data == NULL)
		throw std::exception();
	this->Size = _size;
	for (int i = 0; i < _size; i++)
	{
		*(_data + i) = 0;
	}


}

Vector::Vector(int _size)
{
	this->Size = _size;
	this->Data = new double[_size];
	for (int i = 0; i < _size; i++)
	{
		this->Data[i] = 0;
	}

}

Vector::Vector(const Vector& v)
{
	if (v.Data == NULL)
		throw std::exception("DATA UY");
	Size = v.Size;
	Data = new double[Size];
	for (int i = 0; i < Size; i++)
	{
		Data[i] = v.Data[i];
	}

}

Vector::~Vector()
{
	delete[] this->Data;
	this->Data = nullptr;
	this->Size = 0;

}

Vector& Vector::operator=(const Vector& v)
{
	Size = v.Size;
	this->Data = new double[Size];
	for (int i = 0; i < Size; i++)
	{
		this->Data[i] = v.Data[i];
	}
	return *this;
}

Vector Vector::operator+(const Vector& tmp) const
{

	int s = this->Size;
	if (this->Size != tmp.Size)
		throw - 1;
	if ((this->Data == nullptr && this->Size <= 0) && (tmp.Data == nullptr && tmp.Size <= 0))
		throw - 1;
		Vector sum(s);
		for (int i = 0; i < sum.Size; i++)
			sum.Data[i] = tmp.Data[i] + Data[i];
		return sum;
	
}

Vector Vector::operator-(const Vector& tmp) const
{

	int s = this->Size;
	if (this->Size != tmp.Size)
		throw - 1;
	if ((this->Data == nullptr && this->Size <= 0) && (tmp.Data == nullptr && tmp.Size <= 0))
		throw - 1;
	Vector sum(s);
	for (int i = 0; i < sum.Size; i++)
		sum.Data[i] = Data[i] - tmp.Data[i];
	return sum;
}

double Vector::operator*(const Vector& tmp) const
{
	double result = 0;
	int s = this->Size;
	if (this->Size != tmp.Size)
		throw - 1;
	if ((this->Data == nullptr && this->Size <= 0) && (tmp.Data == nullptr && tmp.Size <= 0))
		throw - 1;
	for (int i = 0; i < s; i++)
		result += Data[i] * tmp.Data[i];
	return result;
}

Vector Vector::operator*(const int tmp) const
{
	Vector result(Size);
	for (int i = 0; i < Size; i++)
	{
		result.Data[i] = this->Data[i] * tmp;
	}
	return	result;
}

Vector Vector::operator/(const int tmp) const
{
	Vector result(Size);
	for (int i = 0; i < Size; i++)
	{
		result.Data[i] = this->Data[i] / tmp;
	}
	return	result;
}

double& Vector::operator[](const int tmp)
{
	return this->Data[tmp];
}

double Vector::GetLenght()
{
	double result = 0;
	if (this->Data != nullptr && this->Size > 0)
	{
		for (int i = 0; i < Size; i++)

			result += Data[i] * Data[i];

		return sqrt(result);
	}
	else
		return -1;
}

double Vector::lenghtbetweenvectors(const Vector& tmp)
{
	double result = 0;
	if (this->Data != nullptr && this->Size > 0)
	{
		for (int i = 0; i < Size; i++)

			result += (tmp.Data[i] - Data[i]) * (tmp.Data[i] - Data[i]);

		return sqrt(result);
	}
	else
		return -1;
}

double Vector::GetCosA(Vector& tmp)
{
	double mult = 0, res1, result=0;
	int s = this->Size;
	if (this->Size != tmp.Size)
		throw - 1;
	if ((this->Data == nullptr && this->Size <= 0) && (tmp.Data == nullptr && tmp.Size <= 0))
		throw - 1;
	
		for (int i = 0; i < s; i++)
		{
			mult += this->Data[i] * tmp.Data[i];
		}
	result = this->GetLenght();
	res1 = tmp.GetLenght();
	double coss = mult / (result * res1);
	return coss;

}




std::istream& operator>>(std::istream& in, const Vector& tmp)
{
	for (int i = 0; i < tmp.Size; i++)
	{
		cout << "Введите " << i + 1 << " Кординату вектора " << endl;
		in >> tmp.Data[i];
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Vector& tmp)
{
	out << "( ";
	for (int i = 0; i < tmp.Size; i++)
	{
		out << tmp.Data[i] << " ";
	}
	out << ")" << endl;
	return out;

}
