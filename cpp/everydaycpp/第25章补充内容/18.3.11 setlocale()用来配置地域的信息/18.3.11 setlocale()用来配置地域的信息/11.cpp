/*
//���ӣ���ʾ��ǰ�ı�������

#include <locale.h>
#include <iostream>
int main(void)
{
  std::cout<<setlocale(LC_ALL,"Japanese");
  return 0;
}
*/


//��������
#include<iostream> 
using namespace std; 
int main() 
{ 
  //setlocale(LC_ALL,"chs");
   wcout.imbue(locale("kor"));
  wchar_t m[]=L"�������"; 
  wcout <<m;
  return 0;
}
