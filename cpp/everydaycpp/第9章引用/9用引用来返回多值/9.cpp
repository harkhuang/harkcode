#include <iostream>
using namespace std;
int func(int a,int&b,int&c);
int main()
{
	int a,b,c;
	int check;
	cout<<"请输入要进行运算的数字，";
	cout<<"您输入的数字将作为圆的半径和正方形的边长：";
	cin>>a;
	check=func(a,b,c);
	if (check)
	{
		cout<<"输入的数字超过计算范围！\n";
	}
	else
	{
		cout<<"圆的面积为："<<b<<endl;
		cout<<"正方形的面积为："<<c<<endl;
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