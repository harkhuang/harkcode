#include <iostream>
using namespace std;
bool add(int a[],int n);
void main()
{
	int a[]={22,44,66,88,1,32,64};
	bool check=add(a,7);
	if (check==true)
	{
		cout<<"����a��7��Ԫ���ǰ��մ�С�����˳�����еġ�\n";
	}
	else
		cout<<"����a��7��Ԫ�ز��ǰ��մ�С�����˳�����еġ�\n";
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