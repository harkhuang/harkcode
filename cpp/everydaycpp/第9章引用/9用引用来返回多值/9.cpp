#include <iostream>
using namespace std;
int func(int a,int&b,int&c);
int main()
{
	int a,b,c;
	int check;
	cout<<"������Ҫ������������֣�";
	cout<<"����������ֽ���ΪԲ�İ뾶�������εı߳���";
	cin>>a;
	check=func(a,b,c);
	if (check)
	{
		cout<<"��������ֳ������㷶Χ��\n";
	}
	else
	{
		cout<<"Բ�����Ϊ��"<<b<<endl;
		cout<<"�����ε����Ϊ��"<<c<<endl;
	}
	return 0;
}
int func(int a,int&b,int&c)
{
	if (a>20000)
	{
		a=1;
	}
	else
	{
		b=a*a*3.14;
		c=a*a;
		a=0;
	}
	return a;
}