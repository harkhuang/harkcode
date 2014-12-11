#include <iostream>
#include <assert.h>
using namespace std;
void main() 
{ 
	float a,b; 
	cout<<"请输入除数：";
	cin>>a;
	cout<<"请输入被除数：";
	cin>>b; 
	assert(b!=0); 
	cout<<"运算结果为:"<<a/b<<"\n";
} 
