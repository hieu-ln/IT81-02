//Bai 5-6 chuong 2
#include<stdio.h>
#include<iostream>

using namespace std;

const int MAX= 100;


//Khoi tao
void init (int a[], int &sp)
{
	sp=-1;
}
//Kiem tra ngan xep rong
int isEmpty(int a[], int sp)
{
	if(sp==-1)
		return 1;
	return 0;
}
//Kiem tra ngan xep day
int isFull(int a[], int sp)
{
	if(sp==MAX-1)
		return 1;
	return 0;
}
//Them phan tu vao ngan xep
int Push( int a[], int &sp, int x)
{
	if(sp<MAX-1)
	{
		a[++sp]=x;
		return 1;
	}
	return 0;
}
// Xoa 1 phan tu 
int Pop ( int a[], int &sp, int &x)
{
	if(sp!=-1)
	{
		x=a[sp--];
		return 1;
	}
	return 0;
}
// Xuat stack
void Process_stack( int a[], int sp)
{
	for( int i=0; i < sp+1;i++)
	{
		cout << a[i] << "\t";

	}
	cout << endl;
}
int convert(int songuyen, int a[], int sp)
{
	init(a,sp);
	int nhiphan=0;
	while(songuyen!=0)
	{
		int phandu=songuyen%2;
		if(Push(a,sp,phandu))
			songuyen /=2;
		else
			break;
	}
	while(!isEmpty(a,sp))
	{
		int x;
		if(Pop(a,sp,x))
			nhiphan=nhiphan*10 + x;
		else
			break;
	}
	return nhiphan;
}
int main()
{
	int a[MAX];
	int choice,sp,x,i;
	int songuyen;
	system("cls");
	cout << " Bai tap 5 chuong 2 stack" << endl;
	cout << " 1.Khoi tao danh sach rong " << endl;
	cout << " 2.Them phan tu vao stack" << endl;
	cout << " 3.Lay phan tu  ra khoi stack " << endl;
	cout << " 4.Kiem tra stack co rong hay khong " << endl;
	cout << " 5.Kiem tra stack co day hay khong " << endl;
	cout << " 6.Xuat Stack " << endl;
	cout << " 7. Chuyen doi so thap phan sang nhi phan " << endl;
	cout << " 8.Thoat " << endl;
	do{
		cout << " \n Vui long cho so de thuc hien : ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init(a,sp);
			cout << " Ban vua khoi tao Stack rong thanh cong ~ \n";
			break;
		case 2:
			cout << " Vui long nhap gia tri x=";
			cin >> x;
			i=Push(a,sp,x);
			cout << " Stack sau khi them la: ";
			Process_stack(a,sp);
			break;
		case 4:
			i=isFull(a,sp);
			if(i==0)
				cout << " Stack chua day ! " << x << endl;
			else
				cout << " Stack da day ! " << endl;
			break;
		case 5:
			i=isEmpty(a,sp);
			if(i==0)
				cout << " Stack khong rong ! " << x << endl;
			else
				cout << " Stack rong ! " << endl;
			break;
		case 6 :
			cout << "Stack hien tai la : ";
			Process_stack(a,sp);
			break;
		case 7:
			cout << " Hay nhap so nguyen can chuyen doi : ";
			cin >> songuyen;
			cout << " Gia tri nhi phan la : " << convert(songuyen,a,sp) << endl;
			break;
		case 8 : 
			cout << " Goodbye ... ! " << endl;
			break;
		default:
			break;
		}
	}while(choice!=7);
	return 0;
}