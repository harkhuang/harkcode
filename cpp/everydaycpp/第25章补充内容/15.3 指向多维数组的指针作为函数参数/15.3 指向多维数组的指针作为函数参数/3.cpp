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
	cout<<"����Ԫ����ӵ��ܺ�Ϊ��"<<sum<<endl;
}
void find(int(*p)[3],int n)
{
	int i;
	cout<<"��"<<n+1<<"�е�Ԫ��Ϊ��";
	for (i=0;i<3;i++)
	{
		cout<<*(*(p+n)+i)<<" ";
	}
} 
