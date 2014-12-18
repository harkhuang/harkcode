/*
//21.29.1  输出乱字符"烫"
#include <iostream>
using namespace std;
int main()
{
	char ch[30];
	cout<<"请输入字符:";
	cin.read(ch,30);
	cout<<ch<<endl;
	cout<<"程序结束\n";
	return 0;
}
*/

/*
//21.29.2  解决输出乱字符"烫"的问题
#include <iostream>
using namespace std;
int main()
{
	char ch[30]={0};
	cout<<"请输入字符:";
	cin.read(ch,30);
	cout<<ch<<endl;
	cout<<"程序结束\n";
	return 0;
}
*/

//例21.29.3   超出字符进入缓冲区
#include <iostream>
using namespace std;
int main()
{
	char ch1[30]={0};
	char ch2[30];
	cout<<"请输入第一串字符:";
	cin.read(ch1,5);
	cout<<"字符串1为:"<<ch1<<endl;
	cout<<"请输入第二串字符：";
	cin.getline(ch2,30);
	cout<<"字符串2为:"<<ch2<<endl;
	cout<<"程序结束\n";
	return 0;
}
