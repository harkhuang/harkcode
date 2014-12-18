/*
#include <iostream>
using namespace std;
int main()
{
	int a[3][4]=
		{
		  1,2,3,4,
		  11,12,13,14,
		  111,112,113,114
		};
	int *p;
	for (p=a[0];p<=&a[2][3];p++)
	{
		if ((p-a[0])%4==0)
		{
			cout<<"\n";
		}
		cout<<*p<<" ";
	}
}
*/

//加强训练

#include <iostream>
using namespace std;
int main()
{
	int a[3][4]=
		{
			 1,2,3,4,
			 11,12,13,14,
			 111,112,113,114
		};
	int(*p)[4],i,j;
	p=a;
	cout<<"请输入行数：\n";
	cin>>i;
	cout<<"请输入列数：\n";
	cin>>j;
	cout<<"a["<<i<<"]["<<j<<"]："<<*(*(p+i)+j);
	return 0;
}
