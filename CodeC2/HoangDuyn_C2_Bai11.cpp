//Bai 11 chuong 2
#include<iostream>
#include<stdio.h>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node *front,*rear;
//Khoi tao Queue
void init()
{
	front = NULL;
	rear = NULL;
}
//Ktra rong
int isEmpty()
{
	if(front == NULL)
		return 1;
	return 0;
}
void Push(int x)
{
	Node*p=new Node;
	p->info=x;
	p->link=NULL;
	if(rear==NULL)
		front = p;
	else
		rear->link=p;
	rear=p;
}
int Pop(int &x)
{
	if(front!=NULL)
	{
		Node*p=front;
		front=p->link;
		x=p->info;
		if(front==NULL)
		{
			rear=NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
void Process_queue()
{
	if(front!=NULL)
	{
		Node*p=front;
		cout << " <-- ";
		do{
			cout << p->info<< "  ";
			p=p->link;
		}while(p!=NULL);
		cout << " <-- " << endl;
	}
}
int main()
{
	int choice, x,i;
	system("cls");
	cout << " Bai tap 11 chuong 2 " << endl;
	cout << " 1.Khoi tao Queue rong " << endl;
	cout << " 2.Them phan tu vao queue " << endl;
	cout << " 3.Lay phan tu ra khoi Queue " << endl;
	cout << " 4.Kiem tra Queue rong hay khong " << endl;
	cout << " 5.Xuat Queue ra " << endl;
	cout << " 6.Thoat " << endl;
	do{
		cout << " \n Vui long chon so de thuc hien : ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init();
			cout << " Ban vua khoi tao Queue thanh cong ! " << endl;
			break;
		case 2:
			cout << " Vui long nhap gia tri x=";
			cin >> x;
			Push(x);
			cout << " Queue sau khi them la : ";
			Process_queue();
			break;
		case 3:
			Pop(x);
			cout << " Phan tu lay ra tu Queue la x=" << x << endl;
			cout << " Queue sau khi lay ra la : ";
			Process_queue();
			break;
		case 4:
			i=isEmpty();
			if(i==0)
				cout << " Queue khong rong ! " << endl;
			else
				cout << " Queue rong ! " << endl;
			break;
		case 5 :
			cout << " Queue hien tai la : " ;
			Process_queue();
			break;
		case 6:
			cout << " Goodbye ...!" << endl;
		default: 
			break;
		}
	}while(choice!=6);
	return 0;
}