#include <iostream>
using namespace std;
bool add(int a[],int n);
void main()
{
	int a[]={22,44,66,88,1,32,64};
	bool check=add(a,7);
	if (check==true)
	{
		cout<<"数组a的7个元素是按照从小到大的顺序排列的。\n";
	}
	else
		cout<<"数组a的7个元素不是按照从小到大的顺序排列的。\n";
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