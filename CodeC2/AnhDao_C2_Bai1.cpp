//Bai tap 1: Quan li danh sach toi da 100 phan tu.
#include <iostream>
using namespace std;
//1.1Khai bao cau truc danh sach.
#define MAX 100
int a[MAX];
int n;
//1.2 Nhap danh sach
void input(int a[], int &n)
{
	cout << "Nhap so luong phan tu trong danh sach: ";
	cin >> n;
	cout << "Nhap cac phan tu trong danh sach: ";
	for(int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i + 1 << "] = ";
		cin >> a[i];
	}
}
//1.3 Xuat danh sach.
void output(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
//1.4 Tim phan tu trong danh sach.
int search(int a[], int n, int x)
{
	int i = 0;
	if(n > 0 && n < MAX)
		while(i < n && a[i] != x)
		{
			i++;
			if(i == n)
			   return -1;
		}
		return i;
}
//1.5 Them mot phan tu vao cuoi danh sach.
int insertLast(int a[], int &n, int x)
{
	if(n < MAX && n > 0)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else
		return 0;
}
// 1.6 Xoa phan tu cuoi danh sach.
int deleteLast(int a[], int &n)
{
	if(n > 0 && n < MAX)
	{
		n--;
		return 1;
	}
	return 0;
}
//1.7 Xoa phan tu tai vi tri thu i
int deleteI(int a[], int &n, int i)
{
	if(n > 0)
	{
		if(i >= 0 && i < n)
		{
			for(int j = i; j < n -1; j++)
				a[j] = a[j + 1];
			n--;
			return 1;
		}
		return 0;
	}
}
//1.8 Tim mot phan tu neu thay thi xoa
int searchAndDelete(int a[], int &n, int x)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] == x)
		{
			deleteI(a,n,i);
			return 1;
		}
	}
	return 0;
}
int main()
{
	int choice, x, i;
	system("cls");
	cout << "------------Bai tap 1_Chuong 2_AnhDao----------------\n";
	cout << "1. Nhap danh sach\n";
	cout << "2. Xuat danh sach\n";
	cout << "3. Tim mot phan tu trong danh sach.\n";
	cout << "4. Them mot phan tu vao cuoi danh sach.\n";
	cout << "5. Xoa mot phan tu vao cuoi danh sach.\n";
	cout << "6. Xoa phan tu tai vi tri thu i.\n";
	cout << "7. Tim mot phan tu va neu co thi xoa phan tu do.\n";
	cout << "8. Thoat\n";
	do{
		cout << "Vui long chon lenh can thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1: 
			input(a,n);
			cout << "Ban da nhap thanh cong.\n";
			break;
		case 2:
			if(n > 0 && n < MAX)
			{
				cout << "Danh sach la: ";
				output(a,n);
			}
			break;
		case 3:
			if(n > 0 && n < MAX)
			{
				cout << "Vui long nhap so can tim: ";
				cin >> x;
				i = search(a,n,x);
				if(i == -1)
					cout << "Khong tim thay x = " << x << " trong danh sach.\n";
				else
					cout << "Tim thay x = " << x << " trong danh sach tai vi tri " << i + 1 << endl;
			}
			break;
		case 4:
			if(n > 0 && n < MAX)
			{
				cout << "Vui long nhap so can them vao danh sach: ";
				cin >> x;
				i = insertLast(a,n,x);
				if(i == 0)
					cout << "Danh sach da day, khong the them!\n";
				else
				{
					cout << "Da them phan tu x = " << x << " vao cuoi danh sach/n";
					cout << "Danh sach sau khi them cuoi./n";
					output(a,n);
				}
			}
			break;
		case 5:
			if(n > 0 && n < MAX)
			{
				i = deleteLast(a,n);
				if(i > 0)
				{
					cout << "Ban da xoa thanh cong!\n";
					cout << "Danh sach sau khi xoa.\n";
					output(a,n);
				}
				else
					cout << "Danh sach rong khong xoa duoc.\n";
			}
			break;
		case 6:
			if( n >= 0 && n < MAX)
			{
				cout << "Vui long nhap vi tri can xoa: ";
				cin >> x;
				i = deleteI(a,n,x);
				if( i == 1)
				{
					cout << "Xoa thanh cong!\n";
					cout << "Danh sach sau khi xoa!\n";
					output(a,n);
				}
				else
					cout << "Khong tim thay phan tu nao de xoa\n";
				break;

			}
		case 7:
			if( n >= 0 && n < MAX)
			{
				cout << "Vui long nhap gia tri can xoa: ";
				cin >> x;
				i = searchAndDelete(a,n,x);
				if(i == 1)
				{
					cout << "Xoa thanh cong phan tu x = " << x << endl;
					cout << "Danh sach sau khi xoa./n";
					output(a,n);
				}
				else
					cout << "Khong tim thay phan tu can xoa.\n";
				break;
			}
		case 8:
			cout << "Good bye.............!!!!\n";
			break;
		default:
			break;
		}
	}while(choice != 8);
	system ("pause");
	return 0;
}