#include <iostream>
#include <windows.h>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int p, l, x; //l-длинна p-на гвозди х-для чтения из файла 
	int  n = 0, m[20];//n-посчитали количество элементов m-сам массив чисел
	cout << "l ";cin >> l;
	cout << "p ";cin >> p;
	ifstream f1;
	ofstream f2("4out.txt");
	f1.open("4.txt");
	if (!f1.good())
	{
		cout << "Файл f1 не найден!" << endl;
	}
	while (f1 >> x) { //загнали числа в массив заодно посчитали их
		m[n] = x;
		n++;
	}
	bool* k = new bool[n];
	for (int i = 0; i <= n; i++)
	{
		k[i] = 0;
	}	
	for (int i = 0; i < pow(2,n); i++)
	{
		int l1 = l;
		int q = n-1;
		while (k[q] == 1) {
			k[q--] = 0;
		}
		k[q] = 1;
		for (int j = 0; j < n; j++) {
			if (k[j] == 1) {
				l1 =l1- m[j] - 2 * p;
			}
		}
		if (l1 == 0) {
			for (int t = 0; t <= n; t++)
			{
				f2 << t + 1;
				if (t != n) {
					if (k[t] == 1)f2 << "-";
					else f2 << ' ';
				}
			}
			f2 << endl;
		}
	}

	system("pause");
}
