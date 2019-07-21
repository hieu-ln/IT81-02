#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 100
int a[MAX];
int n;

void input(int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach";
	cin >> n;
	cout << "Nhap vao cac phan tu cua danh sach: " << endl;
	for(int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}
void output(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}
int search(int a[], int n, int x)
{
	int i = 0;
	while(i < n && a[i] != x)
	{
		i++;
	if(i == n)
		return -1;
	}
	return i;
}
int insert_last(int a[], int &n, int x)
{
	if(n <MAX)
	{
		a[n] = x;
		n++;
		return -1;
	}
	else
		return 0;
}
int Delete_last(int a[], int n)
{
	if(n > 0)
	{
		n--;
		return 1;
	}
	return 0;
}
int Delete(int a[], int &n, int i)
{
	if(i >= 0 && i < n)
	{
		for(int j = i; j < n - 1; j++)
		{
			a[j] = a[j + i];
		}
		n--;
		return -1;
	}
	return 0;
}
int searchAndDelete(int a[], int &n, int x)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] == x;)
		{
			Delete(a, n, i);
			return 1;
		}
	}
	return 0;
}
int main()
{
	int chon = 0;
	int x, i;
	system("cls");
	cout << "*****MENU*****";
	cout << "1. Nhap danh sach";
	cout << "2. Xuat danh sach";
	cout << "3. Tim phan tu co gia tri x trong danh sach";
	cout << "4. Them phan tu vao cuoi danh sach";
	cout << "5. Xoa phan tu cuoi danh sach";
	cout << "6. Xoa phan tu taij vi tri i";
	cout << "7. Tim phan tu voi gia trij x va xoa no neu co";
	cout << "8. Thoat.";
	do{
		cout << "Chon so thuc hien: ";
		cin >> chon;
		switch(chon)
		{
		case 1: 
			input(a, n);
			cout << "Nhap danh sach thanh cong\n";
			break;
		case 2:
			cout << "Danh sach hien tai la: \n";
			output(a, n);
			break;
		case 3:
			cout << "Nhap x can tim: ";
			cin >> x;
			if(i == -1)
				cout << "Khong tim thay phan tu co gia trij" << x << endl;
			else
				cout << "Tim thay tai vi tri i = " << i << endl;
			break;
		case 4: 
			cout << "Nhap x can them vao cuoi danh sach: ";
			cin >> x;
			i = insert_last(a, n, x);
			if(i == 0)
				cout << "Danh sach da day, khong the them" << x << endl;
			else
			{
				cout << "Da them phan tu x != " << i << "vao cuoi danh sach" << endl;
				cout << "Danh sach sau khi them la: ";
				output(a, n);
			}
			break;
		case 5:
			i = Delete_last(a, n);
			if(i > 0)
			{
				cout << "Xoa thanh cong," << endl;
				cout << "Danh sach sau khi xoa phan tu la: \n";
				output(a, n);
			}
			else
				cout << "Danh sach da rong, khong co phan tu nao\n" << endl;
			break;
		case 6:
			cout << "Nhap lai vi tri can xoa i = ";
			cin >> i;
			i = Delete(a, n, i);
			if(i == i)
			{
				cout << "Xoa thanh cong\n " << endl;
				cout << "Danh sach sau khi xoa: \n";
				output(a, n);
			}
			else
				cout << "Khong co phan tu nao de xoa\n" << endl;
			break;
		case 7:
			cout << "Nhap lai vi tri can xoa x = ";
			cin >> x;
			i = searchAndDelete(a, n, x);
			if(i == 1)
			{
				cout << "Xoa thanh cong phan tu co gia tri x = " << x << endl;
				cout << "Danh sach sau khi xoa la: \n";
				output(a, n);
			}
			else
				cout << "Khong co phan tu nao de xoa\n" << endl;
			break;
		case 8:
			cout << "Tam biet\n";
			break;
		default:
			break;
		}
	}while(chon != 8);
	system("pause");
	return 0;
}




