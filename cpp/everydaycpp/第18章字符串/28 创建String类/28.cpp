
//��18.28  String���Ĭ�Ϲ��캯��ʵ�ֿ��ַ���

#include <iostream>
using namespace std;
class String 
{
public:
	String();
    int getlen()const{return len;}
private:
	int len;
	char*str;
};
String::String()
{
	len=0;
	str=new char[1];
	str[0]='\0';
}
int main()
{
	String s1;
	cout<<s1.getlen()<<endl;
	return 0;
}
