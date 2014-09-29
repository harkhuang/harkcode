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
    return new ConcreteProduct();
}
