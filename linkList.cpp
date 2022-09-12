#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *link;
		Node(int n){
			data=n;
			link=NULL;
		}
};
insertAtTail(Node *&tail,int d){
	Node *temp=new Node(d);
	tail->link=temp; 
	tail=temp;
}
insertAtHead(Node *&head,int d){
	Node *temp=new Node(d);
	temp->link=head;
	head=temp;
}
void show(Node *&head){
	Node *temp;
	temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"\t";
		temp=temp->link;
	}
	cout<<endl;
}
int main(){
	Node *n1=new Node(10);
	Node *head, *tail;
	head=n1;
	tail=n1;
	insertAtTail(tail,12);
	show(head);
	insertAtHead(head,30);
	show(head);
}
