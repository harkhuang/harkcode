#include <iostream>
using namespace std;
class human
{
public:
	void walk(){cout<<"人类能够直立行走!";}
	
};
class mother:public human
{
	
};
class father:public human
{
	
};
class son:public mother,public father
{

};
int main()
{
	son  tom;
    tom.mother::walk();
	tom.father::walk();
	tom.human::walk();
	return 0;
}