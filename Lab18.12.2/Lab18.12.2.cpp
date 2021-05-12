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
    for (int i = 0; i < size; i++)
    {
        Money tmp;
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
void AddMax(Tset& A)
{
    it i = A.end();
    i--;
    A.insert(*i);
}
Money FindAVG(Tset& A)
{
    int  k = A.size();
    Money sum(0, 0);
    auto iter = A.begin();
    for (iter; iter != A.end(); iter++)
    {
        sum = sum + *iter;
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
    cout << "\n-----------------------------------------------------------------\n";
    AddMax(A);
    ShowSet(A);
    cout << "\n-----------------------------------------------------------------\n";
    cout << "Введите ключ для удаления: ";
    Money key;
    cin >> key;
    A.erase(key);
    ShowSet(A);
    cout << "\n-----------------------------------------------------------------\n";
    Money avg = FindAVG(A);
    cout << "\nСреднее арефметическое: " << avg << endl;
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
}