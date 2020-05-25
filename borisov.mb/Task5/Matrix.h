#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "Vector.h"
class Matrix
{
private:
	int RowsMatrix;
	int ColsMatrix;
	Vector* RowsArray;
public:
	Matrix();
	Matrix(int _RowsMatrix, int _ColsMatrix);
	Matrix(const Matrix& matrix);
	~Matrix();
	void PrintMatrix() const;
	Matrix Minor(int row, int col);
	double Determinant();
	void Transpose();
	void SetValue(int i, int j, double value);
	Matrix& operator=(const Matrix& matrix);
	Matrix operator+(const Matrix& matrix) const;
	Matrix operator-(const Matrix& matrix) const;
	Matrix operator*(const int value) const;
	Matrix operator*(const Matrix& matrix) const;
	Matrix operator^(const int degree);
	Matrix Reverse();
	Matrix operator/(Matrix& matrix) const;
	friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
	friend std::istream& operator>>(std::istream& in, const Matrix& matrix);
};
#endif