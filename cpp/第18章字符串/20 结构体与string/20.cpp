/*
//��18.20.1  ��string���󴫵ݸ�����

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

//��18.20.2  �����ô���string����

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
