#include <iostream>
using namespace std;
int main()
{
	int a[13]={1,1};
	int n;
	for (n=2;n<13;n++)
	{
		a[n]=a[n-1]+a[n-2];
		
	}
	cout<<a[12]<<endl;
	return 0;
}