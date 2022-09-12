#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
		node(int d){
			data=d;
			next=NULL;
		}
};
cout<<sizeof(node);
void insertAtHead(node *&head,int d){
	//CREATING 1ST NODE
	if(head==NULL){
		node *temp=new node(d);
		head=temp;
		return;
	} 
	node *temp=new node(d);
	temp->next=head;
	head=temp;
}
void insertAtTail(node *&tail,int d){
	if(tail==NULL){
		node *temp=new node(d);
		tail=temp;
		return;
	}
	node *temp=new node(d);
	tail->next=temp;
	tail=temp;
}

void insertAtAnyPoint(node *&tail,node *&head,int pos,int d){
	node *temp=head;
	int cnt=1;
	if(pos==1){
		insertAtHead(head,d);
		return;
	}
	while(cnt<pos-1){
		temp=temp->next;
		cnt++;
	}
	if(temp->next==NULL){
		insertAtTail(tail,d);
		return;
	} 
	node *nodeToInsert=new node(d);
	nodeToInsert->next=temp->next;
	temp->next=nodeToInsert; 
	
}
void disp(node *&head){
	node *temp;
	temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void deleteNode(node *&tail,node *&head,int pos){
	node *curr,*prev;
	curr=head;
	prev=NULL;
	if(pos==1){
		head=head->next;
		delete curr;
		return;
	}
	int cnt=1;
	while(cnt<pos){
		prev=curr;
		curr=curr->next;
		cnt++;
	}
	if(curr->next==NULL){
		prev->next=curr->next;
		tail=prev;
	}
	prev->next=curr->next;
	curr->next=NULL;
	delete curr;
}
int main(){
	node *head=NULL,*tail=NULL;
	node *n1=new node(10);
	head=n1;
	tail=n1;
	insertAtHead(head,12);
	insertAtHead(head,13);
	insertAtHead(head,12);
	insertAtTail(tail,15);
	insertAtTail(tail,14);
	insertAtAnyPoint(tail,head,1,2000);
	insertAtAnyPoint(tail,head,3,3000);
	insertAtAnyPoint(tail,head,4,4000);
	insertAtAnyPoint(tail,head,10,4000);
	disp(head);
	deleteNode(tail,head,5);
	deleteNode(tail,head,7);
	disp(head);
	cout<<"head:"<<head->data<<endl;
	cout<<"tail:"<<tail->data<<endl;
}
