#include <iostream>
using namespace std;
int find(int,int[],int);
int find1(int,int[],int);
bool add(int a[],int n);
void main()
{
	int a[]={22,1,66,88,44,32,64};
	if (add(a,7)==1)
	{
		cout<<"采用二分算法得到的位置为："<<find1(44,a,7)+1;
	}
	else
		cout<<"采用递增算法得到的位置为："<<find(44,a,7)+1;
}
int find(int m,int a[],int n)
{
	for (int i=0;i<n;i++)
	{
		if (a[i]==m)
		{
			return i;
		}
	}
	return n;
}
int find1(int m,int a[],int n)
{
	int o=0,h=n-1,i;
	while (o<=h)
	{
		i=(o+h)/2;
		if (a[i]==m)
		{
			return i;
		}
		if (a[i]<m)
		{
			o=i+1;
		}
		else
			h=i-1;
	}
	return n;
}
bool add(int a[],int n)
{
	for (int i=1;i<n;i++)
	{
		if (a[i]<a[i-1])
		{
			return false;
		}
	}
	return true;
}