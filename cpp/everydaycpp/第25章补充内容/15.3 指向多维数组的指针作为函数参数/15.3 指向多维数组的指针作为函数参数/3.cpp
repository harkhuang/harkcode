#include <iostream>
using namespace std;
int main()
{
	void sum(int*p,int n);
	void find(int(*p)[3],int n);
	int num[2][3]=
	{
		1,2,3,
		4,5,6
	};
	sum(*num,6);
	find(num,1);
}
void sum(int*p,int n)
{
	int*end;
	int sum=0;
	end=p+n-1;
	for (;p<=end;p++)
	{
		sum=sum+(*p);
	}
	cout<<"所有元素相加的总和为："<<sum<<endl;
}
void find(int(*p)[3],int n)
{
	int i;
	cout<<"第"<<n+1<<"行的元素为：";
	for (i=0;i<3;i++)
	{
		cout<<*(*(p+n)+i)<<" ";
	}
} 
