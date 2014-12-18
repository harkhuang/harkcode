//例18.16. 返回一个字符串的地址

#include <iostream>
#include <string>
using namespace std;
char *get(char*str);
int main()
{
	char c[10];
	char *ch;
	cout<<"请输入您的名字！";
	cin>>c;
	ch=get(c);
	cout<<"您的名字是"<<ch<<endl;
	delete []ch;
	ch=get("Jack");
	cout<<"您的名字是"<<ch<<endl;
	delete []ch;
	char *ch1="Mike";
	ch=get(ch1);
	cout<<"您的名字是"<<ch<<endl;
	delete []ch;
	return 0;
}
char *get(char*str)
{
	char *p=new char[strlen(str)+1];
	strcpy(p,str);
	cout<<p;
	return p;
}
