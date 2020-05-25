#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <new>
#include "Exceptions.h"
class Vector
{
private:
	int Size;
	double* Data;
	int ArraySize;
public:
	Vector();
	Vector(int _size, double* _data);
	Vector(int _size);
	Vector(const Vector& vector);
	~Vector();
	Vector& operator=(const Vector& tmp);
	Vector operator+(const Vector& tmp) const;
	Vector operator-(const Vector& tmp) const;
	Vector operator*(Vector* vector);
	double& operator[](const int index);
	double operator()(Vector& vector1, Vector& vector2);
	friend std::ostream& operator<<(std::ostream& out, const Vector& vector);
	friend std::istream& operator>>(std::istream& in, const Vector& vector);
	void PrintVector();
	double Length() const;
	double LengthBetweenVectors(const Vector& vector);
	double GetCosA(Vector& vector) const;
	void Transpose(Vector& vector);
	void SetSize(int _size);
	int GetSize() const;
};

void Minor(double** arr, int n, int row, int col, double** newarr);
double Determinant(double** arr, int n);

#endif
