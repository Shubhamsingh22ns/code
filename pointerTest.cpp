#include <iostream>
using namespace std;
int main(){
	int i=10;
	int *ptr=&i;
	cout<<"size of i:"<<sizeof(i)<<endl;
	cout<<"size of pointer:"<<sizeof(ptr)<<endl;
	char ch='d';
	char *ptr2=&ch;
	cout<<"size of i:"<<sizeof(ch)<<endl;
	cout<<"size of pointer:"<<sizeof(ptr2)<<endl;
}
