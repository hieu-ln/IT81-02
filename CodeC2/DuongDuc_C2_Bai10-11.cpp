//Bai 10-11 - Chuong 2
#include<iostream>
using namespace std;

#define MAX 100
int a[MAX];
int front, rear;

struct Node{
	int info;
	Node *link;
};
Node *frontP, *rearP;

void init(int a[], int &front, int&rear){
	front = -1;
	rear = -1;
}

int Push(int a[], int &front, int &rear, int x){
	if (rear - front == MAX - 1)
		return 0;
	else{
		if (front == -1)
			front = 0;
		if (rear == MAX - 1){
			for (int i = front; i <= rear; i++)
				a[i - front] = a[i];
			rear = MAX - 1 - front;
			front - 0;
		}
		a[++rear] = x;
		return 1;
	}
}

int Pop(int a[], int &front, int &rear, int &x){
	if (front == -1)
		return 0;
	else{
		x = a[front++];
		if (front > rear){
			front = -1;
			rear = -1;
		}
		return 1;
	}
}

void initP(){
	front = NULL;
	rear = NULL;
}

void PushP(int x){
	Node *p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (rearP == NULL)
		frontP = p;
	else
		rearP->link = p;
	rearP = p;
}

int PopP(int x){
	if (front != NULL){
		Node *p = frontP;
		x = p->info;
		frontP = frontP->link;
		if (frontP == NULL)
			rearP = NULL;
		delete p;
		return 1;
	}
	return 0;
}

int isEmpty(){
	if (frontP == NULL)
		return 1;
	return 0;
}
