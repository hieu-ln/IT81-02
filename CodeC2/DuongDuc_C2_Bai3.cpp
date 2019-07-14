//Bai 3 - Chuong 2
#include<iostream>
using namespace std;

//3.1
struct Node{
	int info;
	Node *link;
};
Node *first;

//3.2
void init(){
	first = NULL;
}

//3.3
void ProcessList(){
	Node *p;
	p = first;
	while(p!=NULL){
		cout<<p -> info<<"\t"<<endl;
		p=p->link;
	}
	cout<<endl;
}

//3.4
Node *Search(int x){
	Node *p = first;
	while ((p!=NULL) && (p->info!=x))
		p=p->link;
	return p;
}

//3.5
void InsertFirst(int x){
	Node *p;
	p= new Node;
	p->info = x;
	p->link = first;
	first =p;
}

//3.6
void InsertLast(int x){
	Node *p;
	p = new Node;
	p->info=x;
	p->link=NULL;
	if(first = NULL)
		first = p;
	else{
		Node *q=first;
		while(q->link!=NULL)
			q=q->link;
	}
}

//3.7
int Delete_first(){
	if(first!=NULL){
		Node*p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

//3.8
int DeleteLast(){
	Node *p, *q;
	p=first; 
	q= NULL;
	if(p!=NULL){
		while(p->link != NULL){
			q=p;
			p=p->link;
		}
		if(p!=first)
			q->link =NULL;
		else
			first =NULL;
		delete p;
		return 1;
	}
	return 0;
}

//3.9(*)
int FindAndDelete(int x){
	if (first != NULL){
		Node *p, *q;
		p = first;
		q = first;
		while (p != NULL && p->info != x){
			q = p;
			p = p->link;
		}

		if (p != first && p->link != NULL){
			if (p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}

		else if (p == first){
			first = p->link;
			delete p;
			return 1;
		}

		else if (p->link == NULL && p->info == x){
			q->link = NULL;
			delete p;
			return 1;
		}

		else
			return 0;
	}
	return 0;
}


void main(){
	int x;
	int choice;

	cout<<"=======DANH SACH LIEN KET DON=======";
	cout<<"1.Tao danh sach rong\n";
	cout<<"2.Xuat cac phan tu trong danh sach\n";
	cout<<"3.Tim mot phan tu trong danh sach\n";
	cout<<"4.Them mot phan tu vao dau danh sach\n";
	cout<<"5.Them mot phan tu vao cuoi danh sach\n";
	cout<<"6.Xoa mot phan tu dau danh sach\n";
	cout<<"7.Xoa mot phan tu cuoi danh sach\n";
	cout<<"8.Tim mot phan tu trong danh sach neu thay, xoa phan tu\n";
	cout<<"9.Thoat\n";

	do{
		cout<<"Chon: ";
		cin>>choice;
	}while(choice > 0 && choice < 7);

	switch(choice){
	case 1: 
		init();
		break;
	case 2:
		ProcessList();
		break;
	case 3:
		cout<<"Nhap phan tu can tim: ";
		cin>>x;
		if(Search(x)==NULL)
			cout<<x<<" khong co trong danh sach!\n";
		else
			cout<<x<<" co trong danh sach tai dia chi: "<<Search(x)<<endl;
		break;
	case 4:
		cout<<"Nhap phan tu can them: ";
		cin>>x;
		InsertFirst(x);
		break;
	case 5:
		cout<<"Nhap phan tu can them: ";
		cin>>x;
		InsertLast(x);
		break;
	case 6:
		Delete_first();
		break;
	case 7:
		DeleteLast();
		break;
	case 8:
		cout << "Nhap phan tu can xoa: ";
		cin >> x;
		if (FindAndDelete(x) == 1)
			cout << "Da tim thay va xoa thanh cong!\n";
		else
			cout << "Khong tim thay phan tu\n";
	}
}