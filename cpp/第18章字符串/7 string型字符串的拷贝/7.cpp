/*
#include <iostream>
using namespace std;
int main(void)
{
	char ch1[15] = "abcdefghijklmn";
	char ch2[] = "1234567890";
	cout<<"Դ�ַ���"<<ch1;
	memmove(ch1, ch2, 10);
	cout<<"������:" <<ch1;
	return 0;
}
*/

//��18.7.2  string���ַ����Ŀ���

#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string str = "abcd";
	char ch []= "1234";
	int n;
	cout<<"Դ�ַ���"<<ch<<endl;
	n=str.copy(ch, 4,0);
	cout<<"������"<<n<<"�ַ�"<<endl;
	cout<<"������:" <<ch<<endl;
	return 0;
}

