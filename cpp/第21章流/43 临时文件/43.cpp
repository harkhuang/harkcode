#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	cout<<"tmpnam函数的最多调用次数："<<TMP_MAX<<"\n临时文件名的字符数目："<<L_tmpnam<<"字符\n";
	char pszName[L_tmpnam]={'\0'};
	cout<<"下面是系统自动创建的十个临时文件的名字:\n";
	for (int i=0;i<10;i++)
	{
		tmpnam(pszName);
		cout<<pszName<<endl;
	}
	return 0;
} 
