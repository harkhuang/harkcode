/*
#include <iostream>
using namespace std;
int main()
{
	char*name[]={"Jack","Mick","Rose","Jesson","Tom"};
	char**p;
	int i;
	for (i=0;i<5;i++)
	{
		p=name+i;
		cout<<*p<<endl;
	}
	return 0;
}
*/

#include <iostream>
using namespace std;
void main()
{
	int a[5]={1,2,3,4,5};
	int *p1[5];
	int **p2=p1;
	for (int i=0;i<5;i++)
	{
		p2[i]=&a[i];
	}
	for (int i=0;i<5;i++)
	{
		cout<<**p2;
		p2++;
	}
}
