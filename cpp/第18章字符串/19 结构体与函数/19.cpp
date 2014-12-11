/*
//例18.19.1	函数按值返回结构体

#include <iostream>
using namespace std;
struct time
{
	int hour;
	int minute;
};
const int perhour=60;
time sum(time t1,time t2);
void show(time t);
int main()
{
	time one={8,15};
	time two={6,55};
	time day=sum(one,two);
	cout<<"两天总计:";
	show(day);
	time day3={9,35};
	cout<<"三天总计:";
	show(sum(day,day3));
	return 0;
}
time sum(time t1,time t2)
{
	time total;
	total.minute=(t1.minute+t2.minute)%perhour;
	total.hour=t1.hour+t2.hour+(t1.minute+t2.minute)/perhour;
	return total;
}
void show(time t)
{
	cout<<t.hour<<":"<<t.minute<<endl;
}
*/

//例18.19.2  函数按址返回结构体

#include <iostream>
using namespace std;
struct time
{
	int hour;
	int minute;
};
const int perhour=60;
time &sum(time t1,time t2);
void show(time t);
int main()
{
	time one={8,15};
	time two={6,55};
	time *day=&sum(one,two);
	cout<<"两天总计:";
	show(*day);
	time day2={9,35};
	cout<<"三天总计:";
	time *p1=&sum(*day,day2);
	show(*p1);
	delete day;
	delete p1;
	return 0;
}
time &sum(time t1,time t2)
{
    time *total=new time;
	total->minute=(t1.minute+t2.minute)%perhour;
	total->hour=t1.hour+t2.hour+(t1.minute+t2.minute)/perhour;
	return *total;
}
void show(time t)
{
	cout<<t.hour<<":"<<t.minute<<endl;
}

