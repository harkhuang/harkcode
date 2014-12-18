//例子：以下代码输出当天的时间与日期.

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
	strftime(ch,80,"今天的时间日期为：\n%A %B %d %Y %X \n",ptr);
	cout<<ch;
	return 0;
}
