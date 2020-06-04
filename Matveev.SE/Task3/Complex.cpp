#include<iostream>
#include"Complex.h"
using namespace std;
Complex::Complex(int deistva,int deistvb, int mnima,int mnimb)
{
deistvit.set_a(deistva);//устанавливается действительная часть(числитель)
deistvit.set_b(deistvb);//устанавливается действительная часть(знаменатель)
mnim.set_a(mnima);//устанавливается мнимая часть(числитель)
mnim.set_b(mnimb);//устанавливается мнимая часть(знаменатель)
}
Complex::~Complex() {
deistvit.set_a(0);//устанавливается действительная часть равная нулю
deistvit.set_b(0);//устанавливается действительная часть равная нулю
mnim.set_a(0);//устанавливается мнимая часть равная нулю
mnim.set_b(0);//устанавливается мнимая часть равная нулю
}
void Complex::print() {
if (mnim.get() > 0.0) {
cout<<"Z=";
deistvit.print();
cout<<"+";
mnim.print();
cout<<"i" << endl;
}
else {
cout <<"Z=";
deistvit.print();
cout <<"-";
mnim.print();
cout <<"i" << endl;
}
}
void Complex::operator=(Complex c) {
deistvit = c.deistvit;
mnim = c.mnim;
} 
Complex Complex::operator+(Complex c){
	Complex c1(0,1,0,10);
	c1.mnim+=c.mnim;
	c1.deistvit+=c.deistvit;
	return c1;
}
Complex Complex::operator-(Complex c){
	Complex c1(0,1,0,1);
	c1.mnim-=c.mnim;
	c1.deistvit-=c.deistvit;
	return c1;
}
Complex Complex::operator*(Complex c){
	Complex c1(0,1,0,1);
	c1.deistvit=deistvit*c.deistvit-mnim*c.mnim;
	c1.mnim=deistvit*c.mnim+mnim*c.deistvit;
	return c1;
}
Complex Complex::operator/(Complex c){
	Complex c1(0,1,0,1);
	c1.deistvit=(deistvit*c.deistvit+mnim*c.mnim)/(c.deistvit*c.deistvit+c.mnim*c.mnim);
	c1.mnim=(mnim*c.deistvit-deistvit*c.mnim)/(c.deistvit*c.deistvit+mnim*c.mnim);
	return c1;
}
void Complex::operator+=(Complex c){
Complex c1(0,1,0,1);
c1.deistvit=deistvit;
c1.mnim=mnim;
c1=c1+c;
deistvit=c1.deistvit;
mnim=c1.mnim;
}
void Complex::operator-=(Complex c){
Complex c1(0,1,0,1);
c1.deistvit=deistvit;
c1.mnim=mnim;
c1=c1-c;
deistvit=c1.deistvit;
mnim=c1.mnim;
}
void Complex::operator*=(Complex c){
Complex c1(0,1,0,1);
c1.deistvit=deistvit;
c1.mnim=mnim;
c1=c1*c;
deistvit=c1.deistvit;
mnim=c1.mnim;
}
void Complex::operator/=(Complex c){
Complex c1(0,1,0,1);
c1.deistvit=deistvit;
c1.mnim=mnim;
c1=c1/c;
deistvit=c1.deistvit;
mnim=c1.mnim;
}
bool Complex::operator==(Complex c){
	if(c.deistvit==deistvit&&mnim==c.mnim) return true;
	else return false;
}
bool Complex::operator!=(Complex c){
	if(c.deistvit!=deistvit||c.mnim!=mnim) return true;
	else return false;
}
