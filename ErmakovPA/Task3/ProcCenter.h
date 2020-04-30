#include <string>
#include <iostream>

using namespace std;

class ProcCenter {
private:

	string card;
	string password;
	string person;
	int money;
	bool ban;
public:

	ProcCenter();
	~ProcCenter();
	ProcCenter(string card, string pass,string name,int m);
	ProcCenter(const ProcCenter& tmp);

	ProcCenter& operator= ( ProcCenter& tmp);
	void SetCard(string s);
	void SetPass(string s);
	void SetPerson(string s);
	void SetMoney(int m);
	void SetBan(bool b);

	string GetCard();
	string GetPass();
	string GetPerson();
	int GetMoney();
	bool GetBan();


	

};