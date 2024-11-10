#include <iostream>
#include"Windows.h"
#include<fstream>
#include <time.h>
#include"Hash.h"

using namespace std;

int main()
{
    srand(time(0));
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    bool c = false;
    do {
        char a;
        int count = 0, d, B;
        cout << "Проверяем а (до 30 классов) или б (20000-50000 классов) (a, b соответственно)" << endl;
        cin >> a;
        switch (a) {
        case 'a': {
            ifstream f;
            f.open("lb5in.txt");
            if (!f.good()) {
                cout << "Error file" << endl;
                break;
            }
            while (!f.eof()) {
                f >> d;
                count++;
            }
            B = count / 2;
            if (B > 30)B = 30;
            Hash hash(B);
            f.close();
            f.open("lb5in.txt");
            while (!f.eof()) {
                f >> d;
                hash.insert(d % B, d);
            }
            hash.print();
            cout << "что ищем?: "; cin >> d;
            if (hash.find(d % B, d)) {
                cout << "Такой элемент существует" << endl;
            }
            else { cout << "Такой элемент не существует" << endl; }
            break;
        }
        case 'b': {
            int n = 100000;//количество элементов для заполнения в файл
            {//заполнение файла рандомными числами
                ofstream f1("file.2000.txt", ios::out);
                for (int i = 0; i < n; i++) {
                    f1 << fabs(rand() % 30000) << " ";
                }
                f1.close(); }
            ifstream f;
            f.open("file.2000.txt");
            if (!f.good())cout << "Error file" << endl;
            int a, c, hx;
            cout << "Введите количество классов В: "; cin >> B;
            Hash hash(B);
            cout << "Введите a: "; cin >> a;
            cout << "Введите c: "; cin >> c;
            while (!f.eof()) {
                f >> d;
                hx = (a * d + c) % B;
                hash.insert(hx, d);
            }
            cout << "что ищем?: "; cin >> d;
            hx = (a * d + c) % B;

            if (hash.find(hx, d)) {
                cout << "Такой элемент существует" << endl;
            }
            else { cout << "Такой элемент не существует" << endl; }

            cout << "Количество коллизий:" << hash.countCollisions() << endl;
            cout << "Процент заполняемости таблицы:" << hash.calculateLoadFactor() << endl;
            vector<pair<int, int>> v1 = hash.longestCollisionChain();
            cout << "Длина самой-самой цепочки: " << v1.size() << endl;
            for (auto& entry : v1) {
                cout << entry.second << " ";
            }
            cout << endl;

        }
        }
        cout << "Проверяем еще раз? 0 - No 1 - yes" << endl;
        cin >> c;
    } while (c);
    system("pause");
    return 0;
}