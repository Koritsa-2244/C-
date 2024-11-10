#include <iostream> 
#include <windows.h> 
#include<time.h> 
using namespace std;

// Определение структуры узла для стека
struct Node { /*динамич. список*/
	int data, top;
	Node* next;
};

// Функция инициализации стека
void InitStack(Node*& top) {
	top = NULL;
}

// Функция добавления элемента в стек
void push(Node*& top, int value) {
	Node* tmp = new Node;
	tmp->next = top;
	top = tmp;
	top->data = value;
}

// Функция извлечения элемента из стека
int pop(Node*& top) {
	Node* tmp = top;
	int d = top->data;
	top = top->next;
	delete(tmp);
	return d;
}

// Функция проверки наличия элементов в стеке
bool empty(Node*& top) {
	return top == NULL;
}

// Функция очистки стека
void nullStack(Node*& top) {
	Node* tmp;
	while (!empty(top)) {
		tmp = top;
		top = top->next;
		delete(tmp);
	}
}



// Определение класса очереди
class Queue {
	struct Node
	{
		int data;
		Node* next;
	};

	Node* head, * tail;

public:

	Queue() {
		head = 0;
		tail = 0;
	}

	// Метод проверки наличия элементов в очереди
	bool empty() {
		return head == NULL;
	}

	// Метод добавления элемента в очередь
	void add(int value) {
		Node* tmp = new Node();
		tmp->data = value;
		tmp->next = NULL;

		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
		}

	}
	void ShowQueue()//выводим очередь
	{
		if (empty())
			cout << "Очередь пустая!\n";
		else
		{
			Node* tmp = head;
			while (tmp != NULL)
			{
				cout << tmp->data << " ";
				tmp = tmp->next;
			}
		}
		cout << endl;
	}


	// Метод удаления элемента из очереди
	int del()
	{
		if (empty())
			cout << "Очередь пустая!\n";
		else {
			int d = head->data;
			if (head == tail)
			{
				delete(head);
				head = tail = NULL;
			}
			else
			{
				Node* tmp = head;
				head = head->next;
				delete(tmp);
			}
			return d;
		}
	}
};

// Точка входа в программу
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	Node* st1, * st2;  // Создание указателей на вершину стеков
	Queue que;  // Создание объекта класса Queue для очереди 

	InitStack(st1);  // Инициализация стека 1
	InitStack(st2);  // Инициализация стека 2

	int w = rand() % (20 - 4 + 1) + 4, e = rand() % (20 - 4 + 1) + 4;
	for (int i = 0; i < w; i++) {
		push(st1, rand() % (20 - 4 + 1) + 4);  // Добавление случайного значения в стек 1
	}

	for (int i = 0; i < e; i++) {
		push(st2, rand() % 10);  // Добавление случайного значения в стек 2
	}
	Node* tmp1 = st2;
	int j = 0;
	cout << "Динамические списки" << endl << "st2: ";
	if (!empty(st2)) {
		j = tmp1->data;
		Node* tmp = st2;
		while (tmp != NULL)
		{
			int k = tmp->data;
			if (j < k) j = k;
			cout << k << ' ';
			tmp = tmp->next;
		}
	}
	cout << endl << "st2 max: " << j << endl;
	int c = 0;
	cout << "st1: ";
	if (!empty(st1)) {
		Node* tmp = st1;
		while (tmp != NULL)
		{
			int k = tmp->data;
			cout << k << " ";
			tmp = tmp->next;
			if (j != 0 && k % j == 0) {
				que.add(k);
				c++;
			}
		}
	}
	cout << endl << "Queue: ";
	if (!que.empty())
	{
		que.ShowQueue();
	}
	cout << endl;
	return 0;
}
