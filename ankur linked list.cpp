#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(int data){
			this->data=data;
			this->next=NULL;
		}
};
void InsertAtHead(Node* &head,int d){
	Node* temp=new Node(d);
	temp->next=head;
	head=temp;
}
void InsertAtTail(Node* &tail,int d){
	Node* temp=new Node(d);
	tail->next=temp;
	tail=temp;
}
void print(Node* &head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"  ";
		temp=temp->next;
		
	}	
	cout<<endl;
}
int main(){
	Node* node1=new Node(5);
	cout<<node1->data<<endl;
	Node* head=node1;
	Node* tail=node1;
	//InsertAtHead(head,10);
	//print(head);
	//InsertAtHead(head,15);
	//print(head);
	//InsertAtHead(head,20);
	//print(head);
	InsertAtTail(tail,15);
	print(head);
	InsertAtTail(tail,20);
	print(head);
	InsertAtTail(tail,25);
	print(head);
	
}
