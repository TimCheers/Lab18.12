#include <iostream>
#include "Money.h"
#include <set>
#include <time.h>
using namespace std;
typedef multiset<Money> Tset;
typedef Tset::iterator it;
int SafeInput(bool strict) 
{
	int result;
	while (!(cin >> result) || (cin.peek() != '\n') || (strict && result <= 0)) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите корректное число!" << endl;
	}
	cin.get();
	return result;
}
int random(int a, int b)
{
	if (a > 0) return a + rand() % (b - a);
	else return a + rand() % (abs(a) + b);
}
Tset MakeSet(int size)
{
	Tset A;
	Money tmp;
	for (int i = 0; i < size; i++)
	{
		cin >> tmp;
		A.insert(tmp);
	}
	return A;
}
void ShowSet(Tset A)
{
	auto iter = A.begin();
	for (iter; iter != A.end(); iter++)
	{
		cout << *iter << "  ";

	}
}
int main()
{
	system("chcp 1251>nul");
	srand(time(NULL));
	cout << "Введите количество элементов: ";
	int size = SafeInput(1);
	Tset A = MakeSet(size);
	cout << "-----------------------------------------------------------------\n";
	ShowSet(A);
	cout << "\n-----------------------------------------------------------------\n";
}

