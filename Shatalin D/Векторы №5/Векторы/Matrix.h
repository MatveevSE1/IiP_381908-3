#pragma once
#include"Vector.h";

class Matrix
{
private:
	int rows;
	int columns;
	Vector* RowsArray;

public:
	Matrix();
	~Matrix();
	Matrix(int str, int stolp);
	Matrix(const Matrix& tmp);
	Matrix& operator=(const Matrix& tmp);
	Matrix operator+(const Matrix& tmp)const;
	Matrix operator-(const Matrix& tmp)const;
	Matrix operator*(const int& t)const;
	Matrix operator/(const int& t)const;
	Matrix operator*(const Matrix& tmp)const;
	Matrix operator/(const Matrix& tmp)const;
	Matrix operator^(const int tmp) const;
	Matrix T();
	int D();
	void Set(Vector& tmp, int i);
	void MOut();
};