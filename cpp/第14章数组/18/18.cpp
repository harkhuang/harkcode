#include <iostream>
using namespace std;
int find(int,int[],int);
void main()
{
	int a[]={1,32,55,67,68,70,70,73,82,101,198,200,201};
	int check=find(70,a,13);
	if (check==13)
	{
		cout<<"没有查找到数据\n";
	}
	else
		cout<<"70在数组a中的位置是："<<check+1<<endl;
}
int find(int m,int a[],int n)
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