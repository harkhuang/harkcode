#include <iostream>
using namespace std;
int main()
{
	int *p=new int;
	cout<<"ָ��p����Ŀռ��ַΪ��\t\t"<<p<<endl;
	p++;
	cout<<"�ԼӺ�ָ��p����Ŀռ��ַΪ��"<<p<<endl;
	p--;
	cout<<"�Լ���ָ��p����Ŀռ��ַΪ��"<<p<<endl;
	p=p-2;
	cout<<"��2��ָ��p����Ŀռ��ַΪ�� "<<p<<endl;
	return 0;
}
