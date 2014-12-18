#include <iostream>
using namespace std;
int main()
{
	int *p=new int;
	if (p!=NULL)
	{
		int &r=*p;	
		r=3;
		cout<<r<<endl;
	}
	return 0;
}