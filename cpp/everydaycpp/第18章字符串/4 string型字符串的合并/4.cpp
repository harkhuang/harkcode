/*
//例18.4.1   char型字符数组的合并

#include <iostream>
using namespace std;
int main()
{
	char ch1[]="what's your name";
	char ch2[]="my name is Jack";
	strcat(ch1,ch2);
	cout<<ch1<<endl;
	cout<<ch2<<endl;
	return 0;
}
*/

/*
//纠正错误
#include <iostream>
using namespace std;
int main()
{
	char ch1[33]="what's your name";
	char ch2[]="my name is Jack";
	strcat(ch1,ch2);
	cout<<ch1<<endl;
	cout<<ch2<<endl;
	return 0;
}
*/




//例18.4.2  string型字符串的合并

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1;
	cout<<"str1:"<<str1.size()<<endl;
	str1 ="what's your name";
	cout<<"str1:"<<str1.size()<<endl;
	string str2="my name is Jack";
	cout<<"str2:"<<str2.size()<<endl;
	str1=str1+str2;
	cout<<str1<<endl;
	cout<<str2<<endl;
	cout<<"str1:"<<str1.size()<<endl;
	cout<<"str2:"<<str2. length()<<endl;
	return 0;
}
