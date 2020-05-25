#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <cstdlib>
#include <iostream>

namespace Exceptions
{
	extern const std::string NSQEX;
	extern const std::string MDNEX;
	extern const std::string MDSEX;
	extern const std::string MBSEX;
	extern const std::string DBZEX;
	extern const std::string VDSEX;
	extern const std::string VDNEX;
}

enum TypeOfMatrixException
{
	NOT_SQUARE_EXCEPTION = 1,
	MATRIX_DATA_NULL_EXCEPTION = 2,
	MATRIX_DIFFERENT_SIZES_EXCEPTION = 3,
	MATRIX_BAD_SIZES_EXCEPTION = 4,
	DIVIDED_BY_ZERO_EXCEPTION = 5,
};

enum TypeOfVectorException
{
	VECTOR_DIFFERENT_SIZES_EXCEPTION = 10,
	VECTOR_DATA_NULL_EXCEPTION = 20,
};

struct MatrixException
{
	TypeOfMatrixException exceptionCode;
	std::string exceptionName;
	MatrixException(TypeOfMatrixException _exceptionCode, std::string _exceptionName) : exceptionCode(_exceptionCode), exceptionName(_exceptionName) {}
};

struct VectorException
{
	TypeOfVectorException exceptionCode;
	std::string exceptionName;
	VectorException(TypeOfVectorException _exceptionCode, std::string _exceptionName) : exceptionCode(_exceptionCode), exceptionName(_exceptionName) {}
};

void MatrixExceptionHandling(MatrixException& exception);
void VectorExceptionHandling(VectorException& exception);

#endif
