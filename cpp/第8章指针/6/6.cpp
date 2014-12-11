#include <iostream>
using namespace std;
int main()
{
	int i;
	int *p=0;
	cout<<"i的地址为："<<&i<<endl;
	cout<<"p的值为："<<p<<endl;
	cout<<"p的内存地址为："<<&p<<endl;
	i=3;
	cout<<"i的地址为："<<&i<<endl;
	p=&i;
	cout<<"p的值为："<<p<<endl;
	cout<<"p的内存地址为："<<&p<<endl;
	return 0;

}