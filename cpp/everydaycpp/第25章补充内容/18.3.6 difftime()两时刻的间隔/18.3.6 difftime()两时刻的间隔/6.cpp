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
	cout<<"ѭ��ʹ����"<<difftime(end,start)<<"��.\n";
	return 0;
}
