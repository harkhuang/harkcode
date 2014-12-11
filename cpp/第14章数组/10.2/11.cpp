#include <iostream>
using namespace std;
int main()
{
	int a[6]={1,34,78,98,32,45};
	int i,j,t;
	for (j=0;j<5;j++)
	{
		for(i=0;i<6-j;i++)
			if (a[i]>a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}

	}	
	cout<<"排序后的数字为：\n";
	for (i=0;i<6;i++)
	{
		cout<<a[i]<<"\n";
	}
	return 0;
}