#include <iostream>
#include <windows.h>
#include<time.h>
using namespace std;

struct Queue1 {
	int* elements;  // массив для хранения элементов
	int head, tail;  // указатели на начало и конец очереди
	int size;  // количество элементов очереди
};

void InitQueue(Queue1& q, int capacity) {
	q.head = -1;
	q.size = capacity + 1;
	q.tail = -1; // указатель конца очереди
	q.elements = new int[capacity + 1];  // выделение памяти для массива
}
bool empty(Queue1& q)
{
	return(q.head == -1 && q.tail == -1);
}


void add(Queue1& q, int item) {
	if ((((q.tail + 1) % q.size) + 1) % q.size == q.head) {  // проверяем, не заполнена ли очередь
		cout << "Queue is full";  // выводим сообщение, если очередь переполнена
		return;  // выходим из функции
	}
	if (q.head == -1)
		q.head = 0;
	q.tail = (q.tail + 1) % q.size;// обновляем указатель на конец очереди
	q.elements[q.tail] = item;  // добавляем элемент в очередь
}
int del(Queue1& q)
{
	if (empty(q)) {
		cout << "Очередь пустая!\n";
		return 0;
	}
	else {
		int d = q.elements[q.head];
		if (q.head == q.tail)
			q.head = q.tail = -1;
		else
			q.head = (q.head + 1) % q.size;
		return d;
	}

}


//STACK
struct Stack1 { /*создание струкруты стека*/
	int top;
	int* data;
};

void InitStack(Stack1& st, int capacity) { /*инициализирует стек и создает место*/
	st.data = new int[capacity];
	st.top = -1;
}
void push(Stack1& st, int value) { /*добавляет элемент*/
	st.data[++st.top] = value; //++i увеличивает i на 1, потом возвращает
}
int pop(Stack1& st) { /*удаляет по одному*/
	return st.data[st.top--];
}
void nullStack(Stack1& st) { /*стирает стек*/
	st.top = -1;
}
bool empty(Stack1& st) { /*проверяет наличие элементов стека*/
	return st.top == -1;
}



int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	Stack1 st1, st2;
	Queue1 que;
	int w = 10, e = 8;
	InitStack(st1, w);
	InitStack(st2, e);
	for (int i = 0; i < w; i++) {//создание стека 1
		push(st1, 0);
	}
	for (int i = 0; i < e; i++) {//создание стека 2
		push(st2, -2);
	}
	int j = 0;
	cout << "st2: ";//выводим стек 2, ищем максимум
	if (!empty(st2)) {
		j = st2.data[st2.top];
		int i = st2.top;
		while (i != -1) {
			int k = st2.data[i--];
			if (j < k) j = k;
			cout << k << ' ';
		}
	}
	cout << endl << "st2 max: " << j << endl;
	int c = 0;
	cout << "st1: ";//выводим стек 1, считаем количество элементов кратных максимуму
	if (!empty(st1)) {
		int i = st1.top;
		while (i != -1) {
			int k = st1.data[i--];
			cout << k << " ";
			if (j != 0 && k % j == 0) {
				c++;
			}
		}
	}
	InitQueue(que, c);
	if (!empty(st1)) { //вносим элементы в очередь 
		int i = st1.top;
		while (i != -1) {
			int k = st1.data[i--];
			if (j != 0 && k % j == 0) {
				add(que, k);
			}
		}
	}
	cout << endl << "Queue: ";
	if (!empty(que)) { //выводим очередь
		int p = que.head;
		while (p != (que.tail + 1) % que.size)
		{
			cout << que.elements[p] << " ";
			p = (p + 1) % que.size;
		}
	}
	cout << endl;
	return 0;
}
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
