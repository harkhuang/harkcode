//例18.29  创建可自动调节大小的String类字符串对象
#include <iostream>
using namespace std;
class String 
{
public:
	String();
	String(const char*const ch);//带一个参数的构造函数用来初始化字符串
	int getlen()const{return len;}
	const char*getstr()const{return str;}
private:
	int len;
	char*str;
};
String::String()
{
	cout<<"默认构造函数\n";
	len=0;
	str=new char[1];
	str[0]='\0';
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
int main()
{
	String s1;
	cout<<"s1:"<<s1.getstr()<<"\t共"<<s1.getlen()<<"字符"<<endl;
	String s2("study");
	cout<<"s2:"<<s2.getstr()<<"\t共"<<s2.getlen()<<"字符"<<endl;
	char*temp="help me";
	String s3(temp);
	cout<<"s3:"<<s3.getstr()<<"\t共"<<s3.getlen()<<"字符"<<endl;
	return 0;
}
