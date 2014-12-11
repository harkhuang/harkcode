#include <iostream>
using namespace std;
int main()
{
	union
	{
		int a;
		int b;
	};
	cout<<"请输入a的值：";
	cin>>a;
	cout<<"请输入b的值：";
	cin>>b;
	cout<<"a:"<<a<<"\t"<<"b:"<<b;
	return 0;
}
