#include "Matrix.h"



void GetMatr(double** mas, double** p, int i, int j, int m)
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
int Determinant(double** mas, int m)
{
	int i, j, t, n;
	double** p, d;
	p = new double* [m];
	for (i = 0; i < m; i++)
		p[i] = new double[m];
	j = 0; d = 0;
	t = 1;
	n = m - 1;
	if (m < 1) cout << "Ошибка";
	if (m == 1) {
		d = mas[0][0];
		return(d);
	}
	if (m == 2) {
		d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
		return(d);
	}
	if (m > 2) {
		for (i = 0; i < m; i++) {
			GetMatr(mas, p, 0, i, m);
			d = d + t * mas[0][i] * Determinant(p, n);
			t = -t;
		}
	}
	return(d);
}
Matrix::Matrix()
{
	this->rows = 3;
	this->columns = 3;
	this->RowsArray = static_cast<Vector*>(operator new[](this->rows * sizeof(Vector)));
	for (int i = 0; i < rows; i++)
	{
		new (RowsArray + i) Vector(columns);
	}
}

Matrix::~Matrix()
{
	this->rows = 0;
	this->columns = 0;
	for (int i = 0; i < rows; i++)
	{
		RowsArray[i].~Vector();
	}
	operator delete[](RowsArray);
}

Matrix::Matrix(int str, int stolp)
{
	this->rows = str;
	this->columns = stolp;
	this->RowsArray = static_cast<Vector*>(operator new[](this->rows * sizeof(Vector)));
	for (int i = 0; i < rows; i++)
	{
		new (RowsArray + i) Vector(columns);
	}
}

Matrix::Matrix(const Matrix& tmp)
{
	if (tmp.RowsArray == nullptr)
		throw 1;
	this->rows = tmp.rows;
	this->columns = tmp.columns;
	this->RowsArray = static_cast<Vector*>(operator new[](this->rows * sizeof(Vector)));
	for (int i = 0; i < rows; i++)
	{
		new (RowsArray + i) Vector(columns);
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			RowsArray[i][j] = tmp.RowsArray[i][j];
		}

	}
}

Matrix& Matrix::operator=(const Matrix& tmp)
{
	if (tmp.RowsArray == nullptr)
		throw 1;
	this->rows = tmp.rows;
	this->columns = tmp.columns;
	this->RowsArray = static_cast<Vector*>(operator new[](this->rows * sizeof(Vector)));
	for (int i = 0; i < rows; i++)
	{
		new (RowsArray + i) Vector(columns);
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			RowsArray[i][j] = tmp.RowsArray[i][j];
		}

	}
	return *this;
}

Matrix Matrix::operator+(const Matrix& tmp) const
{
	Matrix result(tmp.rows, tmp.columns);


	if (rows != tmp.rows)
	{
		return result;
	}
	if (columns != tmp.columns)
	{
		return result;
	}
	else {
		for (int i = 0; i < rows; i++)
		{

			result.RowsArray[i] = this->RowsArray[i] + tmp.RowsArray[i];
		}

	}
	return result;
}

Matrix Matrix::operator-(const Matrix& tmp) const
{
	Matrix result(tmp.rows, tmp.columns);


	if (rows != tmp.rows)
	{
		return result;
	}
	if (columns != tmp.columns)
	{
		return result;
	}
	else {
		for (int i = 0; i < rows; i++)
		{

			result.RowsArray[i] = this->RowsArray[i] - tmp.RowsArray[i];
		}

	}
	return result;
}

Matrix Matrix::operator*(const int& t) const
{
	Matrix result(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		result.RowsArray[i] = RowsArray[i] * t;
	}
	return result;
}

Matrix Matrix::operator/(const int& t) const
{
	Matrix result(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		result.RowsArray[i] = RowsArray[i] / t;
	}
	return result;
}

Matrix Matrix::operator*(const Matrix& tmp) const
{
	Matrix result(rows, tmp.columns);
	int ki = 0, kj = 0, t;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			for (int t = 0; t < tmp.columns; t++)
			{
				result.RowsArray[i][j] += (this->RowsArray[i][t] * tmp.RowsArray[t][j]);
			}
		}

	}
	return result;
}

Matrix Matrix::operator/(const Matrix& tmp) const
{
	Matrix result(rows, columns), j(rows, columns);
	int d;
	result = tmp;
	d = result.D();
	cout << "Определитель второй матрици = " << d << endl;
	if (d == 0)
	{
		cout << "Ошибка!" << endl;
		return j;
	}
	result = result.T();
	result = result / d;
	result.MOut();
	result = result * *this;
	return result;
}

Matrix Matrix::operator^(const int tmp) const
{
	Matrix result(rows, columns);
	result = *this;
	if (tmp > 1)
	{
		for (int i = 1; i < tmp; i++)
		{
			result = result * *this;
		}
		return result;
	}
	else if (tmp == 0)
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
			{
				result.RowsArray[i][j] = 1;
			}
		return result;
	}
	else
	{
		cout << "Ошибка!" << endl;
		return *this;
	}

}

Matrix Matrix::T()
{
	Matrix tmp(columns, rows);
	for (int i = 0; i < columns; ++i)
	{
		for (int j = i; j < rows; ++j)
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
	p = new double* [columns];
	for (int i = 0; i < columns; i++)
		p[i] = new double[columns];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			p[i][j] = RowsArray[i][j];
		}
	}
	d = Determinant(p, rows);
	return d;
}


void Matrix::Set(Vector& tmp, int i)
{
	this->columns = tmp.getsize();
	this->rows = i + 1;
	this->RowsArray[i] = tmp;
}

void Matrix::MOut()
{
	for (int i = 0; i < this->rows; i++)
	{
		cout << this->RowsArray[i];
	}
}