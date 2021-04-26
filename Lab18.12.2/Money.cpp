#include "Money.h"
Money::Money()
{
	R = 0;
	K = 0;
}
Money::Money(unsigned long int R, unsigned int K)
{
	this->K = K;
	this->R = R;
}
Money::Money(const Money& other)
{
	this->K = other.K;
	this->R = other.R;
}
Money::~Money()
{
}
void Money::show()
{
	cout << "Ñóììà: " << R << '.' << K << endl;
}
Money& Money:: operator = (const Money& other)
{
	this->K = other.K;
	this->R = other.R;
	return *this;
}
bool Money:: operator == (const Money& other)
{
	return this->R == other.R && this->K == other.K;
}
bool Money:: operator != (const Money& other)
{
	return !(this->R == other.R && this->K == other.K);
}
Money Money:: operator +(const Money& other)
{
	Money tmp;
	int tmpK = 0, tmpR = 0;
	tmp.K = this->K + other.K;
	if (tmp.K >= 100)
	{
		tmpR = tmp.K / 100;
		tmpK = tmp.K - tmpR * 100;
		tmp.K = tmpK;
	}
	tmp.R = this->R + other.R + tmpR;
	return tmp;
}
Money Money :: operator -(const Money& other)
{
	Money tmp;
	int tmpK = 0, tmpR = 0;
	tmp.R = this->R - other.R;
	tmp.K = this->K - other.K;
	if (this->K < other.K)
	{
		tmp.R--;
		tmp.K = 100 - abs(this->K - other.K);
	}
	return tmp;
}
Money Money :: operator -(const double value)
{
	Money tmp;
	int tmpp = (value - int(value)) * 100;
	tmp.R = this->R - (int)value;
	tmp.K = this->K - tmpp;
	if (this->K < tmpp)
	{
		tmp.R--;
		tmp.K = 100 - abs(this->K - tmpp);
	}
	return tmp;
}
ostream& operator << (ostream& out, const Money& other)
{
	return (out << other.R << '.' << other.K);
}
istream& operator >> (istream& in, Money& other)
{
	char ch;
	in >> other.R >> ch >> other.K;
	return in;
}
