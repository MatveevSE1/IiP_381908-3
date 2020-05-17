#include "Bankomat.h"

Bancomat::Bancomat()
{
	ProcCenter c;
	amount_of_clients = 4;
	client = new ProcCenter[amount_of_clients];

	this->c100 = 1600;
	this->c1000 = 1600;
	this->c200 = 1600;
	this->c2000 = 1600;
	this->c500 = 1600;
	this->c5000 = 1600;
	for (int i = 0; i < (int)amount_of_clients; i++)
	{
		client[i] = c;
	}
}

Bancomat::~Bancomat()
{
	ProcCenter c;
	amount_of_clients = 4;
	this->c100 = 1600;
	this->c1000 = 1600;
	this->c200 = 1600;
	this->c2000 = 1600;
	this->c500 = 1600;
	this->c5000 = 1600;
	for (int i = 0; i < (int)amount_of_clients; i++)
	{
		client[i] = c;
	}
}

string Bancomat::TakeCard()
{
	int i = 0,check, size;
	bool agreed = false;
	string s;
	char *f;
	cout << "Enter card ID (Insert card)" << endl;
	do {
		cin >> s;
		i++;
		size = s.length();
		f = new char[size];
		for (int i = 0; i < size; i++)
		{
			f[i] = s[i];
		}
		check = atoi(f);
		if (check != 0 && check > 0 && check <=9999)
		{
			return s;
		}
		else
		{
			if(s == "0000")
				return s;
			cout << "Input error" << endl
				<< "Attempts left: " << 3 - i << endl;
		}

	} while (i < 3);
	return s = "null";
}

int Bancomat::FindClient(string s, int spisok)
{
	string ss;
	int i;
	bool ret = false;

		for (i = 0; i < spisok; i++)
		{
			ss = client[i].GetCard();
			if (strcmp(ss.c_str(), s.c_str()) == 0)
			{
				if(client[i].GetBan()==true)
				{
					cout << "Your card is banned. try later" << endl;
					system("pause");
					system("cls");
					return -1;
				}
				ret = ChekPIN(i);

				if (ret == true)
					return i;
				else
					return -1;
			}
		}
	
	cout << "Card not found" << endl;
	return -1;
}

bool Bancomat::ChekPIN(int ID)
{
	int i = 0, check, size;
	bool agreed = false;
	string s;
	char* f;
	cout << "Enter PIN:" << endl;
	do {
		cin >> s;
		i++;
		size = s.length();
		f = new char[size];
		for (int i = 0; i < size; i++)
		{
			f[i] = s[i];
		}
		check = atoi(f);
		if (check != 0 && s==client[ID].GetPass())
		{	
			return true;
		}
		else
		{
			if (s == "0000" && s == client[ID].GetPass())
				return true;
			cout << "Incorrect PIN" << endl
				<< "Attempts left: " << 3 - i << endl;
		}

	} while (i < 3);
	cout << "Card is banned" << endl;
	client[ID].SetBan(true);
	system("pause");
	system("cls");
	return false;
}

bool Bancomat::ShowStatus(string s,int spisok)
{
	string ss;
	int i;
	bool ret = false;

	for (i = 0; i < spisok; i++)
	{
		ss = client[i].GetCard();
		if (strcmp(ss.c_str(), s.c_str()) == 0)
		{
			cout << "Wellcome, "<< client[i].GetPerson() << endl<<endl;
			cout << "Your balance: " << client[i].GetMoney() <<endl <<endl;
			return true;
			
		}
	}

	cout << "Card not found" << endl;
	return false;
}

ProcCenter& Bancomat::operator[](const int tmp)
{
	return this->client[tmp];
}

void Bancomat::PlusMoney(int id)
{
	unsigned int pc100, pc200, pc500, pc1000, pc2000, pc5000, res;
	bool vip;
	cout << "Attention! The ATM accepts only banknotes in denominations of: \n 100, 200, 500, 1000, 2000 and 5000 rubles" << endl;
	
	do {
		cout << "Deposit cash" << endl;
		cout << "Number of notes at 100 rub - ";
		cin >> pc100;
		cout << "Number of notes at 200ð rub - ";
		cin >> pc200;
		cout << "Number of notes at 500ð rub - ";
		cin >> pc500;
		cout << "Number of notes at 1000ð rub - ";
		cin >> pc1000;
		cout << "Number of notes at 2000ð rub - ";
		cin >> pc2000;
		cout << "Number of notes at 5000ð rub - ";
		cin >> pc5000;
		if (pc100 + pc200 + pc500 + pc1000 + pc2000 + pc5000 >= 40)
			cout << endl << "Attention, an ATM issues up to 40 bills at a time.\nPlease select a lower amount" << endl;
	} while (pc100 + pc200 + pc500 + pc1000 + pc2000 + pc5000 >= 40);
	
	vip = Set100(c100 += pc100);
	vip = Set200(c200 += pc200);
	vip = Set500(c500 += pc500);
	vip = Set1000(c1000 += pc1000);
	vip = Set2000(c2000 += pc2000);
	vip = Set5000(c5000 += pc5000);
	if (vip == false)
	{
		res = pc100 * 100 + pc200 * 200 + pc500 * 500 + pc1000 * 1000 + pc2000 * 2000 + pc5000 * 5000;
		cout << endl << "Operation completed successfully" << endl << endl;
		client[id].SetMoney(client[id].GetMoney()+res);
		cout << "Entered on your card "<< res<<" rub" << endl << endl;
		cout << "Your balance: " << client[id].GetMoney() << endl << endl;

	}
	else
		cout << "Operation failed" << endl << endl;
}

void Bancomat::MinusMoney(int id)
{
	unsigned int pc100, pc200, pc500, pc1000, pc2000, pc5000, res;
	bool vip;
	cout << "The amount you wish to cash" << endl;
	
	do {
		cout << "Number of notes at 100 rub - ";
		cin >> pc100;
		cout << "Number of notes at 200ð rub - ";
		cin >> pc200;
		cout << "Number of notes at 500ð rub - ";
		cin >> pc500;
		cout << "Number of notes at 1000ð rub - ";
		cin >> pc1000;
		cout << "Number of notes at 2000ð rub - ";
		cin >> pc2000;
		cout << "Number of notes at 5000ð rub - ";
		cin >> pc5000;
		if (pc100 + pc200 + pc500 + pc1000 + pc2000 + pc5000 >= 40)
			cout << endl << "Attention, an ATM issues up to 40 bills at a time.\nPlease select a lower amount" << endl;
	} while (pc100  + pc200  + pc500  + pc1000  + pc2000  + pc5000 >=40);
	
	vip = Set100(c100 -= pc100);
	vip = Set200(c200 -= pc200);
	vip = Set500(c500 -= pc500);
	vip = Set1000(c1000 -= pc1000);
	vip = Set2000(c2000 -= pc2000);
	vip = Set5000(c5000 -= pc5000);

	res = pc100 * 100 + pc200 * 200 + pc500 * 500 + pc1000 * 1000 + pc2000 * 2000 + pc5000 * 5000;
	if (client[id].GetMoney() < res)
	{
		cout << endl << "Not enough funds on the card" << endl << endl;
		vip = true;
	}
	if (vip == false)
	{
		
		cout << "Operation completed successfully" << endl << endl;
		client[id].SetMoney(client[id].GetMoney()-res);
		cout << "The client was given " << res << "rub" << endl << endl;
		cout << "Your balance: " << client[id].GetMoney() << endl << endl;

	}
	else
		cout << "Operation failed" << endl << endl;
}

bool Bancomat::ReturnCard(string s)
{
	cout << "Card  ¹"<< s <<" returned to customer"<< endl << endl;
	return true;
}



bool Bancomat::Set100(unsigned int m)
{
	if (m <= 2000&&m>=0)
	{
		this->c100 = m;
		return 0;
	}
	else
	{
		cout << "ATM is full of bills of 100 rub or empty" << endl;
		return 1;
	}

}

bool Bancomat::Set200(unsigned int m)
{
	if (m <= 2000 && m >= 0)
	{
		this->c200 = m;

		return 0;
	}
	else
	{
		cout << "ATM is full of bills of 200 rub or empty" << endl;
		return 1;
	}

}

bool Bancomat::Set500(unsigned int m)
{

	if (m <= 2000 && m >= 0)
	{
		this->c500 = m;
		return 0;
	}
	else
	{
		cout << "ATM is full of bills of 500 rub or empty" << endl;
		return 1;
	}

}

bool Bancomat::Set1000(unsigned int m)
{
	if (m <= 2000 && m >= 0)
	{
		this->c1000 = m;

		return 0;
	}
	else
	{
		cout << "ATM is full of bills of 1000 rub or empty" << endl;
		return 1;
	}

}

bool Bancomat::Set2000(unsigned int m)
{
	if (m <= 2000 && m >= 0)
	{
		this->c2000 = m;

		return 0;
	}
	else
	{
		cout << "ATM is full of bills of 2000 rub or empty" << endl;
		return 1;
	}

}

bool Bancomat::Set5000(unsigned int m)
{
	if (m <= 2000 && m >= 0)
	{
		this->c5000 = m;


		return 0;
	}
	else
	{
		cout << "ATM is full of bills of 5000 rub or empty" << endl;
		return 1;
	}
}

unsigned int Bancomat::Get100()
{
	return this->c100;
}

unsigned int Bancomat::Get200()
{
	return this->c200;
}

unsigned int Bancomat::Get500()
{
	return this->c500;
}

unsigned int Bancomat::Get1000()
{
	return this->c1000;
}

unsigned int Bancomat::Get2000()
{
	return this->c2000;
}

unsigned int Bancomat::Get5000()
{
	return this->c5000;
}

