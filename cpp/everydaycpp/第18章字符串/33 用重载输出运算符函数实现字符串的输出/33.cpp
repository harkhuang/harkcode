//��18.33  ʵ��String���������

#include <iostream>
using namespace std;
class String 
{
public:
	String();//Ĭ�Ϲ��캯�����ڴ������ַ���
	String(const String&rs);
	String(const char*const ch);//��һ�������Ĺ��캯��������ʼ���ַ���
	char&operator[](unsigned short int length);
	char operator[](unsigned short int length)const;
    String&operator=(const String&s);//��ֵ�������������ַ���֮��ĸ�ֵ
	friend ostream &operator<<(ostream & o, const String &str)
	{
		o<<str.str;
		return o;
	}
	unsigned short int getlen()const{return len;}
	const char*getstr()const{return str;}
private:
	unsigned short int len;
	char*str;
};
String::String()
{
	cout<<"Ĭ�Ϲ��캯��\n";
	len=0;
	str=new char[1];
	str[0]='\0';
}
String::String(const String&rs)
{
	cout<<"���ƹ��캯��ִ��...\n";
	len=rs.getlen();
	str=new char[len+1];
	for(int i=0;i<len;i++)
		str[i]=rs[i];
	str[len]='\0';
}
String::String(const char*const ch)
{
	cout<<"���캯��\n";
	len=strlen(ch);
	str=new char[len+1];
	for(int i=0;i<len;i++)
		str[i]=ch[i];
	str[len]='\0';
}
char&String::operator[](unsigned short int length)
{
	cout<<"operator[]ִ��\n";
	if(length>len)
		return str[len-1];
	else
		return str[length];
}
char String::operator[](unsigned short int length)const
{
	cout<<"operator[]constִ��\n";
	if (length>len)
	{
		return str[len-1];
	}
	else
		return str[length];
}
String&String::operator=(const String&s)
{
	cout<<"operator=ִ��...\n";
	if (this==&s)
		return *this;
	delete[]str;
	len=s.getlen();
	str=new char[len+1];
	for(int i=0;i<len;i++)
	{
		str[i]=s[i];
	}
	str[len]='\0';
	return *this;
}
int main()
{
	String s1="hello world";
	String s2;
	s2=s1;
	cout<<s2<<endl;
	s2="name";
	cout<<s2<<endl;
	return 0;
}
