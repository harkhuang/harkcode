#include <time.h>
#include <iostream>
using namespace std;
int main()
{
	struct tm *ptr;
	time_t t;
	t =time(NULL);
	ptr=localtime(&t);
	cout<<asctime(ptr);
	return 0;
}
