//��18.35 ʵ���ַ����ıȽϹ���

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
  String s1("aaa"),s2("bbb");
  int check1=s1>s2;
  int check2=s1<s2;
  int check3=s1=="aaa";
  cout<<"s1>s2:"<<check1<<endl;
  cout<<"s1<s2:"<<check2<<endl;
  cout<<"s1==aaa:"<<check3<<endl;
  return 0;
}
