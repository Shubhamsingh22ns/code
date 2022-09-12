#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *ptr;
		node(int data){
			this->data=data;
			ptr=NULL;
		}
		
};
int main(){
	node *n1=new node(20);
	cout<<n1->data<<endl;
	cout<<n1->ptr;
	
}
