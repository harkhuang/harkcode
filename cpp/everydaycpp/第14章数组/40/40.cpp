#include <iostream>
using namespace std;
void main()
{
	const int n=10;
	int a[n][n];
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<=i;j++)
		{
			if (j==0||j==i)
			{
				a[i][j]=1;
			}
			else 
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n\n";
	}
}