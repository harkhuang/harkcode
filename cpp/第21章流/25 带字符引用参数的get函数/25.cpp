/*
//例21.25.1  get()函数的级连
#include <iostream>
using namespace std;
int main()
{
	char a,b,c;
	cin.get(a).get(b).get(c);
	cout<<"a:"<<a<<"\nb:"<<b<<"\nc:"<<c<<endl;
	return 0;
}
*/

//例21.25.2	  循环到文件尾结束
#include <iostream>
using namespace std;
int main()
{
	char ch;
	while (cin.get(ch))
	{
		cout<<ch;
	}
	cout<<"程序结束\n";
	return 0;
}
