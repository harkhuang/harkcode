#include <iostream>
using namespace std;
int main()
{
	int i;
	int *p=0;
	cout<<"i�ĵ�ַΪ��"<<&i<<endl;
	cout<<"p��ֵΪ��"<<p<<endl;
	cout<<"p���ڴ��ַΪ��"<<&p<<endl;
	i=3;
	cout<<"i�ĵ�ַΪ��"<<&i<<endl;
	p=&i;
	cout<<"p��ֵΪ��"<<p<<endl;
	cout<<"p���ڴ��ַΪ��"<<&p<<endl;
	return 0;

}