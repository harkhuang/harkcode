//��18.30  ��������Խ��
#include <iostream>
using namespace std;
class String 
{
public:
	String();
	String(const char*const ch);//��һ�������Ĺ��캯��������ʼ���ַ���
	char&operator[](int length);//�����÷��ص������±����������
	int getlen()const{return len;}
	const char*getstr()const{return str;}
private:
	int len;
	char*str;
};
String::String()
{
	cout<<"Ĭ�Ϲ��캯��\n";
	len=0;
	str=new char[1];
	str[0]='\0';
}

String::String(const char*const ch) //���캯�����岿��
{
	cout<<"���캯��\n";
	len=strlen(ch);
	str=new char[len+1];
	for(int i=0;i<len;i++)
		str[i]=ch[i];
	str[len]='\0';
}
char&String::operator[](int length) // �����±�����������Ķ��岿��
{
	if(length>len)
		return str[len-1];
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
	cin>>s3[999];
	cout<<"s3:"<<s3.getstr()<<"\t��"<<s3.getlen()<<"�ַ�"<<endl;
	cout<<"s3[999]:"<<s3[999]<<endl;
	return 0;
}
