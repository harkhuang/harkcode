/*
//��21.26.1  ������������get()������ʹ�÷���
#include <iostream>
using namespace std;
int main()
{
	char ch[20];
	cin.get(ch,20);
	cout<<ch;
	cout<<"�������\n";
	return 0;
}
*/

/*
//��21.26.2  ������������get()������ȱ��
#include <iostream>
using namespace std;
int main()
{
	char ch1[20];
	char ch2[20];
	cout<<"�������һ���ַ���";
	cin.get(ch1,20);
	cout<<"�ַ���1Ϊ:"<<ch1<<endl;
	cout<<"������ڶ����ַ���"<<endl;
	cin.get(ch2,20);
	cout<<"�ַ���2Ϊ:"<<ch2<<endl;
	cout<<"�������\n";
	return 0;
}
*/

//��21.26.3  cin.ignore()��ʹ�÷���
#include <iostream>
using namespace std;
int main()
{
	char ch1[20];
	char ch2[20];
	cout<<"�������һ���ַ�:";
	cin.get(ch1,20);
	cout<<"�ַ���1Ϊ:"<<ch1<<endl;
	cout<<"������ڶ����ַ���";
	cin.ignore();
	cin.get(ch2,20);
	cout<<"�ַ���2Ϊ:"<<ch2<<endl;
	cout<<"�������\n";
	return 0;
}
