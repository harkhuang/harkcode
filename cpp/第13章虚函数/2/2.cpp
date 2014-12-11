#include <iostream>
using namespace std;
class father
{
public:
	virtual void run()const{cout<<"father can run 1000meters\n";}
	void jump()const{cout<<"father can jump 10 steps\n";}
};
class son:public father
{
public:
	void run()const{cout<<"son can run 10 meters\n";}
	void jump()const{cout<<"son can jump 15 steps\n";}
};
int main()
{
	father*p=new son;
	p->jump();
	p->run();
	delete p;
	return 0;
}
