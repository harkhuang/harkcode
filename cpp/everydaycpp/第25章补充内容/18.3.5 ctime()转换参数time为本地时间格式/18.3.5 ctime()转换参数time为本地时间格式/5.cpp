#include <time.h>
#include <iostream>
using namespace std;
int main(void)
{
	time_t t;
	t = time(NULL);
	cout<<ctime(&t);
	return 0;
}
