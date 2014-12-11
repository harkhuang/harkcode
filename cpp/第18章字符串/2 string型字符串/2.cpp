/*
//例18.2.1  字符数组与字符对象的不同
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str="string型字符串";
	char ch[]="char型字符数组";
	cout<<str<<endl;
	cout<<ch<<endl;
	cout<<"请输入“狗”的英文单词："<<endl;
	cin>>str;
	if(str=="dog")
	{
		cout<<"狗："<<str<<endl;
		cout<<str<<"的第1个字符是："<<str[0]<<endl;
	}
	else 
		cout<<"输入错误\n";
	cout<<"请输入“猪”的英文单词："<<endl;
	cin>>ch;
	if(ch =="pig")
	{
		cout<<"猪："<<ch<<endl;
		cout<<ch<<"的第1个字符是："<<ch[0]<<endl;
	}
	else 
		cout<<"输入错误\n";
	return 0;
}
*/


/*
//例18.2.2  自定义check比较函数

#include <iostream>
#include <string>
using namespace std;
int check(char ch[]);
int main()
{
	string str="string型字符串";
	char ch[]="char型字符数组";
	
	cout<<str<<endl;
	cout<<ch<<endl;
	cout<<"请输入“狗”的英文单词："<<endl;
	cin>>str;
	if(str=="dog")
	{
		cout<<"狗："<<str<<endl;
		cout<<str<<"的第1个字符是："<<str[0]<<endl;
	}
	else 
		cout<<"输入错误\n";
	cout<<"请输入“猪”的英文单词："<<endl;
	cin>>ch;
	if(check(ch)==1)
	{
		cout<<"猪："<<ch<<endl;
		cout<<ch<<"的第1个字符是："<<ch[0]<<endl;
	}
	else  cout<<"输入错误\n";
	return 0;
}
int check(char ch[])
{
	char ch1[]="pig";
	bool quit=false;
	for(int i=0;i<strlen(ch1);i++)
	{
		if(ch[i] !=ch1[i])
		{
			quit=true;
			break;
		}
	}
	if(quit==false)
		return 1;
	else
		return 0;
}
*/


/*
//例18.2.3  修改后的check函数

#include <iostream>
#include <string>
using namespace std;
int check(char ch[],char ch1[]);
int main()
{
	string str="string型字符串";
	char ch[]="char型字符数组";
	cout<<str<<endl;
	cout<<ch<<endl;
	cout<<"请输入“狗”的英文单词："<<endl;
	cin>>str;
	if(str=="dog")
	{
		cout<<"狗："<<str<<endl;
		cout<<str<<"的第1个字符是："<<str[0]<<endl;
	}
	else 
		cout<<"输入错误\n";
	cout<<"请输入“猪”的英文单词："<<endl;
	cin>>ch;
	if(check(ch,"pig")==1)
	{
		cout<<"猪："<<ch<<endl;
		cout<<ch<<"的第1个字符是："<<ch[0]<<endl;
	}
	else  cout<<"输入错误\n";
	return 0;
}
int check(char ch[],char ch1[])
{
	bool quit=false;
	for(int i=0;i<strlen(ch1);i++)
	{
		if(ch[i] !=ch1[i])
		{
			quit=true;
			break;
		}
	}
	if(quit==false)
		return 1;
	else
		return 0;
}
*/


//例18.2.4  使用strcmp函数

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str="string型字符串";
	char ch[]="char型字符数组";
	
	cout<<str<<endl;
	cout<<ch<<endl;
	cout<<"请输入“狗”的英文单词："<<endl;
	cin>>str;
	if(str=="dog")
	{
		cout<<"狗："<<str<<endl;
		cout<<str<<"的第1个字符是："<<str[0]<<endl;
	}
	else 
		cout<<"输入错误\n";
	cout<<"请输入“猪”的英文单词："<<endl;
	cin>>ch;
	if(strcmp(ch,"pig")==0)
	{
		cout<<"猪："<<ch<<endl;
		cout<<ch<<"的第1个字符是："<<ch[0]<<endl;
	}
	else  cout<<"输入错误\n";
	return 0;
}
