#include <iostream>
using namespace std;
typedef unsigned short int ut;
int main()
{
	ut i;
	ut *p=0;
	i=5;
	p=&i;
	cout<<"i="<<i<<endl;
	cout<<"*p="<<*p<<endl;
	cout<<"��ָ�����޸ķ���i�е�����...\n";
	*p=90;
	cout<<"i="<<i<<endl;
	cout<<"*p="<<*p<<endl;
	i=9;
	cout<<"i="<<i<<endl;
	cout<<"*p="<<*p<<endl;
	return 0;
}