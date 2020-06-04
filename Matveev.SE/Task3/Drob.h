#pragma once
#include<string>

using namespace std;

class Drob {
public:
int a;
int b;
void set_a(int);
void set_b(int);
int get_a();
int get_b();
float get();
void print();
bool operator==(Drob);
void operator=(Drob);
void operator+=(Drob);
void operator-=(Drob);
void operator*=(Drob);
void operator/=(Drob);
Drob operator+(Drob);
Drob operator-(Drob);
Drob operator*(Drob);
Drob operator/(Drob);
bool operator>(Drob);
bool operator<(Drob);
bool operator>=(Drob);
bool operator<=(Drob);
bool operator!=(Drob);
};