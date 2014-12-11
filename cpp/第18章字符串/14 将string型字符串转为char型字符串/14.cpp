//例18.14  将string型字符串转为char型字符串

#include <iostream>
#include<string>
using namespace std;
int main()
{
	string str="hello world";
	const char *ch;
	ch=str.c_str();
	cout<<ch;
	return 0;
}
