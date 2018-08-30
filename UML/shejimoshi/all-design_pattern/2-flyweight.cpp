//Flyweight 享元模式
#include <string>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
class Flyweight
{
public:
	 
	  virtual ~Flyweight();
	  virtual void Operation(const string& extrinsicState);
	  string GetIntrinsicState();
protected:
	Flyweight(string intrinsicState);
private:
	string _intrinsicState;
};
class ConcreteFlyweight:public Flyweight
{
public:
	ConcreteFlyweight(string intrinsicState);
	~ConcreteFlyweight();
	void Operation(const string& extrinsicState);
protected:
private:
};

Flyweight::Flyweight(string intrinsicState)
{
	this->_intrinsicState = intrinsicState;
}
Flyweight::~Flyweight()
{
}
void Flyweight::Operation(const string& extrinsicState)
{
}
string Flyweight::GetIntrinsicState()
{
	return this->_intrinsicState;
}
ConcreteFlyweight::ConcreteFlyweight(string
	intrinsicState):Flyweight(intrinsicState)
{
	cout<<"ConcreteFlyweight Build....."<<intrinsicState<<endl;
}
ConcreteFlyweight::~ConcreteFlyweight()
{
}
void ConcreteFlyweight::Operation(const string& extrinsicState)
{
	cout<<"ConcreteFlyweight:内蕴["<<this->GetIntrinsicState()<<"] 外蕴["<<extrinsicState<<"]"<<endl;
}

class FlyweightFactory
{
public:
	FlyweightFactory(){};
	~FlyweightFactory(){};
	Flyweight* GetFlyweight(const string& key);
protected:
private:

	//共享类容器
	vector<Flyweight*> _fly;

	//非共享元素
	vector<Flyweight*> _unsharefly;
};



// 获取共享元素类指针
Flyweight* FlyweightFactory::GetFlyweight(const string& key)
{
	vector<Flyweight*>::iterator it = _fly.begin();
	for (; it != _fly.end();it++)
	{
		//找到了，就一起用， ^_^
		if ((*it)->GetIntrinsicState() == key)
		{
			cout<<"already created by users...."<<endl;
			return *it;
		}
	}
	Flyweight* fn = new ConcreteFlyweight(key);
	_fly.push_back(fn);
	return fn;
}

int main(int argc,char* argv[])
{
	FlyweightFactory* fc = new FlyweightFactory();
	Flyweight* fw1 = fc->GetFlyweight("hello");
	Flyweight* fw2 = fc->GetFlyweight("world!");
	Flyweight* fw3 = fc->GetFlyweight("hello");
	return 0;
}