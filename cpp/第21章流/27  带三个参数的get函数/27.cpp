/*
//��21.27.1  ʹ�ô�����������get()����
#include <iostream>
using namespace std;
int main()
{
	char ch1[30];
	char ch2[30];
	cout<<"�������һ���ַ�:";
	cin.get(ch1,30,'s');
	cout<<"�ַ���1Ϊ:"<<ch1<<endl;
	cout<<"������ڶ����ַ���";
	cin.ignore();
	cin.get(ch2,30);
	cout<<"�ַ���2Ϊ:"<<ch2<<endl;
	cout<<"�������\n";
	return 0;
}
*/

/*
//��21.27.2  �����������е�����
#include <iostream>
using namespace std;
int main()
{
	char ch1[30];
	char ch2[30];
	cout<<"�������һ���ַ�:";
	cin.get (ch1,30,'s');
	cout<<"�ַ���1Ϊ:"<<ch1<<endl;
	cout<<"������ڶ����ַ���";
	cin.ignore(1024,'\n');
	cin.get(ch2,30);
	cout<<"�ַ���2Ϊ:"<<ch2<<endl;
	cout<<"�������\n";
	return 0;
}
*/

//��21.27.3  ��û�����������������������������
#include <iostream>
#include <limits>	//Ϊ��ʹ��numeric_limits
using namespace std;
int main()
{
	char ch1[30];
	char ch2[30];
	cout<<"�������һ���ַ�:";
	cin.get (ch1,30,'s');
	cout<<"�ַ���1Ϊ:"<<ch1<<endl;
	cout<<"������ڶ����ַ���";
	cin.ignore( numeric_limits<streamsize>::max(),'\n');
	// numeric_limits<streamsize>::max( ) ���ػ������Ĵ�С��
	//ignore �����ڴ˽������뻺�����е�������ա�
	cin.get (ch2,30);
	cout<<"�ַ���2Ϊ:"<<ch2<<endl;
	cout<<"�������\n";
	return 0;
}
