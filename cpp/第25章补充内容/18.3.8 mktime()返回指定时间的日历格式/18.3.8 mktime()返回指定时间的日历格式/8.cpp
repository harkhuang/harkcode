/*
//����1����ʾ�ӹ�Ԫ1970��1��1��0ʱ0��0 ������ĸ�������ʱ����������������

#include<iostream>
#include <time.h>
using namespace std;
int main() 
{ 
	time_t t; 
    struct tm *p; 
	time(&t); 
	cout<<"�ӹ�Ԫ1970��1��1��0ʱ0��0������ĸ�������ʱ��������������:"<<t<<endl; 
	p=localtime(&t); 
	t = mktime(p); 
	cout<<"�ӹ�Ԫ1970��1��1��0ʱ0��0������ĸ�������ʱ��������������:"<<t<<endl;
return 0;
} 
*/


/*
//����2����ʾ2007��11��1�������ڼ���
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


//����3�������û����������N��ʾN�������ڡ�

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
   cout<<"��ǰʱ������Ϊ:\n"<<asctime(&when)<<"\n";
   cout<<"����鿴������ʱ�����ڣ�������һ��������" ;
   cin>>days;

   when.tm_mday = when.tm_mday + days;
   if( (result = mktime(&when)) != -1 )
      cout<< days<<"����ʱ������Ϊ��\n"<<asctime(&when)<<"\n";
   else
      cerr<<"mktimeʧ��";
}
