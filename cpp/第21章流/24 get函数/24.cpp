/*
//��21.24.1  ��ȡ�����ַ�
#include <iostream>
using namespace std;
int main()
{
	char ch;
	ch=cin.get();
	cout<<"ch:"<<ch<<endl;
	return 0;
}
*/


/*
//��21.24.2  ѭ����ȡ�ַ�
#include <iostream>
using namespace std;
int main()
{
	char ch;
	while ((ch=cin.get())!='\n')
	{
		cout<<ch;
	}
	cout<<"\n�������\n";
	return 0;
}
*/

/*
//��21.24.3  ����س�����"\n"��ASCII��ֵ
#include<iostream>
using namespace std;
int main() 
{ 
	int c; 
	c=int('\n');
	cout<<c;
	cout<<endl;
	c=cin.get(); 
	cout<<c; 
	cout<<endl;
	return 0;
}
*/

/*
//��21.24.4 �س���"\r"���ǿ�ͷ���ַ���
#include<iostream>
using namespace std;
int main() 
{ 
	cout<<"hello\r"<<"give me";
	return 0;
}
*/

/*
//��21.24.5  ��������ͬʹ�ûس���"\r"�����Ľ��Ҳ��ͬ
#include<iostream>
using namespace std;
int main() 
{ 
	cout<<"hello\r";
	return 0;
}
*/


/*
//��21.24.6  ��Ҫ����ʱˢ�»�����
#include<iostream>
using namespace std;
int main() 
{ 
	char ch[10];
	cout<<"hello\r";
	cin>>ch;
	return 0;
}
*/

/*
//������21.24.2		ѭ����ȡ�ַ�
#include <iostream>
using namespace std;
int main()
{
	char ch;
	while ((ch=cin.get())!='\n')
	{
		cout<<ch;
	}
	cout<<"�������\n";
	return 0;
}
*/


/*
//��21.24.7	  ѭ������ַ�ֱ�������ַ�s
#include <iostream>
using namespace std;
int main()
{
	char ch;
	while ((ch=cin.get())!='s')
	{
		cout<<ch;
	}
	cout<<"�������\n";
	return 0;
}
*/


//��21.24.8  ��get()��Ϊcin>>
#include <iostream>
using namespace std;
int main()
{
	char ch;
	cin>>ch;
	while (ch!='\n')
	{
		cout<<ch;
		cin>>ch;
	}
	cout<<"�������\n";
	return 0;
}
