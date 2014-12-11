/*
//例18.31.1   const修饰符实现重载

#include<iostream>
using namespace std;
class A
{
public: 
	A(int i, int j) { x=i;y=j; } 
	void set(int s1,int s2){x=s1;y=s2;}
	void print(){cout<<x<<endl;}
	void print()const{cout<<y<<endl;}
private: 
	int x, y;
};
void main()
{
    const A a(2,3);
	a.print();
	//a.set(4,5);
	A b(2,3);
	b.print();
	b.set(4,5);
	b.print();
}
*/

//例18.31.2  复制构造函数实现两个对象的赋值

#include <iostream>
using namespace std;
class String 
{
public:
	String();
	String(const String&rs); //复制构造函数
	String(const char*const ch);//带一个参数的构造函数用来初始化字符串
	char&operator[](unsigned short int length);//按引用返回的下标运算符函数
	char operator[](unsigned short int length)const; //按值返回的const下标运算符函数
	unsigned short int getlen()const{return len;}
	const char*getstr()const{return str;}
private:
	unsigned short int len;
	char*str;
};
String::String()
{
	cout<<"默认构造函数\n";
	len=0;
	str=new char[1];
	str[0]='\0';
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
int main()
{
	String s1;
	cout<<"s1:"<<s1.getstr()<<"\t共"<<s1.getlen()<<"字符"<<endl;
	String s2("study");
	cout<<"s2:"<<s2.getstr()<<"\t共"<<s2.getlen()<<"字符"<<endl;
	char*temp="help me";
	String s3(temp);
	cout<<"s3:"<<s3.getstr()<<"\t共"<<s3.getlen()<<"字符"<<endl;
	cin>>s3[-999];
	cout<<"s3:"<<s3.getstr()<<"\t共"<<s3.getlen()<<"字符"<<endl;
	cout<<"s3[-999]:"<<s3[-999]<<endl;
	String s4=s3;
	cout<<"s4:"<<s4.getstr()<<"\t共"<<s4.getlen()<<"字符"<<endl;
	return 0;
}
