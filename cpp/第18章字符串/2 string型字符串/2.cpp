/*
//��18.2.1  �ַ��������ַ�����Ĳ�ͬ
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str="string���ַ���";
	char ch[]="char���ַ�����";
	cout<<str<<endl;
	cout<<ch<<endl;
	cout<<"�����롰������Ӣ�ĵ��ʣ�"<<endl;
	cin>>str;
	if(str=="dog")
	{
		cout<<"����"<<str<<endl;
		cout<<str<<"�ĵ�1���ַ��ǣ�"<<str[0]<<endl;
	}
	else 
		cout<<"�������\n";
	cout<<"�����롰����Ӣ�ĵ��ʣ�"<<endl;
	cin>>ch;
	if(ch =="pig")
	{
		cout<<"��"<<ch<<endl;
		cout<<ch<<"�ĵ�1���ַ��ǣ�"<<ch[0]<<endl;
	}
	else 
		cout<<"�������\n";
	return 0;
}
*/


/*
//��18.2.2  �Զ���check�ȽϺ���

#include <iostream>
#include <string>
using namespace std;
int check(char ch[]);
int main()
{
	string str="string���ַ���";
	char ch[]="char���ַ�����";
	
	cout<<str<<endl;
	cout<<ch<<endl;
	cout<<"�����롰������Ӣ�ĵ��ʣ�"<<endl;
	cin>>str;
	if(str=="dog")
	{
		cout<<"����"<<str<<endl;
		cout<<str<<"�ĵ�1���ַ��ǣ�"<<str[0]<<endl;
	}
	else 
		cout<<"�������\n";
	cout<<"�����롰����Ӣ�ĵ��ʣ�"<<endl;
	cin>>ch;
	if(check(ch)==1)
	{
		cout<<"��"<<ch<<endl;
		cout<<ch<<"�ĵ�1���ַ��ǣ�"<<ch[0]<<endl;
	}
	else  cout<<"�������\n";
	return 0;
}
int check(char ch[])
{
	char ch1[]="pig";
	bool quit=false;
	for(int i=0;i<strlen(ch1);i++)
	{
		if(ch[i] !=ch1[i])
		{
			quit=true;
			break;
		}
	}
	if(quit==false)
		return 1;
	else
		return 0;
}
*/


/*
//��18.2.3  �޸ĺ��check����

#include <iostream>
#include <string>
using namespace std;
int check(char ch[],char ch1[]);
int main()
{
	string str="string���ַ���";
	char ch[]="char���ַ�����";
	cout<<str<<endl;
	cout<<ch<<endl;
	cout<<"�����롰������Ӣ�ĵ��ʣ�"<<endl;
	cin>>str;
	if(str=="dog")
	{
		cout<<"����"<<str<<endl;
		cout<<str<<"�ĵ�1���ַ��ǣ�"<<str[0]<<endl;
	}
	else 
		cout<<"�������\n";
	cout<<"�����롰����Ӣ�ĵ��ʣ�"<<endl;
	cin>>ch;
	if(check(ch,"pig")==1)
	{
		cout<<"��"<<ch<<endl;
		cout<<ch<<"�ĵ�1���ַ��ǣ�"<<ch[0]<<endl;
	}
	else  cout<<"�������\n";
	return 0;
}
int check(char ch[],char ch1[])
{
	bool quit=false;
	for(int i=0;i<strlen(ch1);i++)
	{
		if(ch[i] !=ch1[i])
		{
			quit=true;
			break;
		}
	}
	if(quit==false)
		return 1;
	else
		return 0;
}
*/


//��18.2.4  ʹ��strcmp����

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str="string���ַ���";
	char ch[]="char���ַ�����";
	
	cout<<str<<endl;
	cout<<ch<<endl;
	cout<<"�����롰������Ӣ�ĵ��ʣ�"<<endl;
	cin>>str;
	if(str=="dog")
	{
		cout<<"����"<<str<<endl;
		cout<<str<<"�ĵ�1���ַ��ǣ�"<<str[0]<<endl;
	}
	else 
		cout<<"�������\n";
	cout<<"�����롰����Ӣ�ĵ��ʣ�"<<endl;
	cin>>ch;
	if(strcmp(ch,"pig")==0)
	{
		cout<<"��"<<ch<<endl;
		cout<<ch<<"�ĵ�1���ַ��ǣ�"<<ch[0]<<endl;
	}
	else  cout<<"�������\n";
	return 0;
}
