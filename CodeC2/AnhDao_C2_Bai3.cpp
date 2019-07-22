//Bai 3, Chuong 2: Danh sach lien ket don
#include <stdio.h>
#include <iostream>
using namespace std;

//Cau 3.1: Khai bao cau truc danh sach
struct Node{
	int info;
	Node *link;
};
Node *first;

// Cau 3.2: Khoi tao danh sach rong.
void Init()
{
	first = NULL;
}
// Cau 3.3:  Xuat cac phan tu trong danh sach.
void Process_list()
{
	Node *p;
	p = first;
	while(p != NULL)
	{
		cout << p -> info << "\t";
		p = p -> link;
	}
	cout << endl;
}
//3.4 Tim mot phan tu trong DS
Node *Search(int x)
{
	Node *p = first;
	while(p != NULL && p -> info != x)
		p = p -> link;
	return p;
}
//3.5 Them phan tu vao dau danh sach
void Insert_first(int x)
{
	Node *p;
	p = new Node;
	p -> info = x;
	p -> link = first;
	first = p;
}
//3.6 xoa phan tu dau danh sach
int Delete_first()
{
	if(first != NULL)
	{
		Node *p = first;
		first = first -> link;
		delete p;
		return 1;
	}
	return 0;
}
//3.7 them phan tu cuoi danh sach
void Insert_last(int x)

{
	Node *p;
	p = new Node;
	p -> info = x;
	p -> link = NULL;
	if(first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while (q -> link != NULL)
			q = q -> link;
		q -> link = p;
	}
}
//3.8: xoa phan tu cuoi danh sach
int Delete_last()
{
	if(first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while(p -> link != NULL)
		{
			q = p;
			p = p -> link;
		}
		if(p != first)
			q -> link = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//3.9: Tim phan tu trong danh sach, roi xoa neu co
int SearchAndDelete(int x)
{
	if(first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while(p -> info != x && p -> link != NULL )
		{
			q = p;
			p = p -> link;
		}
		if(p != first && p -> link != NULL)
		{
			//phan tu giua ds
			if(p -> link != NULL)
				q -> link = p -> link;
			else
				q -> link = NULL;
			delete p;
			return 1;
		}
		else
			if(p == first)
			{
				//Phan tu dau ds
				first = p -> link;
				delete p;
				return 1;
			}
			else
				if(p -> link == NULL && p -> info == x)
				{
					//Phan tu cuoi ds
					q -> link == NULL;
					delete p;
					return 1;
				}
				else 
					return 0;
	}
	return 0;
}
//ham hoan doi cho gia tri 2 phan tu
void swap(Node *a, Node *b)
{
	int t = a -> info;
	a -> info = b -> info;
	b -> info = t;
}
//3.10: sap xep danh sach co thu tu tang dan (SV se bo dung sau)
// su dung Selection-Sort
void Sort()
{
	Node *p, *q, *min;
	//Di chuyen ranh gioi cua mang da sap xep va chua sap xep
	p = first;
	while(p != NULL)
	{
		//Tim phan tu nho nhat trong mang chua sap xep
		min = p;
		q = p -> link;
		while(q != NULL)
		{
			if(q -> info < min -> info)
				min = q;
			q = q -> link;
		}
		// Doi cho phan tu nho nhat voi phan tu dau tien
		swap(min, p);
		p = p -> link;
	}
}
// 3.10: sap xep danh sach co co thu tu giam dan (SV se bo sung sau)
//su dung Selection-Sort
void SorDesc()
{
	Node *p, *q, *min;
	//Di chuyen ranh gioi cua mang da sap xep va chua sap xep
	p = first;
	while(p != NULL)
	{
		//Tim phan tu nho nhat trong mang chua sap xep
		min = p;
		q = p -> link;
		while(q != NULL)
		{
			if(q -> info > min -> info)
				min = q;
			q = q -> link;
		}
		// Doi cho phan tu nho nhat voi phan tu dau tien
		swap(min, p);
		p = p -> link;
	}
}
int main()
{
	int choice = 0;
	int x, i;
	Node* p;
	system("cls");
	cout << "------------------Bai tap 3, Chuong 2, Danh sach lien ket don--------------\n";
	cout << "1. Khoi tao DSLK DON rong\n";
	cout << "2. Them phan tu vao dau DSLK DON\n";
	cout << "3. Them phan tu vao cuoi DSLK DON\n";
	cout << "4. Xoa phan tu vao dau DSLK DON\n";
	cout << "5. Xoa phan tu vao cuoi DSLK DON\n";
	cout << "6. Xuat DSLK DON\n";
	cout << "7. Tim mot phan tu gia tri x trong DSLK DON\n";
	cout << "8. Tim phan tu voi gia tri x va xoa no neu co\n";
	cout << "9. Sap xep DSLK DON tang dan\n";
	cout << "10. Sap xep DSLK DON giam dan\n";
	cout << "11. Thoat\n";
	do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			Init();
			cout << "Ban vua khoi tao DSLK DON thanh cong!\n";
			break;
		case 2:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			Insert_first(x);
			cout << "Danh sach sau khi them la: ";
			Process_list();
			break;
		case 3:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			Insert_last(x);
			cout << "Danh sach sau khi them la: ";
			Process_list();
			break;
		case 4:
			i = Delete_first();
			if(i == 0)
				cout << "Danh sach rong, khong the xoa!" << x << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu dau cua DSLK DON!\n";
				cout << "Danh sach sau khi xoa la:";
				Process_list();
			}
			break;
		case 5:
			i = Delete_last();
				if(i == 0)
				cout << "Danh sach rong, khong the xoa!" << x << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu cuoi cua DSLK DON!\n";
				cout << "Danh sach sau khi xoa la:";
				Process_list();
			}
			break;
		case 6:
			cout << "Danh sach hien tai la:";
				Process_list();
			break;
		case 7:
			cout << "Vui long nhap gia tri xan tim x= ";
			cin >> x;
			p = Search(x);
			if(p != NULL)
				cout << "Tim thay phan tu co gia tri x= " << x << endl;
			else
				cout << "Khong tim thay phan tu co gia tri x = " << x << endl;
			break;
		case 8:
			cout << "Vui long nhap gia tri xan tim x= ";
			cin >> x;
			i = SearchAndDelete(x);
			if(i == 1)
			{
				cout << "Da tim thay x = " << x << " va da xoa thanh cong\n";
				cout << "Danh sach sau khi xoa la:";
				Process_list();
			}
			else
				cout << "khong tim thay phan tu co gia tri x= " << x << endl;
			break;
		case 9:
			Sort();
			cout << "Danh sach sau khi sap xep tang dan la: ";
			Process_list();
			break;
		case 10:
			SorDesc();
			cout << "Danh sach sau khi sap xep giam dan la: ";
			Process_list();
			break;
		case 11:
			cout << "Good bye.........!!!" << endl;
			break;
		default:
			break;
		}
	}while(choice != 11);
	system("pause");
	return 0;
}