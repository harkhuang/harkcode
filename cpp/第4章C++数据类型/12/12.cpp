#include <iostream>
using namespace std;
int main()
{
	enum day{Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday};
	day today;
	today=Monday;
	if (today==Sunday||today==Saturday)
	{
		cout<<"周末休息\n";
	}
	else
		cout<<"工作日\n";
	return 0;
}