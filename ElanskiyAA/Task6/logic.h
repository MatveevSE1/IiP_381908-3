#pragma once
#include "picture.h"

class logic{
private:
	bool gameOver;
	enum eDirection { STOP = 0, LEFT, UP, DOWN, RIGHT };
	eDirection dir = LEFT;
public:
	logic();
	~logic();

	bool getgameOver();

	void Input();
	void Logic(int& score, int& levelScore, int& x, int& y, int& frutX, int& frutY, int& nTail, int* tailx, int* taily);
};