#include <iostream>
#include <stack>
using namespace std;

struct Node 
{
	int info;
	Node *left;
	Node *right;
};
Node *CreatNode(int x)
{	
	Node *p = new Node();
	p->info = x;
	p->left = p->right = NULL;
	return p;
}
Node* find(Node* root, int x)
{
	if(root = NULL)
	{
		return NULL;
	}
	Node *p = root;
	while(p != NULL)
	{
		if(p->info > x)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	return p;
}
void InsertNode(Node *&root, int x)
{
	Node *n = CreatNode(x);
	if(root == NULL)
	{
		root = n;
		return;
	}
	else
	{
		Node *f = find(root, x);
		if(f != NULL)
		{
			if(f->info > x)
			{
				f->left = n;
			}	
			else
			{
				f->right = n;
			}
		}
	}
}
int leftof(const int value, const Node *root)
{
	return value < root->info;
}
int rightof(const int value, const Node *root)
{
	return value < root->info;
}
int leftMostValue(const Node *root)
{
	while(root->left != NULL)
		root = root->left;
	return root->info;
}
Node *Delete(Node *root, int value)
{
	if(root == NULL)
		return root;
	if(leftof(value, root))
		root->left = Delete(root->left, value);
	else if(rightof(value, root))
		root->right = Delete(root->right, value);
	else
	{
		if(root->left == NULL)
		{
			Node *newRoot = root->right;
			free(root);
			return newRoot;
		}
		if(root->right == NULL)
		{
			Node *newRoot = root->left;
			free(root);
			return newRoot;
		}
		root->info = leftMostValue(root->right);
		root->right = Delete(root->right, root->info);
	}
	return root;
}
void CreateTree(Node *&root, int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		InsertNode(root, a[i]);
	}
}
void inOrder(struct Node *root)
{
	stack < Node* > s;
	Node *curr = root;
	while(curr != NULL || s.empty() == false)
	{
		while(curr != NULL)
		{
			s.push(curr);
			curr = curr->left;
		}
		curr = s.top();
		s.pop();
		cout << curr->info << " ";
		curr = curr->info;
	}
}
void preorder(struct Node *root)
{
	if(root == NULL)
		return;
	stack < Node* > NodeStack;
	NodeStack.push(root);
	while(NodeStack.empty() == false)
	{
		struct Node *temp_Node = NodeStack.top();
		cout << temp_Node->info << " ";
		NodeStack.pop();
		if(temp_Node->right)
			NodeStack.push(temp_Node->right);
		if(temp_Node->left)
			NodeStack.push(temp_Node->left);
	}
}
void postorderIerative(Node *root)
{
	stack < Node* > stk;
	stk.push(root);
	stack < int > out;
	while(!stk.empty())
	{
		Node *curr = stk.top();
		stk.pop();
		out.push(curr->info);
		if(curr -> left)
			stk.push(curr->left);
		if(curr -> right)
			stk.push(curr->right);
	}
	while(!out.empty())
	{
		cout << out.top() << " ";
		out.pop();
	}
}
int main()
{
	Node *root = NULL;
	int a[] = {41, 6, 36, 46, 16, 54, 47, 11, 14, 49, 47};
	int n = 11;
	CreateTree(root, a, n);
	InsertNode(root, 24);
	printf("Duyet LNR: ");
	inOrder(root);
	printf("Duyet NLR: \n");
	preorder(root);
	printf("Duyet LNR: \n");
	postorderIerative(root);
	printf("Xoa LNR: 24");
	root = Delete(root, 24);
	printf("Duyet LNR: \n");
	inOrder(root);
	printf("Duyet NLR: \n");
	preorder(root);
	postorderIerative(root);
	return 0;
}