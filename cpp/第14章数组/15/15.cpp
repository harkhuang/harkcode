#include <iostream> 
using namespace std;
float average(int *,int);    
void main (void) 
{ 
	int a[100];
	float Average;
	int num=100;
	int i;
	for (i=0;i<100;i++)
	{
		a[i]=num;
		num++;
		cout<<a[i]<<endl;
	}
	Average=average(a,100);
	cout<<"\n 100-199的平均值为："<<Average<<endl;
} 
float average(int *p,int total)
{
	int sum=0;
	float b;
	int i;
	for (i=0;i<total;i++)
	{
		sum=sum+p[i];
		
	}
	b=(float)sum/total;
	return b;
}



