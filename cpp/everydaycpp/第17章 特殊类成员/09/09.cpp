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
	void run(){cout<<"ĸ���ܰ���Ҫ����ʮ��\n";}
	void eat(){cout<<"ĸ��ϲ������ʳ\n";}
};
class Father:public Human
{
public:
	void run(){cout<<"�����ܰ���Ҫ��ʮ��\n";}
	void eat(){cout<<"���ײ�ϲ������ʳ\n";}
};
class Uncle:public Human
{
public:
	void run(){cout<<"�˾��ܰ���Ҫ��ʮ����\n";}
	void eat(){cout<<"�˾�ϲ��͵����ʳ\n";}
};
int main()
{
	void (Human::*pf)()=0;
	Human*p=0;
	char choice1,choice2;
	bool quit=false;
	while(quit==false)
	{
		cout<<"(0)�˳�(1)ĸ��(2)����(3)�˾ˣ�";
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
			cout<<"������0��3֮�������\n";
			continue;
		}
		cout<<"(1)�ܲ�(2)��ʳ\n";
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
