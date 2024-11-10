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
	del(que);
	del(que);
	del(que);
	del(que);
	del(que);
	del(que);
	del(que);
	del(que);
	del(que);
	del(que);
	del(que);
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