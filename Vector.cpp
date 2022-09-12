#include <iostream>
using namespace std;
#include<vector>
int main(){	
vector <int >v;
v.push_back(9);
v.push_back(10);
cout<<"capacity: "<<v.capacity()<<" size: "<<v.size()<<endl;

v.push_back(11);
cout<<"capacity: "<<v.capacity()<<" size: "<<v.size()<<endl;
v.push_back(22);
v.push_back(88);
}
