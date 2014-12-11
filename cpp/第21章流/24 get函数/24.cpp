/*
//例21.24.1  获取单个字符
#include <iostream>
using namespace std;
int main()
{
	char ch;
	ch=cin.get();
	cout<<"ch:"<<ch<<endl;
	return 0;
}
*/


/*
//例21.24.2  循环获取字符
#include <iostream>
using namespace std;
int main()
{
	char ch;
	while ((ch=cin.get())!='\n')
	{
		cout<<ch;
	}
	cout<<"\n程序结束\n";
	return 0;
}
*/

/*
//例21.24.3  输出回车键和"\n"的ASCII码值
#include<iostream>
using namespace std;
int main() 
{ 
	int c; 
	c=int('\n');
	cout<<c;
	cout<<endl;
	c=cin.get(); 
	cout<<c; 
	cout<<endl;
	return 0;
}
*/

/*
//例21.24.4 回车符"\r"覆盖开头的字符串
#include<iostream>
using namespace std;
int main() 
{ 
	cout<<"hello\r"<<"give me";
	return 0;
}
*/

/*
//例21.24.5  编译器不同使用回车符"\r"产生的结果也不同
#include<iostream>
using namespace std;
int main() 
{ 
	cout<<"hello\r";
	return 0;
}
*/


/*
//例21.24.6  需要输入时刷新缓冲区
#include<iostream>
using namespace std;
int main() 
{ 
	char ch[10];
	cout<<"hello\r";
	cin>>ch;
	return 0;
}
*/

/*
//引用例21.24.2		循环获取字符
#include <iostream>
using namespace std;
int main()
{
	char ch;
	while ((ch=cin.get())!='\n')
	{
		cout<<ch;
	}
	cout<<"程序结束\n";
	return 0;
}
*/


/*
//例21.24.7	  循环输出字符直到遇到字符s
#include <iostream>
using namespace std;
int main()
{
	char ch;
	while ((ch=cin.get())!='s')
	{
		cout<<ch;
	}
	cout<<"程序结束\n";
	return 0;
}
*/


//例21.24.8  将get()换为cin>>
#include <iostream>
using namespace std;
int main()
{
	char ch;
	cin>>ch;
	while (ch!='\n')
	{
		cout<<ch;
		cin>>ch;
	}
	cout<<"程序结束\n";
	return 0;
}
