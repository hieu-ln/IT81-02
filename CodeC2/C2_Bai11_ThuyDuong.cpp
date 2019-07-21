#include <iostream>
#include <stdio.h>
using namespace std;

struct Node {
	int info;
	Node *link;
};
Node *front, *rear;

void init() {
	front = NULL;
	rear = NULL;
}

int isEmpty() {
	if (front == NULL)
		return 1;
	return 0;
}

void Push(int x) {
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

int Pop(int &x) {
	if (front != NULL) {
		Node *p = front;
		front = p->link;
		x = p->info;
		if(front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

void Process_queue()
{
	if(front!=NULL) {
		Node *p = front;
		cout << "<--  ";
		do {
			cout << p->info << "  ";
			p=p->link;
		} while (p!=NULL);
		cout << "<--" << endl;
	}
}

int main()
{
	int choice, x, i;
	system("cls");
	cout << "-----------------MENU-------------------\n";
	cout << "1. Khoi tao Queue rong\n";
	cout << "2. Them phan tu vao Queue\n";
	cout << "3. Lay phan tu ra khoi Queue\n";
	cout << "4. Xuat Queue\n";
	cout << "5. Thoat\n";
	do{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init();
			cout << "Khoi tao Queue thanh cong!\n";
			break;
		case 2:
			cout << "Nhap phan tu can them x = ";
			cin >> x;
			Push(x);
			cout << "Queue sau khi them: ";
			Process_queue();
			break;
		case 3:
			Pop(x);
			cout << "Phan tu lay ra tu Queue la x = " << x << endl;
			cout << "Queuesau khi lay ra la: ";
			Process_queue();
			break;
		case 4: 
			cout << "Queue hien tai la: ";
			Process_queue();
			break;
		case 5:
			cout << "Chuong trinh ket thuc...\n";
			break;
		default:
			break;
		}
	} while(choice!=5);
	system("pause");
	return 0;
}