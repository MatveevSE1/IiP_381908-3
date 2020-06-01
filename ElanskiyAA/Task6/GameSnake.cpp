#include "logic.h"
#include "picture.h"
using namespace std;

int main(){
	logic l;
	picture p;
	int x = rand() % (p.getwidth() - 3) + 3;
	int y = rand() % (p.getheight() - 3) + 3;
	int frutX = rand() % p.getwidth();
	int frutY = rand() % p.getheight();
	int tailx[100], taily[100];
	int nTail = 0;
	int fps = 0;
	int score = 0;
	int levelScore = 0;
	p.SettingLevel(fps, levelScore);
	while (!l.getgameOver()) {
		p.Draw(fps, score, x, y, frutX, frutY, nTail, tailx, taily);
		l.Input();
		l.Logic(score, levelScore, x, y, frutX, frutY, nTail, tailx, taily);
	}
}