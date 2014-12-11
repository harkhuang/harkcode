#include <iostream>
using namespace std;
class father
{
public:
	father():age(54){cout<<"father  construct  with age"<<age<<"\n";}
	~father(){cout<<"father  finalizer  \n";}
	void jump()const{cout<<"father jump\n";}
	void run()const{cout<<"father run\n";}
protected:
	int age;
};
class son:public father
{
public:
	son(){cout<<"construct  father..\n";}
	//~son(){cout<<"调用子类的析构函数\n";}
	~son(){cout<<"son  filezer...\n";}
	void math(){cout<<"son  learn match.\n";}
	void jump()const{cout<<"son  jump  10 fools..\n";}
	void run()const{cout<<"son run 10 000 meters..\n";}
};
int main()
{
	son*p=new son;
	p->jump();
	p->run();
	p->math();
	delete p;
	return 0;
}
