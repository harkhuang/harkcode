/*
//例18.20.1  把string对象传递给函数

#include <iostream>
#include <string>
using namespace std;
void show(const string p);
int main()
{
	string str="hello world";
	show(str);
	return 0;
}
void show(const string p)
{
	cout<<p;
}
*/

//例18.20.2  按引用传递string对象

#include <iostream>
#include <string>
using namespace std;
void show(const string &p);
int main()
{
	string str="hello world";
	show(str);
	return 0;
}
void show(const string &p)
{
	cout<<p;
}
