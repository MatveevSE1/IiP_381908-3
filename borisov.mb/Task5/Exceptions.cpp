#include "Exceptions.h"
void MatrixExceptionHandling(MatrixException& exception)
{
	try
	{
		throw exception;
	}
	catch(MatrixException& exception)
	{
		std::cout << exception.exceptionName << std::endl;
		exit(static_cast<int>(exception.exceptionCode));
	}
}

void VectorExceptionHandling(VectorException& exception)
{
	try
	{
		throw exception;
	}
	catch (VectorException & exception)
	{
		std::cout << exception.exceptionName << std::endl;
		exit(static_cast<int>(exception.exceptionCode));
	}
}
namespace Exceptions
{
	extern const std::string NSQEX = "NOT_SQUARE_EXCEPTION";
	extern const std::string MDNEX = "MATRIX_DATA_NULL_EXCEPTION";
	extern const std::string MDSEX = "MATRIX_DIFFERENT_SIZES_EXCEPTION";
	extern const std::string MBSEX = "MATRIX_BAD_SIZES_EXCEPTION";
	extern const std::string DBZEX = "DIVIDED_BY_ZERO_EXCEPTION";
	extern const std::string VDSEX = "VECTOR_DIFFERENT_SIZES_EXCEPTION";
	extern const std::string VDNEX = "VECTOR_DATA_NULL_EXCEPTION";
}