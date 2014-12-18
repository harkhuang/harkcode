#include <iostream>
using namespace std;
int main()
{
	for(int i=0;i<60;i++)
	{
		if (i%6==0)
		{
			cout<<"\n";
		}
		cout<<i<<"\t";
	}
	return 0;
}
