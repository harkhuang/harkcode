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
	cout<<"������a��ֵ:";
	cin>>a;
	cout<<"������b��ֵ:";
	cin>>b;
	cout<<"�����Ϊ��";
	func(a,b,max);
	cout<<"��С��Ϊ��";
	func(a,b,min);
	cout<<"������ӵĺ�Ϊ��";
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
	cout<<"������a��ֵ:";
	cin>>a;
	cout<<"������b��ֵ:";
	cin>>b;
	cout<<"�����Ϊ��";
	func(a,b,max);
	cout<<"��С��Ϊ��";
	func(a,b,min);
	cout<<"������ӵĺ�Ϊ��";
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
