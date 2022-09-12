#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node *prev,*next;
	node(int d){
		data=d;
		prev=NULL;
		next=NULL;
	}
};
void disp(node *head){
	node *temp;
	temp=head;
	while(temp!=0){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int getLength(node *head){
	int len=0;
	node *temp=head;
	while(temp!=NULL){
		len++;
		temp=temp->next;
	}
	return len;
}
void insertAthead(node *&tail,node *&head,int d){
	//EMPTY LIST
	if(head==NULL){
		node *temp=new node(d);
		head=temp;
		tail=temp;
	}
	else{
		node *temp=new node(d);
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
}
void insertAtTail(node *&tail,node *&head,int d){
	//EMPTY LIST
	if(tail==NULL){
		node *temp=new node(d);
		head=temp;
		tail=temp;
	}
	else{
		node *temp=new node(d);
		temp->prev=tail;
		tail->next=temp;
		tail=temp;
	}
}
void insertAtAnyPoint(node *&tail,node *&head,int pos,int d){
	//INSERT AT FIRST
	if(pos==1){
		insertAthead(tail,head,d);
		return;
	}
	//INSERT AT Pth POSITION
	node *temp=head;
	node *insertNode=new node(d);
	int count=1;
	while(count<pos-1){
		temp=temp->next;
		count++;
	}
	//INSERT AT LAST
	if(temp->next==NULL){
		insertAtTail(tail,head,d);
		return;
	}
	insertNode->next=temp->next;
	temp->next->prev=insertNode;
	temp->next=insertNode;
	insertNode->prev=temp;	
}
void deleteNode(node *&tail,node *&head,int pos){
	//DELETE 1ST NODE
	if(pos==1){
		node *temp=head;
		temp->next->prev=NULL;
		head=temp->next;
		temp->next=NULL;
		delete temp;
	}
		node *left=NULL,*curr=head;
		int count=1;
		while(count<pos){
			left=curr;
			curr=curr->next;
			count++;
		}
		if(curr->next=NULL){
			curr->next=NULL;
			tail=left;
			curr->prev=NULL;
			left->next=NULL;
			delete curr;	
		}
		left->next=curr->next;
		curr->next->prev=left;
		curr->prev=NULL;
		curr->next=NULL;
		delete curr;
	
}
int main(){
	node *head,*tail;
	head=NULL;
	tail=NULL;
	insertAthead(tail,head,12);
	disp(head);
	insertAthead(tail,head,11);
	disp(head);
	insertAtTail(tail,head,25);
	disp(head);
	insertAtTail(tail,head,26);
	disp(head);
	insertAtAnyPoint(tail,head ,1,2);
	disp(head);
	insertAtAnyPoint(tail,head ,6,27);
	disp(head); 
	insertAtAnyPoint(tail,head,2,22);
	disp(head);
	cout<<"head:"<<head->data<<endl;
	cout<<"tail:"<<tail->data<<endl;
	deleteNode(tail,head,4);
	disp(head);
	cout<<"head:"<<head->data<<endl;
	cout<<"tail:"<<tail->data<<endl;
	deleteNode(tail,head,5);
	disp(head);
	cout<<"head:"<<head->data<<endl;
	cout<<"tail:"<<tail->data<<endl;
}
