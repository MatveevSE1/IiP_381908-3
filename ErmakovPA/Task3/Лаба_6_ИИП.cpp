#include "Bankomat.h"
int main() {

	Bancomat banki;
	string s;
	int choiose, id;
	bool existAndСonfirmed = false, cardtaken = false, work = false;
	ProcCenter c1("1000", "1077", "Fry", 100), c2("0002", "1234", "BADASS", 600), c3("1538", "0672", "Jotaro Kujo", 120000);
	banki[0] = c1;
	banki[1] = c2;
	banki[2] = c3;


	do {

		do {
			system("cls");
			cout << "\tWelcome to Bizzare-bank!" << endl;
			s = banki.TakeCard();
			id = banki.FindClient(s, 3);
			if (id == -1)
			{
				banki.ReturnCard(s);
				system("pause");
				system("cls");
			}
		} while (id == -1);


		banki.ShowStatus(s, 3);
		do {
			do {
				cout << "Your actions:" << endl << "1 - Deposit cash\n2 - Cash withdraw\nPress anykey for back" << endl;
				cin >> choiose;
			} while (choiose > 1 && choiose < 2);

			switch (choiose)
			{
			case 1:banki.PlusMoney(id); break;
			case 2:banki.MinusMoney(id); break;
			default:break;
			}

			do {
				cout << "Your actions:" << endl << "1 - Continue\n2 - Exit" << endl;
				cin >> choiose;
			} while (choiose > 1 && choiose < 2);

			switch (choiose)
			{
			case 1:cardtaken = false; break;
			case 2:cardtaken = banki.ReturnCard(s); work = true; break;
			default:break;
			}

		} while (cardtaken == false);
	} while (work == true);
}