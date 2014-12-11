#include <iostream>
#include <string>
using namespace std;
class book 
{
public:
	int num;
	float price;
	book *next;
};
book*head=NULL;
bool check(string str)
{
	for(int i=0;i<str.length();i++)
	{
		if((str[i]>'9'||str[i]<'0')&&(str[i]!='.'))
			return false;
	}
	return true;
}
book*creat()
{
	book*p1,*p2;
	p1=new book;
	head=p1;
	p2=p1;
	cout<<"请输入图书的编号，以0结束"<<endl;
	string str;
	cin>>str;
	while(!check(str))
	{
		cout<<"输入的不是数字，请重新输入，按0返回！！！"<<endl;
		cin>>str;
	}
    p1->num=atoi(str.c_str());
	
	if (p1->num!=0)
	{
		cout<<"请输入图书的价格"<<endl;
		cin>>str;
		while(!check(str))
		{
			cout<<"输入的不是数字，请重新输入，按0返回！！！"<<endl;
			cin>>str;
		}
    p1->price=atof(str.c_str());
	}
	else
	{
		delete p1;p2=NULL;p2->next=NULL;head=NULL;return head;
	}
	while (p1->num!=0)
	{
		p2=p1;
		p1=new book;
		cout<<"请输入图书的编号，以0结束"<<endl;
		cin>>str;
		while(!check(str))
		{
			cout<<"输入的不是数字，请重新输入，按0返回！！！"<<endl;
			cin>>str;
		}
    p1->num=atoi(str.c_str());
		if (p1->num!=0)
		{
			cout<<"请输入图书的价格"<<endl;
			cin>>str;
			while(!check(str))
			{
				cout<<"输入的不是数字，请重新输入，按0返回！！！"<<endl;
				cin>>str;
			}
    p1->price=atof(str.c_str());
	
		}
		p2->next=p1;
	}
	delete p1;
	p2->next=NULL;
	return head;
}
int main()
{
	creat();
	return 0;
}