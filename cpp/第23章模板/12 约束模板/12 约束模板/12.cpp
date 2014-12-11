#include <iostream>
#include <string>
using namespace std;
template<class T>
T Max(T a,T b)
{
	return(a>b)?(a):(b);
}
char*Max(char*a,char*b)
{
	if(strcmp(a,b)>0)
		return a;
	else
		return b;
}

int main()
{
	int x=2,y=3;
	cout<<Max(x,y)<<endl;
	char*ch1="abc";
	char*ch2="def";
	cout<<Max(ch1,ch2)<<endl;
	return 0;
} 
