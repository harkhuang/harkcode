#define  num 10
#include <iostream>
using namespace std;
int main()
{
	int girl[num];
	int total,i;
	float average;
	total=0;
	cout<<"请输入"<<num<<"名女生的分数\n";
	for (i=0;i<num;i++)
	{
		cout<<"编号为"<<i+1<<"的女生的分数=";
		cin>>girl[i];
		total=total+girl[i];
	}
	average=(float)total/num;
	cout<<num<<"名女生的平均成绩为："<<average<<"\n";
	return 0;
}