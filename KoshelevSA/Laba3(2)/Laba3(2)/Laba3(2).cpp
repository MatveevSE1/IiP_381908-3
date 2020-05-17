#include <iostream>
#include"fraction.h"
#include "Komp.h"
using namespace std;
int main()
{
	int a1,a2,b1, b2,g;
	fraction*dr1 = new fraction();
	fraction*dr2 = new fraction();
	Kompl aa, bb, cc,c1;
	cout << "Vvedite try complexnih cisla" << endl;
	cin >> c1;
	cout << "pervoe " << c1 << endl;
	cin >> aa;
	cout << "vtoroe " << aa << endl;
	cin >> bb;
	cout << "tret'e " << bb << endl;
	cout << "Vvedite chislo " << endl;
	cin >> g;
	cout <<"proverka in u out" <<c1 << endl;
	cc = aa + bb;
	cout << "Otvet compl chislo pri slozh "<<cc<<endl;
	
	cc = aa + g;
	cout << "Otvet compl chislo pri slozh s int " << cc << endl;
	cc = aa - bb;
	cout << "Otvet compl chislo pri vicjit " << cc<<endl;
	cc = aa / bb;
	cout << "Otvet compl chislo pri delen " << cc<<endl;
	cc = aa * bb;
	cout << "Otvet compl chislo pri umnozh " << cc << endl;
	cc += aa + bb;
	cout << "Otvet compl chislo pri slozh sovm s prisv " << cc << endl;
	cc -= aa + bb;
	cout << "Otvet compl chislo pri vicjit sovm s prisv " << cc << endl;
	cc *= aa + bb;
	cout << "Otvet compl chislo pri umnozh sovm s prisv " << cc << endl;
	cc /= aa + bb;
	cout << "Otvet compl chislo pri delen sovm s prisv " << cc << endl;
	cc = aa - g;
	cout << "Otvet compl chislo pri vicjit s int " << cc << endl;
	cc = aa / g;
	cout << "Otvet compl chislo pri delen s int " << cc << endl;
	cc = aa - g;
	cout << "Otvet compl chislo pri umnozh s int " << cc << endl;
	cc != aa;
	cout << "Otvet compl chislo pri nerawenstwe " << cc << endl;
	cc > aa;
	cout << "Otvet compl chislo pri bol'she " << cc << endl;
	cc < aa;
	cout << "Otvet compl chislo pri men'she " << cc << endl;
	cc == aa;
	cout << "Otvet compl chislo pri ravenstve " << cc << endl;
	cc == aa;
	cout << "Otvet compl chislo pri bol'she ili ravno " << cc << endl;
	cc == aa;
	cout << "Otvet compl chislo pri men'she ili ravno " << cc << endl;
	cc /= g;
	cout << "Otvet compl chislo pri delen sovm s prisv int " << cc << endl;
	cc *= g;
	cout << "Otvet compl chislo pri umnozh sovm s prisv int " << cc << endl;

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
	Kompl* zal = new Kompl(*dr1, *dr2);

	dr1->Proizv(*dr1, *dr2);
	dr1->Shastn(*dr1, *dr2);
	dr1->Sum(*dr1, *dr2);
	dr1->Razn(*dr1, *dr2);
	zal->Otv();
	

}