/*
//例21.27.1  使用带三个参数的get()函数
#include <iostream>
using namespace std;
int main()
{
	char ch1[30];
	char ch2[30];
	cout<<"请输入第一串字符:";
	cin.get(ch1,30,'s');
	cout<<"字符串1为:"<<ch1<<endl;
	cout<<"请输入第二串字符：";
	cin.ignore();
	cin.get(ch2,30);
	cout<<"字符串2为:"<<ch2<<endl;
	cout<<"程序结束\n";
	return 0;
}
*/

/*
//例21.27.2  抛弃缓冲区中的数据
#include <iostream>
using namespace std;
int main()
{
	char ch1[30];
	char ch2[30];
	cout<<"请输入第一串字符:";
	cin.get (ch1,30,'s');
	cout<<"字符串1为:"<<ch1<<endl;
	cout<<"请输入第二串字符：";
	cin.ignore(1024,'\n');
	cin.get(ch2,30);
	cout<<"字符串2为:"<<ch2<<endl;
	cout<<"程序结束\n";
	return 0;
}
*/

//例21.27.3  获得缓冲区的容量并丢弃该容量的数据
#include <iostream>
#include <limits>	//为了使用numeric_limits
using namespace std;
int main()
{
	char ch1[30];
	char ch2[30];
	cout<<"请输入第一串字符:";
	cin.get (ch1,30,'s');
	cout<<"字符串1为:"<<ch1<<endl;
	cout<<"请输入第二串字符：";
	cin.ignore( numeric_limits<streamsize>::max(),'\n');
	// numeric_limits<streamsize>::max( ) 返回缓冲区的大小。
	//ignore 函数在此将把输入缓冲区中的数据清空。
	cin.get (ch2,30);
	cout<<"字符串2为:"<<ch2<<endl;
	cout<<"程序结束\n";
	return 0;
}
