#include <iostream>
#include<stdio.h>
#include <fstream>
#include <sstream>
using namespace std;

#define MAX 20

//DSLK su dung cho STACK VA QUEUE va DANH SACH KE
struct node
{
	int info;
	node *link;
};
node * First[MAX];
int n;
char vertex[MAX];

node *sp;
node *front , *rear;
//STACK
void InitStack()
{
	sp = NULL;
}
int isEmptyS()
{
	if(sp!=NULL)
		return 1;
	return 0;
}
void PushS(int x)
{
	node *p = new node;
	p->info = x;
	p->link= sp;
	sp = p;
}
int PopS(int &x)
{
	if(sp != NULL ) 
	{
		node * p = sp;
		x = p->info;
		sp= p->link;
		delete p;
		return 1;
	}
	return 0;
}//end Stack
//Queue
void InitQ()
{
	front = NULL;
	rear = NULL;
}
int isEmptyQ()
{
	if (front == NULL)
		return 1;
	return 0;
}
void PushQ(int x)
{
	node *p = new node;
	p->link = NULL;
	p->info = x;
	if(rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int PopQ(int &x)
{
	if(front !=NULL)
	{
		node *p = front;
		front = p->link;
		x= p->info;
		if(front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}//end q
void InitGraph(int &n)
{
	for(int i = 0; i< n; i++)
		First[i] = NULL;
	n= 0;
}
void InsertLast(node *&first, node *p)
{
	if(first == NULL)
		first = p;
	else
	{
		node *q= first ;
		while(q->link !=NULL)
		{
			q= q->link;
		}
		q->link= p;
	}

}
void inputGraphFromText()
{
	string line;
	ifstream myfile("danhsachke1.txt");
	if(myfile.is_open())
	{
		myfile >> n;
		for(int i = 0; i< n ; i++)
			myfile>>vertex[i];
		string str;
		int i = 0;
		while(getline(myfile, str))
		{
			istringstream ss(str);
			int u;
			while(ss>>u)
			{
				//dinh u
				node *p = new node ;
				p->info = u;
				p->link = NULL;
				InsertLast(First[i-1], p);
			}
			i++;
		}
	}
}
void inputGraph()
{
	cout <<"Nhap so dinh cua do thi ";
	cin >> n;
	cout <<"Nhap ten dinh ";
	for(int i = 0; i< n; i++)
		cin >> vertex[i];
	for(int i =0; i< n+1;i++)
	{
		if(i> 0)
			cout <<"Nhap danh sach ke cua dinh thu " << i- 1 << " ( " <<vertex[i] <<") :";
		int u;
		string str;
		while(getline(cin,str))
		{
			istringstream ss(str);
			while(ss>>u)
			{
				//dinh u
				node *p = new node ;
				p->info = u;
				p->link = NULL;
				InsertLast(First[i-1], p);
			}
		}
			break;
	}
}
void outputGraph()
{
	for(int i=0; i< n; i++)
	{
		cout <<"Dinh" << i << " (" <<vertex[i] << ") :" ;
		node *p =First[i];
		while(p!=NULL)
		{
			cout << p->info << " " ;
			p = p->link;
		}
		cout <<endl;
	}
}
void output(int a[], int n)
{
	for(int i= 0; i<n; i++)
		cout << vertex[a[i]] << " ";
}
//duyet do thi tao BFS
int c[100], bfs[100];
int nbfs = 0;

void Initc()
{
	for(int i= 0; i< n;i++)
		c[i] = 1;
}
void BFS(int v) // v la dinh bat dau
{
	int p;
	node *w;
	PushQ(v);
	c[v]  = 0;
	while(front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		w= First[p];
		nbfs++;
		while(w!=NULL)
		{
			if(c[w->info])
			{
				PushQ(w->info);
				c[w->info] = 0;
			}
			w=w->link;
		}
	}
}
//duyet do thi theo chieu sau DFS
int dfs[100];
int ndfs =0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	c[s] = 0;
	int  u= s;
	node *v = NULL;
	while(isEmptyS() == 0)
	{
		if(v==NULL)
			PopS(u);
		v=First[u];
		while(v!=NULL)
		{
			if(c[v->info] == 1)
			{
				PushS(u);
				PushS(v->info);
				dfs[ndfs] = v->info;
				ndfs++;
				c[v->info] = 0;
				u=v->info;
				break;
			}
			v=v->link;
		}
	}
} 
void Search_by_BFS(int x, int v)
{
	int p;
	node *w;
	PushQ(v);
	c[v] = 0;
	while(front != NULL)
	{
		PopQ(p);
		if(x==p)
		{
			cout <<" tim thay x  " <<endl;
			return;
		}
		w=First[p];
		while(w!=NULL)
		{
				if(c[w->info] )
			{
				PushQ(w->info);
				c[w->info] = 0;
			}
				w=w->link;
		}
	}
}
int main()
{
	int a[MAX];
	int b[MAX];
	int choice , x,i;
	cout <<"  ----------Bai tap 5, chuong 5 ----------   "<<endl;
	cout <<" 1.Khoi tao danh sach ke rong" <<endl;
	cout <<" 2.Nhap danh sach tu file text" <<endl;
	cout <<" 3.Nhap danh sach ke "<<endl;
	cout <<" 4.Xuat danh sach ke"<<endl;
	cout <<" 5.Duyet do thi theo chieu rong "<<endl;
	cout <<" 6.Duyet do thi theo chieu sau DFS "<<endl;
	cout <<" 7.Tim dinh co gia tri  x theo BFS" << endl;
	cout <<" 8.Thoat"<<endl;
	do{
		cout <<"Nhap so de thuc thi chuong tirnh :"<<endl;
		cin >> choice;
		switch(choice)
		{
		case 1:
			n=10;
			InitGraph(n);
			cout <<" Ban  vua khoi tao danh sach ke thanh cong" <<endl;
			break;
		case 2:
			inputGraphFromText();
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			InitQ();
			Initc();
			cout <<"Vui long nhap dinh xuat phat: "<<endl;
			cin >> x;
			nbfs  = 0;
			BFS(x);
			cout <<"Thu tu dinh sau khi duyet BFS "<<endl;
			output(bfs,n);
			break;
		case 6:
			InitStack();
			Initc();
			cout <<"Vui long nhap dinh xuat phat: "<<endl;
			cin >> x;
			ndfs  = 0;
			DFS(x);
			cout <<"Thu tu dinh sau khi xuat phat DFS "<<endl;
			output(dfs,n);
			break;
		case 7:
			InitQ();
			Initc();
			nbfs = 0;
			cout << "Vui long nhap gia tri x can tim "<<endl;
			cin >>x;
			Search_by_BFS(x,0);
			break;
		case 8:
			cout <<"Goodbye   !!! " <<endl;
			break;
		default:
			break;
		}
	}while(choice != 8);
	return 1;
}