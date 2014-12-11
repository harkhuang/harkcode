/*
//例21.26.1  带两个参数的get()函数的使用方法
#include <iostream>
using namespace std;
int main()
{
	char ch[20];
	cin.get(ch,20);
	cout<<ch;
	cout<<"程序结束\n";
	return 0;
}
*/

/*
//例21.26.2  带两个参数的get()函数的缺点
#include <iostream>
using namespace std;
int main()
{
	char ch1[20];
	char ch2[20];
	cout<<"请输入第一串字符：";
	cin.get(ch1,20);
	cout<<"字符串1为:"<<ch1<<endl;
	cout<<"请输入第二串字符："<<endl;
	cin.get(ch2,20);
	cout<<"字符串2为:"<<ch2<<endl;
	cout<<"程序结束\n";
	return 0;
}
*/

//例21.26.3  cin.ignore()的使用方法
#include <iostream>
using namespace std;
int main()
{
	char ch1[20];
	char ch2[20];
	cout<<"请输入第一串字符:";
	cin.get(ch1,20);
	cout<<"字符串1为:"<<ch1<<endl;
	cout<<"请输入第二串字符：";
	cin.ignore();
	cin.get(ch2,20);
	cout<<"字符串2为:"<<ch2<<endl;
	cout<<"程序结束\n";
	return 0;
}
