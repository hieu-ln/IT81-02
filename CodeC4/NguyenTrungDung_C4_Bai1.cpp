//Chương 4 bài 1 Cây NHỊ phân tìm kiếm
#include <iostream>
#include <stdio.h>
using namespace std;

#define COUNT 10
// 1.1 Khai bao cau truc cay NPTK
struct node
{
	int info;
	node *left;
	node *right;
};
node *root;
//1.2 Khoi tao cay rong
void Init()
{
	root  = NULL;
}
//Them 1 phan tu
void  Insert_Node(node *&p, int x)
{
	if(p == NULL)
	{
		p = new node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if(p->info == x)
			return ;
		else
			if(p->info > x)
				return Insert_Node(p->left,x);
			else
				return Insert_Node(p->right,x);
	}
}
//1.4 Tim mot phan tu trong cay
node *Search(node *p, int x)
{
	while(p != NULL)
	{
		if(p->info == x)
			return p;
		else
			if(p->info > x)
				p=p->left;
			else
				p=p->right;
	}
	return NULL;
}
//1.5 Xoa mot nut trong cay
void SearchStandFor(node *&p, node *&q)
{
	if(q->left == NULL)
	{
		p->info = q->info;
		p= q;
		q= q->right;
	}
	else
		SearchStandFor(p,q->left);
}
int Delete(node *&T, int x)
{
	if( T == NULL) return 0;
	if(T->info == x)
	{
		node *p = T;
		if(T->left == NULL)
			T = T->right;
		else
			if(T->right == NULL)
				T=T->left;
			else
				SearchStandFor(p,T->right);
		delete p;
		return 1;
	}
	if(T->info < x) return Delete(T->right,x);
	if(T->info > x) return Delete(T->left,x);
}
//1.6 Duyet cay theo thu tu NLR
void DuyetNLR(node *p)
{
	if(p!=NULL)
	{
		cout <<p->info<<" ";
		DuyetNLR(p->left);
		DuyetNLR(p->right);
	}
}
//1.7 Duyet cay theo thu tu LNR
void DuyetLNR(node *p)
{
	if(p!= NULL)
	{
		DuyetLNR(p->left);
		cout <<p->info<<" ";
		DuyetLNR(p->right);
	}
}
//1.8 Duyet cay theo thu tu LRN
void DuyetLRN(node *p)
{
	if(p!=NULL)
	{
		DuyetLRN(p->left);
		DuyetLRN(p->right);
		cout <<p->info<<" ";
	}
}
void prin2DUtil(node *p, int space)
{
	//Base case
	if(p == NULL)
		return;
	space += COUNT;
	prin2DUtil(p->right, space);
	cout <<endl;
	for(int i = COUNT; i< space; i++)
		cout <<" ";
	cout << p->info <<"\n";
	prin2DUtil(p->left,space);
}
void Process_Tree()
{
	prin2DUtil(root,0);
}
int main()
{
	int choice = 0;
	int x,i;
	node *p;
	system("cls");
	cout <<"---------- BAI TAP 1_CHUONG 4_CAY NPTK ----------" <<endl;
	cout <<"1. Khoi tao cay NPTK rong" <<endl;
	cout <<"2. Them phan tu vao cay NPTK " <<endl;
	cout <<"3. Tim phan tu X trong cay NPTK : "<<endl;
	cout <<"4. Xoa phan tu co gia tri X trong cay NPTK "<<endl;
	cout <<"5. Duyet cay NPTK theo LNR "<<endl;
	cout <<"6. Duyet cay NPTK theo NLR "<<endl;
	cout <<"7. Duyet cay NPTK theo LRN "<<endl;
	cout <<"8. Xuat cay NPTK "<<endl;
	cout <<"9.Thoat "<<endl;
	do{
		cout <<"Vui long chon so de thuc thi chuong trinh: "<<endl;
		cin >> x;
		switch(choice)
		{
		case 1:
			Init();
			cout <<"Ban vua khoi tao cay NPTK thanh cong" <<endl;
			break;
		case 2:
			cout <<"Vui long nhap gia tri X can them: "<<endl;
			cin >> x;
			Insert_Node(root,x);
			cout <<"Cay sau khi them la: "<<endl;
			Process_Tree();
			break;
		case 3:
			cout <<" Vui long nhap gia tri X can tim: "<<endl;
			cin >> x;
			p= Search(root,x);
			if(p != NULL)
				cout <<"Tim thay x= " << x << "trong cay NPTK " <<endl;
			else
				cout <<"Khong tim thay x trong Cay NPTK " <<endl;
			break;
		case 4:
			cout <<" Vui long nhap gia tri X can xoa: "<<endl;
			cin >> x;
			i = Delete(root,x);
			if(i == 0)
				cout <<"Khong tim thay x de xoa " <<endl;
			else
			{
				cout <<"Da xoa thanh cong phan tu x= " <<x<< " trong cay NPTK"<<endl;
				cout <<"Cay NPTK sau khi xoa la: ";
				Process_Tree();
			}
			break;
		case 5:
			cout <<"Cay NPTK duyet theo LNR: "<<endl;
			DuyetLNR(root);
			break;
		case 6:
			cout <<"Cay NPTK duyet theo NLR: "<<endl;
			DuyetNLR(root);
			break;
		case 7:
			cout <<"Cay NPTK duyet theo LRN : "<<endl;
			DuyetLRN(root);
			break;
		case 8:
			cout <<"Cay NPTK nhu sau: "<<endl;
			Process_Tree();
			break;
		case 9:
			cout <<"Goodbye !!!" <<endl;
			break;
		default:
			break;
		}
	}while(choice!=9);
	system("pause");
	return 0;
}