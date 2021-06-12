#include<bits/stdc++.h>
using namespace std;
#define int long long int

class Node{
public:
	int data;
	Node* next;
	Node(){
		data=-1;
		next=NULL;
	}
	Node(int x){
		data=x;
		next=NULL;
	}
};
class llist{
	Node* root=NULL;
public:
	void addval(int x){
		Node* p=new Node(x);
		Node* ptr=root;
		if(root==NULL){
			root=p;
			return;
		}
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=p;
	}
	void insertfirstnode(int x){
		Node* ptr=root;
		Node* p=new Node(x);
		if(root==NULL){
			root=p;return;
		}
		p->next=root;
		root=p;
	}
	void deletefirstnode(){
		Node* ptr=root;
		if(root==NULL)	return;
		root=root->next;
		delete(ptr);
	}
	void deletelastnode(){
		if(root==NULL)	return;
		Node* ptr=root;
		if(root->next==NULL){
			root=NULL;
			delete(ptr);
			return;
		}
		Node* p1=root;
		Node* p2=root;
		p1=root;
		while((p1->next)!=NULL){
			p2=p1;
			p1=p1->next;
		}
		p2->next=NULL;
		delete(p1);
	}
	void reveselist(){
		Node* ptr1=NULL;
		Node* ptr2;
		if(root==NULL)	return;
		while(root!=NULL){
			ptr2=ptr1;
			ptr1=root;
			root=(root->next);
			ptr1->next=ptr2;
		}
		root=ptr1;
	}
	void findmiddlenode(){
		Node* slow=root;
		Node* fast=root;
		if(root==NULL){
			cout << "List is empty, No middle element exist:\n";
			return;
		}
		while(fast!=NULL && fast->next!=NULL){
			slow=slow->next;
			fast=fast->next;
			fast=fast->next;
		}
		cout << "Middle element is : " << slow->data << endl;
	}
	bool is_sorted(Node* ptr){
		if(ptr==NULL)	return true;
		if(ptr->next==NULL)	return true;
		Node* prev=ptr;
		Node* cur=ptr->next;
		while(cur!=NULL){
			if((prev->data)>(cur->data))	return false;
			prev=cur;
			cur=cur->next;	
		}
		return true;
	}
	Node* getmid(Node* ptr){
		Node* midprev=NULL;
		while(ptr!=NULL && ptr->next!=NULL){
			midprev=(midprev==NULL)?ptr:midprev->next;
			ptr=ptr->next;
			ptr=ptr->next;
		}
		Node* mid=midprev->next;
		midprev->next=NULL;
		return mid;
	}
	Node* merge(Node* l1,Node* l2){
		Node tmp(0);
		Node* ptr=&tmp;
		while(l1!=NULL && l2!=NULL){
			if((l1->data)<(l2->data)){
				ptr->next=l1;
				l1=l1->next;
			}
			else{
				ptr->next=l2;
				l2=l2->next;
			}
			ptr=ptr->next;
		}
		if(l1)	ptr->next=l1;
		else	ptr->next=l2;
		return tmp.next;
	}
	Node* sort_list(Node* ptr){
		if(ptr==NULL || ptr->next==NULL)	return ptr;
		Node* mid=getmid(ptr);
		Node* left=sort_list(ptr);
		Node* right=sort_list(mid);
		return merge(left,right);
	}
	void sortlist(){
		root=sort_list(root);
	}
	bool is_cycle(){
		Node* ptr=root;
		Node* sp=root;
		Node* fp=root;
		while(sp!=NULL && fp!=NULL && fp->next!=NULL){
			sp=sp->next;
			fp=fp->next->next;
			if(sp==fp)	return true;
		}
		return false;
	}
	void remove_duplicates(){
		if(!is_sorted(root)){
			sortlist();
		}
		Node* cur=root;
		Node* nxt_nxt=root;
		if(root==NULL)	return;
		while(cur->next!=NULL){
			if(cur->data==cur->next->data){
				nxt_nxt=cur->next->next;
				free(cur->next);
				cur->next=nxt_nxt;
			}
			else{
				cur=cur->next;
			}
		}
	}
	void printlist(){
		Node* ptr=root;
		cout << "Linked list data are:  ";
		while(ptr!=NULL){
			cout << ptr->data << " ";
			ptr=ptr->next;
		}
		cout << endl;
	}
};

int32_t main(){

	int choice,val;
	bool is_by=false;
	llist lt;
	while(true){
		cout << "Enter 1 for add one element\n";
		cout << "Enter 2 for add one element at the end\n";
		cout << "Enter 3 for add one element at the beginning\n";
		cout << "Enter 4 for delete one element from beginning\n";
		cout << "Enter 5 for delete one element from end\n";
		cout << "Enter 6 for middle element\n";
		cout << "Enter 7 for reverse the list\n";
		cout << "Enter 8 for sort the list\n";
		cout << "Enter 9 for remove duplicate from the list\n";
		cout << "Your choice: ";
		cin >> choice;
		switch(choice){
			case 1:
				cout << "Enter value: ";
				cin >> val;
				lt.addval(val);
				break;
			case 2:
				cout << "Enter value: ";
				cin >> val;
				lt.addval(val);
				break;
			case 3:
				cout << "Enter value: ";
				cin >> val;
				lt.insertfirstnode(val);
				break;
			case 4:
				lt.deletefirstnode();
				break;
			case 5:
				lt.deletelastnode();
				break;
			case 6:
				lt.findmiddlenode();
				break;
			case 7:
				lt.reveselist();
				break;
			case 8:
				lt.sortlist();
				break;
			case 9:
				lt.remove_duplicates();
				break;
			default:
				is_by=true;
				break;
		}
		if(is_by){
			cout << "bye\n";
			break;
		}
		system("cls");
		lt.printlist();
		cout << endl;
	}

	return 0;
}
