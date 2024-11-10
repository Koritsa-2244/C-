#include <iostream>
#include <time.h>
#include <ctime>

using namespace std;

void randarr(int* m, int n) {
	for (int i = 0; i < n; i++)
	{
		m[i] = rand() % 100 - 10;
	}
	cout << endl;
}
void sortarr(int* m, int n) {
	for (int i = 0; i < n; i++)
	{
		m[i] = i+1;
	}
	cout << endl;
}
void assortarr(int* m, int n) {
	for (int i = 0; i < n; i++)
	{
		m[i] = n+1-i;
	}
	cout << endl;
}
void vivod(int* m, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << m[i] << " ";
	}
	cout << endl;
}
void selection(int* m, int n) {
	for (int i = 0; i < n-1; i++)
	{
		int min = m[i], index = i;
		for (int j = i+1; j < n; j++)
		{
			if (m[j] < min)min = m[j], index = j;
		}
		m[index] = m[i];
		m[i] = min;
	}
}
void visselection(int* m, int n) {
	bool c = 0;
	int k = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int min = m[i], index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (m[j] < min) {
				min = m[j];
				index = j;
				c = 1;
			}
		}
		if (c == 1) {
			cout << k << " iter: ";
			for (int j = 0; j < n; j++)
			{
				if (j < i) {
					cout << "\033[1;32m";
					cout << m[j] << " ";
					cout << "\033[0m";
				}
				else if (j == index || j == i) {
					cout << "\033[1;31m";
					cout << m[j] << " ";
					cout << "\033[0m";
				}
				else {
					cout << m[j] << " ";
				}
			}
			cout << endl;
		}
		m[index] = m[i];
		m[i] = min;
		if (c == 1) {
			cout << k << " iter: ";
			k++;
			for (int j = 0; j < n; j++)
			{
				if (j < i) {
					cout << "\033[1;32m";
					cout << m[j] << " ";
					cout << "\033[0m";
				}
				else if (j == index || j==i) {
					cout << "\033[1;31m";
					cout << m[j] << " ";
					cout << "\033[0m";
				}
				else {
					cout << m[j] << " ";
				}
			}
			cout << endl;
			c = 0;
		}
	}
}
void shell(int* m, int n) {
	int step = n / 2;
	while (step > 0) {
		for (int i = 0; i < n-step; i++)
		{
			int j = i;
			while (j >= 0 && m[j] > m[j + step]) {
				swap(m[j], m[j + step]);
				j -= step;
			}
		}
		step = step / 2;
	}
}
void visshell(int* m, int n) {
	int t = 0;
	int step = n / 2;
	while (step > 0) {
		for (int i = 0; i < n - step; i++)
		{
			int j = i;
			while (j >= 0 && m[j] > m[j + step]) {
				cout << "Step: " << step << " " << t << " iter: ";
				t++;
				for (int k = 0; k < n; k++)
				{
					if (step == 1 && k < j) {
						cout << "\033[1;32m";
						cout << m[k] << " ";
						cout << "\033[0m";
					}
					else if (k < j && k + j % step == 0) {
						cout << "\033[1;32m";
						cout << m[k] << " ";
						cout << "\033[0m";
					}
					else if (k > j+step && (k - j) % step == 0) {
						cout << "\033[1;34m";
						cout << m[k] << " ";
						cout << "\033[0m";
					}
					else if (k == j || k == j + step) {
						cout << "\033[1;31m";
						cout << m[k] << " ";
						cout << "\033[0m";
					}
					else {
						cout << m[k] << " ";
					}
				}
				cout << endl;
				swap(m[j], m[j + step]);
				j -= step;
			}
		}
		step = step / 2;
	}

}
void sort(int* m, int left, int right) {
	int i = left, j = right, key = m[(left + right) / 2];
	do {
		while (m[i] < key)i++;
		while (m[j] > key)j--;
		if (i <= j) {
			swap(m[i], m[j]);
			i++, j--;
		}
	} while (i <= j);
	if (i < right)sort(m, i, right);
	if (j > left)sort(m, left, j);
}
void vissort(int* m, int left, int right, int n) {
	int i = left, j = right, key = m[(left + right) / 2];
	do {
		while (m[i] < key)i++;
		while (m[j] > key)j--;
		if (i <= j) {
			for (int k = 0; k < n; k++)
			{
				if (m[k] == key) {
					cout << "\033[1;32m";
					cout << m[k] << " ";
					cout << "\033[0m";
				}
				else if (k == j || k == i) {
					cout << "\033[1;31m";
					cout << m[k] << " ";
					cout << "\033[0m";
				}				
				else {
					cout << m[k] << " ";
				}
			}
			cout << endl;
			swap(m[i], m[j]);
			i++, j--;
		}
	} while (i <= j);
	if (i < right)vissort(m, i, right, n);
	if (j > left)vissort(m, left, j, n);
}
void quickSort(int* m, int n) {
	sort(m, 0, n - 1);
}
void visquickSort(int* m, int n) {
	vissort(m, 0, n - 1,n);
}

int main()
{
	srand(time(0));
	
	bool s;
	do {
		int c;
		cout << "Output estimated time - 0, visualize slection - 1, visualize shell - 2, visualize quick - 3, print sort - 4 " << endl;
		cin >> c; 
		int n = 10;
		cout << "n: "; cin >> n;

		int* arsl = new int[n];
		int* assl = new int[n];
		int* aassl = new int[n];
		int* arsh = new int[n];
		int* assh = new int[n];
		int* aassh = new int[n];
		int* arq = new int[n];
		int* asq = new int[n];
		int* aasq = new int[n];

		switch (c)
		{
		case 0: {
			//randarr(arsl, n);
			clock_t start = clock();
			//selection(arsl, n);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			cout << endl << "time selection sort, random: " << seconds;

			//sortarr(assl, n);
			start = clock();
			//selection(assl, n);
			end = clock();
			seconds = (double)(end - start) / CLOCKS_PER_SEC;
			cout << endl << "time selection sort, sort: " << seconds;

			//assortarr(aassl, n);
			start = clock();
			//selection(aassl, n);
			end = clock();
			seconds = (double)(end - start) / CLOCKS_PER_SEC;
			cout << endl << "time selection sort, assort: " << seconds;

			/*randarr(arsh, n);
			start = clock();
			shell(arsh, n);
			end = clock();
			seconds = (double)(end - start) / CLOCKS_PER_SEC;
			cout << endl << "time shell sort, random: " << seconds;

			sortarr(assh, n);
			start = clock();
			shell(assh, n);
			end = clock();
			seconds = (double)(end - start) / CLOCKS_PER_SEC;
			cout << endl << "time shell sort, sort: " << seconds;

			assortarr(aassh, n);
			start = clock();
			shell(aassh, n);
			end = clock();
			seconds = (double)(end - start) / CLOCKS_PER_SEC;
			cout << endl << "time shell sort, assort: " << seconds;*/

			randarr(arq, n);
			start = clock();
			quickSort(arq, n);
			end = clock();
			seconds = (double)(end - start) / CLOCKS_PER_SEC;
			cout << endl << "time quick sort, random: " << seconds;

			sortarr(asq, n);
			start = clock();
			quickSort(asq, n);
			end = clock();
			seconds = (double)(end - start) / CLOCKS_PER_SEC;
			cout << endl << "time quick sort, sort: " << seconds;

			assortarr(aasq, n);
			start = clock();
			quickSort(aasq, n);
			end = clock();
			seconds = (double)(end - start) / CLOCKS_PER_SEC;
			cout << endl << "time quick sort, assort: " << seconds;

			break;
		}
		case 1:
			randarr(arsl, n);
			vivod(arsl, n);
			visselection(arsl, n);
			vivod(arsl, n);
			break;
		case 2:
			randarr(arsh, n);
			vivod(arsh, n);
			visshell(arsh, n);
			vivod(arsh, n);
			break;
		case 3: {
			assortarr(arq, n);
			vivod(arq, n);
			visquickSort(arq, n);
			vivod(arq, n);
			break; }
		case 4:
		{
			cout << "selection: " << endl;
			cout << " random: ";
			randarr(arsl, n);
			vivod(arsl, n);
			selection(arsl, n);
			vivod(arsl, n);

			cout << " sort: ";
			sortarr(assl, n);
			vivod(assl, n);
			selection(assl, n);
			vivod(assl, n);

			cout << " assort: ";
			assortarr(aassl, n);
			vivod(aassl, n);
			selection(aassl, n);
			vivod(aassl, n);

			cout << endl << "shell:" << endl;
			cout << " random: ";
			randarr(arsh, n);
			vivod(arsh, n);
			shell(arsh, n);
			vivod(arsh, n);

			cout << " sort: ";
			sortarr(assh, n);
			vivod(assh, n);
			shell(assh, n);
			vivod(assh, n);

			cout << " assort: ";
			assortarr(aassh, n);
			vivod(aassh, n);
			shell(aassh, n);
			vivod(aassh, n);

			cout << endl << "quickSort: " << endl;
			cout << " random: ";
			randarr(arq, n);
			vivod(arq, n);
			quickSort(arq, n);
			vivod(arq, n);

			cout << " sort: ";
			sortarr(asq, n);
			vivod(asq, n);
			quickSort(asq, n);
			vivod(asq, n);

			cout << " assort: ";
			assortarr(aasq, n);
			vivod(aasq, n);
			quickSort(aasq, n);
			vivod(aasq, n);
		}
		break;
		default:
			break;
		}
		cout << endl << "repet? 1 - yes, 0 - no "; cin >> s;
	}while (s);

	cout << endl;
	system("pause");
	return 0;
}
