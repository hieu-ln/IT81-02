#include<iostream>
using namespace std;

struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;
void init()
{
	root = NULL;
}
void print(Node *p, int space)
{
	if (p == NULL)
		return;
	space += COUNT;
	print(p->right, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << endl;
	print(p->left, space);
}
void Process_print()
{
	print(root, 0);
}
void insert_Node(Node *&p, int x)
{
	if (p == NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x)
			return;
		else if (p->info > x)
			return insert_Node(p->left, x);
		else
			return insert_Node(p->right, x);
	}
}
void insert_Node1(Node *p, int x)
{
	if (p->info == x)
		return 0;
	else
		if (p->info > x)
		{
			if (p->left == NULL)
			{
				Node *y = new Node;
				y->info = x;
				y->left = NULL;
				y->right = NULL;
				p->left = y;
				return 1;
			}
			else
				return insert_Node1(p->left, x);
		}
		else
		{
			if (p->right == NULL)
			{
				Node *y = new Node;
				y->info = x;
				y->left = NULL;
				y->right = NULL;
				p->right = y;
				return 1;
			}
			else
				return insert_Node1(p->right, x);
		}
}
Node *search(Node *p, int x)
{
	if (p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if (p->info > x)
				p = p->left;
			else
				p = p->right;
	}
	return NULL;
}
int Delete(Node *&T, int x)
{
	if (T == NULL)
		return 0;
	if (T->info == x)
	{
		Node *p = T;
		if (T->left == NULL)
			T = T->right;
		else
			if (T->right == NULL)
				T = T->left;
			else
				search(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x)
		return Delete(T->right, x);
	if (T->info > x)
		return Delete(T->left, x);
}

void duyetNLR(Node *p)
{
	if (p != NULL)
	{
		cout << p->info << " ";
		duyetLNR(p->left);
		duyetLNR(p->right);
	}
}
void duyetLRN(Node *p)

{
	duyetLNR(p->left);
	duyetLNR(p->right);
	cout << p->info << " ";
}
void duyetLNR(Node *p)
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		cout << p->info << " ";
		duyetLNR(p->right);
	}
}

int main()
{
	int x;
	int chon;
	char cont;
	do {
		cout << "*****MENU*****\n";
		cout << "1. Khoi tao cay rong\n";
		cout << "2. Them 1 node vao cay\n";
		cout << "3. Tim mot phan tu trong cay\n";
		cout << "4. Xoa 1 phan tu trong cay\n";
		cout << "5. Duyet NLR\n";
		cout << "6. Duyet LNR\n";
		cout << "7. Duyet LRN\n";
		cout << "Ban chon\n";
		cin >> chon;
		switch (chon)
		{
		case 1:
			init();
			cout << "Khoi tao thanh cong\n";
			break;
		case 2:
			cout << "Nhap gia tri can them\n";
			cin >> x;
			insert_Node(root, x);
			cout << "Gia tri cay nhi phan sau khi them la: \n";
			Process_print();
			break;
		case 3:
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			if (search(root, x) == NULL)
				cout << x << "Khong co trong cay\n";
			else
				cout << x << "Co trong cay\n";
			break;
		case 4:
			cout << "Nhap phan tu can xoa: ";
			cin >> x;
			if (Delete(root, x))
			{
				cout << "Cay sau khi xoa la: \n";
				Process_print();
				cout << endl;
			}
			else
				cout << "Xoa khong thanh cong\n";
			break;
		case 5:
			cout << "ket qua duyet NLR: ";
			duyetNLR(root);
			cout << endl;
			break;
		case 6:
			cout << "ket qua duyet LNR: ";
			duyetLNR(root);
			cout << endl;
			break;
		case 7:
			cout << "ket qua duyet LRN: ";
			duyetLRN(root);
			cout << endl;
			break;
		default:
			break;
		}
		cout << "Ban co muon tiep tuc (y/n): ";
		cin >> cont;
	} while (cont == 'y' || cont == 'Y');
}