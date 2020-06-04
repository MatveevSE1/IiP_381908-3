#include<iostream>
#include"Drob.h"

using namespace std;

void Drob::set_a(int a1) {
a = a1;
}
void Drob::set_b(int b1) {
b = b1;
}
int Drob::get_a() {
return a;
}
int Drob::get_b() {
return b;
}
void Drob::print() {
cout << "(" << a << "/" << b << ")";
}
float Drob::get() {
return (float) a/b;
}
bool Drob::operator==(Drob d){
	if(get_a()==d.get_a()&&get_b()==d.get_b()) return true;
	else return false;
}
Drob Drob::operator+(Drob d){
	Drob d1;
	d1.set_a(a*d.get_b()+d.get_a()*get_b());
	d1.set_b(get_b()*d.get_b());
	return d1;
}
Drob Drob::operator-(Drob d){
	Drob d1;
	d1.set_a(a*d.get_b()-d.get_a()*get_b());
	d1.set_b(get_b()*d.get_b());
	return d1;
}
Drob Drob::operator*(Drob d){
	Drob d1;
	d1.set_a(a*d.get_a());
	d1.set_b(b*d.get_b());
	return d1;
}
Drob Drob::operator/(Drob d){
	Drob d1;
	d1.set_a(a*d.get_b());
	d1.set_b(b*d.get_a());
	return d1;
}
void Drob::operator=(Drob d){
	a=d.get_a();
	b=d.get_b();
}
void Drob::operator+=(Drob d){
	Drob s;
	s.a=get_a();
	s.b=get_b();
	s=s+d;
	a=s.get_a();
	b=s.get_b();
}

void Drob::operator-=(Drob d){
	Drob s;
	s.a=get_a();
	s.b=get_b();
	s=s-d;
	a=s.get_a();
	b=s.get_b();
}
void Drob::operator*=(Drob d){
	Drob s;
	s.a=get_a();
	s.b=get_b();
	s=s*d;
	a=s.get_a();
	b=s.get_b();
}
void Drob::operator/=(Drob d){
	Drob s;
	s.a=get_a();
	s.b=get_b();
	s=s+d;
	a=s.get_a();
	b=s.get_b();
}
bool Drob::operator>(Drob d){
	if(get()>d.get()) return true;
	else return false;
}
bool Drob::operator>=(Drob d){
	if(get()>=d.get()) return true;
	else return false;
}
bool Drob::operator<(Drob d){
	if(get()<d.get()) return true;
	else return false;
}
bool Drob::operator<=(Drob d){
	if(get()<=d.get()) return true;
	else return false;
}
bool Drob::operator!=(Drob d){
	if(get()!=d.get()) return true;
	else return false;
}