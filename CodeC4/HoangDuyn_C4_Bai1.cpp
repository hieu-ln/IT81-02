// Bai 1 chuong 4 
#include<iostream>
#include<stdio.h>

using namespace std;

const int COUNT = 10;


struct Node
{
	int info;
	Node * left;
	Node *right;
};
Node*root;

void tree_empty()
{
	root = NULL;
}

void InsertNode( Node *&p, int x)
{
	if(p==NULL)
	{
		p=new Node;
		p->info=x;
		p->left=NULL;
		p->right=NULL;
	}
	else
	{
		if(p->info==x)
			return ;
		else if (p-> info > x)
			return InsertNode(p->left,x);
		else 
			return InsertNode(p->right, x);
	}
}
Node *search(Node  *p, int x)
{
	while(p!=NULL)
	{
		if ( p-> info==x)
			return p;
		else
			if(p->info>x)
				p=p->left;
			else
				p=p->right;
	}
	return NULL;
}
void searchStandFor(Node *&p, Node *&q)
{
	if(q->left==NULL)
	{
		p->info=q->info;
		p=q;
		q=q->right;
	}
	else
		searchStandFor(p,q->left);
}
int Delete(Node *& T , int x)
{
	if(T==NULL)
		return 0;
	if(T->info==x)
	{
		Node*p=T;
		if(T->left==NULL)
			T=T->right;
		else if(T->right==NULL)
			T=T->left;
		else
			searchStandFor(p,T->right);
		delete p;
		return 1;
	}
	if(T->info<x)
		return Delete(T->right, x);
	if(T->info>x)
		return Delete(T->left,x);
	
}
void duyetLNR(Node *p)
{
	if(p!=NULL)
	{
		duyetLNR(p->left);
		cout << p-> info << "  ";
		duyetLNR(p->right);
	}
}

void duyetNLR(Node*p)
{
	if ( p!=NULL)
	{
		duyetNLR(p->left);
		duyetNLR(p->right);
		cout << p->info << "  " ;
	}
}
void duyetLRN( Node *p)
{
	if(p!=NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->info << "  ";
	}
}
void print2DUtil(Node *p, int space)
{
	//Base case
	if(p==NULL)
		return;
	// Increase distance between levels
	space +=COUNT;
	//Process right child first
	print2DUtil(p->right,space);
	// Print current node after space
	// count 
	cout << endl;
	for ( int i = COUNT; i < space; i++)
	cout << "  " ;
	cout << p-> info << "\n";
	// Process left child
	print2DUtil(p->left, space);
}
void Process_Tree()
{
	print2DUtil(root,0);
}
int main()
{
	int choice =0;
	int x,i;
	Node*p;
	system("cls");
	cout << " Bai tap 1 Chuong 4 Cay Nhi Phan Tim Kiem " << endl;
	cout << " 1. Khoi tao cay nhi phan tim kiem rong " << endl;
	cout << " 2. Them phan tu vao cay nhi phan tim kiem " << endl;
	cout << " 3. Tim phan tu co gia tri x trong cay nhi phan tim kiem " << endl;
	cout << " 4. Xoa phan tu co gia tri x trong cay nhi phan tim kiem " << endl;
	cout << " 5. Duyet cay nhi phan theo LNR " << endl;
	cout << " 6. Duyet cay nhi phan theo NLR " << endl;
	cout << " 7. Duyet cay nhi phan theo LRN " << endl;
	cout << " 8. Xuat cay nhi phan tim kiem " << endl;
	cout << " 9. Thoat " << endl;
	do {
		cout << " \n Vui long chon so de thuc hien : ";
		cin >> choice;
		switch(choice)
		{
		case 1: 
			tree_empty();
			cout << " Khoi tao cay rong thanh cong ! ";
			break;
		case 2:
			cout << "Vui long nhap gia tri x can them vao cay : ";
			cin >> x;
			InsertNode(root,x);
			cout << " Cay nhi phan tim kiem sau khi them la : ";
			Process_Tree();
			break;
		case 3: 
			cout << " Vui long nhap gia tri x can tim : ";
			cin >> x;
			p=search(root,x);
			if(p!=NULL)
				cout << " Tim thay x=" << x << " trong cay ! " << endl;
			break;
		case 4 :
			cout << " Vui long nhap gia tri x can xoa: ";
			cin >>x ;
			i =Delete ( root, x);
			if( i==0)
				cout << " Khong tim thay x = " << x << " trong cay nhi phan tim kiem ! ";
			else
			{
				cout << " Da xoa thanh cong phan tu x = " << x << " trong cay nhi phan tim kiem ! ";
				cout << " Cay nhi phan sau khi xoa phan tu x = "  << x << " la : ";
				Process_Tree();
			}
			break;
		case 5 :
			cout << " Cay nhi phan tim kiem duyet theo LNR la : ";
			duyetLNR(root);
			break;
		case 6 :
			cout << " Cay nhi phan tim kiem duyet theo NLR la : ";
			duyetNLR(root);
			break;
		case 7 :
			cout << " Cay nhi phan tim kiem duyet theo LRN la : ";
			duyetLRN(root);
			break;
		case 8 :
			cout << " Cay nhi phan tim kiem nhu sau : ";
			Process_Tree();
			break;
		case 9 :
			cout << " GOODBYE ... ! " << endl;
		default:
			break;

		}
	}while(choice!=9);
	return 0;
}