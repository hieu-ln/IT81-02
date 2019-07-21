#include <iostream>
using namespace std;
#define MAX 100
int sp;
int a[MAX];

void nhap(int a[], int sp)
{
	cout << "Nhap danh sach : "<< endl;
	for(int i = 0; i < sp;i++)
	{
		cout << "\t";
		cin >> a[i];
	}
}
void xuat(int a[], int sp)
{
	cout << "Danh sach xuat ra: " << endl;
	for(int i = 0;i < sp; i++)
	{
		cout << a[i] << "\t";
	}
}
void Insertion(int a[], int sp)
{
	int x;
	int j;
	for(int i = 1; i < sp;i++)
	{
		x = a[i];
		j = i -1;
		while(j >= 0 && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void Selection(int a[], int sp)
{
	int min_pos;
	for(int i = 0; i < sp - 1; i++)
	{
		min_pos = i;
		for(int j = i + 1; j < sp;j++)
		{
			if(a[j] < a[min_pos])
				min_pos = j;
			swap(a[min_pos],a[i]);
		}
	}
}

void Interchange(int a[], int sp)
{
	for(int i = 0;i < sp - 1;i++)
	{
		int j = i + 1;
		while(j <= sp - 1)
		{
			if(a[j] < a[i])
				swap(a[j],a[i]);
			j++;
		}
	}
}

void Bubble(int a[], int sp)
{
	for(int i = 0;i < sp;i++)
	{
		for(int j = sp - 1; j > i;j--)
		{
			if(a[j - 1] > a[j])
				swap(a[j],a[j-1]);
		}
	}
}

void Quick(int a[], int l, int r)
{
	int x = a[(l+r)/2];
	int i = l;
	int j = r;
	while(i < j)
	{
		while(a[i] < x)
			i++;
		while(a[j] > x)
			j--;
		if(i <= j)
		{
			swap(a[i],a[j]);
			i++;j--;
		}
	}
	if(l < j)
		Quick(a,l,j);
	if(i < r)
		Quick(a,i,r);
}
void	shift(int a[], int i, int sp)
{
	int j = 2*i + 1;
	if(j >= sp)
		return;
	if(j + 1 < sp)
		if(a[j] < a[j+1])
			j++;
	if(a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a,j, sp);
	}
}
void Heap(int a[], int sp)
{
	int i = sp/2;
	while(i >= 0)
	{
		shift(a,i,sp-1);
		i--;
	}
	int right = sp - 1;
	while(right > 0)
	{
		swap(a[0],a[right]);
		right--;
		if(right > 0)
			shift(a,0,right);
	}
}


int seachTT(int a[],int sp, int x)
{
	for(int i = 0; i < sp;i++)
	{
		if(x == a[i])
			return i;
	}
	return -1;
}
int seachNP(int a[], int sp, int x)
{
	int left = 0;
	int right = sp - 1;
	while( left <= right)
	{
		int t = (left+right)/2;
		if(x == a[t])
			return t;
		else
		{
			if(x > a[t])
				left = t++;
			right = t--;
		}
	}
	return -1;
}

int main()
{
	int chon, x;

	cout << "Nhap so luong phan tu: ";
	cin >> sp;
	nhap(a,sp);
	cout << endl;
	xuat(a,sp);
	system("pause");
	system("cls");
	
	cout << "1.Insertion_sort sap xep danh sach tang dan." << endl;
	cout << "2.Selection_sort sap xep danh sach tang dan." << endl;
	cout << "3.Interchange_sort sap xep danh sach tang dan." << endl;
	cout << "4.Bubble_sort sap xep danh sach tang dan." << endl;
	cout << "5.Quick_sort sap xep danh sach tang dan." << endl;
	cout << "6.Heap_sort sap xep danh sach tang dan." << endl;
	cout << "7.Tim kiem tuan tu phan tu trong danh sach. " << endl;
	cout << "8.Tim kiem nhi phan phan tu trong danh sach." << endl;
	cout << "9.Thoat\n";

	system("pause");
	system("cls");
	cout << "\t Chon cac muc theo so thu tu: ";
	cin >> chon;
	system("cls");
	while(chon > 0 && chon < 11)
	{
	switch(chon)
	{
	case 1:
		cout << "Nhap so ban muon chen truc tiep: " << endl;
		Insertion(a,sp);
		xuat(a,sp);
		break;
	case 2:
		cout << "Lua chon truc tiep: \n";
		Selection(a,sp);
		xuat(a,sp);
		break;
	case 3:
		cout << "Doi cho truc tiep: \n";
		Interchange(a,sp);
		xuat(a,sp);
		break;
	case 4:
		cout << "Noi bot: \n";
		Bubble(a,sp);
		xuat(a,sp);
		break;
	case 5:
		cout << "Phan hoach: \n";
		Quick(a,0 ,sp);
		xuat(a,sp);
		break;
	case 6:
		cout << "Heap: \n";
		Heap(a,sp);
		xuat(a,sp);
		break;
	case 7:
		cout << "Nhap so can tim theo tuan tu: ";
		cin >> x;
		if(seachTT(a,sp,x))
		{
		cout << "Tim thay so ban can tim o vi tri i = " <<seachTT(a,sp,x) << endl;
		}
		else
			cout << "Khong tim thay" << endl;
		break;
	case 8:
		cout << "Nhap so can tim theo nhi phan: ";
		cin >> x;
		if(seachNP(a,sp,x))
		{
		cout << "Tim thay so ban can tim o vi tri i = " <<seachNP(a,sp,x) << endl;
		}
		else
			cout << "Khong tim thay" << endl;
		break;
	}
	cout << endl << endl ;
	cout << "9. Thoat\n 10.Tiep tuc"<< endl;
	cout << "Ban co muon tiep tuc : ";
	cin >> chon;
	}
	system("pause");
	return 0;
}