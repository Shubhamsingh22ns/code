#include<iostream>
using namespace std;
class node{
	public:
		int data ;
		node *link;
		node(int data){
			this->data=data;
			link=NULL;
		}
};
void insertAtHead(node *&head,int d){
	//CREATING A NODE NAMED AS TEMP
	node *temp=new node(d);
	temp->link=head;
	head=temp;
}
void insertAtTail(node *&tail,int d){
	//CREATING A NODE NAMED AS TEMP
	node *temp=new node(d);
	tail->link=temp;
	tail=temp;
}
void insertAtPosition(node *&head,node *&tail,int pos,int d){
	node *temp;
	temp=head;
	int count=1;
	//INSERT AT 1ST POSITION
	if(pos==1){
		insertAtHead(head,d);
		return;
	}
	while(count<pos-1){
		temp=temp->link;
		count++;
	}
	//INSERTION AT LAST
	if(temp->link==NULL){
		insertAtTail(tail,d);
		return;
	}
	node *nodeToInsert=new node(d);
	nodeToInsert->link=temp->link;
	temp->link=nodeToInsert;
}
void disp(node *&head){
	node *temp;
	temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"\t";
		temp=temp->link;
	}
	cout<<endl;
}
void deleteNode(node *&tail,node *&head,int pos){
	//DELETE 1ST NODE
	if(pos==1){
		node *temp=head;
		head=head->link;
		delete temp;
	}
	else{
		node *prev=NULL,*curr=head;
		int count=1;
		while(count<pos){
			prev=curr;
			curr=curr->link;
			count++;
		}
		if(curr->link==NULL){
			prev->link=curr->link;
			tail=prev;
			delete curr;
			return;
		}
		prev->link=curr->link;
		curr=NULL;
		delete curr;
	}
}

int main(){
	node *n1=new node(10);
	node *head,*tail;
	head=n1;
	tail=n1;
	cout<<"insert at haed: ";
	insertAtHead(head,12);
	disp(head);
	cout<<"insert at tail: ";
	insertAtTail(tail,100);
	disp(head);
	cout<<"insert at any position: ";
	insertAtPosition(head,tail,2,90);
	disp(head);
	insertAtPosition(head,tail,1,80);
	disp(head);
	cout<<"insert at tail: ";
	insertAtPosition(head,tail,6,110);
	disp(head);
	cout<<"DELETE NODE FROM HERE:"<<endl;
	deleteNode(tail,head,1);
	disp(head);
	deleteNode(tail,head,2);
	disp(head);
	deleteNode(tail,head,4);
	disp(head);
	cout<<"TAIL:"<<tail->data<<endl;
	cout<<"HEAD:"<<head->data<<endl;
}
