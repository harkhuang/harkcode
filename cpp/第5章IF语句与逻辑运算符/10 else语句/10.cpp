#include <iostream>
using namespace std;
int main()
{
	int a,b;
	cout<<"请输入第一个数：";
	cin>>a;
	cout<<"请输入第二个数：";
	cin>>b;
	if (a>b)
	{
		cout<<"第一个数比第二个数大。\n";
	}
	else
		cout<<"第二个数比第一个数大。\n";
	cout<<"该程序执行完毕\n";
	return 0;
}