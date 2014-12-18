//例18.12  string类的成员函数empty

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str="";
	if(str.empty())
		cout<<"字符串为空！";
	else
		cout<<str;
	return 0;
}
