/*
//21.29.1  ������ַ�"��"
#include <iostream>
using namespace std;
int main()
{
	char ch[30];
	cout<<"�������ַ�:";
	cin.read(ch,30);
	cout<<ch<<endl;
	cout<<"�������\n";
	return 0;
}
*/

/*
//21.29.2  ���������ַ�"��"������
#include <iostream>
using namespace std;
int main()
{
	char ch[30]={0};
	cout<<"�������ַ�:";
	cin.read(ch,30);
	cout<<ch<<endl;
	cout<<"�������\n";
	return 0;
}
*/

//��21.29.3   �����ַ����뻺����
#include <iostream>
using namespace std;
int main()
{
	char ch1[30]={0};
	char ch2[30];
	cout<<"�������һ���ַ�:";
	cin.read(ch1,5);
	cout<<"�ַ���1Ϊ:"<<ch1<<endl;
	cout<<"������ڶ����ַ���";
	cin.getline(ch2,30);
	cout<<"�ַ���2Ϊ:"<<ch2<<endl;
	cout<<"�������\n";
	return 0;
}
