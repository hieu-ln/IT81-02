#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *link;	
};

int search(Node *head, int info) 
{
  Node* temp = head;
  while (temp != NULL)
  {
	  if (temp -> info == info)
		  return 1;
	  temp = temp -> link;
  }
  return 0;
}
void Input(Node **head, int x);
Node* findIntersection(Node* list1, Node* list2)
{
	Node* intersectionLL = NULL;
	Node* temp1 = list1;
	while (temp1 != NULL)
	{
		if (search(list2, temp1 -> info))
			Input(&intersectionLL, temp1 -> info);
		temp1 = temp1 -> link;
	}
	return intersectionLL;
}
Node* PhanBu(Node* list1, Node* list2)
{
	Node* intersectionLL = NULL;
	Node* temp1 = list1;
	while(temp1 != NULL)
	{
		if (search(list2, temp1 -> info) == 0)
			Input(&intersectionLL, temp1 -> info);
		temp1 = temp1 -> link;
	}
	return intersectionLL;
}
Node* PhanBu2(Node* list1, Node* list2)
{
	Node* intersectionLL = NULL;
	Node* temp2 = list2;
	while(temp2 != NULL)
	{
		if (search(list1, temp2 -> info) == 0)
			Input(&intersectionLL, temp2 -> info);
		temp2 = temp2->link;
	}
	return intersectionLL;
}
void Input(Node **head,int x)
{
	Node*curr=new Node;
	curr -> info = x;
	curr -> link = NULL;
	if (*head == NULL)
		*head = curr;
	else 
	{
		curr -> link = *head;
		*head = curr;
	}	
}
void Output(Node**head)
{
	Node *temp = *head;
	while (temp != NULL) 
		{
			if (temp -> link != NULL)
				cout << temp -> info << "->";
			else
				cout << temp -> info;
			temp = temp -> link; 
		}
	cout << endl;
}

int main() 
{  
	Node *result = NULL;
	Node *unionLL = NULL;
	Node *intersectionLL = NULL;
	Node *Bu =NULL;
	Node *Bu2 =NULL;
	Node *list1 = NULL;
	Node *list2 = NULL;
	int x, chon;
	while(true)
	{
		cout << "\nNhap chon:\n"
			 << "0. Thoat\n"
			 << "1. Them dau danh sach 1\n"
			 << "2. Them dau danh sach 2\n"
			 << "3. Danh sach 2 tap hop\n"
			 << "4. Giao 2 danh sach\n"
			 << "5. Bu 2 danh sach\n"
			 << "Chon: ";
		cin >> chon;
		switch(chon)
		{
		case 0:
			return 1;
			break;
		case 1:
			cout << "Nhap gia tri muon them dau danh sach 1: ";
			cin >> x;
			Input(&list1, x);
			cout << "Them thanh cong!\n";
			break;
		case 2:
			cout << "Nhap gia tri muon them dau danh sach 2: ";
			cin >> x;
			Input(&list2, x);
			cout << "Them thanh cong!\n";
			break;
		case 3:
			cout << "Danh sach 2 tap hop la:\n";
			Output(&list1);
			Output(&list2);
			break;
		case 4:
			intersectionLL = findIntersection(list1, list2);
			if(intersectionLL != NULL)
			{
				cout << "Tap hop giao 2 danh sach la" << endl;
				Output(&intersectionLL);
			}
			else
				cout << "Khong co giao" << endl;
			break;
		case 5:
			Bu = PhanBu(list1, list2);
			Bu2 = PhanBu2(list1, list2);
			if (Bu != NULL && Bu2 != NULL)
			{
				cout << "Bu danh sach 1 la" << endl;
				Output(&Bu);
				cout << "\nBu danh sach 1 la" << endl;
				Output(&Bu2);
			}
			else
				cout << "Khong co bu" << endl;
			break;
		default:
			cout << "Gia tri chon khong hop le\n";
			break;
		}
	}
	return 0;
}#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *link;	
};

int search(Node *head, int info) 
{
  Node* temp = head;
  while (temp != NULL)
  {
	  if (temp -> info == info)
		  return 1;
	  temp = temp -> link;
  }
  return 0;
}
void Input(Node **head, int x);
Node* findIntersection(Node* list1, Node* list2)
{
	Node* intersectionLL = NULL;
	Node* temp1 = list1;
	while (temp1 != NULL)
	{
		if (search(list2, temp1 -> info))
			Input(&intersectionLL, temp1 -> info);
		temp1 = temp1 -> link;
	}
	return intersectionLL;
}
Node* PhanBu(Node* list1, Node* list2)
{
	Node* intersectionLL = NULL;
	Node* temp1 = list1;
	while(temp1 != NULL)
	{
		if (search(list2, temp1 -> info) == 0)
			Input(&intersectionLL, temp1 -> info);
		temp1 = temp1 -> link;
	}
	return intersectionLL;
}
Node* PhanBu2(Node* list1, Node* list2)
{
	Node* intersectionLL = NULL;
	Node* temp2 = list2;
	while(temp2 != NULL)
	{
		if (search(list1, temp2 -> info) == 0)
			Input(&intersectionLL, temp2 -> info);
		temp2 = temp2->link;
	}
	return intersectionLL;
}
void Input(Node **head,int x)
{
	Node*curr=new Node;
	curr -> info = x;
	curr -> link = NULL;
	if (*head == NULL)
		*head = curr;
	else 
	{
		curr -> link = *head;
		*head = curr;
	}	
}
void Output(Node**head)
{
	Node *temp = *head;
	while (temp != NULL) 
		{
			if (temp -> link != NULL)
				cout << temp -> info << "->";
			else
				cout << temp -> info;
			temp = temp -> link; 
		}
	cout << endl;
}

int main() 
{  
	Node *result = NULL;
	Node *unionLL = NULL;
	Node *intersectionLL = NULL;
	Node *Bu =NULL;
	Node *Bu2 =NULL;
	Node *list1 = NULL;
	Node *list2 = NULL;
	int x, chon;
	while(true)
	{
		cout << "\nNhap chon:\n"
			 << "0. Thoat\n"
			 << "1. Them dau danh sach 1\n"
			 << "2. Them dau danh sach 2\n"
			 << "3. Danh sach 2 tap hop\n"
			 << "4. Giao 2 danh sach\n"
			 << "5. Bu 2 danh sach\n"
			 << "Chon: ";
		cin >> chon;
		switch(chon)
		{
		case 0:
			return 1;
			break;
		case 1:
			cout << "Nhap gia tri muon them dau danh sach 1: ";
			cin >> x;
			Input(&list1, x);
			cout << "Them thanh cong!\n";
			break;
		case 2:
			cout << "Nhap gia tri muon them dau danh sach 2: ";
			cin >> x;
			Input(&list2, x);
			cout << "Them thanh cong!\n";
			break;
		case 3:
			cout << "Danh sach 2 tap hop la:\n";
			Output(&list1);
			Output(&list2);
			break;
		case 4:
			intersectionLL = findIntersection(list1, list2);
			if(intersectionLL != NULL)
			{
				cout << "Tap hop giao 2 danh sach la" << endl;
				Output(&intersectionLL);
			}
			else
				cout << "Khong co giao" << endl;
			break;
		case 5:
			Bu = PhanBu(list1, list2);
			Bu2 = PhanBu2(list1, list2);
			if (Bu != NULL && Bu2 != NULL)
			{
				cout << "Bu danh sach 1 la" << endl;
				Output(&Bu);
				cout << "\nBu danh sach 1 la" << endl;
				Output(&Bu2);
			}
			else
				cout << "Khong co bu" << endl;
			break;
		default:
			cout << "Gia tri chon khong hop le\n";
			break;
		}
	}
	return 0;
}