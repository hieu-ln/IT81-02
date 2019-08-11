#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;
//khai bao ma  tran ma tran hai chieu
#define MAX 20
int a[MAX][MAX];
int n;
char vertex[MAX];

void initGraph()
{
	n = 0;
}
void inputGraphFromText()
{
	string line;
	ifstream myfile("matrantrongso1.txt");
	if(myfile.is_open())
	{
		myfile >> n;
		for(int i =0; i< n; i++)
			myfile >> vertex[i];
		for(int  i =0; i< n; i++)
		{
			for(int j = 0; j< n;j++)
				myfile >> a[i][j];
		}
	}
}
//Nhap ma tran ke cua do thi
void inputGraph()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for(int i =0; i< n; i++)
		cin >> vertex[i];
	for(int i= 0; i< n;i++)
	{
		cout << "Nhap dong thu" << i+1 << ": ";
		for(int j = 0; j< n; j++)
			cin >> a[i][j];
	}
}
void outputGraph()
{
	cout << setw(6)<<left;
	for(int i = 0; i< n; i++)
	{
		for(int j= 0 ; j< n; j++)
			cout << a[i][j] << setw(6) <<left;
		cout << endl;
	}
}
//khai bao tap E
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0; // so phan tu tap
//khai bao tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0;

int tontai(int d, int D[], int nD)
{
	for(int i= 0; i< n; i++)
		if(D[i] == d)
			return 1;
	return 0;
}
void xoavitri(int i)
{
	for(int j= i; j< nE; j++)
	{
		E1[j] = E1 [j+1];
		E2[j] = E2 [j+1];
		wE[j] = wE [j+1];
	}
	nE--;
}
void xoacanh(int u, int v)
{
	for(int i= 0; i< n; i++)
		if(E1[i] == u && E2[i] == v)
		{
			xoavitri(i);
			break;
		}
}
void prim(int s)
{
	int u =s , min ,i,d1 ,d2;
	while(nT < n-1)
	{
		for(int v =0; v<n; v++)
			if(a[u][v] != 0)
				if(tontai(v,T2,nT) == 0)
				{
					E1[nE] = u;
					E2[nE] = v;
					wE[nE] = a[u][v];
					nE++;
				}
				for(int i= 0; i< nE; i++)
					if(tontai(E2[i],T2,nT) ==0)
					{
						min = wE[i];
						d1= E1[i];
						d2 = E2[i];
						break;
					}
					for(int i= 0; i< nE; i++)
						if(tontai(E2[i],T2,nT) ==0)
							if(min >wE[i])
							{
								min = wE[i];
								d1= E1[i];
								d2 = E2[i];
							}
							T1[nT] = d1;
							T2[nT] = d2;
							wT[nT] = a[d1][d2];
							a[d1][d2] = 0;
							a[d2][d1] = 0;
							nT++;
							xoacanh(d1,d2);
							u=d2;
	}
}
void output(bool VertextName)
{
	int tong = 0;
	for(int i = 0; i<n ; i++)
	{
		if(VertextName)
			cout <<endl <<"( "<<vertex[T1[i]] << ", "<<vertex[T2[i]] << ") "<<wT[i];
		else
			cout <<endl <<"( "<<T1[i]<<","<<T2[i]<<") "<<wT[i];
		tong+=wT[i];
	}
	cout <<"\n Tong=" <<tong;
}
int main()
{
	int choice, x, i;
	cout << "Khoi tao ma tran rong" <<endl;
	cout << "Nhap ma tran ke tu file" <<endl;
	cout << "Nhap ma tran ke " <<endl;
	cout << "Xuat ma tran ke "<<endl;
	cout << "Tim cay khung toi thieu" <<endl;
	cout << "Thoat "<<endl;
	do{
		cout << "Vui long chon so de thuc thi chuong trinh : "<<endl;
		cin >> choice;
		switch(choice)
		{
		case 1:
			initGraph();
			cout << "khoi tao ma tran rong thanh cong" <<endl;
			break;
		case 2:
			inputGraphFromText();
			cout <<"ban vua nhap ma tran ke thanh cong" <<endl;
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			cout << "Nhap ding xaut phat ";
			cin >> x;
			prim(x);
			cout << "Cay khung toi thieu" <<endl;
			output(true);
			break;
		case 6:
			cout << "Goodbye !!! "<<endl;
			break;
		}
	}while(choice != 6);
	return 0;
}