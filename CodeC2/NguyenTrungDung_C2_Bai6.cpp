#include <iostream>
#include <conio.h>
using namespace std;

#define MAX 100
int a[MAX];
int n;
//tao stack rong
void init(int a[], int &n)
{
	n = -1;
}
//chen 1 ptu vao stack
void push(int a[], int &n, int x)
{
	if (n < MAX - 1)
		a[++n] = x;
}
//lay 1 ptura khoi stack
int pop(int a[], int &n, int &x)
{
	if (n != -1)
	{
		x = a[n--];
		return x;
	}
	return 0;
}
//chuyen thap phan sang nhi phan su dung stack
void changeToBinary(int a[], int &n, int x)
{
	while (x != 0)
	{
		int tam = x % 2;
		push(a, n, tam);
		x = x / 2;
	}
}
void menu()
{
	cout << "-----BAI 6--CHUONG 2-----" << endl;
	cout << "1. Tao stack rong" << endl;
	cout << "2. Chen 1 phan tu vao stack" << endl;
	cout << "3. Lay 1 phan tu ra tu stack" << endl;
	cout << "4. Chuyen he thap phan sang nhi phan" << endl;
	cout << "5. Thoat" << endl;
}
void main()
{
	int tp;
	int kq[MAX];
	int nkq;
	int x;
	int choice = 0;

	menu();
	do {
		cout << "Chon so muon thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Tao stack rong thanh cong" << endl;
			break;
		case 2:
			cout << "Nhap gtri muon chen: ";
			cin >> x;
			push(a, n, x);
			cout << "Chen gtri vao stack thanh cong" << endl;
			break;
		case 3:
			x = pop(a, n, x);
			if (x != 0)
			{
				cout << "Lay 1 ptu tu stack thang cong" << endl;
				cout << "Ptu co gtri la: " << x << endl;
			}
			else
				cout << "Lay gtri khong thanh cong" << endl;
			break;
		case 4:
			cout << "Nhap gtri thap phan: ";
			cin >> tp;
			init(kq, nkq);
			changeToBinary(kq, nkq, tp);
			cout << "Gtri nhi phan tuong ung la: ";
			while (nkq > -1)
				cout << pop(kq, nkq, x);
			cout << endl;
			break;
		default:
			cout << "Goodbey!" << endl;
		}
	} while(choice > 0 && choice < 6);
}