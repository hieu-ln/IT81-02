#include <iostream>
using namespace std;
#define MAX 100

void init(int a[], int &sp);
int isEmpty(int a[], int sp);
int isFull(int a[], int sp);
int Push(int a[], int &sp, int x);
int Pop(int a[], int &sp, int &x);
void Process_stack(int a[], int sp);
int Convert(int so, int a[], int sp);
int main()
{
	int a[MAX];
	int sp, x, i;
	int choice;
	system("cls");
	cout << "-----------MENU-----------\n";
	cout << "1. Khoi tao Stack rong\n";
	cout << "2. Kiem tra Stack co rong hay khong\n";
	cout << "3. Kiem tra Stack co day hay khong\n";
	cout << "4. Them 1 phan tu vao Stack\n";
	cout << "5. Lay 1 phan tu ra khoi Stack\n";
	cout << "6. Xuat Stack\n";
	cout << "7. Chuyen tu thap phan sang nhi phan\n";
	cout << "8. Thoat\n";
	do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init(a, sp);
			cout << "Khoi tao Stack thanh cong\n";
			break;
		case 2: 
			if(isEmpty(a,sp))
				cout << "Stack rong!\n";
			else
				cout << "Stack khong rong\n";
			break;
		case 3:
			if(isFull(a,sp))
				cout << "Stack da day!\n";
			else
				cout << "Stack chua day\n";
			break;
		case 4:
			cout << "Nhap phan tu can them vao Stack x = ";
			cin >> x;
			i = Push(a, sp, x);
			cout << "Stack sau khi them la: ";
			Process_stack(a, sp);
			break;
		case 5: 
			i= Pop(a, sp, x);
			cout << "Phan tu lay ra tu Stack x= " << x << endl;
			cout << "Stack sau khi lay ra la: ";
			Process_stack(a, sp);
			break;
		case 6:
			cout << "Stack hien tai la: ";
			Process_stack(a, sp);
			break;
			int tp;
		case 7:
			cout << "Nhap gia tri he thap phan can chuyen: ";
			cin >> tp;
			cout << "Gia tri nhi phan la: " << Convert(tp, a, sp) << endl;
			break;
		case 8: 
			cout << "Chuong trinh ket thuc...\n";
			break;
		default:
			break;
		}
	} while(choice!=8);
	system("pause");

}
void init(int a[], int &sp)
{
	sp= -1;
}
int isEmpty(int a[], int sp)
{
	if(sp==-1)
		return 1;
	return 0;
}
int isFull(int a[], int sp)
{
	if(sp==MAX - 1)
		return 1;
	return 0;
}
int Push(int a[], int &sp, int x)
{
	if(sp < MAX - 1) {
		a[++sp] = x;
		return 1;
	}
	return 0;
}
int Pop(int a[], int &sp, int &x)
{
	if(sp!= -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
void Process_stack(int a[], int sp)
{
	for(int i=0; i<sp+1; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}
int Convert(int so, int a[], int sp)
{
	init(a, sp);
	int np = 0;
	while(so!=0)
	{
		int du = so % 2;
		if (Push(a, sp, du))
			so /= 2;
		else
			break;
	}
	while (!isEmpty(a, sp))
	{
		int x;
		if(Pop(a, sp , x))
			np = np * 10 + x;
		else
			break;
	}
	return np;
}