//��18.15   char���ַ����뺯��

#include <iostream>
#include <string>
using namespace std;
int get(const char*p);
int main()
{
	char ch[15]="hello word";
	char *p="very well";
	int a=get(ch);
	int b=get(p);
	cout<<ch<<"����"<<a<<"���ַ�"<<endl;
	cout<<p<<"����"<<b<<"���ַ�"<<endl;
	return 0;
}
int get(const char*p)
{
	int count=0;
	while(*p)
	{
		count++;
		p++;
	}
	return count;
}
