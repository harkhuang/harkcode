#include <iostream>
using namespace std;
class human
{
public:
	void walk(){cout<<"�����ܹ�ֱ������!";}
	
};
class mother:virtual public human
{
public:
	void walk(){cout<<"ĸ���ܹ�ֱ������!";}
};
class father:virtual public human
{
public:
	void walk(){cout<<"�����ܹ�ֱ������!";}
};
class son:public mother,public father
{
public:
	void walk(){cout<<"�����ܹ�ֱ������!";}
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