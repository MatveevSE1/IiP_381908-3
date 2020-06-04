#include<iostream>
#include"Drob.h"
using namespace std;
class Complex {
public:
Drob mnim;
Drob deistvit;
Complex(int,int,int,int);
~Complex();
void print();
void operator=(Complex);
Complex operator+(Complex);
Complex operator-(Complex);
Complex operator*(Complex);
Complex operator/(Complex);
void operator+=(Complex);
void operator-=(Complex);
void operator*=(Complex);
void operator/=(Complex);
bool operator!=(Complex);
bool operator==(Complex);
};