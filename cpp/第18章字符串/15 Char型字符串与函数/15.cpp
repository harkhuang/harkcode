//例18.15   char型字符串与函数

#include <iostream>
#include <string>
using namespace std;
int get(const char*p);
int main()
{
	char ch[15]="hello word";
	char *p="very well";
	int a=get(ch);
	int b=get(p);
	cout<<ch<<"共有"<<a<<"个字符"<<endl;
	cout<<p<<"共有"<<b<<"个字符"<<endl;
	return 0;
}
int get(const char*p)
{
	int count=0;
	while(*p)
	{
		count++;
		p++;
	}
	return count;
}
