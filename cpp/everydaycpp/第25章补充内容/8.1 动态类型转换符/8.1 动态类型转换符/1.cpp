
//��������ת��ָ��
#include <iostream>
using namespace std;
class Father 
{
public:
	virtual void experience(){cout<<"���׾���ȶ��Ӷ�\n";}
};
class Son:public Father 
{
public:
	virtual void Run()
	{
		cout<<"�����ܵıȸ��׿�";
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
		cout<<"ת��ʧ��\n";
	delete pFather;
	return 0;
} 



/*
//��������ת������

#include <iostream>
using namespace std;
class Father 
{
public:
     virtual void Run (){cout<<"�����ܵÿ�\n";}
};
class Son:public Father 
{
public:
	virtual void Run()
	{
		cout<<"�����ܵıȸ��׿�\n";
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
		cout<<"ת��ʧ��\n";
	}
	catch (...) 
	{
		cout<<"ת������\n";
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