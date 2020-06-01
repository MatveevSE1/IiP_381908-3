#include "picture.h"
#include "logic.h"

picture::picture(){
	setlocale(LC_CTYPE, "rus");
	srand(time(NULL));
	width = 20;
	height = 20;
}

picture::~picture(){
	width = 0;
	height = 0;
}

int picture::getwidth()
{
	return width;
}
int picture::getheight()
{
	return height;
}

void picture::Draw(int& fps, int& score, int x, int y, int frutX,  int frutY, int nTail, int* tailx, int* taily) {
	logic l;
	Sleep(fps);
	system("cls");
	for (int i = 0; i < width + 2; i++) {
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < height + 2; i++) {
		for (int j = 0; j <= width; j++) {
			if (j == 0 || j == width)
				cout << "#";
			if (i == y && j == x)
				cout << "0";
			else if (i == frutY && j == frutX)
				cout << "*";
			else {
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailx[k] == j && taily[k] == i) {
						print = true;
						cout << "o";
					}
				}
				if (!print)
					cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++) {
		cout << "#";
	}
	cout << endl;
	cout << "Score: " << score << endl;
}

void picture::SettingLevel(int& fps, int& levelScore) {
	int lev;
	cout << "Какаой уровень сложности хотите?\n1. Лёгкий\n2. Средний\n3. Сложный\n";
	do {
		cin >> lev;
	} while (lev < 0 || lev > 4);
	switch (lev) {
	case 1:
		fps = 200;
		levelScore = 500;
		break;
	case 2:
		fps = 100;
		levelScore = 750;
		break;
	case 3:
		fps = 50;
		levelScore = 1000;
		break;
	}
}