/*
#include <iostream>
using namespace std;
int max(int ,int);
int min(int,int);
int add(int,int);
void func(int x,int y,int(*p)(int,int));
int main()
{
	
	int a,b;
	cout<<"请输入a的值:";
	cin>>a;
	cout<<"请输入b的值:";
	cin>>b;
	cout<<"最大数为：";
	func(a,b,max);
	cout<<"最小数为：";
	func(a,b,min);
	cout<<"两数相加的和为：";
	func(a,b,add);
	return 0;
}
int max(int x,int y)
{
	int z;
	if (x>y)
	{
		z=x;
	}
	else
		z=y;
	return (z);
}
int min(int x,int y)
{
	int z;
	if (x<y)
	{
		z=x;
	}
	else
		z=y;
	return(z);
}
int add(int x,int y)
{
	int z;
	z=x+y;
	return(z);
}
void func(int x,int y,int(*p)(int,int))
{
	int z;
	z=(*p)(x,y);
	cout<<z<<endl;
}
*/


#include <iostream>
using namespace std;
int max(int ,int);
int min(int,int);
int add(int,int);
//void func(int x,int y,int(*p)(int,int));
void func(int x,int y,int p(int,int));
int main()
{
	
	int a,b;
	cout<<"请输入a的值:";
	cin>>a;
	cout<<"请输入b的值:";
	cin>>b;
	cout<<"最大数为：";
	func(a,b,max);
	cout<<"最小数为：";
	func(a,b,min);
	cout<<"两数相加的和为：";
	func(a,b,add);
	return 0;
}
int max(int x,int y)
{
	int z;
	if (x>y)
	{
		z=x;
	}
	else
		z=y;
	return (z);
}
int min(int x,int y)
{
	int z;
	if (x<y)
	{
		z=x;
	}
	else
		z=y;
	return(z);
}
int add(int x,int y)
{
	int z;
	z=x+y;
	return(z);
}
//void func(int x,int y,int(*p)(int,int))
void func(int x,int y,int p(int,int))
{
	int z;
	z=p(x,y);
	cout<<z<<endl;
} 
