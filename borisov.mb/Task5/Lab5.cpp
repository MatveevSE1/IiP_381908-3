#include <iostream>
#include "Matrix.h"
int main()
{
	using namespace std;
	int choose;
	int degree;
	cout << "PROGRAM RUNNING\nCHOOSE:\n1 - VECTOR    2 - MATRIX    0 - EXIT" << endl;
	cin >> choose;
	if (choose == 0)
		exit(0);
	if (choose == 1)
	{
		int SizeOfArray;
		int SizeOfVector;
		cout << "Enter size of vectors: ";
		cin >> SizeOfVector;
		Vector FIRSTvector(SizeOfVector);
		Vector SECONDvector(FIRSTvector);
		Vector RESULTvector(SECONDvector);
		cout << "========FIRST VECTOR ENTER========" << endl;
		cin >> FIRSTvector;
		cout << "========SECOND VECTOR ENTER========" << endl;
		cin >> SECONDvector;
		system("cls");
		cout << "========FIRST VECTOR========" << endl;
		cout << FIRSTvector;
		cout << "Length: " << FIRSTvector.Length() << endl;
		cout << "========SECOND VECTOR========" << endl;
		cout << SECONDvector;
		cout << "Length: " << SECONDvector.Length() << endl;
		cout << "========FIRST + SECOND========" << endl;
		RESULTvector = FIRSTvector + SECONDvector;
		cout << RESULTvector;
		cout << "========FIRST - SECOND========" << endl;
		RESULTvector = FIRSTvector - SECONDvector;
		cout << RESULTvector;
		cout << "========FIRST * SECOND========" << endl;
		cout << "Enter size of array: ";
		cin >> SizeOfArray;
		Vector* ArrayOfVectors = static_cast<Vector*>(operator new[](SizeOfArray * sizeof(Vector)));
		for (int i = 0; i < SizeOfArray; i++)
			new(ArrayOfVectors + i) Vector(SizeOfVector);
		for (int i = 0; i < SizeOfArray; i++)
		{
			ArrayOfVectors[i].SetSize(SizeOfArray);
			cin >> ArrayOfVectors[i];
		}
		RESULTvector = FIRSTvector * ArrayOfVectors;
		cout << RESULTvector;
		cout << "========(FIRST, SECOND)========" << endl;
		cout << FIRSTvector(FIRSTvector, SECONDvector) << endl;
		cout << "========LENGTH (FIRST, SECOND)========" << endl;
		cout << FIRSTvector.LengthBetweenVectors(SECONDvector) << endl;
		cout << "========COS (FIRST, SECOND)========" << endl;
		cout << FIRSTvector.GetCosA(SECONDvector);
	}
	if (choose == 2)
	{
		int Rows, Cols;
		cout << "Enter Rows: ";
		cin >> Rows;
		cout << "Enter Cols: ";
		cin >> Cols;
		Matrix FIRSTmatrix(Rows, Cols);
		Matrix SECONDmatrix(FIRSTmatrix);
		Matrix RESULTmatrix(SECONDmatrix);
		cout << "========FIRST MATRIX ENTER========" << endl;
		cin >> FIRSTmatrix;
		cout << "========SECOND MATRIX ENTER========" << endl;
		cin >> SECONDmatrix;
		system("cls");
		cout << "========FIRST MATRIX========" << endl;
		cout << FIRSTmatrix;
		cout << "========SECOND MATRIX========" << endl;
		cout << SECONDmatrix;
		cout << "========FIRST + SECOND========" << endl;
		RESULTmatrix = FIRSTmatrix + SECONDmatrix;
		cout << RESULTmatrix;
		cout << "========FIRST - SECOND========" << endl;
		RESULTmatrix = FIRSTmatrix - SECONDmatrix;
		cout << RESULTmatrix;
		cout << "========FIRST * SECOND========" << endl;
		RESULTmatrix = FIRSTmatrix * SECONDmatrix;
		cout << RESULTmatrix;
		cout << "========FIRST ^ DEGREE========" << endl;
		cout << "Enter degree: ";
		cin >> degree;
		RESULTmatrix = FIRSTmatrix^ degree;
		cout << RESULTmatrix;
		cout << "========FIRST / SECOND========" << endl;
		RESULTmatrix = FIRSTmatrix / SECONDmatrix;
		cout << RESULTmatrix;
	}
}