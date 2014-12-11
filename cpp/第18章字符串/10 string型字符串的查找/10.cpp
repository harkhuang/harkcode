/*
//例18.10.1  char型字符串的查找

#include <iostream>
using namespace std;
int main(void)
{
	char ch1[15];
	char *p, c = 'w';
	strcpy(ch1, "hello world");
	p = strchr(ch1, c);
	if (p)
		cout<<"字符"<<c<<"位于第"<<p-ch1<<endl;
	else
		cout<<"没有找到";
	return 0;
}
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1( "hello world" );
	int f = str1.find( "w",0);
	if( f!= string::npos )
		cout << "在第 " << f<<"个字符" << endl;
	else
		cout << "没有找到" << endl;
	return 0;
}
