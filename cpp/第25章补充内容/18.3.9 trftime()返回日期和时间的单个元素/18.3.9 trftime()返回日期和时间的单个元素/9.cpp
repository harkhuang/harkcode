//���ӣ����´�����������ʱ��������.

#include <time.h>
#include <iostream>
using namespace std;
int main(void)
{
	struct tm *ptr;
	time_t t;
	char ch[80];
	t=time(NULL);
	ptr=localtime(&t);
	strftime(ch,80,"�����ʱ������Ϊ��\n%A %B %d %Y %X \n",ptr);
	cout<<ch;
	return 0;
}
