#include "ProcCenter.h"

class Bancomat {
	
private:

	ProcCenter* client;
	unsigned int c100;
	unsigned int c200;
	unsigned int c500;
	unsigned int c1000;
	unsigned int c2000;
	unsigned int c5000;
	unsigned int amount_of_clients;
public:

	Bancomat();
	~Bancomat();

	string TakeCard();
	int FindClient(string s, int spisok);
	bool ChekPIN(int id);
	bool ShowStatus(string s, int spisok);
	ProcCenter& operator[](const int tmp);
	void PlusMoney(int id);
	void MinusMoney(int id);

	bool ReturnCard(string s);

	bool Set100(unsigned int m);
	bool Set200(unsigned int m);
	bool Set500(unsigned int m);
	bool Set1000(unsigned int m);
	bool Set2000(unsigned int m);
	bool Set5000(unsigned int m);

	unsigned int Get100();
	unsigned int Get200();
	unsigned int Get500();
	unsigned int Get1000();
	unsigned int Get2000();
	unsigned int Get5000();


};