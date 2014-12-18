/*
#include <locale.h>
#include <iostream>
int main(void)
{
	std::cout<<setlocale(LC_ALL,"Japanese");
	return 0;
}
*/

/*
//语言设置
#include<iostream> 
using namespace std; 
int main() 
{ 
	setlocale(LC_ALL,"CHINESE");
	wchar_t m[]=L"世界你好"; 
	wcout <<m;
	return 0;
}
*/


//通过localeconv函数来读取该货币符号的本国形式与国际形式，如：
#include <iostream>
#include <locale.h>
using namespace std;
int main ()
{
	setlocale (LC_MONETARY,"");
	struct lconv * lc;
	lc=localeconv();
	cout<<"本国货币符号:"<<lc->currency_symbol<<"\n";//货币符号（如：$）
	cout<<"国际货币符号:"<<lc->int_curr_symbol<<"\n";//货币符号（如：USD）
	return 0;
}

