#include<iostream>
using namespace std;
int main()
{  
	int*p=new int;
	cout<<"p:"<<p<<endl;
	int *p1=new int;
	cout<<"p1:"<<p1<<endl;
	if(p>p1)
		cout<<"p����p1���ڴ��ַ��\n";
	else
		 cout<<"pС��p1���ڴ��ַ��\n";
	return 0;
}