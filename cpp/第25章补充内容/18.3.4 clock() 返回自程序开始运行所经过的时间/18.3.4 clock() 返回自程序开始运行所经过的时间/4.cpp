#include <iostream>
#include <time.h>
using namespace std;
void Rtime()
{
	cout<<"调用该程序所花费的时间: "<<clock()/CLOCKS_PER_SEC<<"secs\n";
}
int main()
{
	Rtime();
	return 0;
}
