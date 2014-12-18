#include <iostream>
#include <string>
using namespace std;
float(*fp)(float&,float&);
void(*p)(float&,float&);
float triangle(float &x,float &y)
{
	return x*y*0.5;
}
float rectangle(float &x,float&y)
{
	return x*y;
}
void Swap(float&x,float&y)
{
	float n;
	n=x;
	x=y;
	y=n;
}
void print(float&x,float&y)
{
	cout<<"长为："<<x<<" "<<"宽为："<<y<<endl;
}
bool check(string str)
{
	for (int i=0;i<str.length();i++)
	{
		if ((str[i]>'9'||str[i]<'0')&&(str[i]!='.'))
		{
			return false;
		}
		
	}
	return true;
}
void get(float &x,float&y)
{
	cout<<"请输入x的新值：";
	string str1;
	cin>>str1;
	while (!check(str1))
	{
		cout<<"输入的不是数字，请重新输入！！！"<<endl;
		cin>>str1;
	}
	x=atof(str1.c_str());
	cout<<"请输入y的新值：";
	string str2;
	cin>>str2;
	while (!check(str2))
	{
		cout<<"输入的不是数字，请重新输入！！！"<<endl;
		cin>>str2;
	}
	y=atof(str2.c_str());
}
int main()
{
	bool quit=false;
	float a=2,b=3;
	int choice;
	while(quit==false)
	{
		cout<<"(0)退出(1)设定长宽(2)三角形(3)长方形(4)交换长宽:";
		cin>>choice;
		switch (choice)
		{
		case 1:cout<<"设定前长和宽的值：";
			/*print(a,b);
			get(a,b);
			cout<<"设定后长和宽的值：";
			print(a,b);*/
			p=get;
			break;
		case 2://print(a,b);
			//cout<<"三角形的面积为：";
			//<<triangle(a,b)<<endl;
			fp=triangle;
			break;
		case 3://print(a,b);
			//cout<<"长方形的面积为：";
			//<<rectangle(a,b)<<endl;
			fp=rectangle;
			break;
		case 4:cout<<"交换前长和宽的值：";
			/*print(a,b);
			swap(a,b);
			cout<<"交换后长和宽的值：";
			print(a,b);*/
			p=Swap;
			break;
		default:
			quit=true;
			break;
		}
		if (choice==1||choice==4)
		{
			print(a,b);
			p(a,b);
			print(a,b);
		}
		else if(choice==2||choice==3)
		{
			print(a,b);
			cout<<"面积为："<<fp(a,b)<<endl;
		}
	}
	return 0;
}