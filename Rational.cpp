#include <iostream>
#include <cmath>
#include "Rational.h"
using namespace std;
Rational::Rational() //����������� �� ���������
{
	nominator = 0;
	denominator = 1;
}
Rational::Rational(int nominator) //����������� � ���������� nominator
{
	this->nominator = nominator;
	denominator = 1;
}
Rational::Rational(int nominator, int denominator) //����������� ��� ����� ����������
{
	this->nominator = nominator;
	this->denominator = denominator;
}
int Rational::GetNominator() const
{
	return nominator;
}
int Rational::GetDenominator() const
{
	return denominator;
}
void Rational::drob() //��������� ����������
{
	if (nominator != 0)
	{
		int m = denominator,n = nominator, ost = m % n;
		while (ost != 0)	
		{
			m = n; 
			n = ost;
			ost = m % n;
		}
		int NOD = n;
		if (NOD != 1)
		{
			nominator /= NOD; 
			denominator /= NOD;
		}
	}
}
ostream& operator<<(ostream& out, const Rational &Rational) //�������� ������
{
	out << Rational.nominator << "/" << Rational.denominator;
	return out;
}
istream& operator>>(istream& in, Rational& Rational) //�������� �����
{
	in >> Rational.nominator >> Rational.denominator;
	return in;
}
Rational operator+(Rational a, Rational b) //���������� �������� +
{
	return Rational(a.GetNominator() + b.GetNominator(), a.GetDenominator() + b.GetDenominator());
}
Rational operator-(Rational a, Rational b) //���������� �������� -
{
	return Rational(a.GetNominator() - b.GetNominator(), a.GetDenominator() - b.GetDenominator());
}
Rational operator*(Rational a, Rational b) //���������� �������� *
{
	return Rational(a.GetNominator() * b.GetNominator(), a.GetDenominator() * b.GetDenominator());
}
Rational operator/(Rational a, Rational b) //���������� �������� /
{
	return Rational(a.GetNominator() / b.GetNominator(), a.GetDenominator() / b.GetDenominator());
}
