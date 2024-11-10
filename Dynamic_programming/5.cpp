#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
using namespace std;

void poisk(int** m,int **m1,int n1, int n2, int j) {//ищем оптимально-минимальный путь 
	if (j < 0)return; //если крайний левый столбец обработан, выходим из функции
	if (j == n2-1) { //крайний правый столбец просто копируем
		for (int k = 0; k < n1; k++)
		{
			m1[k][j] = m[k][j];
		}
		j--;
		poisk(m, m1, n1, n2, j);
	}
	else { 
		for (int i = 0; i < n1; i++)
		{
			if (i == 0) { //нулевой элемент обрабатываем в соответствии с условием, сравниваем нулевой, первый и последний элементы
				int up = m1[n1-1][j + 1] + m[i][j];
				int right = m1[i][j + 1] + m[i][j];
				int down = m1[i+1][j + 1] + m[i][j];
				m1[i][j] = min(up, right);
				m1[i][j] = min(m1[i][j], down);
			}
			if (i != 0 && i != n1-1) { //обрабатываем элемент справа-сверху, справа, справа-снизу
				int up = m1[i-1][j + 1] + m[i][j];
				int right = m1[i][j + 1] + m[i][j];
				int down = m1[i + 1][j + 1] + m[i][j];
				m1[i][j] = min(up, right);
				m1[i][j] = min(m1[i][j], down);
			}
			if(i==n1-1) { //обрабатываем нулевой, последний и предпоследний элементы
				int up = m1[i - 1][j + 1] + m[i][j];
				int right = m1[i][j + 1] + m[i][j];
				int down = m1[0][j + 1] + m[i][j];
				m1[i][j] = min(up, right);
				m1[i][j] = min(m1[i][j], down);
			}

		}
		j--;
		poisk(m, m1, n1, n2, j);
	}
}
void prnt(int** m, int** m1,bool**m2, int n1, int n2, int j,int i, int minim) { //обозначаем подсчитаный оптимальный путь
	m2[i][j] = 1; //элементу m2 соотв. минимальному элементу m придаем значение 1
	if (j == n2-1) return; //если пришли в крайний столбец выходим из фнкц
	//ищем минмальное значение соседнее с настоящим элементом
	if (i == 0) { ///нулевой элемент обрабатываем в соответствии с условием, сравниваем нулевой, первый и последний элементы
		if (m1[n1 - 1][j + 1] < m1[i][j + 1] && m1[n1 - 1][j + 1] < m1[i + 1][j + 1]){
			prnt(m, m1, m2, n1, n2, ++j, n1 - 1, minim);
			return; //если минимальный последний элемент массива m2 вызываем функцию с коорд. этого элемента
		}
		else { 
			if (m1[i][j + 1] < m1[i + 1][j + 1]){ 
				prnt(m, m1, m2, n1, n2, ++j, i, minim);
				return; //если минимален правый (или равен последнему) элемент передаем его
			}
			else {
				prnt(m, m1, m2, n1, n2, ++j, ++i, minim);
				return; //если минимален нижний элемент (или равен правому) передаем его
			}
		}
	}
	//аналогично обрабатываем средние и крайние нижние элементы
	if (i != 0 && i != n1 - 1) {
		if (m1[i-1][j + 1] < m1[i][j + 1] && m1[i - 1][j + 1] < m1[i + 1][j + 1]) {
			prnt(m, m1, m2, n1, n2, ++j, --i, minim);
			return;
		}
		else {
			if (m1[i][j + 1] < m1[i + 1][j + 1]){ 
				prnt(m, m1, m2, n1, n2, ++j, i, minim);
				return;
			}
			else {
				prnt(m, m1, m2, n1, n2, ++j, ++i, minim);
				return;
			}
		}
	}
	if (i == n1 - 1) {
		if (m1[i - 1][j + 1] < m1[i][j + 1] && m1[i - 1][j + 1] < m1[0][j + 1]) {
			prnt(m, m1, m2, n1, n2, ++j, --i, minim);
			return;
		}
		else {
			if (m1[i][j + 1] < m1[0][j + 1]){ 
				prnt(m, m1, m2, n1, n2, ++j, i, minim);
				return;
			}
			else {
				prnt(m, m1, m2, n1, n2, ++j, 0, minim);
				return;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int x, n1, n2, minim=0;
	ifstream f1 ("input.txt");
	if (!f1.good())
	{
		cout << "Файл f1 не найден!" << endl;
	}
	f1 >> n1;
	f1 >> n2;
	int** m = new int*[n1]; //массив для чтения
	int** m1 = new int* [n1]; //массив для поиска и подсчета пути
	bool** m2 = new bool* [n1]; //массив для обозначения пути
	for (int i = 0; i < n1; i++)//создаем массивы
	{
		m[i] = new int[n2];
		m1[i] = new int[n2];
		m2[i] = new bool[n2];
	}
	for (int i = 0; i < n1; i++)//читаем из файла в м
	{
		for (int j = 0; j < n2; j++)
		{
			f1 >> m[i][j]; //читаем из файла
			m2[i][j] = 0; //"обнуляем" массив
		}
	}
	poisk(m, m1, n1, n2, n2 - 1);//ищем кратчайший путь
	minim = 32766;
	for (int i = 0; i < n1; i++)
	{ //находим минимальный элемент
		minim = min(minim, m1[i][0]);
	}
	cout <<"min way - "<< minim << endl;
	for (int i = 0; i < n1; i++)
	{
		if (minim == m1[i][0]) {//если нашли куда привел минимальный путь вызываем функцию
			prnt(m, m1, m2, n1, n2, 0, i, minim);
			break;
		}
	}
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			if(m2[i][j]){//если элемент - часть пути, выводим красным
				cout << "\033[1;31m";
				cout << m[i][j] << ' ';
				cout << "\033[0m";
			}
			else cout << m[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
	system("pause");
}
