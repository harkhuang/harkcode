#include <iostream>
using namespace std;
int main()
{
	int *p=new int;
	*p=3;
	cout<<"��3����p�ĵ�ַ��ָ��p��ȡ��ֵ��\t"<<*p<<endl;
	delete p;
	p=0;
	//cout<<"ɾ���ռ��ָ��p��ȡ��ֵ��\t\t"<<*p<<endl;
	long *p1=new long;
	cout<<"�����¿ռ��ָ��p�б���ĵ�ַ��\t"<<p<<endl;
	*p1=999999;
	cout<<"ָ���¿ռ��ָ��p1����ĵ�ַ��\t\t"<<p1<<endl;
	p=new int;
	*p=23;
	cout<<"��23����p�ĵ�ַ��ָ��p��ȡ��ֵ��\t"<<*p<<endl;
	cout<<"��23����p�ĵ�ַ��ָ��p1��ȡ��ֵ��\t"<<*p1<<endl;
	delete p1;
	return 0;
}