// Векторы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Matrix.h"
#include "Windows.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(0));

	int n;
	cout << "Введите размер вектора" << endl;
	do {
		cin >> n;
	} while (n < 3);
	Vector v1(n), v2(n), sum(n), resVec(n);
	double result, cos;
	cout << "Вектор 1 " << endl;
	cin >> v1;
	cout << "Вектор 2 " << endl;
	cin >> v2;
	Vector* tt = new Vector[n];

	cout << endl << "Длина вектора  " << v1.GetLenght() << endl;

	cout << "Длина между векторами  " << v1.lenghtbetweenvectors(v2) << endl;
	try {
		sum = v1 + v2;
		cout << "Сложение векторов  " << sum << endl;
	}
	catch(int) 
	{
		cout << "Векторы не равны по размеру или векторы нулевые" << endl;
	}

	try {
		sum = v1 - v2;
		cout << "Разность векторов  " << sum << endl;
	}
	catch (int) 
	{
		cout << "Векторы не равны по размеру или векторы нулевые" << endl;
	}
	try {
		result = v1 * v2;
		cout << "Скалярное произведение  " << result << endl;
	}
	catch (int) 
	{
		cout << "Векторы не равны по размеру или векторы нулевые" << endl;
	}

	try {
		cos = v1.GetCosA(v2);
		cout << "Косинус между углами  " << cos << endl;
	}
	catch (int)
	{
		cout << "Векторы не равны по размеру или векторы нулевые" << endl;
	}

	tt[2] = v2;
	tt[1] = v1;
	for (int i = 3; i < n; i++)
	{
		v2.Random();
		tt[i] = v2;
	}

	resVec = v1.VecMult(tt);
	cout << endl << "Векторное произведение  " << resVec << endl;

	Matrix m1(n, n), m2(n, n), m3;
	Matrix ress(n, n);
	for (int i = 0; i < n; i++)
	{
		v1.Random();
		v2.Random();
		m1.Set(v1, i);
		m2.Set(v2, i);
	}

	cout << endl;
	cout << "Генерация матрицы" << endl;
	m1.MOut();
	cout << endl;
	m2.MOut();
	cout << endl;

	cout << "Сумма матриц " << endl;

	ress = m1 + m2;
	cout << endl;
	ress.MOut();

	cout << "Вычитание матриц " << endl;

	ress = m1 - m2;
	cout << endl;
	ress.MOut();

	cout << "Умножение матрицы на скаляр" << endl;
	int a;
	cout << "Введите скаляр ";
	cin >> a;
	ress = ress * a;
	cout << endl;
	ress.MOut();

	cout << "Умножение матриц" << endl;

	ress = m1 * m2;
	cout << endl;
	ress.MOut();

	cout << "Деление матрицы на скаляр" << endl;
	cout << "Введите скаляр ";
	cin >> a;
	ress = ress / a;
	cout << endl;
	ress.MOut();

	cout << "Деление матриц " << endl;

	ress = m1 / m2;
	cout << endl;
	ress.MOut();

	cout << "Возведение в степень первой матрици " << endl;
	cout << "Введите степень ";
	cin >> a;

	ress = m1 ^ a;
	cout << endl;
	ress.MOut();
}