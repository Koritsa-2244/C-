#include <iostream> 
#include <windows.h> 
#include <fstream>
#include<vector>
#include <regex>
#include<string>

using namespace std;

struct node {
    string word;
    int k;//частота
    node* left, * right;
};
void statistic(node*& root, string word1) {
    if (root == NULL) {
        root = new node;
        root->word = word1;
        root->k = 1;
        root->left = NULL;
        root->right = NULL;
    }
    else if (word1 < root->word)statistic(root->left, word1);
    else if (word1 > root->word)statistic(root->right, word1);
    else root->k++;
}
void abc_sort_tree(node*& node1, std::ofstream& f) {
    if (node1 != NULL) {
        abc_sort_tree(node1->left, f);
        f << node1->word << " - " << node1->k << std::endl;
        abc_sort_tree(node1->right, f);
    }
}
void printTreef(node** arr, string name_file, int i) {
    ofstream f(name_file, std::ios::binary | std::ios::out);
    for (int j = i-1; j >= 0; j--) {
        f << arr[j]->word << " " << arr[j]->k << endl;
    }
}
void udalenie(node*& koren) {
    if (koren->left) udalenie(koren->left);
    if (koren->right) udalenie(koren->right);
    koren = NULL;
}
void splitword(string& word, string& word1) {
    bool c = 0;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == '-') {
            c = 1;
        }
        if(c) word1 += word[i];
    }
}
void clearWord(string& word, string& word1) {
    bool c = 0;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == '[')return;
        if (word[i] == '-')return;
        if (c == 0) {
            if ((word[i] >= 97 && word[i] <= 122)) {//если маленькая буква - меняем на заглавную (англ.)
                word[i] -= 32;
            }
            else if ((word[i] >= -32 && word[i] <= -1)) {//если маленькая буква - меняем на заглавную (рус.)
                word[i] -= 32;
            }
            if ((word[i] >= 97 && word[i] <= 122) || (word[i] >= -64 && word[i] <= -31) || word[i] == '’') {
                word1 += word[i];
                c = 1;
            }
        }
        else if((word[i]>=65 && word[i]<=90) || (word[i] >= 97 && word[i] <= 122) || (word[i] >= -64 && word[i] <= -1) || word[i] == '’')word1 += word[i];
    }
}
void freq_sort_tree(node** a, int n) { //сортировка указателей методом Шелла
    int step = n / 2;
    while (step > 0)
    {
        for (int i = 0; i < n - step; i++)
        {
            int j = i;
            while (j >= 0 && a[j]->k > a[j + step]->k)
            {
                node* tmp = a[j];
                a[j] = a[j + step];
                a[j + step] = tmp;
                j -= step;
            }
        }
        step /= 2;
    }
}
void poisk(node* node1, string word, int& freq) {
    if (node1 == NULL)return;
    if (node1 != NULL && node1->word == word) {
            freq = node1->k;
            return;
    }
    else if (word < node1->word)poisk(node1->left, word, freq);
    else if (word > node1->word)poisk(node1->right, word, freq);
}
void poisk_lenght(node* node1, int lenght, std::ofstream& f) {
    if (node1 == NULL)return;
    if (node1->word.size() == lenght) {
        f << node1->word << " - " << node1->k << std::endl;
    }
    poisk_lenght(node1->left, lenght, f);
    poisk_lenght(node1->right, lenght, f);
}
void CreateArr(node*& node1, node** arr, int& i) { //массив указателей
    if (node1 != NULL) {
        arr[i] = node1;
        i++;
        CreateArr(node1->left, arr, i);
        CreateArr(node1->right, arr, i);
    }
    return;
}

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string file_name;
    ifstream f;//файл для чтения
    int count = 0;

    do {//открываем файл
        cout << "\nФайл не найден.\n"
            << "Введите имя файла: ";
        getline(cin, file_name);
        f.open(file_name, ios::binary / ios::in);
        if (f.good())
            break;
    } while (true);

    node* root = NULL;
    string word;
    string word1="";
    while (!f.eof()) {//читаем из файла в дерево алфав порядок
        f >> word;
        //splitword(word, word1);//делим слово по дефису (если такой есть)
        //if(word1!="") statistic(root, word1);
        //word1 = "";
        //clearWord(word, word1);
        statistic(root, word); 
        word1 = "";
        count++;
    }
    f.close();
    ofstream f1 ("slovaralph.txt", std::ios::binary | std::ios::out);//файл для записи
    abc_sort_tree(root, f1);//выводим алфавитный словарь
    f1.close();
    cout << endl << "sort" << endl;
    f1.open("slovarfr.txt", std::ios::binary | std::ios::out);
    node** array = new node * [count];
    int i = 0;
    CreateArr(root, array, i);
    freq_sort_tree(array, i);
    printTreef(array, "slovarfr.txt", i);//выводим частотный словарь
    delete[]array;
    f1.close();
    cout << "какое слово ищем? ";
    string slovo; cin >> slovo;
    int c = 0;
    //поиск слова
    poisk(root, slovo, c);
    if (c == 0)cout << "не нашли такое" << endl;
    else cout << slovo << " - " << c << endl;
    c = 0;
    cout << "lenght: "; cin >> c;
    //поиск по длине
    f1.open("slovar_lenght.txt", std::ios::binary | std::ios::out);
    poisk_lenght(root, c, f1);
   
    f1.close();
    udalenie(root);
    system("pause");

    return 0;
}
