#ifndef _FACTORY_H_
#define _FACTORY_H_
#include <iostream>

#include "product.h"
using namespace std;

class AbstractFactory
{
public:
	~AbstractFactory();
    virtual AbstractProductA *MakeProductA() = 0;//����ֻ�нӿ�
	virtual AbstractProductB *MakeProductB() = 0;//����ֻ�нӿ�
protected:
	AbstractFactory();
private:
	
	
};

class ConcreteFactory1:public Factory
{
public:
	~ConcreteFactory1();
	ConcreteFactory1();
	virtual AbstractProductA * MakeProductA();  //��������ʵ��
	virtual AbstractProductB * MakeProductB();
protected:
	
	
private:

};

class ConcreteFactory2:public Factory
{
public:
	~ConcreteFactory2();
	ConcreteFactory2();
	virtual AbstractProductA * MakeProductA();
	virtual AbstractProductB * MakeProductB();
protected:
	
	
private:

};


#endif

