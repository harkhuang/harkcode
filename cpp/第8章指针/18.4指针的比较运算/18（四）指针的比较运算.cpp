#include<iostream>
using namespace std;
int main()
{  
	int*p=new int;
	cout<<"p:"<<p<<endl;
	int *p1=new int;
	cout<<"p1:"<<p1<<endl;
	if(p>p1)
		cout<<"p大于p1的内存地址。\n";
	else
		 cout<<"p小于p1的内存地址。\n";
	return 0;
}