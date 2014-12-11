#include <iostream>
using namespace std;
class Human 
{
public:
	virtual void run()=0;
	virtual void eat()=0;
};
class Mother:public Human
{
public:
	void run(){cout<<"母亲跑百米要花二十秒\n";}
	void eat(){cout<<"母亲喜欢吃零食\n";}
};
class Father:public Human
{
public:
	void run(){cout<<"父亲跑百米要花十秒\n";}
	void eat(){cout<<"父亲不喜欢吃零食\n";}
};
class Uncle:public Human
{
public:
	void run(){cout<<"舅舅跑百米要花十五秒\n";}
	void eat(){cout<<"舅舅喜欢偷吃零食\n";}
};
int main()
{
	void (Human::*pf)()=0;
	Human*p=0;
	char choice1,choice2;
	bool quit=false;
	while(quit==false)
	{
		cout<<"(0)退出(1)母亲(2)父亲(3)舅舅：";
		cin>>choice1;
		switch(choice1)
		{
		case '0':quit=true;break;
		case '1':p=new Mother;break;
		case '2':p=new Father;break;
		case '3':p=new Uncle;break;
		default:choice1='q';break;
		}
		if (quit)
		{
			break;
		}
		if (choice1=='q')
		{
			cout<<"请输入0到3之间的数字\n";
			continue;
		}
		cout<<"(1)跑步(2)进食\n";
		cin>>choice2;
		switch(choice2)
		{
		case '1':pf=&Human::run;break;
		case '2':pf=&Human::eat;break;
		default:break;
		}
		(p->*pf)();
		delete p;
	}
	return 0;
}
