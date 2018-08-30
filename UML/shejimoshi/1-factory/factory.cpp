#include <iostream>
#include "factory.h"
#include"product.h"

using namespace std;

Factory::Factory()
{

}

Factory::~Factory()
{

}

ConcreteFactory::ConcreteFactory()
{
    cout<<"ConcreteProduct"<<endl;
}

ConcreteFactory::~ConcreteFactory()
{

}
Product * ConcreteFactory::MakeProduct()
{
	//父类指针指向子类
	//这样就不必为找不到子类的创建名字而苦恼了
    return new ConcreteProduct();//真正的实现创建在这里 
}
