#include<iostream>
using namespace std;
int main()
{
	char ch;
	while (cin.get(ch)) //到文件尾结束
	{
		if (ch=='#') //假如ch等于'#'
		{
			cin.putback('$');  //将'#'丢弃并将'￥'放进输入流
		}
		else
		{
			cout<<ch;
		}
	}
	return 0;
}
