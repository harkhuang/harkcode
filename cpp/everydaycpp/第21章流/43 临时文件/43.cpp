#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	cout<<"tmpnam�����������ô�����"<<TMP_MAX<<"\n��ʱ�ļ������ַ���Ŀ��"<<L_tmpnam<<"�ַ�\n";
	char pszName[L_tmpnam]={'\0'};
	cout<<"������ϵͳ�Զ�������ʮ����ʱ�ļ�������:\n";
	for (int i=0;i<10;i++)
	{
		tmpnam(pszName);
		cout<<pszName<<endl;
	}
	return 0;
} 
