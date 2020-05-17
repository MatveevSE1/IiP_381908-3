// ConsoleApplication5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include "fraction.h"
#include "Komp.h"
using namespace std;
int main()
{
	int a1, a2, b1, b2;
	fraction*dr1 = new fraction();
	fraction*dr2 = new fraction();

	do
	{
		cout << "vvedite chislit 1 drobi" << endl;
		cin >> a1;
		if (a1 == 0)
			cout << "Vvedite chislo!=0" << endl;
	} while (a1 == 0);

	do
	{
		cout << "vvedite znam 1 drobi" << endl;
		cin >> b1;
		if (b1 == 0)
			cout << "Vvedite chislo!=0" << endl;
	} while (b1 == 0);

	do
	{
		cout << "vvedite chislit 2 drobi" << endl;
		cin >> a2;
		if (a2 == 0)
			cout << "Vvedite chislo!=0" << endl;
	} while (a2 == 0);

	do
	{
		cout << "vvedite znam 2 drobi" << endl;
		cin >> b2;
		if (b2 == 0)
			cout << "Vvedite chislo!=0" << endl;
	} while (b2 == 0);


	dr1->SetCH(a1);
	dr1->SetZN(b1);
	dr2->SetCH(a2);
	dr2->SetZN(b2);
	Komp* zal = new Komp(*dr1, *dr2);

	dr1->Proizv(*dr1, *dr2);
	dr1->Shastn(*dr1, *dr2);
	dr1->Sum(*dr1, *dr2);
	dr1->Razn(*dr1, *dr2);
	zal->Otv();

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
