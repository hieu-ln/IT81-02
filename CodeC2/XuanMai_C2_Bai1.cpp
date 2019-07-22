#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 100
int a[MAX];
int n;
void nhap(int a[], int &n);
void xuat(int a[], int n);
int timkiem(int a[], int n, int x);
int themcuoi(int a[], int &n, int x);
int xoacuoi(int a[], int &n);
int xoa(int a[], int &n, int i);
int timxoa(int a[], int &n, int x);
int main()
{
	
	int x, i, choice;
	system("cls");
	cout << "---------------MENU---------------\n";
	cout << "1. Nhap danh sach\n";
	cout << "2. Xuat danh sach\n";
	cout << "3. Tim 1 phan tu\n";
	cout << "4. Them phan tu vao cuoi danh sach";
	cout << "5. Xoa phan tu cuoi danh sach\n";
	cout << "6. Xoa phan tu tai 1 vi tri\n";
	cout << "7. Tim 1 phan tu va xoa phan tu do\n";
	cout << "8. Thoat\n";
	do {
				cout << "Vui long chon so de thuc hien: ";
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "Nhap so luong phan tu cua danh sach: ";
					cin >> n;
					nhap(a, n);
					cout << "Nhap danh sach thanh cong!\n";
					break;
				case 2:
					cout << "Danh sach hien tai:\n";
					xuat(a, n);
					break;
				case 3:
					cout << "Nhap x can tim:";
					cin >> x;
					i = timkiem(a, n, x);
					if (i == -1)
						cout << "Khong tim thay phan tu " << x << endl;
					else 
						cout << "Tim thay " << x << " tai vi tri " << i << endl;
					break;
				case 4:
					cout << "Nhap phan tu can them vao cuoi x = ";
					cin >> x;
					i = themcuoi(a, n, x);
					if (i == 0)
						cout << "Danh sach da day, khong the them\n";
					else
						cout << "Da them " << x << " vao cuoi danh sach\n";
					break;
				case 5:
					i = xoacuoi(a, n);
					if (i > 0)
						cout << "Xoa thanh cong\n";
					else
						cout << "Danh sach rong, khong the xoa\n";
					break;
				case 6:
					cout << "Nhap vi tri can xoa: ";
					cin >> i;
					i = xoa(a, n, i);
					if (i == 1)
						cout << "Xoa thanh cong\n";
					else
						cout << "Khong co phan tu nao de xoa\n";
					break;
				case 7:
					cout << "Nhap phan tu can tim va xoa:\n";
					cin >> x;
					i = timxoa(a, n, x);
					if (i == 1)
						cout << "Xoa thanh cong\n";
					else
						cout << "Khong tim thay phan tu\n";
					break;
				case 8:
					cout << "Chuong trinh ket thuc\n";
					break;
				default:
					break;
				}
			} while (choice != 8);
			system("pause");
			return 0;
	}

void nhap(int a[], int &n)
{
	cout << "Nhap danh sach:\n";
	for(int i=0; i<n; i++)
	{
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}
void xuat(int a[], int n)
{
	for(int i=0; i<n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
int timkiem(int a[], int n, int x)
{
	int i=0;
	while ((i < n) && (a[i] != x)) {
		i++;
		if (i == n)
			return -1;
	}
	return i;
}
int themcuoi(int a[], int &n, int x)
{
	if(n>=0 && n < MAX)
	{
		a[n]= x;
		n++;
		return 1;
	}
	return 0;
}
int xoacuoi(int a[], int &n)
{
	if(n > 0)
	{
		n--;
		return 1;
	}
	return 0;
}
int xoa(int a[], int &n, int i)
{
	if(i >=0 && i < n)
	{
		for(int j = i; j < n - 1; j++)
			a[j] = a[j + 1];
		n--;
		return 1;
	}
	return 0;
}
int timxoa(int a[], int &n, int x)
{
	if (timkiem(a, n, x) == -1)
		return 0;
	if(xoa(a, n, timkiem(a, n, x)))
		return 1;
}