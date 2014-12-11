//例18.38  完成后的String类

#include <iostream>
using namespace std;
class String 
{
public:
	String();//默认构造函数用于创建空字符串
    ~String();
	String(const String&rs);
	String(const char*const ch);//带一个参数的构造函数用来初始化字符串
	char&operator[](unsigned short int length);
	char operator[](unsigned short int length)const;
    String&operator=(const String&s);//赋值函数用于两个字符串之间的赋值
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
	str=new char[length+1];
	int i;
	for(i=0;i<=length;i++)
		str[i]='\0';
	len=length;
}
String::String()
{
	len=0;
  str=new char[1];
  str[0]='\0';
}
String::~String()
{
	delete []str;
	len=0;
}
String::String(const String&rs)
{
	len=rs.getlen();
	str=new char[len+1];
	for(int i=0;i<len;i++)
		str[i]=rs[i];
	str[len]='\0';
}
String::String(const char*const ch)
{
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
void String::operator+=(const String&rs)
{
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
int main()
{
String s1;
	cout<<"s1的长度:"<<s1.getlen()<<endl;
	char*temp="help me";
	s1=temp;
	cout<<"s1:"<<s1.getstr()<<"\t s1的长度:"<<s1.getlen()<<endl;
	char ch[10];
	strcpy(ch," all right");
	s1+=ch;
	cout<<"ch:\t"<<ch<<endl;
	cout<<"s1:\t"<<s1.getstr()<<endl;
	cout<<"s1:"<<s1<<endl;
	s1[2]='o';
	cout<<"s1:"<<s1<<endl;
	cout<<"s1[999]:"<<s1[999]<<endl;
	String s2="mother";
	String s3("Mother");
	cout<<"s2:"<<s2<<"\t s3:"<<s3<<endl;
	String s4=s2+s3;
	cout<<"s2+s3="<<s4<<endl;
	int check=s2>s3;
	cout<<"s2>s3:"<<check<<endl;
	check=s2<s3;
	cout<<"s2<s3:"<<check<<endl;
	check=s2==s2;
	cout<<"s2==s2:"<<check<<endl;
	cin>>s2[0]>>s3[0];
	s2=s2+s3;
	cout<<"s2:"<<"\t"<<s2<<endl;
	return 0;
}
