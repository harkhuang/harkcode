
//向下类型转换指针
#include <iostream>
using namespace std;
class Father 
{
public:
	virtual void experience(){cout<<"父亲经验比儿子多\n";}
};
class Son:public Father 
{
public:
	virtual void Run()
	{
		cout<<"儿子跑的比父亲快";
	}
};
int main()
{
	Father*pFather;
	int choice;
	cout<<"(1)Father(2)Son:";
	cin>>choice;
	if (choice==2)
	{
			pFather=new Son;
	}
	else
			pFather=new Father;
	Son*p=dynamic_cast<Son*>(pFather);
	if (p)
	{
		p->Run();
	}
	else
		cout<<"转换失败\n";
	delete pFather;
	return 0;
} 



/*
//向下类型转换引用

#include <iostream>
using namespace std;
class Father 
{
public:
     virtual void Run (){cout<<"父亲跑得快\n";}
};
class Son:public Father 
{
public:
	virtual void Run()
	{
		cout<<"儿子跑的比父亲快\n";
	}
};
void fun(Father&r)
{
	try
	{
		Son&p=dynamic_cast<Son&>(r);
		p.Run();
	}
	catch (bad_cast)
	{
		cout<<"转换失败\n";
	}
	catch (...) 
	{
		cout<<"转换出错\n";
	}
}
int main()
{
	Father pFather;
	Son son;
	fun(son);
	fun(pFather);
	return 0;
}
*/