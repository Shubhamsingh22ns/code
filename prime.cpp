#include<iostream>
using namespace std;
int main(){
	int num,n,i=2;
	bool flag=0;
	cout<<"enter no:";
	cin>>n;
	while(i<n){
		if(n%i==0){
			flag=1;
			break;
		}
		i++;
	}
	if(flag){
		cout<<"not prime";
	}
	else
	cout<<" prime";
}
