#include<iostream>
#include<string>
#include<locale.h>
using namespace std;
struct Tovar {
	float sale;
	int cost;
	int count;
	string name;
	Tovar() {
		name = rand();
	}
};
class Sklad {
public:
	Tovar tovar[9999];
	Sklad() {
		for (int i = 0; i < 9999; i++) {
			tovar[i].sale = (1 + rand() % 50) / 100.0;
			tovar[i].cost = 1 + rand() % 500;
		}
	}
}sklad;
class Kassa {
public:
	int cost;
	Tovar tovar[9999];
	Kassa() {
		cost = 0;
		for (int i = 0; i < 9999; i++) {
			tovar[i].count = 0;
		}
	}
	void Scan(int shtrix) {
		cout << "�������������:" << endl;
		Info(shtrix);
		CheckAdd(shtrix);
	}
	void Info(int shtrix) {
		cout << "�����:" << sklad.tovar[shtrix].name << endl;
		cout << "�����-���:" << shtrix << endl;
		cout << "����:" << sklad.tovar[shtrix].cost << endl;
		cout << "������:" << sklad.tovar[shtrix].sale*100.0 << "%" << endl;
	}
	void CheckAdd(int shtrix) {
		tovar[shtrix].count++;
		cost += sklad.tovar[shtrix].cost;
	}
	void Check() {
		cout << "������������/����������/�����-���/����/������/���� � ������ ������" << endl;
		for (int i = 0; i < 9999; i++) {
			if (tovar[i].count > 0) cout << sklad.tovar[i].name << "/" << i << "/" << tovar[i].count << "/" << sklad.tovar[i].cost << "/" << sklad.tovar[i].sale << "/" << sklad.tovar[i].cost*sklad.tovar[i].sale << endl;
		}
		GetCost();
	}
	void GetCost() {
		cout << "����� ����:" << cost;
	}
	void Remove(int shtrix) {
		cout << "������ �����:" << cost << endl;
		Info(shtrix);
		tovar[shtrix].count = 0;
	}
}kassa;
int main() {
	setlocale(LC_ALL, "rus");
	int N = 0;
	int shtrix;
	while (1) {
		cout << "1 - ������������� �����" << endl;
		cout << "2 - �������� �������� ������ �� ������" << endl;
		cout << "3 - �������� ������ � ������ � ���" << endl;
		cout << "4 - ������������ ���" << endl;
		cout << "5 - ���������� �������� �����" << endl;
		cout << "6 - ������� �����" << endl;

		cin >> N;
		if (N != 4 && N != 5 && N <= 6) {
			cout << "������� �����-��� ������" << endl;
			cin >> shtrix;
			if (shtrix < 1000 || shtrix>9999) N = 7;
		}
		if (N > 6 || N < 0) cout << "������������ ����!" << endl;
		if (N == 1) kassa.Scan(shtrix);
		if (N == 2) kassa.Info(shtrix);
		if (N == 3) kassa.CheckAdd(shtrix);
		if (N == 4) kassa.Check();
		if (N == 5) kassa.GetCost();
		if (N == 6) kassa.Remove(shtrix);
		if (N == 5 || N == 6) break;
	}
	getchar();
	getchar();
	return 0;
}