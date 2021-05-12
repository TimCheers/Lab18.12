#include <iostream>
#include "container.h"
#include "Money.h"
using namespace std;
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
int main()
{
	system("chcp 1251>nul");
	srand(time(NULL));
	cout << "Введите количество элементов: ";
	int size = SafeInput(1);
	container<Money> Vector(size);
	cout << "-----------------------------------------------------------------\n";
	Vector.show();
	cout << "\n-----------------------------------------------------------------\n";
	Vector.PushMax();
	Vector.show();
	cout << "\n-----------------------------------------------------------------\n";
	cout << "Введите ключ для удаления: ";
	Money key;
	cin >> key;
	Vector.delKey(key);
	Vector.show();
	cout << "\n-----------------------------------------------------------------\n";
	Vector.AVG();
	Vector.show();
	cout << "\n-----------------------------------------------------------------\n";
	return 0;
}

