#include <iostream>
#include <set>
#include <time.h>
using namespace std;
typedef multiset<int> Tset;
typedef Tset::iterator it;
int SafeInput(bool strict) {
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
    int tmp;
	for (int i = 0; i < size; i++)
	{
		tmp = random(0, 100);
		A.insert(tmp);
	}
	return A;
}
void ShowSet(Tset A)
{
	auto iter = A.begin();
	for (iter; iter!=A.end(); iter++)
	{
		cout << *iter << "  ";

	}
}
void FindMax(Tset& A)
{
	auto iter = A.end();
	iter--;
	A.insert(*iter);
}
int FindAVG(Tset& A)
{
	int sum = 0, k = A.size();
	auto iter = A.begin();
	for (iter; iter != A.end(); iter++)
	{
		sum += *iter;
	}
	return (sum / k);
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
	cout << endl;
	FindMax(A);
	ShowSet(A);
	cout << "\n-----------------------------------------------------------------\n";
	cout << "Введите ключ для удаления: ";
	int key = SafeInput(1);
	A.erase(key);
	ShowSet(A);
	cout << "\n-----------------------------------------------------------------\n";
	int avg = FindAVG(A);
	auto iter = A.begin();
	Tset B;
	for (iter; iter != A.end(); iter++)
	{
		B.insert(*iter + avg);
	}
	A.clear();
	iter = B.begin();
	for (iter; iter != B.end(); iter++)
	{
		A.insert(*iter);
	}
	B.clear();
	ShowSet(A);
	cout << "\n-----------------------------------------------------------------\n";
	return 0;
}
