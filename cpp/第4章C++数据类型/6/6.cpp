#include <iostream>
#include <locale>
using namespace std;
int main()
{
	setlocale(LC_ALL,"'zh_TW");
	wchar_t wt[]=L"жа";
	wcout<<wt;
	return 0;
}