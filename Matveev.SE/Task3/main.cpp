#include<iostream>
#include<locale.h>
#include"Complex.h"

using namespace std;

int main() {
setlocale(LC_ALL,"rus");
Complex complex(1,10,1,10);
cout<<"������ ����������� �����:";
complex.print();
Complex complex1(4,5,3,8);
cout<<"������ ����������� �����:";
complex1.print();
cout<<"�����:";
Complex res(0,1,0,1);
res=complex+complex1;
res.print();
cout<<"��������:";
res=complex-complex1;
res.print();
cout<<"������������:";
res=complex*complex1;
res.print();
cout<<"�������:";
res=complex/complex1;
res.print();
getchar();
getchar();
}