//Bai 10 chuong 2
#include<iostream>
#include<stdio.h>
using namespace std;

struct Node 
{
	int info;
	Node *link;
};
Node *sp;
// Khoi tao
void init()
{
	sp=NULL;
}
// Ktra Stack rong
int isEmpty()
{
	if(sp==NULL)
		return 1;
	return 0;
		
}
void Push(int x)
{
	Node *p=new Node;
	p-> info=x;
	p->link=sp;
	sp=p;
}
int Pop(int &x)
{
	if(sp!=NULL)
	{
		Node *p=sp;
		x=p->info;
		sp=p->link;
		delete p;
		return 1;

	}
	return 0;
}
// Xuat Stack ra 
void Process_stack()
{
	Node * p=sp;
	do{
		cout << p->info << "  ";
		p=p->link;
	}while(p!=NULL);
	cout << endl;
}
int main()
{
	int choice, x, i ;
	system ("cls");
	cout << " Bai tap 10, chuuong 2" << endl;
	cout << " 1.Khoi tao Stack rong " << endl;
	cout << " 2.Them phan tu vao stack " << endl;
	cout << " 3.Lay phan tu ra khoi Stack " << endl;
	cout << " 4.Xuat STACK " << endl;
	cout << " 5.Thoat " << endl;
	do{
		cout << " \n Vui long chon so de thuc hien : ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init();
			cout << " Khoi taao Stack rong than cong ! " << endl;
			break;
		case 2:
			cout << " Vui long nhap gia tri x=";
			cin >> x;
			Push(x);
			cout << " Stack sau khi them la : ";
			Process_stack();
			break;
		case 3:
			Pop(x);
			cout << " Phan tu la ra tu stack la x=" << x << endl;
			cout << " Stack sau khi lay ra la : ";
			Process_stack();
			break;
		case 4 :
			cout << " Stack hien tai la : ";
			Process_stack();
			break;
		case 5:
			cout << "GOODBYE ...!" << endl;
			break;
		default : 
			break;
		}
	}while(choice!=5);
	return 0;
}