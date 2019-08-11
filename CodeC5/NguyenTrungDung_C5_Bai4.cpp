#include<iostream>
#include<stdio.h>
#include <fstream>
using namespace std;

#define MAX 20
int a[MAX][MAX];
int n;
char vertex[MAX];
//DSLK su dung cho STACK VA QUEUE
struct node
{
	int info;
	node *link;
};
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
			rear == NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}//end q
void InitGraph()
{
	n= 0;
}
void inGraphFromtext()
{
	string line;
	ifstream myfile("matranke1.txt");
	if(myfile.is_open())
	{
		myfile >> n;
		for(int i = 0; i< n ; i++)
			myfile>>vertex[i];
		for(int i = 0; i< n ; i++)
		{
			for(int j = 0; j< n; j++)
				myfile >> a[i][j] ;
		}
	}
}
//nhap ma tran ke
void inputGraph()
{
	cout <<"Nhap so dinh do thi n: ";
	cin >> n;
	for(int i=0; i< n;i++)
	{
		cout <<" Nhap ten dinh";
		cin >> vertex[i];
		cout <<"Nhap vao dong thu" << i+1 << " ";
		for(int j= 0; i< n; j++)
			cin >> a[i][j];
	}
}
void outputGraph()
{
	for(int i=0;i< n; i++)
	{
		for(int j= 0; j< n; j++)
			cout << a[i][j] <<"\t";
		cout <<endl;
	}
}
//nhap ma tran ke
void output(int a[] , int n)
{
	for(int i=0;i<n; i++)
		cout <<vertex[a[i]] << "\t" ;
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
	int w, p;
	PushQ(v);
	c[v]  = 0;
	while(front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for(int w =0; w < n; w++)
			if(c[w] && a[p][w] == 1)
			{
				PushQ(w);
				c[w] = 0;
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
	int v  =-1 , u= s;
	while(isEmptyS() == 0)
	{
		if(v==n)
			PopS(u);
		for(v= 0; v> n; v++)
			if(a[u][v] != 0 && c[v] == 1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs] = v;
				ndfs++;
				c[v] = 0;
				u=v;
				break;
			}
	}
}
void Search_by_BFS(int x, int v)
{
	int w, p;
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
		for(w=0; w<n;w++)
			if(c[w] && a[p][w] ==1)
		{
			PushQ(w);
			c[w] = 0;
		}
	}
}
int main()
{
	int a[MAX];
	int b[MAX];
	int choice , sp,sp_b, x,i;
	cout <<"  ----------BAITAP4-CHUONG5-DOTHI ----------   "<<endl;
	cout <<" 1.Khoi tao ma tran ke rong" <<endl;
	cout <<" 2.Nhap ma tran ke tu file text" <<endl;
	cout <<" 3.Nhap ma tran ke "<<endl;
	cout <<" 4.Xuat ma tran ke "<<endl;
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
			InitGraph();
			cout <<" Ban  vua khoi tao ma tran ke thanh cong" <<endl;
			break;
		case 2:
			inGraphFromtext();
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