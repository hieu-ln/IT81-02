//BT
#include <iostream>

#include <iomanip>

using namespace std;



#define MAX 100

int A[MAX], B[MAX], C[MAX] ;

int n, m;



void nhap(int A[], int &n)

{

	for (int i = 0; i < n; i++)

	{

		cout << "A[" << i << "] = ";

		cin >> A[i];

	}

}

void nhapb(int B[], int &n)

{

	for (int i = 0; i < n; i++)

	{

		cout << "B[" << i << "] = ";

		cin >> B[i];

	}

}

void xuat(int A[], int n)

{

	for (int i = 0; i < n; i++)

	{

		cout << setw(4) << A[i];

	}

	cout<<endl;

}

void Giao(int A[], int B[], int n, int m) 

{ 

	int i = 0, j = 0; 

	while (i < n && j < m) 

	{ 

		if (A[i] < B[j]) 

			i++; 

		else

			if (B[j] < A[i]) 

				j++;

			else

			{

				cout << B[j] << " "; 

			   i++; 

			   j++; 

			}

	}

} 

void Bu(int A[], int B[], int n, int m) 

{ 

    int i = 0, j = 0; 

    while (i < n && j < m) 

    { 

        

        if (A[i] != B[j]) 

        { 

            cout << A[i] << " "; 

            i++; 

        }

		else

        { 

            i++; 

            j++; 

        } 

    } 

} 

int main()

{

	int chon;

	while (true)

	{

		cout << "\nNhap so de thuc thi chuong trinh:\n"

			 << "0. Thoat\n"

	 		 << "1. Nhap vao danh sach A\n"

	 	 	 << "2. Nhap vao danh sach B\n"

	 		 << "3. Xuat ca 2 danh sach\n"

	 		 << "4. Giao 2 danh sach\n"

	 		 << "5. Bu 2 danh sach\n"

	 		 << "Chon: ";

		cin >> chon;

		switch(chon)

		{

		case 0:

			return 1;

			break;

		case 1:

			do

			{

				cout << "Nhap so phan tu cua mang A duoi 100 phan tu: ";

				cin >> n;

				if (n < 0 || n > 100)

					cout << "Nhap sai. Nhap lai\n";

			} while(n < 0 || n > 100);

			nhap(A, n);

			break;

		case 2:

			do

			{

			cout << "Nhap so phan tu cua mang B duoi 100 phan tu: ";

			cin >> m;

			if(m < 0 || m > 100)

				cout << "Nhap sai. Nhap lai\n";

			} while(m < 0 || m > 100);

			nhap(B, m);

			break;

		case 3:

			cout << "Xuat 2 danh sach:\n";

			cout << "Danh sach A:\n";

			xuat(A, n);

			cout<<"Danh sach B:\n";

			xuat(B, m);

			break;

		case 4:

			cout << "Giao 2 danh sach la\n";

			Giao(A, B, n, m);

			break;

		case 5:

			cout << "Bu cua danh sach A\n";

			Bu(A, B, n, m);

		

			cout << "\nBu cua danh sach B\n";

			Bu(B, A, m, n);

			break;

		default:

			cout<<"Gia tri chon khong hop le\n";

			break;

		}

	}

	return 0;

}