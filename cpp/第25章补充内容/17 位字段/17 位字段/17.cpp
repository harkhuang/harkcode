#include <iostream>
using namespace std;
struct Date
	{ 
	unsigned day:5;
	unsigned  month:4;
	unsigned  year:14;
	}; 
int main()
{
	Date date;
	date.day = 12; 
	cout<<date.day<<endl;
	Date*p=&date;
	p->year=1999;
	cout<<p->year<<endl;
	return 0;
}
