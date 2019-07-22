//Bai 5, chuong 2,: Danh sach han che, ngan xep
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100
//5.2 Tao Stack rong
void init(int a[], int &sp)
{
	sp = -1;
}
//5.3 kiem tra ngan xep rong
int isEmpty(int a[], int sp)
{
	if(sp == -1)
		return 1;
	return 0;
}
//5.4 kiem tra ngan xep day
int isFull(int a[], int sp)
{
	if(sp == MAX -1)
		return 1;
	return 0;
}
//5.5 them phan tu vao ngan xep
int Push(int a[], int &sp, int x)
{
	if(sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
//5.6 xoa mot phan tu
int Pop(int a[], int &sp, int x)
{
	if(sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
//Xuat Stack
void Process_stack(int a[], int sp)
{
	for(int i = 0; i < sp + 1; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}
int main()
{
	int a[MAX];
	int choice, sp, x, i;
	system("cls");
	cout << "------------------Bai tap 5, Chuong 2, Stack-------------------\n";
	cout << "1. Khoi tao Stack rong.\n";
	cout << "2. Them phan tu vao Stack.\n";
	cout << "3. Lay phan tu ra khoi Stack.\n";
	cout << "4. Kiem tra Stack co rong hay khong.\n";
	cout << "5. Kiem tra Stack co day hay khong.\n";
	cout << "6. Xuat Stack\n";
	cout << "7. Thoat\n";
	do{
	    cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				init(a,sp);
				cout << "Ban vua khoi tao Stack rong thanh cong!\n";
				break;
			case 2:
				cout << "Vui long nhap gia tri x = ";
				cin >> x;
				i = Push(a, sp,x);
				cout << "Stack sau khi them la: ";
				Process_stack(a,sp);
				break;
			case 3:
				i = Pop(a,sp,x);
				cout << "Phan tu lay ra khoi Stack la x = " << x << endl;
				cout << "Stack sau khi lay ra la: ";
				Process_stack(a,sp);
				break;
			case 4:
				i = isFull(a, sp);
				if(i == 0)
					cout << "Stack chua day!\n";
				else
					cout << "Stack da day!\n";
				break;
			case 5:
				i = isEmpty(a, sp);
				if(i == 0)
					cout << "Stack khong rong!\n";
				else
					cout << "Stack rong!\n";
				break;
			case 6:
				cout << "Stack hien tai la:";
				Process_stack(a,sp);
				break;
			case 7:
				cout << "Good bye..........!!!!!!!!!!\n";
				break;
			default:
				break;
		}
		
	}while(choice != 7);
	system("pause");
	return 0;
}