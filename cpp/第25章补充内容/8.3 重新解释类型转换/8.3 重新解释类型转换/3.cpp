#include <iostream>
using namespace std;
void *p()
{
	static char ch[20];
	return ch;
}
int main()
{
	char*cp=reinterpret_cast<char*>(p());
	strcpy(cp,"hello,world");
	cout<<cp;
	return 0;
} 
