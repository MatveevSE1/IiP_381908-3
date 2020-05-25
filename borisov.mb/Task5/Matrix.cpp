#include "Matrix.h"

Matrix::Matrix() : RowsMatrix( 3 ), ColsMatrix( 3 )
{
	RowsArray = static_cast<Vector*>(operator new[](RowsMatrix * sizeof(Vector)));
	for (int i = 0; i < RowsMatrix; i++)
		new (RowsArray + i) Vector(ColsMatrix);
}


Matrix::Matrix(int _RowsMatrix, int _ColsMatrix) : RowsMatrix( _RowsMatrix ), ColsMatrix( _ColsMatrix )
{
	RowsArray = static_cast<Vector*>(operator new[](RowsMatrix * sizeof(Vector)));
	for (int i = 0; i < RowsMatrix; i++)
		new (RowsArray + i) Vector(ColsMatrix);
}

Matrix::Matrix(const Matrix& matrix)
{
	MatrixException exception(MATRIX_DATA_NULL_EXCEPTION, Exceptions::MDNEX);
	if (matrix.RowsArray == NULL)
		MatrixExceptionHandling(exception);
	RowsMatrix = matrix.RowsMatrix;
	ColsMatrix = matrix.ColsMatrix;
	RowsArray = static_cast<Vector*>(operator new[](RowsMatrix * sizeof(Vector)));
	for (int i = 0; i < RowsMatrix; i++)
		new (RowsArray + i) Vector(ColsMatrix);
	for (int i = 0; i < RowsMatrix; i++)
	{
		for (int j = 0; j < ColsMatrix; j++)
		{
			RowsArray[i][j] = matrix.RowsArray[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < RowsMatrix; i++)
	{
		RowsArray[i].~Vector();
	}
	operator delete[](RowsArray);
	RowsMatrix = 0;
	ColsMatrix = 0;
}

void Matrix::PrintMatrix() const
{
	std::cout << "MATRIX:" << std::endl;
	for (int i = 0; i < RowsMatrix; i++)
	{
		std::cout << RowsArray[i];
	}
}

void Matrix::Transpose()
{
	Matrix TEMPmatrix(*this);
	for (int i = 0; i < RowsMatrix; i++)
	{
		for (int j = 0; j < ColsMatrix; j++)
		{
			RowsArray[i][j] = TEMPmatrix.RowsArray[j][i];
		}
	}
}

void Matrix::SetValue(int i, int j, double value)
{
	this->RowsArray[i][j] = value;
}

Matrix Matrix::Minor(int row, int col)
{
	MatrixException exception(NOT_SQUARE_EXCEPTION, Exceptions::NSQEX);
	if (RowsMatrix != ColsMatrix)
		MatrixExceptionHandling(exception);
	Matrix TEMPmatrix(RowsMatrix - 1, ColsMatrix - 1);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			TEMPmatrix.RowsArray[i][j] = RowsArray[i][j];
		for (int j = col + 1; j < RowsMatrix; j++)
			TEMPmatrix.RowsArray[i][j = 1] = RowsArray[i][j];
	}
	for (int i = row + 1; i < RowsMatrix; i++)
	{
		for (int j = 0; j < col; j++)
			TEMPmatrix.RowsArray[i - 1][j] = RowsArray[i][j];
		for (int j = col + 1; j < RowsMatrix; j++)
			TEMPmatrix.RowsArray[i - 1][j - 1] = RowsArray[i][j];
	}
	return TEMPmatrix;
}

double Matrix::Determinant()
{
	MatrixException exception(NOT_SQUARE_EXCEPTION, Exceptions::NSQEX);
	double det = 0;
	double degree = 1;
	if (RowsMatrix != ColsMatrix)
		MatrixExceptionHandling(exception);
	if (RowsMatrix == 1)
		return RowsArray[0][0];
	Matrix TEMPmatrix(RowsMatrix - 1, RowsMatrix - 1);
	for (int j = 0; j < RowsMatrix; j++)
	{
		TEMPmatrix = Minor(0, j);
		if (j % 2 == 0)
			det += TEMPmatrix.Determinant() * RowsArray[0][j];
		else
			det -= TEMPmatrix.Determinant() * RowsArray[0][j];
	}
	return det;

}

Matrix& Matrix::operator=(const Matrix& matrix)
{
	MatrixException exception(MATRIX_DATA_NULL_EXCEPTION, Exceptions::MDNEX);
	if (matrix.RowsArray == NULL)
		MatrixExceptionHandling(exception);
	RowsMatrix = matrix.RowsMatrix;
	ColsMatrix = matrix.ColsMatrix;
	RowsArray = static_cast<Vector*>(operator new[](RowsMatrix * sizeof(Vector)));
	for (int i = 0; i < RowsMatrix; i++)
		new (RowsArray + i) Vector(ColsMatrix);
	for (int i = 0; i < RowsMatrix; i++)
	{
		for (int j = 0; j < ColsMatrix; j++)
		{
			RowsArray[i][j] = matrix.RowsArray[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator+(const Matrix& matrix) const
{
	MatrixException exception(MATRIX_DIFFERENT_SIZES_EXCEPTION, Exceptions::MDSEX);
	if (RowsMatrix != matrix.RowsMatrix || ColsMatrix != matrix.ColsMatrix)
		MatrixExceptionHandling(exception);
	Matrix RESULTmatrix(RowsMatrix, ColsMatrix);
	for (int i = 0; i < RowsMatrix; i++)
	{
		for (int j = 0; j < ColsMatrix; j++)
		{
			RESULTmatrix.RowsArray[i][j] = RowsArray[i][j] + matrix.RowsArray[i][j];
		}
	}
	return RESULTmatrix;
}

Matrix Matrix::operator-(const Matrix& matrix) const
{
	MatrixException exception(MATRIX_DIFFERENT_SIZES_EXCEPTION, Exceptions::MDSEX);
	if (RowsMatrix != matrix.RowsMatrix || ColsMatrix != matrix.ColsMatrix)
		MatrixExceptionHandling(exception);
	Matrix RESULTmatrix(RowsMatrix, ColsMatrix);
	for (int i = 0; i < RowsMatrix; i++)
	{
		for (int j = 0; j < ColsMatrix; j++)
		{
			RESULTmatrix.RowsArray[i][j] = RowsArray[i][j] - matrix.RowsArray[i][j];
		}
	}
	return RESULTmatrix;
}

Matrix Matrix::operator*(const int value) const
{
	Matrix RESULTmatrix(RowsMatrix, ColsMatrix);
	for (int i = 0; i < RowsMatrix; i++)
	{
		for (int j = 0; j < ColsMatrix; j++)
		{
			RESULTmatrix.RowsArray[i][j] = RowsArray[i][j] * value;
		}
	}
	return RESULTmatrix;
}

Matrix Matrix::operator*(const Matrix& matrix) const
{
	MatrixException exception(MATRIX_BAD_SIZES_EXCEPTION, Exceptions::MBSEX);
	if (ColsMatrix != matrix.RowsMatrix)
		MatrixExceptionHandling(exception);
	Matrix RESULTmatrix(RowsMatrix, matrix.ColsMatrix);
	for (int i = 0; i < RowsMatrix; i++)
	{
		for (int j = 0; j < matrix.ColsMatrix; j++)
		{
			for (int k = 0; k < ColsMatrix; k++)
			{
				RESULTmatrix.RowsArray[i][j] += RowsArray[i][k] * matrix.RowsArray[k][j];
			}
		}
	}
	return RESULTmatrix;
}

Matrix Matrix::operator^(const int degree) 
{
	Matrix RESULTvector(RowsMatrix, ColsMatrix);
	if (degree < 0)
		exit(1);
	if (degree == 0)
	{
		for (int i = 0; i < RowsMatrix; i++)
		{
			for (int j = 0; j < ColsMatrix; j++)
			{
				RowsArray[i][j] = 1;
			}
		}
		RESULTvector = Matrix(*this);
		return RESULTvector;
	}
	RESULTvector = Matrix(*this);
	for (int i = 1; i < degree; i++)
	{
		RESULTvector = RESULTvector * *this;
	}
	return RESULTvector;
}

Matrix Matrix::Reverse()
{
	MatrixException exception1(NOT_SQUARE_EXCEPTION, Exceptions::NSQEX);
	MatrixException exception2(DIVIDED_BY_ZERO_EXCEPTION, Exceptions::DBZEX);
	if (RowsMatrix != ColsMatrix)
		MatrixExceptionHandling(exception1);
	Matrix RESULTmatrix(RowsMatrix, RowsMatrix);
	double det = this->Determinant();
	if (det == 0)
		MatrixExceptionHandling(exception2);
	Matrix TEMPmatrix(RowsMatrix - 1, RowsMatrix - 1);
	int degree;
	for (int i = 0; i < RowsMatrix; i++)
	{
		degree = i % 2 == 0 ? 1 : -1;
		for (int j = 0; j < RowsMatrix; j++)
		{
			TEMPmatrix = Minor(i, j);
			RESULTmatrix.RowsArray[i][j] = degree * TEMPmatrix.Determinant() / det;
			degree = -degree;
		}
	}
	return RESULTmatrix;
}

Matrix Matrix::operator/(Matrix& matrix) const
{
	MatrixException exception(NOT_SQUARE_EXCEPTION, Exceptions::NSQEX);
	if (matrix.RowsMatrix != matrix.ColsMatrix)
		MatrixExceptionHandling(exception);
	Matrix RESULTmatrix = matrix.Reverse() * *this;
	return RESULTmatrix;
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix)
{
	std::cout << "MATRIX:" << std::endl;
	for (int i = 0; i < matrix.RowsMatrix; i++)
	{
		std::cout << matrix.RowsArray[i];
	}
	return out;
}

std::istream& operator>>(std::istream& in, const Matrix& matrix)
{
	std::cout << "ENTER MATRIX: " << std::endl;
	for (int i = 0; i < matrix.RowsMatrix; i++)
	{
		std::cin >> matrix.RowsArray[i];
	}
	return in;
}
