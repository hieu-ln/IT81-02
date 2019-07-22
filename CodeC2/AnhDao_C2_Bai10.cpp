//Bai 10, Chuong 2: Danh sach han che
//Stack su dung DSLK DON
#include <stdio.h>
#include <iostream>
using namespace std;
//Cau 10.1: Khai bao cau truc Stack
struct Node{
	int info;
	Node *link;
};
Node *sp;
// Cau 10.2: Khoi tao Stack rong.
void init()
{
	sp = NULL;
}
//10.3 Kiem tra Stack rong.
int isEmpty()
{
	if(sp == NULL)
		return 1;
	return 0;
}
//10.4 Them phan tu vao Stack
void Push(int x)
{
	Node *p;
	p = new Node;
	p -> info = x;
	p -> link = sp;
	sp = p;
}
//10.5 lay phan tu ra khoi Stack
int Pop(int &x)
{
	if(sp != NULL)
	{
		Node *p = sp;
		x = p -> info;
		sp = p ->link;
		delete p;
		return 1;
	}
	return 0;
}
//Xuat Stack
void Process_stack()
{
	Node *p = sp;
	do{
		cout << p -> info << "  ";
		p = p -> link;
	}while(p != NULL);
	cout << endl;
}
int main()
{
	int choice, x, i;
	system("cls");
	cout << "-----------------Bai tap 10, Chuong 2, Stack-----------------\n";
	cout << "1. Khoi tao Stack rong\n";
	cout << "2. Them phan tu vao Stack\n";
	cout << "3. Lay phan tu ra khoi Stack\n";
	cout << "4. Xuat Stack.\n";
	cout << "5. Thoat\n";
	do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				init();
				cout << "Ban vua khoi tao DSLK DON thanh cong!\n";
				break;
			case 2:
				cout << "Vui long nhap gia tri x = ";
				cin >> x;
				Push(x);
				cout << "Stack sau khi them la: ";
				Process_stack();
				break;
			case 3:
				Pop(x);
				cout << "Phan tu lay ra tu Stack la x= " << x << endl;
				cout << "Stack sau khi lay ra la: ";
				Process_stack();
				break;
			case 4:
				cout << "Stack hien tai la: ";
				Process_stack();
				break;
			case 5:
				cout << "Good bye..........!!!!!!!!!!\n";
					break;
			default:
				break;
		}
	}while(choice != 5);
	system("pause");
	return 0;
}
