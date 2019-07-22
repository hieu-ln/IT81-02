#include <iostream>
#include <stdio.h>
using namespace std;

struct Node {
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
	while (p != NULL) {
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}

Node *Search(int x) {
	Node *p = first;
	while (p != NULL && p->info != x) {
		p = p->link;
	}
	return 0;
}

void Insert_first(int x) {
	Node *p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

int Delete_first() {
	if (first != NULL) {
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

void Insert_last(int x) {
	Node *p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL) {
		first = p;
	}
	else {
		Node *q = first;
		while (q->link != NULL) {
			q = q->link;
		}
		q->link = p;
	}
}

int Delete_last() {
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first) {
			q->link = NULL;
		}
		else first = NULL;
		delete p;
		return 1;
	}
	return 0;
}

int SearchDelete(int x)
{
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while (p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first && p->link != NULL)
		{
			if (p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else if (p == first)
		{
			first = p->link;
			delete p;
			return 1;
		}
		else if (p->link == NULL & p->info == x)
		{
			q->link = NULL;
			delete p;
			return 1;
		}
		else
			return 0;
	}
	return 0;
}

void swap(Node *a, Node *b) {
	int t = a->info;
	a->info = b->info;
	b->info = t;
}

void SelectionSort() {
	Node *p, *q, *min;
	p = first;
	while (p != NULL)
	{
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->info < min->info)
				min = q;
			q = q->link;
		}
		swap(min, p);
		p = p->link;
	}
}

int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout << "-------------MENU----------\n";
	cout << "1. Khoi tao ds rong\n";
	cout << "2. Them phan tu vao dau ds\n";
	cout << "3. Them phan tu vao cuoi ds\n";
	cout << "4. Xoa phan tu dau ds\n";
	cout << "5. Xoa phan tu cuoi ds\n";
	cout << "6. Xuat ds\n";
	cout << "7. Tim 1 phan tu\n";
	cout << "8. Tim 1 phan tu va xoa\n";
	cout << "9. Sap xep ds tang dan\n";
	cout << "10. Thoat\n";
	do {
		cout << "Chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao ds thanh cong\n";
			break;
		case 2:
			cout << "Nhap x = ";
			cin >> x;
			Insert_first(x);
			cout << "Them phan tu thanh cong\n";
			break;
		case 3:
			cout << "Nhap x = ";
			cin >> x;
			Insert_first(x);
			cout << "Them phan tu thanh cong\n";
			break;
		case 4:
			if (Delete_first == 0)
				cout << "DS rong, khong the xoa\n";
			else
				cout << "Xoa thanh cong\n";
			break;
		case 5:
			if (Delete_last == 0)
				cout << "DS rong, khong the xoa\n";
			else
				cout << "Xoa thanh cong\n";
			break;
		case 6:
			cout << "Danh sach hien tai:\n";
			Process_list();
			break;
		case 7:
			cout << "Nhap x = ";
			cin >> x;
			p = Search(x);
			if (p != NULL)
				cout << "Tim thay " << x << endl;
			else
				cout << "Khong tim thay " << x << endl;
			break;
		case 8:
			cout << "Nhap x = ";
			cin >> x;
			if (SearchDelete(x) == 1)
				cout << "Da tim thay " << x << " va xoa thanh cong\n";
			else
				cout << "Khong tim thay " << x << endl;
			break;
		case 9:
			SelectionSort();
			cout << "Da sap xep danh sach theo thu tu tang dan\n";
			break;
		case 10:
			cout << "Chuong trinh ket thuc\n";
			break;
		default:
			break;
		}
		} while (choice != 10);
		system("pause");
		return 0;
}