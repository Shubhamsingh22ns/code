#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
		node *prev;
		node(int d){
			data=d;
			next=NULL;
			prev=NULL;
		}
};
void insertAtHead(node *&head,int d){
	node *temp=new node(d);
	temp->next=head;
	head->prev=temp;
	head=temp;
}
void insertAtTail(node *&tail,int d){
	node *temp=new node(d);
	temp->prev=tail;
	tail->next=temp;
	tail=temp;
}
void deleteNode(node *&tail,node *&head,int pos){
	//delete 1st node
	if(pos==1){
		node *temp=head;
		temp->next->prev=NULL;
		head=temp->next;
		temp->next=NULL;
		delete temp;
		return;
	}
	int cnt=1;
	node *left,*right;
	left=NULL;
	right=head;
	while(cnt<pos){
		left=right;
		right=right->next;
		cnt++;
	}
	//DELETE LAST NODE
	if(right->next==NULL){
		left=tail;
		left->next=NULL;
		right->prev=NULL;
		delete right;
	}
	left->next=right->next;
	right->next->prev=left;
	right->next=NULL;
	right->prev=NULL;
	delete right;

}
void insertAtAnyPostion(node *&tail,node *&head,int pos,int d){
	if(pos==1){
		insertAtHead(head,d);
		return;
	}
	node *left,*right;
	left=NULL;
	right=head;
	int cnt=1;
	while(cnt<pos){
		left=right;
		right=right->next;
		cnt++;
	}
	if(right->next==NULL){
		insertAtTail(tail,d);
		return;
	}
	node *insertNode=new node(d);
	insertNode->next=right;
	right->prev=insertNode;
	insertNode->prev=left;
	left->next=insertNode;
}
void disp(node *&head){
	node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	node *n1=new node(10);
	node *head,*tail;
	head=n1;
	tail=n1;
	insertAtHead(head,12);
	disp(head);
	cout<<"head:"<<head->data<<endl;
	cout<<"tail:"<<tail->data<<endl;
	insertAtHead(head,13);
	disp(head);
	cout<<"head:"<<head->data<<endl;
	cout<<"tail:"<<tail->data<<endl;
	insertAtTail(tail,20);
	disp(head);
	cout<<"head:"<<head->data<<endl;
	cout<<"tail:"<<tail->data<<endl;
	insertAtAnyPostion(tail,head,3,30);
	disp(head);
	cout<<"head:"<<head->data<<endl;
	cout<<"tail:"<<tail->data<<endl;
	insertAtAnyPostion(tail,head,1,100);
	disp(head);
	cout<<"head:"<<head->data<<endl;
	cout<<"tail:"<<tail->data<<endl;
	insertAtAnyPostion(tail,head,6,30);
	disp(head);
	cout<<"head:"<<head->data<<endl;
	cout<<"tail:"<<tail->data<<endl;
	deleteNode(tail,head,2);
	disp(head);
	cout<<"head:"<<head->data<<endl;
	cout<<"tail:"<<tail->data<<endl;
	deleteNode(tail,head,6);
	disp(head);
	cout<<"head:"<<head->data<<endl;
	cout<<"tail:"<<tail->data<<endl;
	}
