#define  num 10
#include <iostream>
using namespace std;
int main()
{
	int girl[num];
	int total,i;
	float average;
	total=0;
	cout<<"������"<<num<<"��Ů���ķ���\n";
	for (i=0;i<num;i++)
	{
		cout<<"���Ϊ"<<i+1<<"��Ů���ķ���=";
		cin>>girl[i];
		total=total+girl[i];
	}
	average=(float)total/num;
	cout<<num<<"��Ů����ƽ���ɼ�Ϊ��"<<average<<"\n";
	return 0;
}