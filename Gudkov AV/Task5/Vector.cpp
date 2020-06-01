#include "Vector.h"
#include<math.h>
int det = 0, step = -1;


void Minor(double** mas, double** p, int i, int j, int m)
{

	int ki, kj, iSmesh, jSmesh;
	iSmesh = 0;
	for (ki = 0; ki < m - 1; ki++) { 
		if (ki == i) 
			iSmesh = 1;
		jSmesh = 0;
		for (kj = 0; kj < m - 1; kj++) { 
			if (kj == j) 
				jSmesh = 1;
			p[ki][kj] = mas[ki+ iSmesh][kj + jSmesh];
		}
	}
}

void PrintMatr(double** mas, int m) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
}
double Determinant(double** mas, int m,double *dres,int ii,bool three) {
	int  j, k, n;
	double d;
	double** p;
	p = new double* [m];
	for (int i = 0; i < m; i++)
		p[i] = new double[m];
	j = 0; d = 0;
	k = 1; 
	n = m - 1;
	if (m < 1)
		cout << "ne robit";
	if (m == 1)
	{
		d = mas[0][0];
		return(d);
	}

	if (m == 2) {
		d = mas[0][0] * mas[1][1] -(mas[1][0] * mas[0][1]);
		
		if(three == true)
		dres[ii] = d;
		return(d);
	}
	if (m > 2) {
		for (int i = 0; i < m; i++) {
			Minor(mas, p, 0, i, m);
			d = d + (k * mas[0][i] * Determinant(p, n,dres,i, three));
			if (three == false)
			dres[ii] = d;
			k = -k;
		}
	}
	return(d);
}

Vector Vector::VecProduct(Vector* V)
{
	bool _3;
	if (Size == 3)
		_3 = true;
	else
		_3 = false;
	double** p;
	p = new double* [Size];
	for (int i = 0; i < Size; i++)
		p[i] = new double[Size];
	double* mRes = new double[Size];
	Vector res(Size);
	double d;
	double** m = new double* [Size];

	for (int i = 0; i < Size; i++)
		m[i] = new double[Size];

	for (int i = 0; i < Size; i++)
	{
		m[0][i] = 1;
	}
	for (int i = 1; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			m[i][j] = V[i].Data[j];
		}
	}

	Minor(m, p, 0, 0, Size);
	 Determinant(p, Size-1, mRes, 0,_3);

	 d = mRes[0];
	Determinant(m, Size, mRes, 0,_3);
	for (int i = 1; i < Size; i++)
	{
		res.Data[0] = d;
		res.Data[i] = mRes[i];
	}
	
	return res;
}

void Vector::Random()
{
	for (int i = 0; i < this->Size; i++)
	{
		this->Data[i] = rand()%9;
	}
}

int Vector::GetSize()
{
	return this->Size;
}


Vector::Vector()
{
	Data = new double[3];
	Size = 3;
	for (int i = 0; i < Size; i++)
	{
		Data[i] = 0;
	}
	//cout << "simple constr " << this << endl;

}
//
//Vector::Vector(int _size, double* _data)
//{
//	if (_data == NULL)
//		throw std::exception();
//	this->Size = _size;
//	for (int i = 0; i < _size; i++)
//	{
//		*(_data +i)= 0;
//	}
//	cout << "full constr " << this << endl;
//
//}

Vector::Vector(int _size)
{
	this->Size = _size;
	this->Data = new double[_size];
	for (int i = 0; i < _size; i++)
	{
		this->Data[i] = 0;
	}
	//cout <<"constr size "<< this << endl;
}

Vector::Vector(const Vector& v)
{
	if (v.Data == NULL)
		throw std::exception("invalid data");
	Size = v.Size;
	Data = new double[Size];
	for (int i = 0; i < Size; i++)
	{
		Data[i] = v.Data[i];
	}

}

Vector::~Vector()
{
	delete[] this->Data;
	this->Data = nullptr;
	this->Size = 0;
	//cout <<"destr "<< this<<endl;
} 

Vector& Vector::operator=(const Vector& v)
{
	Size = v.Size;
	this->Data = new double[Size];
	for (int i = 0; i < Size; i++)
	{
		this->Data[i] = v.Data[i];
	}
	return *this;
}

Vector Vector::operator+(const Vector& tmp) const
{
	int s = this->Size;
	if (this->Size > tmp.Size)
	{
		s = this->Size;
		Vector ttp(s);
		for (int i = 0; i < tmp.Size; i++)
		{
			ttp.Data[i] = tmp.Data[i];
		}
		Vector sum(s);
		for (int i = 0; i < sum.Size; i++)
			sum.Data[i] = this->Data[i] + ttp.Data[i];
		return sum;

	}
	else if (this->Size < tmp.Size)
	{
		s = tmp.Size;
		Vector ttp(s);
		for (int i = 0; i < this->Size; i++)
		{
			ttp.Data[i] = this->Data[i];
		}
		Vector sum(s);


		for (int i = 0; i < sum.Size; i++)
			sum.Data[i] = tmp.Data[i] + ttp.Data[i];
		return sum;

	}
	else
	{
		Vector sum(s);
		for (int i = 0; i < sum.Size; i++)
			sum.Data[i] = tmp.Data[i] + this->Data[i];
		return sum;
	}
	
}

Vector Vector::operator-(const Vector& tmp) const
{
	int s = this->Size;
	if (this->Size > tmp.Size)
	{
		s = this->Size;
		Vector ttp(s);
		for (int i = 0; i < tmp.Size; i++)
		{
			ttp.Data[i] = tmp.Data[i];
		}
		Vector sum(s);
		for (int i = 0; i < sum.Size; i++)
			sum.Data[i] = this->Data[i] - ttp.Data[i];
		return sum;

	}
	else if (this->Size < tmp.Size)
	{
		s = tmp.Size;
		Vector ttp(s);
		for (int i = 0; i < this->Size; i++)
		{
			ttp.Data[i] = this->Data[i];
		}
		Vector sum(s);


		for (int i = 0; i < sum.Size; i++)
			sum.Data[i] = ttp.Data[i] - tmp.Data[i];
		return sum;

	}
	else
	{
		Vector sum(s);
		for (int i = 0; i < sum.Size; i++)
			sum.Data[i] = this->Data[i] - tmp.Data[i];
		return sum;
	}

}

double Vector::operator*(const Vector& tmp) const
{
	int s = Size;
	double res = 0;
	if (this->Size > tmp.Size)
	{
		s = this->Size;
		Vector ttp(s);
		for (int i = 0; i < tmp.Size; i++)
		{
			ttp.Data[i] = tmp.Data[i];
		}
		
		for (int i = 0; i < s; i++)
			res += this->Data[i] * ttp.Data[i];
		return res;

	}
	else if (this->Size < tmp.Size)
	{
		s = tmp.Size;
		Vector ttp(s);
		for (int i = 0; i < this->Size; i++)
		{
			ttp.Data[i] = this->Data[i];
		}
		
		for (int i = 0; i < s; i++)
			res += tmp.Data[i] * ttp.Data[i];
		return res;

	}
	else
	{
		for (int i = 0; i < s; i++)
			res+= tmp.Data[i] * this->Data[i];
		return res;
	}

}

Vector Vector::operator*(const int tmp) const
{
	Vector res(Size);
	for (int i = 0; i < Size; i++)
	{
		res.Data[i] = this->Data[i] * tmp;
	}
	return	res;
}

Vector Vector::operator/(const int tmp) const
{
	Vector res(Size);
	for (int i = 0; i < Size; i++)
	{
		res.Data[i] = this->Data[i] / tmp;
	}
	return	res;
}

double& Vector::operator[](const int tmp)
{
		return this->Data[tmp];
}

double Vector::lenght()
{
	double res = 0;
	if (this->Data != nullptr && this->Size > 0)
	{
		for (int i = 0; i < Size; i++)

			res += Data[i] * Data[i];

		return sqrt(res);
	}
	else
		return -1;
}

double Vector::lenghtbetweenvectors(const Vector& tmp)
{
	double res = 0;
	if (this->Data != nullptr && this->Size > 0)
	{
		for (int i = 0; i < Size; i++)

			res += (tmp.Data[i] - Data[i]) * (tmp.Data[i] - Data[i]);

		return sqrt(res);
	}
	else
		return -1;
}

double Vector::Cos(Vector& tmp)
{
	double mult = 0, res1, res;
	//int s = this->Size;
	/*if (this->Size > tmp.Size)
	{
		s = this->Size;
		Vector ttp(s);
		for (int i = 0; i < tmp.Size; i++)
		{
			ttp.Data[i] = tmp.Data[i];
		}
		for (int i = 0; i < s; i++)
		{
			mult += this->Data[i] * ttp.Data[i];
		}

	}
	else if (this->Size < tmp.Size)
	{
		s = tmp.Size;
		Vector ttp(s);
		for (int i = 0; i < this->Size; i++)
		{
			ttp.Data[i] = this->Data[i];
		}
		for (int i = 0; i < s; i++)
		{
			mult += tmp.Data[i] * ttp.Data[i];
		}
	}
	else
	{
		for (int i = 0; i < s; i++)
		{
			mult += this->Data[i] * tmp.Data[i];
		}
	}*/
	mult = *this * tmp;
	res = this->lenght();
	res1 = tmp.lenght();
	double coss = mult / (res * res1);
	return coss;
	
}




std::istream& operator>>(std::istream& in, const Vector& tmp)
{
	for (int i = 0; i < tmp.Size; i++)
	{
		cout << "Input "<<i+1<<"-s vector coordinate"<<endl;
		in >> tmp.Data[i];
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Vector& tmp)
{
	out << "( ";
	for (int i = 0; i < tmp.Size; i++)
	{
		out << tmp.Data[i]<<" ";
	}
	out << ")"<<endl;
	return out;

}
