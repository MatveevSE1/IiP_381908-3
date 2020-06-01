#include "Matrix.h"



void GetMatr(double** mas, double** p, int i, int j, int m)
{
	int ki, kj, iSmesh, jSmesh;
	iSmesh = 0;
	for (ki = 0; ki < m - 1; ki++) {
		if (ki == i)
			iSmesh = 1;
		jSmesh = 0;
		for (kj = 0; kj < m - 1; kj++) {
			if (kj == j)
				jSmesh = 1;
			p[ki][kj] = mas[ki + iSmesh][kj + jSmesh];
		}
	}
}
int Determinant(double** mas, int m) 
{
	int i, j,  k, n;
	double** p, d;
	p = new double* [m];
	for (i = 0; i < m; i++)
		p[i] = new double[m];
	j = 0; d = 0;
	k = 1; //(-1) в степени i
	n = m - 1;
	if (m < 1) cout << "Impossible";
	if (m == 1) {
		d = mas[0][0];
		return(d);
	}
	if (m == 2) {
		d = mas[0][0] * mas[1][1] -(mas[1][0] * mas[0][1]);
		return(d);
	}
	if (m > 2) {
		for (i = 0; i < m; i++) {
			GetMatr(mas, p, 0,i, m);
			d = d + k * mas[0][i] * Determinant(p, n);
			k = -k;
		}
	}
	return(d);
}
Matrix::Matrix()
{
	this->Mstr = 3;
	this->Mstolp = 3;
	this->RowsArray = static_cast<Vector*>(operator new[](this->Mstr * sizeof(Vector)));
	for (int i = 0; i < Mstr; i++)
	{
		new (RowsArray + i) Vector(Mstolp);
	}
}

Matrix::~Matrix()
{
	
	for (int i = 0; i < Mstr; i++)
	{
		RowsArray[i].~Vector();
	}
	this->Mstr = 0;
	this->Mstolp = 0;
	operator delete[] (RowsArray);
}

Matrix::Matrix(int str, int stolp)
{
	this->Mstr = str;
	this->Mstolp = stolp;
	this->RowsArray = static_cast<Vector*>(operator new[](this->Mstr * sizeof(Vector)));
	for (int i = 0; i < Mstr; i++)
	{
		new (RowsArray + i) Vector(Mstolp);
	}
}

Matrix::Matrix(const Matrix& tmp)
{
	if (tmp.RowsArray == nullptr)
		throw 1;
	this->Mstr = tmp.Mstr;
	this->Mstolp = tmp.Mstolp;
	this->RowsArray = static_cast<Vector*>(operator new[](this->Mstr * sizeof(Vector)));
	for (int i = 0; i < Mstr; i++)
	{
		new (RowsArray + i) Vector(Mstolp);
	}
	for (int i = 0; i < Mstr; i++)
	{
		for (int j = 0; j < Mstolp; j++)
		{
			RowsArray[i][j] = tmp.RowsArray[i][j];
		}

	}
}

Matrix& Matrix::operator=(const Matrix& tmp)
{
	if (tmp.RowsArray == nullptr)
		throw 1;
	this->Mstr = tmp.Mstr;
	this->Mstolp = tmp.Mstolp;
	this->RowsArray = static_cast<Vector*>(operator new[](this->Mstr * sizeof(Vector)));
	for (int i = 0; i < Mstr; i++)
	{
		new (RowsArray + i) Vector(Mstolp);
	}
	for (int i = 0; i < Mstr; i++)
	{
		for (int j = 0; j < Mstolp; j++)
		{
			RowsArray[i][j] = tmp.RowsArray[i][j];
		}

	}
	return *this;
}

Matrix Matrix::operator+(const Matrix& tmp) const
{
	Matrix res(tmp.Mstr,tmp.Mstolp);
	//double** resRow = new double*[Mstr];

	if (Mstr != tmp.Mstr)
	{
		cout << "m or n no equal"<<endl;
		return res;
	}
	if (Mstolp != tmp.Mstolp)
	{
		cout << "m or n no equal" << endl;
		return res;
	}
	else {
		for (int i = 0; i < Mstr; i++)
		{

			res.RowsArray[i] = this->RowsArray[i] + tmp.RowsArray[i];
		}

	}
	return res;
}

Matrix Matrix::operator-(const Matrix& tmp) const
{
	Matrix res(tmp.Mstr, tmp.Mstolp);
	//double** resRow = new double*[Mstr];

	if (Mstr != tmp.Mstr)
	{
		cout << "m or n no equal" << endl;
		return res;
	}
	if (Mstolp != tmp.Mstolp)
	{
		cout << "m or n no equal" << endl;
		return res;
	}
	else {
		for (int i = 0; i < Mstr; i++)
		{

			res.RowsArray[i] = this->RowsArray[i] - tmp.RowsArray[i];
		}

	}
	return res;
}

Matrix Matrix::operator*(const int& k) const
{
	Matrix res(Mstr, Mstolp);
	for (int  i = 0; i < Mstr; i++)
	{
		res.RowsArray[i] = RowsArray[i] * k;
	}
	return res;
}

Matrix Matrix::operator/(const int& k) const
{
	Matrix res(Mstr, Mstolp);
	for (int i = 0; i < Mstr; i++)
	{
		res.RowsArray[i] = RowsArray[i] / k;
	}
	return res;
}

Matrix Matrix::operator*(const Matrix& tmp) const
{
	Matrix res(Mstr,tmp.Mstolp);
	int ki = 0,kj=0,k ;

	for (int i = 0; i < Mstr; i++)
	{
		for (int j = 0; j < Mstr; j++)
		{
			for (int k = 0; k <tmp.Mstolp ; k++)
			{
				res.RowsArray[i][j] +=(this->RowsArray[i][k] * tmp.RowsArray[k][j]);
			}
		}
		
	}
	return res;
}

Matrix Matrix::operator/(const Matrix& tmp) const
{
	Matrix res(Mstr, Mstolp),j(Mstr, Mstolp);
	int d;
	res = tmp;
	d = res.D();
	cout << "Determinant of second Matrix = " << d<<endl;
	if (d == 0)
	{
		cout << "impossible!!!" << endl;
		return j;
	}
	res = res.T();
	res = res / d;
	cout << "Invert matrix " << endl;
	res.MOut();
	res = res* *this;
	return res;
}

Matrix Matrix::operator^(const int tmp) const
{
	Matrix res(Mstr, Mstolp);
	res = *this;
	if (tmp > 1)
	{
		for (int i = 1; i < tmp; i++)
		{
			res = res * *this;
		}
		return res;
	}
	else if (tmp == 0)
	{
		for (int i = 0; i < Mstr; i++)
			for (int j = 0; j < Mstolp; j++)
			{
				res.RowsArray[i][j] = 1;
			}
		return res;
	}
	else
	{
		cout << "impossible!!!" << endl;
		return *this;
	}

}

Matrix Matrix::T()
{
	Matrix tmp(Mstolp, Mstr);
	for (int i = 0; i < Mstolp; ++i)
	{
		for (int j = i; j < Mstr; ++j)
		{
			tmp.RowsArray[i][j] = this->RowsArray[i][j];
			this->RowsArray[i][j] = this->RowsArray[j][i];
			this->RowsArray[j][i] = tmp.RowsArray[i][j];
		}
	}
	return *this;
}

int Matrix::D()
{
	int d;
	double** p;
	p = new double* [Mstolp];
	for (int i = 0; i < Mstolp; i++)
		p[i] = new double[Mstolp];
	for (int i = 0; i < Mstr; i++)
	{
		for (int j = 0; j < Mstolp; j++)
		{
			p[i][j] = RowsArray[i][j];
		}
	}
	d = Determinant(p,Mstr);
	return d;
}


void Matrix::Set( Vector& tmp, int i)
{
	this->Mstolp = tmp.GetSize();
	this->Mstr = i+1;
	this->RowsArray[i] = tmp;
}

void Matrix::MOut()
{
	for (int i = 0; i < this->Mstr; i++)
	{
		cout << this->RowsArray[i];
	}
}

