#include<iostream>
#include<ctime>
#include<stdio.h>

using namespace std;

const int MAX=50;

int n;
int a[MAX];
//Nhap
void nhap(int a[],int &n)

{
	cout << " Nhap vao so luong phan tu cua danh sach : ";
	cin >> n;
	for ( int i=0; i < n ; i++)
	{
		cout << " Hay nhap vao phan tu thu [" << i + 1 <<"]:";
		cin >> a[i];
	}
}
// Khoi tao
void init(int a[], int &n)
{
	cout << " Hay nhap so luong phan tu cua danh sach: ";
	cin >> n;
	for( int i=0; i<n;i++)
	{
		a[i]=rand()%1000+1;
	}
	cout << " Danh sach da duoc nhap ngau nhien nhu sau: ";
	for(int i =0;i<n;i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}
//Xuat
void xuat( int a[], int n)
{
	for ( int i=0; i<n;i++)
	{
		cout << a[i] << "  ";

	}
	cout << endl;
}
//Copy Mang
void copyArray( int a[], int b[],int n)
{
	for(int i=0; i<n;i++)
	{
		b[i]=a[i];
	}
}
// Insertion
void insertionSort(int a[],int n)
{
	int x,i,j;
	for(int i=0;i<n;i++)
	{
		x=a[i];//Bien luu gia tri
		j=i-1;
		while(0<=j&&x<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=a[j];
	}
}
//Hoan doi gia tri
void swap(int &a, int &b)
{
	int c=a;
	a=b;
	b=c;
}
//SelectionSort
void selectionSort( int a[], int n)
{
	int min_pos,j,i;
	for(int i=0;i<n-1;i++)
	{
		min_pos=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[min_pos])
				min_pos=j;
		swap(a[min_pos],a[i]);
	}
}
//Interchange
void interchangeSort ( int a[],int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
				swap(a[i],a[j]);

}
//Bubble
void bubbleSort( int a[], int n)
{
	for( int i=0;i<n-1;i++)
		for(int j=n-1;j>i;j--)
			if(a[j-1]>a[j])
				swap(a[j],a[j-1]);
		
}
void quickSort( int a[], int left, int right)
{
	double x=a[(left+right)/2];
	int i=left;
	int j=right;
	while(i<j)
	{
		while(a[i]<x)
			i++;
		while(a[j]>x)
			j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(left<j) quickSort(a,left,j);
	if(i<right) quickSort(a,i,right);

	}
	
// Heap
void shift( int a[], int i, int n)
{
	int j=2*i+1;
	if(j>=n)
		return;
	if(j+1<n)
		if(a[j]<a[j+1])
			j++;
	if(a[i]>=a[i])
		return;
	else
	{
		int x=a[i];
		a[i]=a[j];
		a[j]=x;
		shift(a,j,n);
	}
	
}
void heapSort(int a[],int n )
{
	int i=n/2;
	while(i>=0)
	{
		shift(a,i,n-1);
			i--;
	}
	int right=n-1;
	while(right>0)
	{
		swap(a[0],a[right]);
			right--;
		if(right>0)
			shift(a,0,right);
	}
}
//tim kiem tuan tu
void searchSequence( int a[], int n, int x)
{
	int i=0;
	while(i< n && a[i]!=x)
	{
		i++;
	}
	if(i==n)
	{
		cout << " Khong tim thay  gia tri !";
	}
	else
	{
		cout << " Tim thay gia tri " << x << " tai vi tri  " << i;

	}
}
//Tim kiem nhi phan
int searchBinary( int a[],int n, int x)
{
	int left=0, right=n-1, mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(a[mid]==x)
			return mid;
		if(x>a[mid])
			left=mid+1;
		else right=mid-1;
	}
	return  -1;
}

//MAIN
int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x,i;
	system("cls");
	cout << " * * * * * Bai tap 1 Chuong 3 Sap Xep Thu tu Va Tim Kiem * * * * * " << endl;
	cout << " 0.Khoi tao danh sach ngau nhien " << endl;
	cout << " 1.Nhap danh sach " << endl;
	cout << " 2.Xuat danh sach " << endl;
	cout << " 3.Xep thu tu bang SelectionSort " << endl;
	cout << " 4.Xep thu tu bang InsertionSort " << endl;
	cout << " 5.Xep thu tu bang BubbleSort " << endl;
	cout << " 6.Xep thu tu bang InterchangeSort " << endl;
	cout << " 7.Xep thu tu bang QuickSort " << endl;
	cout << " 8.Xep thu tu bang HeapSort " << endl;
	cout << " 9.Tim kiem phan tu x bang Tim Kiem Tuan Tu " << endl;
	cout << " 10.Tim kiem phan tu x bang Tim Kiem Nhi Phan " << endl;
	cout << " 11.THOAT" <<endl;
	do {
		cout << " Vui long chon so de thuc hien :";
		cin >> choice;
		switch(choice)
		{
		case 0:
			init(a,n);
			break;
		case 1: 
			nhap(a,n);
			break;
		case 2:
			cout << " Danh sach la : " << endl;
			xuat(a,n);
			break;
		case 3:
			copyArray(a,b,n);
			start=clock();
			selectionSort(b,n);
			duration=(clock()-start)/(double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout << " Danh sach sau khi sap xep voi SelectionSort la: "<< endl;
				xuat(b,n);
			}
			if(duration>0)
				cout << " Thoi Gian SelectionSort: " << duration*1000000 << " Microseconds" << endl;
			break;
			case 4:
				copyArray(a,b,n);
				start=clock();
				insertionSort(b,n);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout << " Danh sach sau khi sap xep voi InsertionSort la: "<< endl;
					xuat(b,n);
				}
				if(duration>0)
					cout << " Thoi Gian InsertionSort: " << duration*1000000 << " Microseconds" << endl;
				break;
			case 5:
				copyArray(a,b,n);
				start=clock();
				bubbleSort(b,n);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout << " Danh sach sau khi sap xep voi BubbleSort la: "<< endl;
					xuat(b,n);
				}
				if(duration>0)
					cout << " Thoi Gian BubbleSort: " << duration*1000000 << " Microseconds" << endl;
				break;
			case 6:
				copyArray(a,b,n);
				start=clock();
				interchangeSort(b,n);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout << " Danh sach sau khi sap xep voi InterchangeSort la: "<< endl;
					xuat(b,n);
				}
				if(duration>0)
					cout << " Thoi Gian InterchangeSort: " << duration*1000000 << " Microseconds" << endl;
				break;
			case 7:
				copyArray(a,b,n);
				start=clock();
				quickSort(b,0,n-1);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout << " Danh sach sau khi sap xep voi QuickSort la: "<< endl;
					xuat(b,n);
				}
				if(duration>0)
					cout << " Thoi Gian QuickSort: " << duration*1000000 << " Microseconds" << endl;
				break;
			case 8:
				copyArray(a,b,n);
				start=clock();
				heapSort(b,n);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout << " Danh sach sau khi sap xep voi HeapSort la: "<< endl;
					xuat(b,n);
				}
				if(duration>0)
					cout << " Thoi Gian HeapSort: " << duration*1000000 << " Microseconds" << endl;
				break;
			case 9:
				cout << " Vui long nhap gia tri x =";
				cin >> x;
				start=clock();
				searchSequence(a,n,x);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(duration>0)
					cout << " Thoi Gian Tim Kiem Tuan Tu La: " << duration*1000000 << " Microseconds" << endl;
				break;
			case 10:
				cout << " Vui long nhap gia tri x =";
				cin >> x;
				start=clock();
				i=searchBinary(a,n,x);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(i==-1)
					cout << " Khong tim thay " << x << " trong day !" <<endl;
				else
					cout << " Tim thay " << x << " tai vi tri : " << i + 1 << " trong day !" << endl;
				if(duration>0)
					cout << " Thoi Gian Tim Kiem Nhi Phan La: " << duration*1000000 << " Microseconds" << endl;
				break;
			case 11: 
				cout << " GoodBye...!" << endl;
				break;
			default: 
				break;
		}
	}while(choice!=11);
	return 0;	


}