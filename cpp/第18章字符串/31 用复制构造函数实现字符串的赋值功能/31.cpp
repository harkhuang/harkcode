/*
//��18.31.1   const���η�ʵ������

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

//��18.31.2  ���ƹ��캯��ʵ����������ĸ�ֵ

#include <iostream>
using namespace std;
class String 
{
public:
	String();
	String(const String&rs); //���ƹ��캯��
	String(const char*const ch);//��һ�������Ĺ��캯��������ʼ���ַ���
	char&operator[](unsigned short int length);//�����÷��ص��±����������
	char operator[](unsigned short int length)const; //��ֵ���ص�const�±����������
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
int main()
{
	String s1;
	cout<<"s1:"<<s1.getstr()<<"\t��"<<s1.getlen()<<"�ַ�"<<endl;
	String s2("study");
	cout<<"s2:"<<s2.getstr()<<"\t��"<<s2.getlen()<<"�ַ�"<<endl;
	char*temp="help me";
	String s3(temp);
	cout<<"s3:"<<s3.getstr()<<"\t��"<<s3.getlen()<<"�ַ�"<<endl;
	cin>>s3[-999];
	cout<<"s3:"<<s3.getstr()<<"\t��"<<s3.getlen()<<"�ַ�"<<endl;
	cout<<"s3[-999]:"<<s3[-999]<<endl;
	String s4=s3;
	cout<<"s4:"<<s4.getstr()<<"\t��"<<s4.getlen()<<"�ַ�"<<endl;
	return 0;
}
