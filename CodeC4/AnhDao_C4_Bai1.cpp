//Quan li mot cay nhi phan
#include <iostream>
#include<stdio.h>
using namespace std;
#define COUNT 10
//Khai bao cau truc
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;
// Tao cay rong
void inIt()
{
	root = NULL;
}
//Them phan tu
void InsertNode(Node *&p, int x)
{
	if(p == NULL)
	{
		p = new Node;
		p -> info = x;
		p -> left = NULL;
		p -> right = NULL;
	}
	else
	{
		if(p -> info == x)
			return ;
		else
			if(p -> info > x)
				return InsertNode(p -> left,x);
			else
				return InsertNode(p -> right, x);
	}
}
//Tim phan tu
Node *search(Node *p, int x)
{
	while(p != NULL)
	{
		if(p -> info == x)
			return p;
		else
			if(p -> info > x)
				return search( p -> left,x);
			else
				return search(p -> right,x);
	}
	return NULL;
}
//Xoa node
void searchStandFor(Node *&p, Node *&q)
{
	if(q -> left == NULL)
	{
		p -> info = q -> info;
		p = q;
		q = q -> right;
	}
	else
		searchStandFor(p, q -> left);
}
int Delete(Node *&T, int x)
{
	if(T == NULL)
		return 0;
	if(T -> info == x)
	{
		Node *p = T;
		if(T -> left == NULL)
			T = T -> right;
		else
			if(T -> right == NULL)
				T = T -> left;
			else
				searchStandFor(p, T -> right);
		delete p;
		return 1;
	}
	if(T -> info < x)
		return Delete(T -> right, x);
	if(T -> info > x)
		return Delete(T -> left,x);
}
//Duyet theo NLR
void duyetNLR(Node *p)
{
	if(p != NULL)
	{
		cout << p -> info << " ";
		duyetNLR(p -> left);
		duyetNLR(p -> right);
	}
}
//Duyet theo LNR
void duyetLNR(Node *p)
{
	if(p!= NULL)
	{
		duyetLNR(p -> left);
		cout << p -> info << " ";
		duyetLNR(p -> right);
	}

}
//Duyet theo LRN
void duyetLRN(Node *p)
{
	if(p!= NULL)
	{
		duyetLRN(p -> left);
		duyetLRN(p -> right);
		cout << p -> info << " ";
	}

}
void print2DUtil(Node *p, int space)
{
	//base case
	if(p == NULL)
		return;
	//Increase distance between leves
	space += COUNT;
	//Process right child first
	print2DUtil(p -> right, space);
	//Print current node after space
	//count
	cout << endl;
	for(int i = COUNT; i < space; i++)
		cout << " ";
	cout << p -> info << "\n";
	//Process left child
     print2DUtil(p -> left, space);
}
//Wrapper over print2DUtil()
void Process_Tree()
{
	//Pass initial space count as 0
     print2DUtil(root, 0);
}
int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout << "-----------Bait tap 1, Chuong 4----------------\n";
	cout <<"1. Khoi tao cau NPTK rong\n";
	cout <<"2. Them phan tu vao cay NPTK rong\n";
	cout << "3. Tim phan tu co gia tri x trong cay NPTK\n";
	cout << "4. Xoa phan tu co gia tri x trong cay NPTK\n";
	cout << "5. Duyet cay NPTK theo LNR\n";
	cout << "6. Duyet cay NPTK theo NLR\n";
	cout << "7. Duyet cay NPTK theo LRN\n";
	cout << "8. Xuat cay NPTK\n";
	cout << "9. Thoat\n";
	do{
		cout << "Vui long nhap so can thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			inIt();
			cout << "Ban vua khoi tao cay NPTK thanh cong!\n";
			break;
		case 2:
			cout << "Vui long nhap gia tri x can them: ";
			cin >> x;
			InsertNode(root,x);
			cout << "Cay NPTK sau khi them la:";
			Process_Tree();
			break;
		case 3:
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			p = search(root,x);
			if(p != NULL)
				cout << "Tim thay x = " << x << " trong cay NPTK\n";
			else
				cout << "Khong tim thay x trong cay NPTK\n";
			break;
		case 4:
			cout << "Vui long nhap gia tri x can xoa: ";
			cin >> x;
			i = Delete(root,x);
			if(i == 0)
				cout << "Khong tim thay x = " << x << " de xoa\n";
			else{
				cout << "Da xoa thanh cong phan tu x = " << x << " rong cay NPTK\n";
				cout << "Cay NPTK sau khi xoa la: ";
				Process_Tree();
			}
			break;
		case 5:
			cout << "Cay NPTK duyet theo LNR la: ";
			duyetLNR(root);
			cout << endl;
			break;
		case 6:
			cout << "Cay NPTK duyet theo NLR la: ";
			duyetNLR(root);
			cout << endl;
			break;
		case 7:
			cout << "Cay NPTK duyet theo LRN la: ";
			duyetLRN(root);
			cout << endl;
			break;
		case 8:
			cout << "Cay NPTK nhu sau:\n";
			Process_Tree();
			break;
		case 9:
			cout << "Goodbye...............!!!\n";
			break;
		default:
			break;
		}
	}while(choice != 9);
	system("pause");
	return 0;
}