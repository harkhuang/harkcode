#include <iostream>
using namespace std;
class Human 
{
public:
	Human(){cout<<"����Human\n";}
	virtual void smart(){}
	virtual void beautiful(){}
	virtual ~Human(){cout<<"����Human\n";}
};
class father: virtual public Human
{
public:
	father(){cout<<"����father\n";}
	virtual void smart()
	{
		cout<<"���׺ܴ���\n";
	}
	//virtual void beautiful(){}
	virtual ~father(){cout<<"����father"<<endl;}
};
class mother:virtual public Human
{
public:
	mother(){cout<<"����mother\n";}
	virtual void beautiful(){cout<<"ĸ�׺�Ư��"<<endl;}
	virtual ~mother(){cout<<"����mother"<<endl;}
};
class son:public father,public mother
{
public:
	son(){cout<<"����son\n";} 
	virtual void beautiful(){cout<<"����Ҳ��˧\n";}
	virtual void smart(){cout<<"����Ҳ�ܴ���\n";}
	virtual ~son(){cout<<"����son"<<endl;}
};
int main()
{
	Human*p;
	int choice=0;
	while (choice<99)
	{
		bool quit=false;
		cout<<"(0)�˳�(1)����(2)����(3)ĸ��:";
		cin>>choice;
		switch(choice)
		{
			case 0:quit=true;
				break;
			case 1:p=new father;
				p->beautiful();
				delete p;
				break;
			case 2:p=new son;
				p->beautiful();
				p->smart();
				delete p;
				break;
			case 3:p=new mother;
				p->beautiful();
				delete p;
				break;
			default:cout<<"�������0��2֮������֡�";
				break;
		}
		if (quit)
		{
			break;
		}
	}
	cout<<"�������"<<endl;
	return 0;
}