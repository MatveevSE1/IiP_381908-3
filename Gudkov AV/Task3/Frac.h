#include <iostream>
using namespace std;
class fraction
{
private:
	int chisl;
	int znam;
public:
	void SetChisl(int n);
	void SetZnam(int n);
	int GetChisl();
	int GetZnam();
	int Umn(fraction drob1, fraction drob2);
	fraction operator*(fraction& tmp);
	int Del(fraction drob1, fraction drob2);
	fraction operator/(fraction& tmp);
	int Sum(fraction drob1, fraction drob2);
	fraction operator-(fraction& tmp);
	int Vuch(fraction drob1, fraction drob2);
	fraction operator+(fraction& tmp);
	friend istream& operator>>(istream& in, fraction& tmp);

	void Out();
	fraction(int i, int j);
	fraction();
	~fraction();

};

