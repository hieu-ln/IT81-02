#include <iostream>
using namespace std;

struct Node{
	int info;
	Node *left;
	Node *right;
};
Node *root;

void tree_empty(){
	root = NULL;
}
void InsertNode(Node *&p, int x){
	if (p == NULL){
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else{
		if (p->info == x)
			return;
		else if (p->info > x)
			return InsertNode(p->left, x);
		else if (p->info < x)
			return InsertNode(p -> right, x);
	}
}

Node *search(Node *p, int x){
	while (p != NULL){
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

void LNR(Node *p){
	if (p != NULL){
		LNR(p->left);
		cout << p->info << "\t";
		LNR(p->right);
	}
}

void NLR(Node *p){
	if (p != NULL){
		cout << p->info << "\t";
		LNR(p->left);
		LNR(p->right);
	}
}

void LRN(Node *p){
	if (p != NULL){
		LNR(p->left);
		LNR(p->right);
		cout << p->info << "\t";
	}
}

