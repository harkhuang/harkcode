#include <iostream>
using namespace std;
void show(char*name[],int n);
int main()
{
	char*name[]={"Jack","Mick","Rose","Jesson","Tom"};
	show(name,5);
	return 0;
}
void show(char*name[],int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		cout<<name[i]<<endl;
	}
}
