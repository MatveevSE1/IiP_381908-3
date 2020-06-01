#include "logic.h"
#include "picture.h"

void logic::Logic(int& score,  int& levelScore, int& x, int& y, int& frutX, int& frutY, int& nTail, int* tailx, int* taily) {
	picture p;
	int prevX = tailx[0];
	int prevY = taily[0];
	int prev2x, prev2y;
	tailx[0] = x;
	taily[0] = y;
	for (int i = 1; i < nTail; i++) {
		prev2x = tailx[i];
		prev2y = taily[i];
		tailx[i] = prevX;
		taily[i] = prevY;
		prevX = prev2x;
		prevY = prev2y;
	}
	switch (dir) {
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	if (x > p.getwidth() + 1 || x < 0 || y > p.getheight() + 1 || y < 0) {
		gameOver = true;
		system("cls");
		cout << "Game Over!" << endl;
		cout << "Score: " << score;
	}
	for (int i = 0; i < nTail; i++) {
		if (tailx[i] == x && taily[i] == y) {
			gameOver = true;
			system("cls");
			cout << "Game Over!" << endl;
			cout << "Score: " << score;
		}
	}
	if (x == frutX && y == frutY) {
		score+= 50;
		do {
			frutX = rand() % p.getwidth();
			frutY = rand() % p.getheight();
		} while (frutX != x && frutY != y && frutX != 'o' && frutX != 'o');
		nTail++;
	}
	if (score == levelScore) {
		gameOver = true;
		system("cls");
		cout << "You Win!" << endl;
	}
}

logic::logic(){
	gameOver = false;
}

logic::~logic(){
	dir = STOP;
	gameOver = true;
}

bool logic::getgameOver()
{
	return gameOver;
}

void logic::Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 75:
			dir = LEFT;
			break;
		case 77:
			dir = RIGHT;
			break;
		case 72:
			dir = UP;
			break;
		case 80:
			dir = DOWN;
			break;
		}
	}
}