/*
//��18.10.1  char���ַ����Ĳ���

#include <iostream>
using namespace std;
int main(void)
{
	char ch1[15];
	char *p, c = 'w';
	strcpy(ch1, "hello world");
	p = strchr(ch1, c);
	if (p)
		cout<<"�ַ�"<<c<<"λ�ڵ�"<<p-ch1<<endl;
	else
		cout<<"û���ҵ�";
	return 0;
}
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1( "hello world" );
	int f = str1.find( "w",0);
	if( f!= string::npos )
		cout << "�ڵ� " << f<<"���ַ�" << endl;
	else
		cout << "û���ҵ�" << endl;
	return 0;
}
