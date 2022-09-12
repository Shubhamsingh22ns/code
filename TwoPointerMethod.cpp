//TWO POINTER APPROCH IF SORTED ARRAY IS GIVEN
#include <iostream>
using namespace std;
int main(){
	int arr1[]={1,2,2,3,3,4};
	int n1=6;
	int arr2[]={2,2,3,3};
	int n2=4;
	int i=0,j=0;
	while(i<n1 && j<n2){
		if(arr1[i]<arr2[j]){
			i++;
		}
		else if(arr1[i]==arr2[j]){
			cout<<arr1[i]<<"\t";
			i++;
			j++;
		}
		else if(arr1[i]>arr2[j]){
			j++;
		}
	}
}
