#include < iostream >
#include <stdio.h>
using namespace std;

struct Node
{
	int info;
	Node *next,*previous;
};

Node *first , *last ;

void init()
{
	first=NULL;
	last=NULL;
}

Node *ds;
void process()
{
	Node *p = new Node;
	p=ds;
	while(p!=NULL)
	{
		cout<<p->info<< "   " ;
		p=p->next;
	}
	cout<<endl;
}

void insertfirst(int x)
{
	Node *p;
	p=new Node;
	p->info=x;
	p->next=first;
	p->previous =NULL;
	if(first!=NULL )
		first->previous;
	else
		last=p;
	first=p;
}

void insertlast(int x)
{
	Node*p;
	p=new Node;
	p->info=x;
	p->next=NULL;
	p->previous=last;
	if(last !=NULL )
		last->next=p;
	else
		first=p;
	last=p;
}

int deletefirst()
{
	if ( first!=NULL )
	{
		Node*p=first;
		first=first->next;
		delete p;
		if(first!=NULL)
			first->previous;
		else
			last=NULL;
		return 1;
	}
	return 0;
}

int deletelast()
{
	if(last!=NULL)
	{
		Node *p =last;
		last=last->previous;
		if(last !=NULL)
		last->next=NULL;
		else
			first=NULL;
		delete p;
		return 1;
	}
	return 0;
}
Node *search(int y )
{
	Node*p;
	p=first;
	while(p!=NULL && p->info!=y)
		p=p->next;
	return p;
}

int Delete(int y)
{
	Node*p=search(y);
	if(p!=NULL)
	{
		if(p==first)
		{
			if(deletefirst())
				return 1;
			else
				return 0;
		}
		else
			if(p==last)
			{
				if(deletelast())
					return 1;
				else
					return 0;
			}
		else
		{
			Node *q;
			q=p->previous;
			q->next=p->next;
			(p->next)->previous;
			delete p;
			return 1;
			}
	}
	return 0;
}

int main()
{
	int choice,x;
	do{
		cout<<"1.khoi tao danh sach\n2.xuat danh sach\n3.them vao dau danh sach\n4.them phan tu vao cuoi danh sach\n5.xoa phan tu dau\n6.xoa phan tu cuoi\n.7.tim va xoa phan tu\n8.thoat\n " << endl;
		cin >> choice;
		switch(choice)
		{
		case 1:
			init();
			cout<<"khoi tao danh sach rong thanh cong ";
			break;
		case 2:
			cout<<"danh sach hien tai" << endl;
			process();
			break;
		case 3:
			int x;
			cout<<"nhap gia tri x can tim " << endl;
			cin>> x;
			insertfirst(x);
			cout<<"them thanh cong" << endl;
			break;
		case 4:
			cout<<"nhap gia tri x can tim " << endl;
			cin>> x;
			insertlast(x);
			cout<<"them thanh cong" << endl;
			break;
		case 5:
			deletefirst();
			cout<<"danh sach sau khi xoa"<< endl;
			process();
			break;
		case 6:
			deletelast();
			cout<<"ds sau khi xoa" << endl;
			process();
			break;
		case 7:
			int y;
			cout<<"nhap ptu can xoa" << endl;
			cin >> y;
			if(search(y)==NULL)
				cout<<"khong co phan tu can tim " << endl;
			else
			{
				Delete(y);
				cout<<"ds sau khi xoa" << endl;
				process();
			}
			break;
		case 8:
			cout<<"goodbye----------" << endl;
			break;
		default:
			break;
		}
	}while(choice !=8);
	return 0;
}
