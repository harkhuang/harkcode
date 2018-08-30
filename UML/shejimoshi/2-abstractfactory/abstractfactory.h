#ifndef _ABSRACTFACTORY_H_
#define _ABSTACTFACTORY_H_

class AbstractProductA;
class AbstractProductB;

class AbstarctFactory
{
public:
	virtual ~AbstarctFactory();
	virtual AbstractProductA *MakeProductA() = 0;
	virtual AbstractProductB *MakeProductB() = 0;
protected:
	AbstarctFactory();
private:
	
};

class ConcreteFactory1:public AbstarctFactory
{
public:
	ConcreteFactory1();
	~ConcreteFactory1();
	AbstractProductA * MakePorductA();
	AbstractProductB * MakeProductB();
};

class ConcreteFactory2:public AbstarctFactory
{
public:
	ConcreteFactory2();
	~ConcreteFactory2();
	AbstractProductA * MakePorductA();
	AbstractProductB * MakeProductB();
}; 

#endif 

