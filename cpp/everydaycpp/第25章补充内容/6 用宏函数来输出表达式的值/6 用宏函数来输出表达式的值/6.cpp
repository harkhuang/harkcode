#define DEBUG
#include <iostream>
using namespace std;
#ifndef DEBUG
#define show(x)
#else
#define show(x)\
	cout<<#x<<":\t"<<x<<"\n";
#endif
int main()
{
	int x=9;
	show(x);
	int *y=&x;
	show(*y);
	show(y);
	char*ch="hello world";
	show(ch);
	return 0;
} 
