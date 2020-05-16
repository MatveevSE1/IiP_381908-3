#include <iostream>
#include "Header.h"
using namespace std;

int main()
{

	int a1, a2, b1, b2;
	fraction* dr1 = new fraction();
	fraction* dr2 = new fraction();
	do {
		cout << "Введите числитель для первой дроби" << endl;
		cin >> a1;
		if (a1 == 0)
			cout << "Ошибка!!!" << endl;
	} while (a1 == 0);
	do {
		cout << "Введите знаменатель для первой дроби" << endl;
		cin >> b1;
		if (b1 == 0)
			cout << "Ошибка!!!" << endl;
	} while (b1 == 0);
	do {
		cout << "Введите числитель для второй дроби" << endl;
		cin >> a2;
		if (a2 == 0)
			cout << "Ошибка!!!" << endl;
	} while (a2 == 0);
	do {
		cout << "Введите знаменатель для второй дроби" << endl;
		cin >> b2;
		if (b2 == 0)
			cout << "Ошибка!!!" << endl;
	} while (b2 == 0);
	dr1->SetCH(a1);
	dr1->SetZN(b1);
	dr2->SetCH(a2);
	dr2->SetZN(b2);
	dr1->Proizv(dr1->GetCH(), dr1->GetZN(), dr2->GetCH(), dr2->GetZN());
	dr1->Shastn(dr1->GetCH(), dr1->GetZN(), dr2->GetCH(), dr2->GetZN());
	dr1->Sum(dr1->GetCH(), dr1->GetZN(), dr2->GetCH(), dr2->GetZN());
	dr1->Razn(dr1->GetCH(), dr1->GetZN(), dr2->GetCH(), dr2->GetZN());

}