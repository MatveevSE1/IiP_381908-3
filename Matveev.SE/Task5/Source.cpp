#include<iostream>
#include<math.h>
#include<time.h>
#include<locale.h>
using namespace std;
class Vector {
public:
	float beginx, beginy;
	float endx, endy;
	Vector(float beginx1, float beginy1, float endx1, float endy1) {
		setlocale(LC_ALL, "rus");
		beginx = beginx1;
		beginy = beginy1;
		endx = endx1;
		endy = endy1;
	}
	~Vector() {
		beginx = 0.0;
		beginy = 0.0;
		endx = 0.0;
		endy = 0.0;
	}
	float x() {
		return endx - beginx;
	}
	float y() {
		return endy - beginy;
	}
	float length() {
		return sqrt(pow(x(), 2) + pow(y(), 2));
	}
	float dist(Vector v) {
		cout << "Расстояние между векторами:" << endl;
		return sqrt(pow(beginx - v.beginx, 2) + pow(beginy - v.beginy, 2));
	}
	void operator=(Vector v) {
		beginx = v.beginx;
		beginy = v.beginy;
		endx = v.endx;
		endy = v.endy;
	}
	float sk_proizv(Vector v) {
		cout << "Скалярное произведение векторов:" << endl;
		return x()*v.x() + y()*v.y();
	}
	float cosinus(Vector v) {
		cout << "Косинус угла между векторами:" << endl;
		return sk_proizv(v) / (v.length()*length());
	}
	Vector summ(Vector v) {
		cout << "Сумма векторов:" << endl;
		Vector vector(v.beginx, v.beginy, endx, endy);
		return vector;
	}
};
class Matrix {
public:
	int sizex, sizey;
	float array[3][3];
	Matrix(int sizex1, int sizey1) {
		srand(time(NULL));
		sizex = sizex1;
		sizey = sizey1;
		for (int j = 0; j < sizey; j++) for (int i = 0; i < sizex; i++) array[i][j] = rand() % 1000;
	}
	Matrix operator=(Matrix m) {
		Matrix matr(m.sizex, m.sizey);
		for (int j = 0; j < m.sizey; j++) for (int i = 0; i < m.sizey; i++) matr.array[i][j] = m.array[i][j];
		return matr;
	}
	Matrix transpmatr() {
		Matrix matr(sizex, sizey);
		for (int i = 0; i < sizey; i++) for (int j = 0; j < sizex; j++) matr.array[i][j] = array[i][j];
		return matr;
	}
	Matrix operator*(float k) {
		Matrix matr(sizex, sizey);
		for (int i = 0; i < sizey; i++) for (int j = 0; j < sizey; j++) matr.array[j][i] = array[j][i] * k;
		return matr;
	}
	Matrix operator/(float k) {
		Matrix matr(sizex, sizey);
		for (int i = 0; i < sizey; i++) for (int j = 0; j < sizey; j++) matr.array[j][i] = array[j][i] / k;
		return matr;
	}
	Matrix operator+(Matrix m) {
		Matrix matr(sizex, sizey);
		for (int i = 0; i < sizey; i++) for (int j = 0; j < sizey; j++) matr.array[j][i] = m.array[j][i] + array[i][j];
		return matr;
	}
	Matrix operator-(Matrix m) {
		Matrix matr(sizex, sizey);
		for (int i = 0; i < sizey; i++) for (int j = 0; j < sizey; j++) matr.array[j][i] = array[i][j] - m.array[i][j];
		return matr;
	}
	void output() {
		cout << "Матрица:" << endl;
		for (int i = 0; i < sizey; i++) {
			for (int j = 0; j < sizex; j++) cout << array[i][j] << "  ";
			cout << endl;
		}
	}
	float det() {
		cout << "Определитель матрицы:" << endl;
		if (sizex == sizey) return 0.0;
		else return array[1][1] * array[2][2] * array[3][3] + array[3][1] * array[2][2] * array[1][3] + array[2][1] * array[3][2] * array[1][3] - array[3][1] * array[2][2] * array[1][3] - array[2][1] * array[1][2] * array[3][3] - array[1][1] * array[2][3] * array[3][2];
	}
};
int main() {
	Vector v1(0, 0, 5, 10);
	Vector v2(-5, -1, 6, 15);
	cout << "Вектор №1" << endl;
	cout << "Координата х:" << endl;
	cout << v1.x() << endl;
	cout << "Координата у:" << endl;
	cout << v1.y() << endl;
	cout << "Длина вектора:" << endl;
	cout << v1.length() << endl;
	cout << "Вектор №2" << endl;
	cout << "Координата х:" << endl;
	cout << v2.x() << endl;
	cout << "Координата у:" << endl;
	cout << v2.y() << endl;
	cout << "Длина вектора:" << endl;
	cout << v2.length() << endl;
	cout << endl;
	cout << v1.dist(v2) << endl;
	cout << v1.cosinus(v2) << endl;
	cout << v1.sk_proizv(v2) << endl;
	cout << "Вектор суммы:" << endl;
	cout << "Координата х:" << endl;
	cout << v1.summ(v2).x() << endl;
	cout << "Координата у:" << endl;
	cout << v1.summ(v2).y() << endl;
	cout << "Длина вектора:" << endl;
	cout << v1.summ(v2).length() << endl;
	Matrix matr1(3, 3);
	Matrix matr2(3, 3);
	cout << "Матрица №1" << endl;
	matr1.output();
	cout << matr1.det() << endl;
	cout << "Матрица №2" << endl;
	matr2.output();
	cout << matr2.det() << endl;
	cout << "Сумма матриц:" << endl;
	Matrix matr3 = matr1 + matr2;
	matr3.output();
	cout << "Разность матриц 1 и 2:" << endl;
	matr3 = matr1 - matr2;
	matr3.output();
	cout << "Произведение матрицы 1 и числа 5:" << endl;
	matr3 = matr1 * 5.0;
	matr3.output();
	cout << "Частное матрицы 1 и числа 5:" << endl;
	matr3 = matr1 / 5;
	matr3.output();
	getchar();
	getchar();
}