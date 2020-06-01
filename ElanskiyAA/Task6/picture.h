#pragma once
#include <iostream>
#include <conio.h>
#include "time.h"
#include "windows.h"
#include <wincrypt.h>
using namespace std;

class picture {
private:
	int width, height;
public:
	picture();
	~picture();

	int getwidth();
	int getheight();

	void Draw(int& fps, int& score, int x, int y, int frutX, int frutY, int nTail, int* tailx, int* taily);
	void SettingLevel(int& fps, int& levelScore);
};