/*
//��21.28.1  getline()������ʹ��
#include <iostream>
using namespace std;
int main()
{
	char ch1[30];
	char ch2[30];
	cout<<"�������һ���ַ�:";
	cin.getline(ch1,30);
	cout<<"�ַ���1Ϊ:"<<ch1<<endl;
	cout<<"������ڶ����ַ���";
	cin.getline(ch2,30);
	cout<<"�ַ���2Ϊ:"<<ch2<<endl;
	cout<<"�������\n";
	return 0;
}
*/

//��21.28.2  ��ջ�����
#include <iostream>
using namespace std;
int main()
{
	char ch1[30];
	char ch2[30];
	cout<<"�������һ���ַ�:";
	cin.getline(ch1,30,'\s');
	cout<<"�ַ���1Ϊ:"<<ch1<<endl;
	cin.ignore(1024,'\n');
	cout<<"������ڶ����ַ���";
	cin.getline(ch2,30);
	cout<<"�ַ���2Ϊ:"<<ch2<<endl;
	cout<<"�������\n";
	return 0;
}
