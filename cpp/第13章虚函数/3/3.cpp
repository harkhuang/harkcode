#include <iostream>
using namespace std;
class poser 
{
public:
	virtual void beat()const {cout<<"normal function\n";}
protected:
	int age;
};
class Ali:public poser
{
public:
	virtual void beat()const{cout<<"ali  is  300\n";}
};
class Lewis:public poser
{
public:
	void beat()const{cout<<"lewis  is  200\n";}
};
class Tyson:public poser
{
public:
	void beat()const{cout<<"tyson is  100\n";}
};
class Holy:public poser
{
public:
	void beat()const{cout<<"holy is 50\n";}
};
int main()
{
	poser *p[5];
	poser *p1;
	int choice,i;
	p1=new Ali;
	p[0]=p1;
	p[0]->beat();	
	
	p1=new Tyson;
	p[1]=p1;
	p[1]->beat();
	
	p1=new Tyson;
	p[2]=p1;
	p[2]->beat();	
	
	p1=new Holy;
	p[3]=p1;
	p[3]->beat();
	

	p1=new poser;
	p[4]=p1;
	p[4]->beat();
	return 0;
}
