#include "Vector.h"
Vector::Vector() : Size(5), ArraySize(1)
{
	Data = new double[5];
	for (int i = 0; i < Size; i++)
	{
		Data[i] = 0;
	}
}

Vector::Vector(int _size) : Size(_size), ArraySize(1)
{
	Data = new double[Size];
	for (int i = 0; i < Size; i++)
	{
		Data[i] = 0;
	}
}

Vector::Vector(int _size, double* _data)
{
	ArraySize = 1;
	VectorException exception(VECTOR_DATA_NULL_EXCEPTION, Exceptions::VDNEX);
	if (_data == NULL)
		VectorExceptionHandling(exception);
	Size = _size;
	Data = new double[Size];
	for (int i = 0; i < Size; i++)
	{
		Data[i] = _data[i];
	}
}

Vector::Vector(const Vector& vector)
{
	VectorException exception(VECTOR_DATA_NULL_EXCEPTION, Exceptions::VDNEX);
	if (vector.Data == NULL)
		VectorExceptionHandling(exception);
	ArraySize = vector.ArraySize;
	Size = vector.Size;
	Data = new double[Size];
	for (int i = 0; i < Size; i++)
	{
		Data[i] = vector.Data[i];
	}
}

Vector::~Vector()
{
	delete[] Data;
	this->Data = nullptr;
	Size = 0;
}

void Vector::PrintVector()
{
	std::cout << "VECTOR: ";
	std::cout << "(";
	for (int i = 0; i < Size; i++)
	{
		std::cout << Data[i] << ", ";
	}
	std::cout << '\b' << '\b';
	std::cout << ")" << std::endl;
}

double Vector::Length() const
{
	double res = 0;
	if (this->Data != nullptr && this->Size > 0)
	{
		for (int i = 0; i < this->Size; i++)
		{
			res += Data[i] * Data[i];
		}
		return sqrt(res);
	}
	else
		return -1;
}

double Vector::LengthBetweenVectors(const Vector& vector)
{
	double result = 0;
	for (int i = 0; i < Size; i++)
	{
		result += (vector.Data[i] - Data[i]) * (vector.Data[i] - Data[i]);
	}
	return sqrt(result);
}

double Vector::GetCosA(Vector& vector) const
{
	double ResultNum = 0;
	for (int i = 0; i < Size; i++)
	{
		ResultNum += Data[i] * vector.Data[i];
	}
	double ResultDen = this->Length() * vector.Length();
	double cos = ResultNum / ResultDen;
	return cos;
}

void Vector::Transpose(Vector& vector)
{
	VectorException exception(VECTOR_DIFFERENT_SIZES_EXCEPTION, Exceptions::VDSEX);
	if (this->Size != vector.Size)
		VectorExceptionHandling(exception);
	for (int i = 0; i < Size; i++)
	{
		this->Data[i] = vector.Data[i];
	}
}

void Vector::SetSize(int _size)
{
	ArraySize = _size;
}

int Vector::GetSize() const
{
	return ArraySize;
}

Vector& Vector::operator=(const Vector& vector)
{
	VectorException exception(VECTOR_DATA_NULL_EXCEPTION, Exceptions::VDNEX);
	if (vector.Data == NULL)
		VectorExceptionHandling(exception);
	Size = vector.Size;
	Data = new double[Size];
	for (int i = 0; i < Size; i++)
	{
		Data[i] = vector.Data[i];
	}
	return *this;
}

Vector Vector::operator+(const Vector& vector) const
{
	VectorException exception1(VECTOR_DIFFERENT_SIZES_EXCEPTION, Exceptions::VDSEX);
	VectorException exception2(VECTOR_DATA_NULL_EXCEPTION, Exceptions::VDNEX);
	if (Size != vector.Size)
		VectorExceptionHandling(exception1);
	if (vector.Data == NULL)
		VectorExceptionHandling(exception2);
	Vector TEMPvector;
	TEMPvector.Size = Size;
	TEMPvector.Data = new double[TEMPvector.Size];
	for (int i = 0; i < Size; i++)
	{
		TEMPvector.Data[i] = Data[i] + vector.Data[i];
	}
	return TEMPvector;
}

Vector Vector::operator-(const Vector& vector) const
{
	VectorException exception1(VECTOR_DIFFERENT_SIZES_EXCEPTION, Exceptions::VDSEX);
	VectorException exception2(VECTOR_DATA_NULL_EXCEPTION, Exceptions::VDNEX);
	if (Size != vector.Size)
		VectorExceptionHandling(exception1);
	if (vector.Data == NULL)
		VectorExceptionHandling(exception2);
	Vector TEMPvector;
	TEMPvector.Size = Size;
	TEMPvector.Data = new double[TEMPvector.Size];
	for (int i = 0; i < Size; i++)
	{
		TEMPvector.Data[i] = Data[i] - vector.Data[i];
	}
	return TEMPvector;
}

Vector Vector::operator*(Vector* vector)
{ 
	VectorException exception(VECTOR_DIFFERENT_SIZES_EXCEPTION, Exceptions::VDSEX);
	for (int i = 0; i < Size; i++)
	{
		if(Size!=vector[i].Size)
			VectorExceptionHandling(exception);
		if (vector[i].ArraySize - 2 < Size)
			VectorExceptionHandling(exception);
	}
	Vector RESULTvector(Size);
	double** temp = new double* [Size];
	double** tmpdata = new double* [Size-1];
	for (int i = 0; i < Size-1; i++)
	{
		tmpdata[i] = new double[Size-1];
	}
	for (int i = 0; i < Size; i++)
	{
		temp[i] = new double[Size];
		temp[0][i] = 1;
	}
	for (int i = 0; i < Size; i++)
		temp[1][i] = Data[i];
	int k = 0;
	for (int i = 2; i < Size; i++)
	{
		
		for (int j = 0; j < Size; j++)
		{
			temp[i][j] = vector[k].Data[j];
		}
		k++;
	}
	for (int i = 0; i < Size; i++)
	{
		Minor(temp, Size, 0, i, tmpdata);
		RESULTvector.Data[i] = Determinant(tmpdata, Size - 1);
	}
	for (int i = 0; i < Size; i++)
	{
		delete[] temp[i];
		delete[] tmpdata[i];
	}
	delete[] temp;
	temp = nullptr;
	delete[] tmpdata;
	tmpdata = nullptr;
	return RESULTvector;
}

double& Vector::operator[](const int index) 
{
	return Data[index];
}


double Vector::operator()(Vector& vector1, Vector& vector2)
{
	double Result;
	Result = vector1.Length() * vector2.Length() * vector1.GetCosA(vector2);
	return Result;
}

std::ostream& operator<<(std::ostream& out, const Vector& vector)
{
	std::cout << "(";
	for (int i = 0; i < vector.Size; i++)
	{
		std::cout << vector.Data[i] << ", ";
	}
	std::cout << '\b' << '\b';
	std::cout << ")" << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, const Vector& vector)
{
	std::cout << "ENTER VECTOR: " << std::endl;
	for (int i = 0; i < vector.Size; i++) {
		std::cout << "[" << i << "] = ";
		std::cin >> vector.Data[i];
	}
	return in;
}

void Minor(double** arr, int n, int row, int col, double** newarr)
{
	int offsetRow = 0;
	int offsetCol = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (i == row)
			offsetRow = 1;
		offsetCol = 0;
		for (int j = 0; j < n - 1; j++)
		{
			if (j == col)
				offsetCol = 1;
			newarr[i][j] = arr[i + offsetRow][j + offsetCol];
		}
	}
}

double Determinant(double** arr, int n)
{
	double det = 0;
	double degree = 1;
	if (n == 1)
		return arr[0][0];
	else if (n == 2)
		return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
	else
	{
		double** newarr = new double* [n - 1];
		for (int i = 0; i < n - 1; i++)
		{
			newarr[i] = new double[n - 1];
		}
		for (int j = 0; j < n; j++)
		{
			Minor(arr, n, 0, j, newarr);
			det = det + (degree * arr[0][j] * Determinant(newarr, n - 1));
			degree = -degree;
		}
		for (int i = 0; i < n - 1; i++)
		{
			delete[] newarr[i];
		}
		delete[] newarr;
	}
	return det;
}

