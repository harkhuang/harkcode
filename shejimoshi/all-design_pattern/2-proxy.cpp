//Proxy 
#include <iostream>
using namespace std;
class Subject
{
public:
	virtual ~Subject();

	//�������ȥʵ��  ��������ʹ�ô����Ŀ��
	virtual void Request() = 0;
protected:
	
	Subject();
private:
};
class ConcreteSubject:public Subject
{
public:
	ConcreteSubject();
	~ConcreteSubject();
	void Request();
protected:
private:
};
class Proxy
{
public:
	Proxy();

	//�������⹹��������
	Proxy(Subject* sub);
	~Proxy();
	void Request();
protected:
private:

	//��������Ϊ��Ա����
	Subject* _sub;
};

Subject::Subject()
{
}
Subject::~Subject()
{
}
ConcreteSubject::ConcreteSubject()
{
}
ConcreteSubject::~ConcreteSubject()
{
}
void ConcreteSubject::Request()
{
	cout<<"ConcreteSubject......request...."<<endl;
}
Proxy::Proxy()
{
}
Proxy::Proxy(Subject* sub)
{
	_sub = sub;
}
Proxy::~Proxy()
{
	delete _sub;
}
void Proxy::Request()
{
	cout<<"Proxy request...."<<endl;
	_sub->Request();
}

int main(int argc,char* argv[])
{

	//����XX������
	Subject* sub = new ConcreteSubject();
	//ͨ��XX����������һ������
	Proxy* p = new Proxy(sub);
	//��Ӧ����Ĳ���
	p->Request();
	return 0;
}