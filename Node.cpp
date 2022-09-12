#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
		node(int n){
			data=n;
			next=NULL;
		}
};
void insertAtHead(node *&head,int d){
	//NEW NODE CREATE
	node *temp=new node(d);
	temp->next=head;
	head=temp;
}
void disp(node *&head){
	node *temp;
	temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<endl;
}
void insertAtTail(node *&tail,int d){
	node *temp=new node(d);
	tail->next=temp; 
	tail=tail->next;
}
int main(){
	node *n1=new node(10);
	node *head,*tail;
	head=n1;
	tail=n1;
	insertAtHead(head,20);
	disp(head);
	insertAtHead(head,30);
	disp(head);
	insertAtTail(tail,40);
	disp(head);
}
