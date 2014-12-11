/*
//VS2005更改了部分输入输出方式以及部分库函数的参数传递方式，
//因此以下程序不建议在VS2005下编译
//以下程序并没有问题，有问题的是VS2005
#include <iostream>
#include <time.h>
#include <locale.h>
using namespace std;
int main()
{
	//setlocale(LC_TIME,"");
	locale native("french");
	//locale::global(locale(""));
	time_t TIME;
	struct tm*TM;
	char ch[81];
	time(&TIME);
	TM=gmtime(&TIME);
	strftime(ch,80,"%#x",TM);
	cout<<ch<<endl;
	return 0;
}
*/


//VS2005更改了部分输入输出方式以及部分库函数的参数传递方式，
//因此以下程序不建议在VS2005下编译
//以下程序并没有问题，有问题的是VS2005，
#include <iostream>
#include <locale.h>
#include <time.h>
using namespace std;
int main()
{
	locale native(locale("chinese"),locale("american"),LC_TIME);
	struct lconv * lc;
	lc=localeconv(); 
	cout<<"本国货币符号:"<<lc->currency_symbol<<"\n";
	cout<<"国际货币符号:"<<lc->int_curr_symbol<<"\n";
	time_t TIME;
	struct tm*TM;
	char ch[81];
	time(&TIME);
	TM=gmtime(&TIME);
	locale french("");
	strftime(ch,80,"%#x",TM);
	cout<<"日期:"<<ch<<endl;
	return 0;
}

