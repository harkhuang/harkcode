#include <iostream>
using namespace std;
int main()
{
	char Peek;
	char ch[30];
	int i=0;
	while ((Peek=cin.peek())!='c'&&Peek!='\n')
	{
		cin.get(ch[i++]);
	}
	ch[i]='\0';
	cout<<ch;
	return 0;
}
