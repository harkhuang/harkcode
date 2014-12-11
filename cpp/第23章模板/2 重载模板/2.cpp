#include <iostream>
using namespace std;
const int num=10;
template<class T>
void Swap(T &rx,T &ry)
{
	cout<<"调用Swap(T &rx,T &ry)函数\n";
	T temp=rx;
	rx=ry;
	ry=temp;
}
template<class T>
void Swap(T rx[],T ry[],int n)
{
	cout<<"调用Swap(T rx[],T ry[],int n)函数\n";
	T temp;
	for (int i=0;i<n;i++)
	{
		temp=rx[i];
		rx[i]=ry[i];
		ry[i]=temp;
	}
}
template<class T>
void show(T rx[],T ry[],int n)
{
	for (int i=0;i<n;i++)
	{
		cout<<"num1["<<i<<"]:"<<rx[i]<<" num2["<<i<<"]:"<<ry[i]<<endl;
	}	
}
int main()
{
	int x=2,y=3;
	cout<<"交换前，x:"<<x<<" y:"<<y<<endl;
	Swap(x,y);
	cout<<"交换后，x:"<<x<<" y:"<<y<<endl;
	int num1[num]={10,11,12,13,14,15,16,17,18,19};
	int num2[num]={0,1,2,3,4,5,6,7,8,9};
	cout<<"交换前:\n";
	show(num1,num2,num);
	Swap(num1,num2,num);
	cout<<"交换后:\n";
	show(num1,num2,num);
	return 0;
}
