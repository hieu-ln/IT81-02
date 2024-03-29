#include<iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
using namespace std;
//Khai bao ma tran bang mang hai chieu
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
	 ifstream  myfile("do_thi_1.txt");
	 if(myfile.is_open())
	 {
		 myfile >> n;
		 for(int i = 0; i < n; i++)
			 myfile >> vertex[i];
		 for(int i = 0; i < n; i++)
			 for(int j = 0; j < n; j++)
				 myfile >> a[i][j];
	 }
 }
void inputGraph()
 {
	 cout << "Nhap so dinh do thi n: ";
	 cin >> n;
	 for(int i = 0; i < n; i++)
		 cin >> vertex[i];
	  for(int i = 0; i < n; i++)
	  {
		 cout << "Nhap vao dong thu : " << i + 1 << " : ";
		 for(int j = 0; j < n; j++)
			 cin >> a[i][j];
	  }
 }
 void outputGraph()
 {
	 cout << setw(6) << left;
	 for(int i = 0; i < n; i++)
	 {
		  for(int j = 0; j < n; j++)
			 cout << a[i][j] << setw(6) << left;
		  cout << endl;
	 }
 }
//Khai bao tapE
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0;
//Khai bao tapT
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0;
//Ton tai
int TonTai(int d, int D[], int nD)
{
	for(int i = 0; i < nD; i++)
		if(D[i] == d)
			return 1;
	return 0;
}
//xuat
void output(bool VertexName)
{
	int tong = 0;
	for(int i = 0; i < nT; i++)
	{
		if(VertexName)
			cout << "\n (" << vertex[T1[i]] << " , " << vertex[T2[i]] << ") =" << wT[i];
		else
			cout << "\n (" << T1[i] << " , " << T2[i]<< ") =" << wT[i];
		tong += wT[i];
	}
	cout << "\n Tong = " << tong;
}
//xoa vi tri E
void XoaViTriE(int i)
{
	for(int j = i; j < nE; j++)
	{
	
		{
			E1[j] = E1[j + 1];
			E2[j] = E2[j + 1];
			wE[j] = wE[j + 1];
		}
	}
	nE--;
}
//xoa canh E
void XoaCanhE(int u, int v)
{
	for(int i = 0; i < nE; i++)
		if(E1[i] == u && E2[i] == v)
		{
			XoaViTriE(i);
			break;
		}
}
void prim(int s)// s la dinh bat dau
{
	int u = s, min, i, d1, d2;
	while(nT < n - 1)
	{
		for(int v = 0; v < n; v++)
			if(a[u][v] != 0)
				if(TonTai(v, T2, nT) == 0)
				{
					E1[nE] = u;
					E2[nE] = v;
					wE[nE] = a[u][v];
					nE++;
				}
		for(i = 0; i < nE; i++)
			if(TonTai(E2[i], T2, nT) == 0)
			{
				min = wE[i]; 
				d1 = E1[i];
				d2 = E2[i];
				break;
			}
		for(i = 0; i < nE; i++)
			if(TonTai(E2[i], T2, nT) == 0)
				if(min > wE[i])
				{
					min = wE[i];
					d1 = E1[i];
					d2 = E2[i];
				}
		T1[nT] = d1; 
		T2[nT] = d2;
		wT[nT] = a[d1][d2];
		a[d1][d2] = 0;
		a[d2][d1] = 0;
		nT++;
		XoaCanhE(d1, d2);
		u = d2;
	}
}
//Tao E
void taoE(){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(a[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = a[i][j];
				a[i][j] = 0;
				a[j][i] = 0;
				nE++;
			}
}
//Sap xep E
void SapXepE(){
	for(int i = 0; i < nE - 1; i++)
		for(int j = i + 1; j < nE; j++)
			if(wE[i] > wE[j])
			{
				swap(wE[i], wE[j]); 
				swap(E1[i], E1[j]);
				swap(E2[i],E2[j]);
			}
}
// Krusal
void krusal()
{
	for(int i = 0; i < nE - 1; i++)
	{
		if(TonTai(E1[i], T1, nT) == 1 && TonTai(E2[i], T2, nT) == 1)
			continue;
		if(TonTai(E1[i], T2, nT) == 1 && TonTai(E2[i], T1, nT) == 1)
			continue;
		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if(nT == n - 1)
			break;
	}
}
//
int main()
{
	int choice, x;
	system("cls");
	cout << "-----------Bai tap 4, Chuong 6--------------\n";
	cout << "1. Khoi tao ma tran ke rong\n";
	cout << "2. Nhap ma tran ke tu file text\n";
	cout << "3. Nhap ma tran ke\n";
	cout << "4. Xuat ma tran ke\n";
	cout << "5.Tim cay khng toi thieu bang PRIM\n";
	cout << "6. Tim cay khung toi thieu bang giai thuat Kruskal\n";
	cout << "7. Tim cay khung toi thieu bang giai thuat Kruskal cai tien\n";
	cout << "8. Thoat.\n";
	do{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			initGraph();
			cout << "Ban vua khoi tao ma tran ke rong thanh cong!\n";
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap ma tran ke tu file; \n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			prim(x);
			cout << "Cay khung toi thieu voi PRIM:\n";
			output(true);
			cout << endl;
			break;
		case 6:
			krusal();
			cout << "Cay khung toi thieu voi fruckal :\n";
			output(true);
			cout << endl;
			break;
		case 7:
			void SapXepE();
			krusal();
			cout << "Cay khung toi thieu voi krusal la : \n ";
			output(true);
			cout << endl;
			break;
		case 8:
			cout << "Goodbye......\n";
			break;
		default:
			break;
		}
	}while(choice != 8);
	system("pause");
	return 0;
}