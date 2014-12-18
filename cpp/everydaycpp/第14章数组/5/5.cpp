#include <iostream>
using namespace std;
int main()
{
	const int n=2;
	int a[n];
	int i;
	for (i=0;i<n;i++)
	{
		a[i]=i;
		cout<<a[i]<<endl;
	}
	return 0;
}