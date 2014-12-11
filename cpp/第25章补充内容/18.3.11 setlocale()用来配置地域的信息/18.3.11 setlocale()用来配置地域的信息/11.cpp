/*
//例子：显示当前的本地设置

#include <locale.h>
#include <iostream>
int main(void)
{
  std::cout<<setlocale(LC_ALL,"Japanese");
  return 0;
}
*/


//语言设置
#include<iostream> 
using namespace std; 
int main() 
{ 
  //setlocale(LC_ALL,"chs");
   wcout.imbue(locale("kor"));
  wchar_t m[]=L"世界你好"; 
  wcout <<m;
  return 0;
}
