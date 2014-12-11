//例18.36  实现字符串的相加功能
#include <iostream>
using namespace std;
class String 
{
public:
	String();//默认构造函数用于创建空字符串
    ~String();//析构函数用于删除对象中的字符串
	String(const String&rs);//复制构造函数
	String(const char*const ch);//带一个参数的构造函数用来初始化字符串
	char&operator[](unsigned short int length);
	char operator[](unsigned short int length)const;
    String&operator=(const String&s);//赋值函数用于两个字符串之间的赋值
	String operator+(const String &);//重载的相加运算符函数
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
	String(unsigned short int);// 私有构造函数
	unsigned short int len;
	char*str;

};
String::String(unsigned short int length)
{
	cout<<"带一个无符号短整型参数的构造函数\n";
	str=new char[length+1];
	int i;
	for(i=0;i<=length;i++)
		str[i]='\0';
	len=length;
}
String::String()
{
  cout<<"默认构造函数\n";
	len=0;
  str=new char[1];
  str[0]='\0';
}
String::~String()
{
	cout<<"析构函数执行...\n";
	delete []str;
	len=0;
}
String::String(const String&rs)
{
	cout<<"复制构造函数执行...\n";
	len=rs.getlen();
	str=new char[len+1];
	for(int i=0;i<len;i++)
		str[i]=rs[i];
	str[len]='\0';
}
String::String(const char*const ch)
{
	cout<<"构造函数\n";
	len=strlen(ch);
	str=new char[len+1];
	for(int i=0;i<len;i++)
		str[i]=ch[i];
	str[len]='\0';
}
char&String::operator[](unsigned short int length)
{
	cout<<"operator[]执行\n";
	if(length>len)
		return str[len-1];
	else
		return str[length];
}
char String::operator[](unsigned short int length)const
{
	cout<<"operator[]const执行\n";
	if (length>len)
	{
		return str[len-1];
	}
	else
		return str[length];
}
String&String::operator=(const String&s)
{
	cout<<"operator=执行...\n";
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
String String::operator+(const String&rs)
{
	cout<<"operator+执行...\n";
	int total=len+rs.getlen();
	String temp(total);
	int i,j;
	for( i=0;i<len;i++)
		temp[i]=str[i];
	for( j=0;j<rs.getlen();j++,i++)
		temp[i]=rs[j];
	temp[total]='\0';
	return temp;
}
int main()
{
	String s1("aaa"),s2("bbb");
    String s3;
	s3=s1+s2;
    cout<<"s1+s2="<<s3<<endl;
	return 0;
}
