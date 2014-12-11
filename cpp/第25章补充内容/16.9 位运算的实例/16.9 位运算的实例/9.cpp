#include<iostream>
using namespace std;
int main()
{
	int a,b,i;
	cout<<"请输入一个整数：";
	cin>>a;
	b=1<<15;						//构造一个最高位为 1、其余各位为0的整数
	cout<<a<<"的二进制形式为：";
	for(i=1;i<=16;i++)
	{
		cout<<(a&b?'1':'0');        	//输出最高位的值（1或者0）
		a<<=1;                  	//将次高位移到最高位上
		if(i%4==0) cout<<' ';       	//四位一组用空格分开
	}
	cout<<"\n";
}
