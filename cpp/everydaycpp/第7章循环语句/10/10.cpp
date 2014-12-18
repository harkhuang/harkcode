#include <iostream>
using namespace std;
int main()
{
	int a,b;
	char c;
	cout<<"多少行？";
	cin>>a;
	cout<<"多少列？";
	cin>>b;
	cout<<"什么字？";
	cin>>c;
    for (int i=0;i<a;i++)
	{
      for (int j=0;j<b;j++)
	  {
		  cout<<c;
      }
       cout<<"\n";
    }
   return 0;
}