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
	cout<<"��Ϊ��"<<x<<" "<<"��Ϊ��"<<y<<endl;
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
	cout<<"������x����ֵ��";
	string str1;
	cin>>str1;
	while (!check(str1))
	{
		cout<<"����Ĳ������֣����������룡����"<<endl;
		cin>>str1;
	}
	x=atof(str1.c_str());
	cout<<"������y����ֵ��";
	string str2;
	cin>>str2;
	while (!check(str2))
	{
		cout<<"����Ĳ������֣����������룡����"<<endl;
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
		cout<<"(0)�˳�(1)�趨����(2)������(3)������(4)��������:";
		cin>>choice;
		switch (choice)
		{
		case 1:cout<<"�趨ǰ���Ϳ��ֵ��";
			/*print(a,b);
			get(a,b);
			cout<<"�趨�󳤺Ϳ��ֵ��";
			print(a,b);*/
			p=get;
			break;
		case 2://print(a,b);
			//cout<<"�����ε����Ϊ��";
			//<<triangle(a,b)<<endl;
			fp=triangle;
			break;
		case 3://print(a,b);
			//cout<<"�����ε����Ϊ��";
			//<<rectangle(a,b)<<endl;
			fp=rectangle;
			break;
		case 4:cout<<"����ǰ���Ϳ��ֵ��";
			/*print(a,b);
			swap(a,b);
			cout<<"�����󳤺Ϳ��ֵ��";
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
			cout<<"���Ϊ��"<<fp(a,b)<<endl;
		}
	}
	return 0;
}