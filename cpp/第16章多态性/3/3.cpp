#include <iostream>
using namespace std;
class father
{
public:
	father(){cout<<"����father\n";}
	void smart()
	{
		cout<<"���׺ܴ���\n";
	}
	//virtual void beautiful(){}
	virtual ~father(){cout<<"����father"<<endl;}
};
class mother
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
	~son(){cout<<"����son"<<endl;}
};
int main()
{
	father *pf;
	mother *pm;
	int choice=0;
	while (choice<99)
	{
		bool quit=false;
		cout<<"(0)�˳�(1)����(2)����:";
		cin>>choice;
		switch(choice)
		{
			case 0:quit=true;
				break;
			case 1:pf=new father;
			//	pf->beautiful();
				break;
			case 2:pm=new son;
				pm->beautiful();
				pm->smart();
				delete pm;
			default:cout<<"�������0��2֮������֡�";
		}
		if (quit)
		{
			break;
		}
	}
	cout<<"�������"<<endl;
	return 0;
}