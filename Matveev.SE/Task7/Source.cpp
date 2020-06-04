#include<iostream>
#include<time.h>
#include<locale.h>
#include<math.h>
using namespace std;
class Computer {
public:
	int chislo;
	int bik;
	int corova;
	int count;
	int array[10];
	Computer() {
		setlocale(LC_ALL, "rus");
		srand(time(NULL));
	}
	bool check(int number) {
		int array1[10];
		int b = number;
		for (int i = count - 1; i >= 0; i--) {
			array1[i] = b % 10;
			b /= 10;
		}
		bik = 0;
		corova = 0;
		for (int i = 0; i < count; i++) {
			if (array[i] == array1[i]) bik++;
		}
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < i; j++) {
				if (array1[i] == array[j]) {
					corova++;
					break;;
				}
			}
		}
		if (bik == count) return true;
		output();
	}
	void generate() {
		for (int i = 0; i < count; i++) {
			while (1) {
				array[i] = rand() % 10;
				bool cont = true;
				for (int j = 0; j < i; j++) if (array[j] == array[i]) cont = false;
				if (i == 0 && array[0] == 0) cont = true;
				if (cont) break;
			}
		}
	}
	void output() {
		cout << "Коровы:" << corova << endl;
		cout << "Быки:" << bik << endl;
	}
	void setcount(int count1) {
		count = count1;
		generate();
	}
}computer;
class Player {
public:
	bool ugadal;
	Player() {
		setlocale(LC_ALL, "rus");
		inputcount();
		ugadal = false;
	}
	int chislo;
	void input() {
		while (1) {
			cout << "Введите число:" << endl;
			cin >> chislo;
			int array2[10];
			int b = chislo;
			for (int i = computer.count - 1; i >= 0; i--) {
				array2[i] = b % 10;
				b /= 10;
			}
			bool cont = true;
			for (int i = 0; i < computer.count; i++) {
				for (int j = 0; j < i; j++) {
					if (array2[j] == array2[i]) cont = false;
				}
			}
			if (chislo >= pow(10, computer.count - 1) && chislo < pow(10, computer.count) && cont) break;
			else cout << "Неверный ввод" << endl;
		}
		ugadal = computer.check(chislo);
	}
	void inputcount() {
		int N;
		while (1) {
			cout << "Введите количество цифр:" << endl;
			cin >> N;
			if (N > 0 && N < 10) break;
		}
		computer.setcount(N);
	}
}player;
int main() {
	while (!player.ugadal) player.input();
	getchar();
	getchar();
	return 0;
}