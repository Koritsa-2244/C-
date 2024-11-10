#include <iostream>
#include <windows.h>
#include<time.h>
using namespace std;

struct Queue1 {
	int* elements;  // ������ ��� �������� ���������
	int head, tail;  // ��������� �� ������ � ����� �������
	int size;  // ���������� ��������� �������
};

void InitQueue(Queue1& q, int capacity) {
	q.head = -1;
	q.size = capacity + 1;
	q.tail = -1; // ��������� ����� �������
	q.elements = new int[capacity + 1];  // ��������� ������ ��� �������
}
bool empty(Queue1& q)
{
	return(q.head == -1 && q.tail == -1);
}


void add(Queue1& q, int item) {
	if ((((q.tail + 1) % q.size) + 1) % q.size == q.head) {  // ���������, �� ��������� �� �������
		cout << "Queue is full";  // ������� ���������, ���� ������� �����������
		return;  // ������� �� �������
	}
	if (q.head == -1)
		q.head = 0;
	q.tail = (q.tail + 1) % q.size;// ��������� ��������� �� ����� �������
	q.elements[q.tail] = item;  // ��������� ������� � �������
}
int del(Queue1& q)
{
	if (empty(q)) {
		cout << "������� ������!\n";
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
struct Stack1 { /*�������� ��������� �����*/
	int top;
	int* data;
};

void InitStack(Stack1& st, int capacity) { /*�������������� ���� � ������� �����*/
	st.data = new int[capacity];
	st.top = -1;
}
void push(Stack1& st, int value) { /*��������� �������*/
	st.data[++st.top] = value; //++i ����������� i �� 1, ����� ����������
}
int pop(Stack1& st) { /*������� �� ������*/
	return st.data[st.top--];
}
void nullStack(Stack1& st) { /*������� ����*/
	st.top = -1;
}
bool empty(Stack1& st) { /*��������� ������� ��������� �����*/
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
	for (int i = 0; i < w; i++) {//�������� ����� 1
		push(st1, 0);
	}
	for (int i = 0; i < e; i++) {//�������� ����� 2
		push(st2, -2);
	}
	int j = 0;
	cout << "st2: ";//������� ���� 2, ���� ��������
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
	cout << "st1: ";//������� ���� 1, ������� ���������� ��������� ������� ���������
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
	if (!empty(st1)) { //������ �������� � ������� 
		int i = st1.top;
		while (i != -1) {
			int k = st1.data[i--];
			if (j != 0 && k % j == 0) {
				add(que, k);
			}
		}
	}
	cout << endl << "Queue: ";
	if (!empty(que)) { //������� �������
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

// ����������� ��������� ���� ��� �����
struct Node { /*�������. ������*/
	int data, top;
	Node* next;
};

// ������� ������������� �����
void InitStack(Node*& top) {
	top = NULL;
}

// ������� ���������� �������� � ����
void push(Node*& top, int value) {
	Node* tmp = new Node;
	tmp->next = top;
	top = tmp;
	top->data = value;
}

// ������� ���������� �������� �� �����
int pop(Node*& top) {
	Node* tmp = top;
	int d = top->data;
	top = top->next;
	delete(tmp);
	return d;
}

// ������� �������� ������� ��������� � �����
bool empty(Node*& top) {
	return top == NULL;
}

// ������� ������� �����
void nullStack(Node*& top) {
	Node* tmp;
	while (!empty(top)) {
		tmp = top;
		top = top->next;
		delete(tmp);
	}
}



// ����������� ������ �������
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

	// ����� �������� ������� ��������� � �������
	bool empty() {
		return head == NULL;
	}

	// ����� ���������� �������� � �������
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
	void ShowQueue()//������� �������
	{
		if (empty())
			cout << "������� ������!\n";
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


	// ����� �������� �������� �� �������
	int del()
	{
		if (empty())
			cout << "������� ������!\n";
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

// ����� ����� � ���������
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	Node* st1, * st2;  // �������� ���������� �� ������� ������
	Queue que;  // �������� ������� ������ Queue ��� ������� 

	InitStack(st1);  // ������������� ����� 1
	InitStack(st2);  // ������������� ����� 2

	int w = rand() % (20 - 4 + 1) + 4, e = rand() % (20 - 4 + 1) + 4;
	for (int i = 0; i < w; i++) {
		push(st1, rand() % (20 - 4 + 1) + 4);  // ���������� ���������� �������� � ���� 1
	}

	for (int i = 0; i < e; i++) {
		push(st2, rand() % 10);  // ���������� ���������� �������� � ���� 2
	}
	Node* tmp1 = st2;
	int j = 0;
	cout << "������������ ������" << endl << "st2: ";
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
