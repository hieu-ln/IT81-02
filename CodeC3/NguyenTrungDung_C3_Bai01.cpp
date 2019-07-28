#include <iostream>
#include <ctime>
using namespace std;

//1.1
#define max 1000
int a[max];
int n;
//1.2
	//khoi tao ngau nhien
void Init(int a[], int &n)
{
	cout << "Nhap sluong ptu: ";
	do{
		cin >> n;
		if (n < 0 || n > max)
			cout << "Nhap n tu 1 - " << max << ". nhap lai: ";
	} while(n < 0 || n > max);
	for (int i = 0; i < n; i++)
		a[i] = rand() % 1000;
	cout << "Danh sach vua khoi tao ngau nhien la:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
	//Khoi tao bang cach nhap
void Input(int a[], int &n)
{
	cout << "Nhap sluong ptu: ";
	do{
		cin >> n;
		if (n < 0 || n > max)
			cout << "Nhap n tu 1 - " << max << ". nhap lai: ";
	} while(n < 0 || n > max);
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}
//1.3
void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
//ham hoan doi
void Swap(int &a, int &b)
{
	int tam = a;
	a = b; 
	b = tam;
}
//1.4
void InsertionSort(int a[], int n)
{
	int i, j, key;
	for (i = 0; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}
//1.5
void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		Swap(a[min], a[i]);
	}
}
//1.6
void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[i])
				Swap(a[i], a[j]);
}
//1.7
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i; j < n - 1; j++)
			if (a[j] > a[j + 1])
				Swap(a[j + 1], a[j]);
}
//1.8
void QuickSort(int a[], int l, int r)
{
	int x = a[(l + r) / 2];
	int i = l, j = r;
	while (i < j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			Swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (i < r)
		QuickSort(a, i, r);
	if (j > l)
		QuickSort(a, l, j);
}
//1.9
void shift(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if (j >= n)
		return;
	if (j + 1 < n)
		if (a[j] < a[j + 1])
			j++;
	if (a[i] >= a[j])
		return;
	else
	{
		Swap(a[i], a[j]);
		shift(a, j, n);
	}
}
void HeapSort(int a[], int n)
{
	int i = n / 2;
	while (i >= 0)
	{
		shift(a, i, n - 1);
		i--;
	}
	int r = n - 1;
	while (r > 0)
	{
		Swap(a[0], a[r]);
		r--;

		if (r > 0)
			shift(a, 0, r);
	}
}
//1.10
int Search(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return i;
	return 0;
}
//1.11
int BinarySearch(int a[], int n, int x)
{
	int l = 0, r = n - 1, m;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (a[m] == x)
			return m;
		else
			if (a[m] > x)
				l = m + 1;
			else
				r = m - 1;
	}
	return 0;
}

//menu
void menu()
{
	cout << "------CHUONG 3 - BAI 1------" << endl;
	cout << "1. Khoi tao danh sach ngau nhien" << endl;
	cout << "2. Nhap danh sach" << endl;
	cout << "3. Xuat danh sach" << endl;
	cout << "4. Sap xep danh sach bang thuat toan InsertionSort" << endl;
	cout << "5. Sap xep danh sach bang thuat toan SelectionSort" << endl;
	cout << "6. Sap xep danh sach bang thuat toan interchangeSort" << endl;
	cout << "7. Sap xep danh sach bang thuat toan BubbleSort" << endl;
	cout << "8. Sap xep danh sach bang thuat toan QuickSort" << endl;
	cout << "9. Sap xep danh sach bang thuat toan HeapSort" << endl;
	cout << "10. Tim kiem 1 ptu trong danh sach dung pp tim kiem tuan tu" << endl;
	cout << "11. Tim kiem 1 ptu trong danh sach dung pp tim kiem nhi phan" << endl;
	cout << "0. Thoat" << endl;
}
void main()
{
	int choice, x, kq;
	srand(time(NULL));
	menu();
	do{
		cout << "Chon 1 so de thuc hien: ";
		cin >> choice;
		cout<<endl;
		switch(choice)
		{
		case 1:
			Init(a, n);
			cout<<endl;
			break;
		case 2:
			Input(a, n);
			cout<<endl;
			break;
		case 3:
			cout << "Danh sach hien tai la:\n";
			Output(a, n);
			cout<<endl;
			break;
		case 4:
			InsertionSort(a, n);
			cout << "Danh sach sau khi sap xep la:\n";
			Output(a, n);
			cout<<endl;
			break;
		case 5:
			SelectionSort(a, n);
			cout << "Danh sach sau khi sap xep la:\n";
			Output(a, n);
			cout<<endl;
			break;
		case 6:
			InterchangeSort(a, n);
			cout << "Danh sach sau khi sap xep la:\n";
			Output(a, n);
			cout<<endl;
			break;
		case 7:
			BubbleSort(a, n);
			cout << "Danh sach sau khi sap xep la:\n";
			Output(a, n);
			cout<<endl;
			break;
		case 8:
			QuickSort(a, 0, n - 1);
			cout << "Danh sach sau khi sap xep la:\n";
			Output(a, n);
			cout<<endl;
			break;
		case 9:
			HeapSort(a, n);
			cout << "Danh sach sau khi sap xep la:\n";
			Output(a, n);
			cout<<endl;
			break;
		case 10:
			cout << "Nhap gtri can tim: ";
			cin >> x;
			kq = Search(a, n, x);
			if (kq != 0)
				cout << "Tim thay gtri x = " << x << " tai vi tri i = " << kq << endl;
			else
				cout << "Khong tim thay gtri x = " << x << endl;
			cout<<endl;
			break;
		case 11:
			cout << "Nhap gtri can tim: ";
			cin >> x;
			kq = BinarySearch(a, n, x);
			if (kq != 0)
				cout << "Tim thay gtri x = " << x << " tai vi tri i = " << kq << endl;
			else
				cout << "Khong tim thay gtri x = " << x << endl;
			cout<<endl;
			break;

		default:
			cout << "Goodbye" << endl;
			break;
		}
	} while(choice != 0);
}