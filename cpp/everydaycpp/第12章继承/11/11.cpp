#include <iostream>
using namespace std;
class father
{
public:
	void setA(int a){tall=a;}
	void printA(){cout<<"���="<<tall<<endl;}
private:
	int tall;
};
class mother
{
private:
	int weight;
public:
	void setB(int a){weight=a;}
	void printB(){cout<<"����="<<weight<<endl;}
};
class son:public father,private mother
{
private:
	int age;
public:
	void setC(int c){age=c;}
	void setb(int b){setB(b);}
	void printC(){printA(),printB(),cout<<"����="<<age<<endl;}
};
int main()
{
	son a;
	a.setA(55);
	a.setb(33);
	a.setC(66);
	a.printC();
    return 0;
}