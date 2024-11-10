#include <iostream>
#include <windows.h>
#include<time.h>
using namespace std;


struct Node {
	float data;
	Node* left, * right;
};
void printTree1(Node* node) {
	if (node != NULL) {
		cout << node->data << " ";
		printTree1(node->left);
		printTree1(node->right);
	}
}
void printTree2(Node* node) {
	if (node != NULL) {
		printTree2(node->left);
		cout << node->data << " ";
		printTree2(node->right);
	}
}
void printTree3(Node* node) {
	if (node != NULL) {
		printTree3(node->left);
		printTree3(node->right);
		cout << node->data << " ";
	}
}

void add(int x, Node*& node) {
	if (node == NULL) {
		node = new Node;
		node->data = x;
		node->left = NULL;
		node->right = NULL;
	}
	else {
		if (rand() % 2 - 0 == 1) 
			add(x, node->left);
		else 
			add(x, node->right);

	}
}

void  ave(Node*& node, float& sum, int& count) {
	if (node != NULL) {
		count++;
		sum += node->data;
		ave(node->right, sum, count);
		ave(node->left, sum, count);
	}
}
int main()
{

	srand(time(0));
	setlocale(0, "1251");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Node* root = NULL;
	for (int i = 0;i < rand() % (15 - 10 + 1) + 10;i++) {
		add(rand() % 200 - 100, root);
	}

	printTree1(root);
	cout << "- прямой обход";
	cout << endl;
	printTree2(root);
	cout << "- симметричный обход";
	cout << endl;
	printTree3(root);
	cout << "- обратный обход";
	cout << endl;
	float q1 = 0;
	int i = 0;
	ave(root, q1,i);
	cout << q1/i << endl;

	system("pause");
	return 0;
}
