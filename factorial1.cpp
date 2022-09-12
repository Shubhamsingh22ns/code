//POWER TYPE PROBLEM (x^n) BY RECURSIVE METHOD
#include <iostream>
using namespace std;
int factorial(int x,int n){
	if(n==0){
		return 1;
	}
	int smallAns=factorial(x,n-1);
	int output=x*smallAns;
	return output;
}
int main(){
	int n,x;
	cout<<"enter the the number:";
	cin>>x;
	cout<<"enter power:";
	cin>>n;
	int ans=factorial(x,n);
	cout<<ans;
}
