#include <iostream>
using namespace std;
int main()
{
	union
	{
		int a;
		int b;
	};
	cout<<"������a��ֵ��";
	cin>>a;
	cout<<"������b��ֵ��";
	cin>>b;
	cout<<"a:"<<a<<"\t"<<"b:"<<b;
	return 0;
}
