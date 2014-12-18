/*
//例子1：显示从公元1970年1月1日0时0分0 秒至今的格林威治时间所经过的秒数。

#include<iostream>
#include <time.h>
using namespace std;
int main() 
{ 
	time_t t; 
    struct tm *p; 
	time(&t); 
	cout<<"从公元1970年1月1日0时0分0秒至今的格林威治时间所经过的秒数:"<<t<<endl; 
	p=localtime(&t); 
	t = mktime(p); 
	cout<<"从公元1970年1月1日0时0分0秒至今的格林威治时间所经过的秒数:"<<t<<endl;
return 0;
} 
*/


/*
//例子2：显示2007年11月1日是星期几。
#include <time.h>
#include <iostream>
using namespace std;
int main()
{
	struct tm t;
	time_t day;
	t.tm_year=2007-1900;
	t.tm_mon=10;
	t.tm_mday=1;
	t.tm_hour=18;
	t.tm_min=52;
	t.tm_sec=0;
	t.tm_isdst=0;
	day=mktime(&t);
	cout<<ctime(&day);
	return 0;
}
*/


//例子3：根据用户输入的数字N显示N天后的日期。

#include <time.h>
#include <iostream>
using namespace std;

void main( void )
{
   struct tm when;
   time_t now, result;
   int    days;

   time( &now );
   when = *localtime( &now );
   cout<<"当前时间日期为:\n"<<asctime(&when)<<"\n";
   cout<<"你想查看几天后的时间日期？请输入一个天数：" ;
   cin>>days;

   when.tm_mday = when.tm_mday + days;
   if( (result = mktime(&when)) != -1 )
      cout<< days<<"天后的时间日期为：\n"<<asctime(&when)<<"\n";
   else
      cerr<<"mktime失败";
}
