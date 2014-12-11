/*
//例21.28.1  getline()函数的使用
#include <iostream>
using namespace std;
int main()
{
	char ch1[30];
	char ch2[30];
	cout<<"请输入第一串字符:";
	cin.getline(ch1,30);
	cout<<"字符串1为:"<<ch1<<endl;
	cout<<"请输入第二串字符：";
	cin.getline(ch2,30);
	cout<<"字符串2为:"<<ch2<<endl;
	cout<<"程序结束\n";
	return 0;
}
*/

//例21.28.2  清空缓冲区
#include <iostream>
using namespace std;
int main()
{
	char ch1[30];
	char ch2[30];
	cout<<"请输入第一串字符:";
	cin.getline(ch1,30,'\s');
	cout<<"字符串1为:"<<ch1<<endl;
	cin.ignore(1024,'\n');
	cout<<"请输入第二串字符：";
	cin.getline(ch2,30);
	cout<<"字符串2为:"<<ch2<<endl;
	cout<<"程序结束\n";
	return 0;
}
