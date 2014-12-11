#include <iostream>
using namespace std;
class human
{
public:
	void walk(){cout<<"人类能够直立行走!";}
	
};
class mother:virtual public human
{
public:
	void walk(){cout<<"母类能够直立行走!";}
};
class father:virtual public human
{
public:
	void walk(){cout<<"父类能够直立行走!";}
};
class son:public mother,public father
{
public:
	void walk(){cout<<"子类能够直立行走!";}
};
int main()
{
	son  tom;
	tom.walk();
    father Mick;
	Mick.walk();
	mother Jane;
	Jane.walk();
	human man;
	man.walk();
	return 0;
}