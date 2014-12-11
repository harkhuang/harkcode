#include <time.h>
#include <iostream>
using namespace std;
int main()
{
	time_t start,end;
	start = time(NULL);
	long unsigned i;
	for(i= 0;i<900000000;i++);
	end = time(NULL);
	cout<<"循环使用了"<<difftime(end,start)<<"秒.\n";
	return 0;
}
