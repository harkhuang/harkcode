#include <iostream>
using namespace std;
int main()
{
	int a[5];
	int i;
	for (i=4;i>=0;i--)
	{
		a[i]=i;
		cout<<a[i]<<endl;
	}
	return 0;
}