
//��18.21  ��string���鴫�ݸ�����

#include <iostream>
#include <string>
using namespace std;
void show(const string str[],int n);
int main()
{
	const int length=5;
	string str[length];
	for(int i=0;i<length;i++)
	{
		cout<<i+1<<":";
		cin>>str[i];
	}
	show(str,length);
	return 0;
}
void show(const string str[],int n)
{
	for (int i=0;i<n;i++)
	{
		cout<<i+1<<":"<<str[i]<<endl;
	}
}