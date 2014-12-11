#include <iostream>
using namespace std;
int find(int,int[],int);
void main()
{
	int a[]={44,32,55,64,34,43,22,98};
	cout<<"请输入要查找的数据：";
	int data;
	cin>>data;
	int check=find(data,a,8);
    if (check==8)
    {
		cout<<"没有查找到数据\n";
    }
	 else
		 cout<<data<<"在数组a中的位置为："<<check+1<<endl;
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