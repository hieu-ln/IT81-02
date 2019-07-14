//Bai 5 - Chuong 2
#include<iostream>
using namespace std;

#define MAX 100
int a[MAX];
int sp;

struct Node
{
	int info;
	Node *link;
};
Node *spP;

void init(int a[], int& sp){
	sp = -1;
}

int Push(int a[], int &sp, int x){
	if (sp < MAX - 1){
		a[++sp] = x;
		return 1;
	}
	return 0;
}

int Pop(int a[], int &sp, int &x){
	if (sp != -1){
		x = a[sp--];
		return 1;
	}
	return 0;
}

int isFull(int a[], int sp){
	if (sp == MAX - 1)
		return 1;
	return 0;
}

int isEmpty(int a[], int sp){
	if (sp == -1)
		return 1;
	return 0;
}

void initP(){
	spP = NULL;
}

void PushP(int x){
	Node *p;
	p = new Node;
	p->info = x;
	p->link = spP;
	spP = p;
}

int PopP(int &x){
	if (spP != NULL){
		Node *p = spP;
		x = p->info;
		spP = p->link;
		delete p;
		return 1;
	}
	return 0;
}

int isEmptyP(){
	if (sp == NULL)
		return 1;
	return 0;
}
