#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node *first;
void init()
{
	first = NULL;
}
void Process_list()
{
	Node *p;
	p = first;
	while(p != NULL)
	{
		cout << p->info << "t";
		p = p->link;
	}
	cout << endl;
}
Node *search(int x)
{
	Node *p = first;
	while(p != NULL && p->info != x)
	{
		p = p->link;
	}
	cout << endl;
}
void insert_first(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}
void Delete_first()
{
	if(first != NULL)
	{
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
void insert_last(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if(first == NULL)
	{
		first = p;
	}
	else
	{
		Node *q = first;
		while(q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}
int Delete_last()
{
	if(first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while(p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if(p != first)
		{
			q->link = NULL;
		}
		else
			first = NULL;
		delete p;
		return ;
	}
	return 0;
}
int searchAndDelete(int x)
{
	if(first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while(p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if(p != first && p->link != NULL)
		{
			if(p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else
			return 0;
	}
	return 0;
}
void swag(Node *a, Node *b)
{
	int t = a->info;
	a->info = b->info;
	b->info = t;
}
void sort()
{
	Node *p, *q, *min;
	p = first;
	while(p !=NULL)
	{
		min = p;
		q = p->link;
		while(p != NULL)
		{
			if(q->info < min->info)
				min = q;
			q = q->link;
		}
		swag(min, p);
		p = p->link;
	}
}
void sortDesc()
{
	Node *p, *q, *min;
	p = first;
	while(q != NULL)
	{
		min = p;
		q = p->link;
		while(q != NULL)
		{
			if(q->info > min->info)
				min = q;
			q = q->link;
		}
		swag(min, p);
	p = p->link;
	}
}
int main()
{
	int chon = 0;
	int x, i;
	Node *p;
	system("cls");
	cout << "*****MENU*****";
	cout << "1. Khoi tao danh sach lien ket rong";
	cout << "2. Them phan tu vao dau danh sach lien ket don";
	cout << "3. Them phan tu vao cuoi danh sach don"; 
	cout << "4. Xoa phan tu dau danh sach lien ket don";
	cout << "5. Xoa phan tu cuoi danh sach lien ket don";
	cout << "6. Xuat danh sach lien ket don";
	cout << "7. Tim mot phan tu gia tri x trong danh sach lien ket don";
	cout << "8. Tim mot phan tu voi gia tri x va xoa no neu co";
	cout << "9. Sap xep danh sach lien ket don tang dan";
	cout << "10. Sap xep danh sach lien ket don giam dan";
	cout << "11. Thoat";
	do{
		cout << "Chon so de thuc hien: \n";
		cin >> chon;
		switch(chon)
		{
		case 1:
			init();
			cout << "Tao danh sach lien ket don thanh cong\n";
			break;
		case 2:
			cout << "Nhap gia tri x: ";
			cin >> x;
			insert_first(x);
			cout << "Danh sach sau khi them la: ";
			Process_list();
			break;
		case 4:
			i = Delete_first();
			if(i == 0)
				cout << "Danh sach rong, khong the xoa!" << x << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu dau cua DSLK don!" << endl;
				cout << "Danh sach sau khi xoa la: ";
				Process_list();
			}
			break;
		case 5:
			i = Delete_last();
			if(i == 0)
				cout << "Danh sach rong, khong the xoa!" << x << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu cuoi cua DSLK don!" << endl;
				cout << "Danh sach sau khi xoa la: ";
				Process_list();
			}
			break;
		case 6:
			cout << "Danh sach hien tai la: ";
			Process_list();
			break;

		case 7:
			cout << "Nhap lai gia tri can tim x = ";
			cin >> x;
			p = search(x);
			if(p != NULL)
			{
				cout << "Tim thay phan tu co gia tri x =" << x << endl;
			}
			else
				cout << "Khong tim thay phan tu co gia tri x = " << x << "!=" <<endl;
			break;
		case 8:
			cout << "Nhap gia tri can tim x = ";
			cin >> x;
			i = searchAndDelete(x);
			if(i == 1)
			{
				cout << "Tim thay x = " << x << "va xoa thanh cong" << endl;
				cout << "Danh sach sau khi xoa la: ";
				Process_list();
			}
			else
				cout << "Khong tim thay phan tu co gia tri x = " << x << "!=" << endl;
			break;
		case 9:
			sort();
			cout << "Danh sach khi sap xep giam dan la: ";
			Process_list();
			break;
		case 10:
			sortDesc();
			cout << "Danh sach khi sap xep giam dan: ";
			Process_list();
			break;
		case 11:
			cout << "Tam biet!" << endl;
			break;
		default:
			break;
		}
	}while(chon != 11);
	system("pause");
	return 0;
}