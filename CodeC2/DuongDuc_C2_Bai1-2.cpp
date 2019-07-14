//Bai 1 - Chuong 2
#include<iostream>
using namespace std;

#define MAX 100

void Input(int a[], int n){
	for (int i = 0; i < n; i++){
		cout << "Nhap a[" << i << "]: ";
		cin >> a[i];
	}
}

void Output(int a[], int n){
	for (int i = 0; i < n; i++){
		cout << a[i] << "\t";
	}
	cout << endl;
}

int Search(int a[], int n, int x){
	for (int i = 0; i < n; i++){
		if (a[i] == x)
			return 1;
	}
	return 0;      //Do phuc tap O(n)
}

void InsertInLast(int a[], int &n, int x){
	a[n] = x;
	n++;
}

void DeleteLast(int a[], int &n){
	n--;
}

void Delete(int a[], int &n, int x){
	for (int i = x; i < n; i++){
		a[i] = a[i - 1];
	}
	n--;
}

void main(){
	int a[MAX];
	int n, x, choice;

	cout << "=======DANH SACH DAC=======";
	cout << "1.Nhap danh sach\n";
	cout << "2.Xuat cac phan tu trong danh sach\n";
	cout << "3.Tim mot phan tu trong danh sach\n";
	cout << "4.Them mot phan tu vao cuoi danh sach\n";
	cout << "5.Xoa mot phan tu cuoi danh sach\n";
	cout << "6.Tim mot phan tu trong danh sach neu thay, xoa phan tu\n";
	cout << "7.Thoat\n";

	do{
		cout << "Chon: ";
		cin >> choice;
	} while (choice > 0 && choice < 7);

	switch (choice)
	{
	case 1:
		do{
			cout << "Nhap so phan tu: ";
			cin >> n;
		} while (n > 0 && choice < 100);
		Input(a, n);
		break;
	case 2:
		Output(a, n);
		break;
	case 3:
		cout << "Nhap phan tu can tim: ";
		cin >> x;
		if (Search(a, n, x) == 1)
			cout << x << " co trong danh sach\n";
		else
			cout << x << " khong co trong danh sach\n";
		break;
	case 4:
		InsertInLast(a, n, x);
		break;
	case 5:
		DeleteLast(a, n);
		break;
	case 6:
		cout << "Nhap vi tri can xoa: ";
		cin >> x;
		Delete(a, n, x);
		break;
	default:
		break;
	}
}