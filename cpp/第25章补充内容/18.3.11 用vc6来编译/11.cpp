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
//��������
#include<iostream> 
using namespace std; 
int main() 
{ 
	setlocale(LC_ALL,"CHINESE");
	wchar_t m[]=L"�������"; 
	wcout <<m;
	return 0;
}
*/


//ͨ��localeconv��������ȡ�û��ҷ��ŵı�����ʽ�������ʽ���磺
#include <iostream>
#include <locale.h>
using namespace std;
int main ()
{
	setlocale (LC_MONETARY,"");
	struct lconv * lc;
	lc=localeconv();
	cout<<"�������ҷ���:"<<lc->currency_symbol<<"\n";//���ҷ��ţ��磺$��
	cout<<"���ʻ��ҷ���:"<<lc->int_curr_symbol<<"\n";//���ҷ��ţ��磺USD��
	return 0;
}

