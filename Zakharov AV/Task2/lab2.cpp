#include <iostream>
#include"fruct.h"
#include "com.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int a1, a2, b1, b2;
	fraction* dr1 = new fraction();
	fraction* dr2 = new fraction();

	do
	{
		cout << "¬ведите числитель первой дроби" << endl;
		cin >> a1;
		if (a1 == 0)
			cout << "¬ведите число!=0" << endl;
	} while (a1 == 0);

	do
	{
		cout << "¬ведите знаменатель первой дроби" << endl;
		cin >> b1;
		if (b1 == 0)
			cout << "¬ведите число!=0" << endl;
	} while (b1 == 0);

	do
	{
		cout << "¬ведите числитель второй дроби" << endl;
		cin >> a2;
		if (a2 == 0)
			cout << "¬ведите число!=0" << endl;
	} while (a2 == 0);

	do
	{
		cout << "¬ведите знаменатель второй дроби" << endl;
		cin >> b2;
		if (b2 == 0)
			cout << "¬ведите число!=0" << endl;
	} while (b2 == 0);


	dr1->SetCH(a1);
	dr1->SetZN(b1);
	dr2->SetCH(a2);
	dr2->SetZN(b2);
	Complex* zal = new Complex(*dr1, *dr2);

	dr1->Proizv(*dr1, *dr2);
	dr1->Shastn(*dr1, *dr2);
	dr1->Sum(*dr1, *dr2);
	dr1->Razn(*dr1, *dr2);
	zal->Otv();

}