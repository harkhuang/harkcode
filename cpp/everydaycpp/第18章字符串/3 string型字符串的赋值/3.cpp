/*
//��18.3.1   char���ַ��ĸ�ֵ

#include <iostream>
using namespace std;
int main()
{
	char ch1[]="what's your name";
	char ch2[]="my name is Jack";
	strcpy(ch1,ch2);
	cout<<ch1<<endl;
	cout<<ch2<<endl;
	return 0;
}
*/

/*
//��18.3.2    string���ַ�������ĸ�ֵ

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1="what's your name";
	string str2="my name is Jack";
	str1=str2;
	cout<<str1<<endl;
	cout<<str2<<endl;
	return 0;
}
*/

//string��ĸ�ֵ����assign
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1=" gh ";
	string str2 = " abcdef ";
	str1.assign( str2, 3, 1 );  
	cout << str1 << endl;
	return 0;
}
