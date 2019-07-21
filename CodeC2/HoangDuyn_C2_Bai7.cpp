// Bai 7 chuong 2
#include<stdio.h>
#include<iostream>
using namespace std;

const int MAX=100;
// Khoi tao QUEUE rong
void init(int a[], int &front, int &rear)
{
	front =-1;
	rear=-1;
}
//Kiem tra QUEUE rong
int isEmpty(int a[], int &front, int &rear)
{
	if(front ==rear)
		return 1;
	else
		return 0;
}
//Kiem tra Queue day
int isFull(int a[], int &front,int &rear)
{
	if((front ==0 && rear == MAX-1)||(front-rear==1))
		return 1;
	return 0;
}
//Them phan tu vao queue
int Push(int a[], int &front, int &rear, int x)
{
	if(rear-front == MAX-1)
		return 0;
	else
	{
		if(front==-1)
			front -0;
		if(rear==MAX-1)
		{
			for(int i = front; i <=rear;i++)
				a[i=front]=a[i];
			rear=MAX-1-front;
			front =0;
		}
		a[++rear]=x;
		return 1;
	}
	return 0;
}
int Pop(int a[], int &front, int &rear, int &x)
{
	if(front==-1)
		return 0;
	else
	{
		x=a[front++];
		if(front > rear)
		{
			front =-1;
			rear = -1;
		}
		return 1;
	}
	return 0;
}
//Xuat queue
void Process_queue( int a[], int f, int r)
{
	cout << " f=" << f << " \t r =" << r << endl;
	if(f<=r && f!=-1)
	{
		cout << " <--  ";
		for ( int i=f; i < r+1; i++)
		{
			cout << a[i] << "   ";

		}
		cout << " <--   " << endl;
	}
}

int main()
{
	int a[MAX];
	int choice, f, r, x, i;
	system("cls");
	cout << " Bai tap 7 chuong 2 Queue " << endl;
	cout << " 1.Khoi tao QUEUE rong " << endl;
	cout << " 2.Them phan tu vao Queue " << endl;
	cout << " 3.Lay phan tu ra khoi Queue " << endl;
	cout << " 4.Kiem tra Queue co rong khong " << endl;
	cout << " 5.Kiem tra Queue co day khong " << endl;
	cout << " 6.xuat QUEUE " << endl;
	cout << " 7. THOAT " << endl;
	do{
		cout << " \n Vui long chon so de thuc hien : ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init(a,f,r);
			cout << " Ban vua khoi tao Queue rong thanh cong ! \n";
			break;
		case 2:
			cout << " vui long nhap gia tri cua X=";
			cin >> x;
			i=Push(a,f,r,x);
			cout << " Queue sau khi them la : ";
			Process_queue(a,f,r);
			break;
		case 3:
			i=Pop(a,f,r,x);
			cout << " Phan tu lay ra dau Queue la x=" << x << endl;
			cout << " Queue sau khi lay ra la : ";
			Process_queue(a,f,r);
			break;
		case 4:
			i=isFull(a,f,r);
			if(i==0)
				cout << " Queue chua day ! " << endl;
			else
				cout << " queue da day ~ " << endl;
			break;
		case 5:
			i=isEmpty(a,f,r);
			if(i==0)
				cout << " Queue khong rong ! ";
			else
				cout << " Queue rong ! " << endl;
			break;
		case 6:
			cout << " Queue hien tai la: ";
			Process_queue(a,f,r);
			break;
		case 7: 
			cout << " GOODBYE !! " << endl;
			break;
		default : 
			break;

		}
	}while(choice!=7);
	return 0;
}
