#include <iostream>
using namespace std;
class father
{
public:
	void smart()
	{
		cout<<"���׺ܴ���\n";
	}
	//virtual void beautiful(){}
	virtual ~father(){cout<<"����father"<<endl;}
};
class son:public father
{
public:
	 virtual void beautiful(){cout<<"����Ҳ��˧\n";}
	~son(){cout<<"����son";}
};
int main()
{
	father *pf;
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
			case 2:pf=new son;
				dynamic_cast<son*>(pf)->beautiful();
				pf->smart();
				delete pf;
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