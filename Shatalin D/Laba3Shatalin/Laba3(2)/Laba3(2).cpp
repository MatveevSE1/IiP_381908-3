#include <iostream>
#include"fraction.h"
#include "Komp.h"
#include <windows.h>

using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a1,a2,b1, b2;
	fraction*dr1 = new fraction();
	fraction*dr2 = new fraction();
	Kompl g, h, j,v1;
	Kompl ress = Kompl();
	Kompl ressBoss = Kompl();
	double k;
	cout << "\t" << "Введите первые элементы 2 дробей"<<endl;
	cin >> g;
	cout << "\t" << "Введите целое число" << endl;
	cin >> k;
	g += k;//результат присваивания сложения 
	cout << g << endl;
	g -= k;//результат присваивания отрицания 
	cout << g << endl;
	g /= k;//результат присваивания деления 
	cout << g << endl;
	g *= k;//результат присваивания умножения 
	cout << g << endl;
	j = g + k;//результат сложения
	cout << j << endl;
	j = g - k;//результат вычитания
	cout << j << endl;
	j = g / k;//результат деления
	cout << j << endl;
	j = g * k;//результат умножения
	cout << j << endl;
	cout << "\t" << "Введите вторые элементы 2 дробей" << endl;
	cin >> h;
	j = g + h;//результат сложения
	cout << j << endl;
	j = g - h;//результат вычитания
	cout << j << endl;
	j = g / h;//результат деления
	cout << j << endl;
	j = g * h;//результат умножения
	cout << j << endl;
	g += h;//результат присваивания сложения 
	cout << g << endl;
	g -= h;//результат присваивания отрицания 
	cout << g << endl;
	g /= h;//результат присваивания деления 
	cout << g << endl;
	g *= h;//результат присваивания умножения 
	cout << g << endl;
	cout << "\t" << "Введите 4 числа" << endl;
	cin >> v1;//проверка на in
	cout << v1 << endl;//проверка на out


	do
	{
		cout<<"\t" << "введите числитель 1 дроби" << endl;
		cin >> a1;
		if (a1 == 0)
			cout << "\t" << "введите числитель не равный 0" << endl;
	} while (a1 == 0);

	do
	{
		cout << "\t" << "Ведите знаменать 1 дроби" << endl;
		cin >> b1;
		if (b1 == 0)
			cout << "\t" << "Введите знаменатель не равный 0" << endl;
	} while (b1 == 0);

	do
	{
		cout << "\t" << "введите числитель 2 дроби" << endl;
		cin >> a2;
		if (a2 == 0)
			cout << "\t" << "введите числитель не равный 0" << endl;
	} while (a2 == 0);

	do
	{
		cout << "\t" << "Ведите знаменать 2 дроби" << endl;
		cin >> b2;
		if (b2 == 0)
			cout << "\t" << "Введите знаменатель не равный 0" << endl;
	} while (b2 == 0);


	dr1->SetCH(a1);
	dr1->SetZN(b1);
	dr2->SetCH(a2);
	dr2->SetZN(b2);
	Kompl* zal = new Kompl(*dr1, *dr2);

	dr1->Proizv(*dr1, *dr2);
	dr1->Shastn(*dr1, *dr2);
	dr1->Sum(*dr1, *dr2);
	dr1->Razn(*dr1, *dr2);
	zal->Otv();


}