#include "ProcCenter.h"

ProcCenter::ProcCenter()
{
	card = "null";
	password = "null";
	person = "noname";
	money = 0;
	ban = false;
}

ProcCenter::~ProcCenter()
{
	card = "null";
	password = "null";
	person = "noname";
	money = 0;
	ban = false;

}

ProcCenter::ProcCenter(string card, string pass, string name, int m)
{
	this->card = card;
	this->password = pass;
	this->person = name;
	this->money = m;
}

ProcCenter::ProcCenter(const ProcCenter& tmp)
{
	card = tmp.card;
	password = tmp.password;
	person = tmp.person;
	money = tmp.money;
	ban = tmp.ban;

}



ProcCenter& ProcCenter::operator=( ProcCenter& tmp)
{
	card = tmp.card;
	password = tmp.password;
	person = tmp.person;
	money = tmp.money;
	ban = tmp.ban;

	return *this;
}

void ProcCenter::SetCard(string s)
{
	this->card = s;
}

void ProcCenter::SetPass(string s)
{
	this->password = s;

}

void ProcCenter::SetPerson(string s)
{
	this->person = s;
}

void ProcCenter::SetMoney(int m)
{
	this->money = m;
}

void ProcCenter::SetBan(bool b)
{
	ban = b;
}

string ProcCenter::GetCard()
{
	return this->card;
}

string ProcCenter::GetPass()
{
	return this->password;
}

string ProcCenter::GetPerson()
{
	return this->person;
}

int ProcCenter::GetMoney()
{
	return this->money;
}

bool ProcCenter::GetBan()
{
	return ban;
}


