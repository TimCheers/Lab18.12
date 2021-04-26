#pragma once
#include <math.h>
#include <iostream>
using namespace std;
class Money
{
public:
	Money();
	Money(unsigned long int R, unsigned int K);
	Money(const Money& other);
	~Money();
	void show();
	Money& operator = (const Money& other);
	bool operator == (const Money& other);
	bool operator != (const Money& other);
	Money operator +(const Money& other);
	Money operator -(const Money& other);
	Money operator -(const double value);
	friend ostream& operator << (ostream& out, const Money& other);
	friend istream& operator >> (istream& in, Money& other);
private:
	long int R;
	int K;
};