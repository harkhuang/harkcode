//��19.4.1  ��String��������������
#include <iostream>
using namespace std;
class String 
{
public:
	String();//Ĭ�Ϲ��캯�����ڴ������ַ���
    ~String();
	String(const String&rs);
	String(const char*const ch);//��һ�������Ĺ��캯��������ʼ���ַ���
	char&operator[](unsigned short int length);
	char operator[](unsigned short int length)const;
    String&operator=(const String&s);//��ֵ�������������ַ���֮��ĸ�ֵ
	String operator+(const String &);
	void operator+=(const String&rs);
	friend ostream &operator<<(ostream & o, const String &str)
	{
		o<<str.str;
		return o;
	}
	friend istream &operator>>(istream&i, String &str)
	{
		i>>str.str;
		return i;
	}
	friend bool operator<(const String&str1,const String &str2)
	{
      if(strcmp(str1.str,str2.str)<0)
	     return 1;
	  else
		  return 0;
	}
	friend bool operator>(const String&str1,const String &str2)
	{
      if(strcmp(str1.str,str2.str)>0)
	     return 1;
	  else
		  return 0;
	}
	friend bool operator==(const String&str1,const String &str2)
	{
       if(strcmp(str1.str,str2.str)==0)
	     return 1;
	  else
		  return 0;
	}
	unsigned short int getlen()const{return len;}
	const char*getstr()const{return str;}
private:
	String(unsigned short int);
	unsigned short int len;
	char*str;

};
String::String(unsigned short int length)
{
	cout<<"String���޷������͹��캯��ִ��\n";
	str=new char[length+1];
	int i;
	for(i=0;i<=length;i++)
		str[i]='\0';
	len=length;
}
String::String()
{
	cout<<"String��Ĭ�Ϲ��캯��ִ��\n";
	len=0;
  str=new char[1];
  str[0]='\0';
}
String::~String()
{
	cout<<"String����������ִ��\n";
	delete []str;
	len=0;
}
String::String(const String&rs)
{
	cout<<"String�ิ�ƹ��캯��ִ��\n";
	len=rs.getlen();
	str=new char[len+1];
	for(int i=0;i<len;i++)
		str[i]=rs[i];
	str[len]='\0';
}
String::String(const char*const ch)
{
	cout<<"String�๹�캯��ִ��...\n";
	len=strlen(ch);
	str=new char[len+1];
	for(int i=0;i<len;i++)
		str[i]=ch[i];
	str[len]='\0';
}
char&String::operator[](unsigned short int length)
{
	if(length>len)
		return str[len-1];
	else
		return str[length];
}
char String::operator[](unsigned short int length)const
{
	if (length>len)
	{
		return str[len-1];
	}
	else
		return str[length];
}
String&String::operator=(const String&s)
{
	cout<<"String��operator=()����ִ��\n";
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
String String::operator +(const String&rhs)
{
    cout<<"String��operator+()����ִ��\n";
	int total=len+rhs.getlen();
	String temp(total);
	int i,j;
	for(i=0;i<len;i++)
		temp[i]=str[i];
	for(j=0;j<rhs.getlen();j++,i++)
		temp[i]=rhs[j];
	temp[total]='\0';
	return temp;
}
void String::operator+=(const String&rs)
{
	cout<<"String��operator+=()����ִ��\n";
	int total=len+rs.getlen();
	String temp(total);
	int i,j;
	for(i=0;i<len;i++)
		temp[i]=str[i];
	for(j=0;j<rs.getlen();j++,i++)
		temp[i]=rs[j];
	temp[total]='\0';
	*this=temp;
}
