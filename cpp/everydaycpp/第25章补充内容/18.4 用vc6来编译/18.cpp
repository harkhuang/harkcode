/*
//VS2005�����˲������������ʽ�Լ����ֿ⺯���Ĳ������ݷ�ʽ��
//������³��򲻽�����VS2005�±���
//���³���û�����⣬���������VS2005
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


//VS2005�����˲������������ʽ�Լ����ֿ⺯���Ĳ������ݷ�ʽ��
//������³��򲻽�����VS2005�±���
//���³���û�����⣬���������VS2005��
#include <iostream>
#include <locale.h>
#include <time.h>
using namespace std;
int main()
{
	locale native(locale("chinese"),locale("american"),LC_TIME);
	struct lconv * lc;
	lc=localeconv(); 
	cout<<"�������ҷ���:"<<lc->currency_symbol<<"\n";
	cout<<"���ʻ��ҷ���:"<<lc->int_curr_symbol<<"\n";
	time_t TIME;
	struct tm*TM;
	char ch[81];
	time(&TIME);
	TM=gmtime(&TIME);
	locale french("");
	strftime(ch,80,"%#x",TM);
	cout<<"����:"<<ch<<endl;
	return 0;
}

