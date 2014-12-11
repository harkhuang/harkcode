#include <iostream>
using namespace std;
class father
{
public:
	father(){cout<<"构造father\n";}
	void smart()
	{
		cout<<"父亲很聪明\n";
	}
	//virtual void beautiful(){}
	virtual ~father(){cout<<"析构father"<<endl;}
};
class mother
{
public:
	mother(){cout<<"构造mother\n";}
	virtual void beautiful(){cout<<"母亲很漂亮"<<endl;}
	virtual ~mother(){cout<<"析构mother"<<endl;}
};
class son:public father,public mother
{
public:
	son(){cout<<"构造son\n";} 
	virtual void beautiful(){cout<<"儿子也很帅\n";}
	~son(){cout<<"析构son"<<endl;}
};
int main()
{
	father *pf;
	mother *pm;
	int choice=0;
	while (choice<99)
	{
		bool quit=false;
		cout<<"(0)退出(1)父亲(2)儿子:";
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
			default:cout<<"请输入从0到2之间的数字。";
		}
		if (quit)
		{
			break;
		}
	}
	cout<<"程序结束"<<endl;
	return 0;
}