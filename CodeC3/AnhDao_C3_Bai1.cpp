//Quan li danh sach dac 100 phan tu kieu so nguyen
#include <iostream>
#include <ctime>
#include <time.h>;
using namespace std;

//1.1 khoi tao
#define MAX 2000
int a[MAX];
int n;
// Tao danh sach tu dong
void init(int a[], int &n)
{
	cout << "Nhap so luong phan tu ";
	cin >> n;
	for (int i = 0; i < n; i++)
		a[i] = rand() % 1000 + 1;
	cout << "Ham duoc khoi tao la:\n";
	{
		for(int i = 0; i< n; i++)
			cout << a[i] << "\t";
		cout << endl;
	}

}

//1.2Nhap danh sach
void input(int a[], int &n)
{
	cout << "Nhap vao so luong phan tu:";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "a[ " << i << "] =";
		cin >> a[i];
	}
}

//1.3 xuat danh sach
void output(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}

//Ham copy mang
void CopyArray(int a[], int b[], int n)
{
	for(int i = 0; i < n; i++)
		b[i] = a[i];
}

//1.4 Insertion Sort
void InsertionSort(int a[], int n)
{
	int x,j;
	for(int i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while(0 <= j && x < a[i])
		{
			a[j + 1] = a[j];
			j= j - 1;
		}
		a[j+1] = x;
	}
}

//Ham doi cho 2 so nguyen
void swap(int &a, int &b)
{
	int t = a;
	a = b; 
	b = t;
}

//1.5 Selection Sort
void SelectionSort (int a[], int n)
{
	int min_pos;
	for(int i = 0; i < n-1; i++)
	{
		min_pos = i;
		for(int j = i + 1; j < n; j++)
			if(a[j] < a[min_pos])
				min_pos = j;
		swap(a[min_pos], a[i]);
	}
}

//1.6 Interchange Sort
void InterchangeSort(int a[], int n)
{
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] > a[j])
				swap(a[i],a[j]);
}

//1.7 Bubble Sort
void BubbleSort(int a[], int n)
{
	bool haveSwap = false;
	for(int i = 0; i < n-1; i++)
	{
		haveSwap = false;
		for(int j = n-1; j > i; j--)
		{
			if(a[j - 1] > a[j])
			{
				swap(a[j], a[j - 1]);
				haveSwap = true;
			}
		}
		if(haveSwap == false)
			break;
	}
}

//1.8 Quick Sort
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while(i < j)
	{
		while(a[i] < x)
			i++;
		while(a[j] > x)
			j--;
		if(i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
		if(left < j) QuickSort(a, left, j);
		if(i < right)
			QuickSort(a,i ,right);
}

//1.9 Heap Sort
//
void shift(int a[], int i, int n)
{
	int j = 2*i+1;
	if(j >= n)
		return;
	if(j + 1 < n)
		if(a[j] < a[j + 1])
			j++;
	if(a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift (a, j, n);
	}
}
//Thuc thi Heap Sort
void HeapSort(int a[], int n)
{
	int i = n/2;
	while(i >= 0)
	{
		shift(a, i, n - 1);
			i--;
	}
	int right = n - 1;
	while(right > 0)
	{
		swap(a[0], a[right]);
		right--;
		if(right > 0)
			shift(a,0,right);
	}
}

//1.10 Tim kiem tuan tu
void SearchSequence(int a[], int n, int x)
{
	int i = 0;
	while(i < n && a[i] != x)
		i++;
	if(i == n)
		cout << "Khong tim thay x = " << x << " trong day.\n";
	else
			cout << "Tim thay x = " << x << " trong day tai vi tri "<< i +1 << endl;
}

//1.12 Tim kiem nhi phan
int BinarySearch(int a[], int n, int x)
{
	int left = 0, right = n - 1, mind;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		if(a[mid] == x)
			return mid;
		if(x > a[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

// Main
int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout << "-----------Bai tap 1_ Chuong 3-----------" << endl;
	cout << "1. Khoi tao danh sach ngau nhien\n";
	cout << "2. Nhap danh sach\n";
	cout << "3. Xuat danh sach\n";
	cout << "4. Sap xep danh sach tang dan voi Insertion Sort\n";
	cout << "5. Sap xep danh sach tang dan voi Selection Sort\n";
	cout << "6. Sap xep danh sach tang dan voi Interchange Sort\n";
	cout << "7. Sap xep danh sach tang dan voi Bubble Sort\n";
	cout << "8. Sap xep danh sach tang dan voi Quick Sort\n";
	cout << "9. Sap xep danh sach tang dan voi Heap Sort\n";
	cout << "10. Tiem kiem theo phuong phap tuan tu\n";
	cout << "11. Tiem kiem theo phuong phap nhi phan\n";
	cout << "12. Thoat\n";
	do{
		cout << "Vui long chon phuong thuc thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init(a,n);
			break;
		case 2:
			input(a,n);
			break;
		case 3:
			cout << "Danh sach la:";
			output(a,n);
			break;
		case 4:
			CopyArray(a,b,n);
			start = clock();
			InsertionSort(b,n);
			duration =(clock() - start) / (double) CLOCKS_PER_SEC;
			if(n < 100)
			{
				cout << "Danh sach sau khi sap xep voi Insertion Sort la:";
				output(b,n);
			}
			if(duration > 0)
				cout << "Thoi gian Insertion Sort la: " << duration * 1000000;
			break;
		case 5:
			CopyArray(a,b,n);
			start = clock();
			SelectionSort(b,n);
			duration =(clock() - start) / (double) CLOCKS_PER_SEC;
			if(n < 100)
			{
				cout << "Danh sach sau khi sap xep voi Selection Sort la:";
				output(b,n);
			}
			if(duration > 0)
				cout << "Thoi gian Selection Sort la: " << duration * 1000000;
			break;
		case 6:
			CopyArray(a,b,n);
			start = clock();
			InterchangeSort(b,n);
			duration =(clock() - start) / (double) CLOCKS_PER_SEC;
			if(n < 100)
			{
				cout << "Danh sach sau khi sap xep voi InterChange Sort la:";
				output(b,n);
			}
			if(duration > 0)
				cout << "Thoi gian InterChange Sort la: " << duration * 1000000;
			break;
		case 7:
			CopyArray(a,b,n);
			start = clock();
			BubbleSort(b,n);
			duration =(clock() - start) / (double) CLOCKS_PER_SEC;
			if(n < 100)
			{
				cout << "Danh sach sau khi sap xep voi Bubble Sort la:";
				output(b,n);
			}
			if(duration > 0)
				cout << "Thoi gian Bubble Sort la: " << duration * 1000000;
			break;
		case 8:
			CopyArray(a,b,n);
			start = clock();
			QuickSort(b,0,n-1);
			duration =(clock() - start) / (double) CLOCKS_PER_SEC;
			if(n < 100)
			{
				cout << "Danh sach sau khi sap xep voi Quick Sort la:";
				output(b,n);
			}
			if(duration > 0)
				cout << "Thoi gian Quick Sort la: " << duration * 1000000000;
			break;
		case 9:
			CopyArray(a,b,n);
			start = clock();
			HeapSort(b,n);
			duration =(clock() - start) / (double) CLOCKS_PER_SEC;
			if(n < 100)
			{
				cout << "Danh sach sau khi sap xep voi Heap Sort la:";
				output(b,n);
			}
			if(duration > 0)
				cout << "Thoi gian Heap Sort la: " << duration * 1000000;
			break;
		case 10:
			cout << "Vui long nhap gia tri can tim: ";
			cin >> x;
			start = clock();
			SearchSequence(a,n,x);
			duration =(clock() - start) / (double) CLOCKS_PER_SEC;
			if(duration > 0)
				cout << "Thoi gian tim kiem tuan tu la: " << duration * 1000000;
			cout << endl;
			break;
		case 11:
			cout << "Vui long nhap gia tri can tim: ";
			cin >> x;
			start = clock();
			i = BinarySearch(a,n,x);
			duration =(clock() - start) / (double) CLOCKS_PER_SEC;
			if(i == -1)
				cout << "Khong tim thay x = " << x << " trong day.\n";
			else
				cout << "Tim thay x = " << x << " trong day.\n";
			if(duration > 0)
				cout << "Thoi gian tim kiem nhi phan la: " << duration * 1000000;
			cout << endl;
			break;
		case 12:
			cout << "Good bye......!!!!!!!\n";
			break;
		default:
			break;
		}
	}while(choice != 12
		);
	system("pause");
	return 0;
}




