//Bai 11, Chuong 2: Danh sach han che
#include <stdio.h>
#include <iostream>
using namespace std;
//11.1 Khai bao cau truc QUEUE
struct Node{
	int info;
	Node *link;
};
Node *front, *rear;
// Cau 11.2: Khoi tao Queue rong.
void init()
{
	front = NULL;
	rear = NULL;
}
//11.3 Kiem tra Queue rong.
int isEmpty()
{
	if(front == NULL)
		return 1;
	return 0;
}
//11.4 Them phan tu vao Queue
void Push(int x)
{
	Node *p;
	p = new Node;
	p -> info = x;
	p -> link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear -> link = p;
	rear = p;
}
//11.5 lay phan tu ra khoi Queue
int Pop(int &x)
{
	if(front != NULL)
	{
		Node *p = front;
		front = p ->link;
		x = p -> info;
		if(front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//Xuat Queue
void Process_queue()
{
	if(front != NULL)
	{
		Node *p = front;
		cout << "<--   ";
		do{
			cout << p -> info << "  ";
			p = p -> link;
		}while(p != NULL);
		cout << "<--  " << endl;
	}
}
int main()
{
	int choice, x, i;
	system("cls");
	cout << "-----------------Bai tap 11, Chuong 2, Queue-----------------\n";
	cout << "1. Khoi tao Queue rong\n";
	cout << "2. Them phan tu vao Queue\n";
	cout << "3. Lay phan tu ra khoi Queue\n";
	cout << "4. Xuat Queue.\n";
	cout << "5. Thoat\n";
	do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				init();
				cout << "Ban vua khoi tao Queue rong thanh cong!\n";
				break;
			case 2:
				cout << "Vui long nhap gia tri x = ";
				cin >> x;
				Push(x);
				cout << "Queue sau khi them la: ";
				Process_queue();
				break;
			case 3:
				Pop(x);
				cout << "Phan tu lay ra tu Queue la x= " << x << endl;
				cout << "Queue sau khi lay ra la: ";
				Process_queue();
				break;
			case 4:
				i = isEmpty();
				if(i == 0)
					cout << "QUEUE khong rong!\n";
				else
					cout << "QUEUE rong!\n";
				break;
			case 5:
				cout << "Queue hien tai la: ";
				Process_queue();
				break;
			case 6:
				cout << "Good bye..........!!!!!!!!!!\n";
					break;
			default:
				break;
		}
	}while(choice != 6);
	system("pause");
	return 0;
}

