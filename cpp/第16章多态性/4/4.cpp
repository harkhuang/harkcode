#include <iostream>
using namespace std;
class Human 
{
public:
	Human(){cout<<"构造Human\n";}
	virtual void smart(){}
	virtual void beautiful(){}
	virtual ~Human(){cout<<"析构Human\n";}
};
class father: virtual public Human
{
public:
	father(){cout<<"构造father\n";}
	virtual void smart()
	{
		cout<<"父亲很聪明\n";
	}
	//virtual void beautiful(){}
	virtual ~father(){cout<<"析构father"<<endl;}
};
class mother:virtual public Human
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
	virtual void smart(){cout<<"儿子也很聪明\n";}
	virtual ~son(){cout<<"析构son"<<endl;}
};
int main()
{
	Human*p;
	int choice=0;
	while (choice<99)
	{
		bool quit=false;
		cout<<"(0)退出(1)父亲(2)儿子(3)母亲:";
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
			default:cout<<"请输入从0到2之间的数字。";
				break;
		}
		if (quit)
		{
			break;
		}
	}
	cout<<"程序结束"<<endl;
	return 0;
}