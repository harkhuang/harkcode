#include <iostream>
#include <time.h>
using namespace std;
void Rtime()
{
	cout<<"���øó��������ѵ�ʱ��: "<<clock()/CLOCKS_PER_SEC<<"secs\n";
}
int main()
{
	Rtime();
	return 0;
}
