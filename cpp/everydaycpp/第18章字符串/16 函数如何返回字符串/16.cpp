//��18.16. ����һ���ַ����ĵ�ַ

#include <iostream>
#include <string>
using namespace std;
char *get(char*str);
int main()
{
	char c[10];
	char *ch;
	cout<<"�������������֣�";
	cin>>c;
	ch=get(c);
	cout<<"����������"<<ch<<endl;
	delete []ch;
	ch=get("Jack");
	cout<<"����������"<<ch<<endl;
	delete []ch;
	char *ch1="Mike";
	ch=get(ch1);
	cout<<"����������"<<ch<<endl;
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
