//Proxy 
#include <iostream>
using namespace std;
class Subject
{
public:
	virtual ~Subject();

	//请求必须去实现  这是真正使用代理的目的
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

	//根据主题构建代理器
	Proxy(Subject* sub);
	~Proxy();
	void Request();
protected:
private:

	//代理器作为成员变量
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

	//构造XX代理器
	Subject* sub = new ConcreteSubject();
	//通过XX代理器生成一个代理
	Proxy* p = new Proxy(sub);
	//相应代理的操作
	p->Request();
	return 0;
}