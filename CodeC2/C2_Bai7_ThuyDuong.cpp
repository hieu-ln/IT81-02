#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 100

void init(int a[], int &front, int &rear) {
	front = -1;
	rear = -1;
}

int isEmpty(int a[], int &front, int &rear) {
	if(front == rear)
		return 1;
	else
		return 0;
}

int isFull(int a[], int &front, int &rear) {
	if((front == 0 && rear == MAX - 1) || (front - rear == 1))
		return 1;
	else
		return 0;
}

int Push(int a[], int &front, int &rear, int x) {
	if (rear - front == MAX - 1)
		return 0;
	else {
		if (front == -1)
			front = 0;
		if (rear == MAX - 1) {
			for (int i = front; i <= rear; i++) {
				a[i - front] = a[i];
			}
			rear = MAX - 1 - front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
	return 0;
}

int Pop(int a[], int &front, int &rear, int &x) {
	if (front == -1)
		return 0;
	else {
		x = a[front++];
		if (front > rear) {
			front = -1;
			rear = -1;
		}
		return 1;
	}
	return 0;
}

void Process_queue(int a[], int f, int r)
{
	cout << "f = " << f << "\t r = " << r << endl;
	if(f <= r && f!= - 1) {
		cout << "<--  ";
		for(int i = f; i < r + 1; i++){
			cout << a[i] << "  ";
		}
		cout << "<--" << endl;
	}
}

int main()
{
	int a[MAX];
	int choice, f, r, x, i;
	system("cls");
	cout << "---------------MENU---------------\n";
	cout << "1. Khoi tao Quere rong\n";
	cout << "2. Kiem tra Quere co rong hay khong\n";
	cout << "3. Kiem tra Quere co day hay khong\n";
	cout << "4. Them 1 phan tu vao Queren\n";
	cout << "5. Lay 1 phan tu ra khoi Quere\n";
	cout << "6. Xuat Quere\n";
	cout << "7. Thoat\n";
	do{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init(a, f, r);
			cout << "Khoi tao Quere thanh cong\n";
			break;
		case 2: 
			if(isEmpty(a, f, r))
				cout << "Quere rong!\n";
			else
				cout << "Quere khong rong\n";
			break;
		case 3:
			if(isFull(a, f, r))
				cout << "Quere da day!\n";
			else
				cout << "Quere chua day\n";
			break;
		case 4:
			cout << "Nhap phan tu can them vao Quere x = ";
			cin >> x;
			i = Push(a, f, r, x);
			cout << "Quere sau khi them la: ";
			Process_queue(a, f, r);
			break;
		case 5: 
			i= Pop(a, f, r, x);
			cout << "Phan tu lay ra tu Quere x= " << x << endl;
			cout << "Quere sau khi lay ra la: ";
			Process_queue(a, f, r);
			break;
		case 6:
			cout << "Quere hien tai la: ";
			Process_queue(a, f, r);
			break;
		case 7: 
			cout << "Chuong trinh ket thuc...\n";
			break;
		default:
			break;
		}
	} while(choice!=7);
	system("pause");
	return 0;
}