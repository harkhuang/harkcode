#include "abstractfactory.h"
#include "product.h"


#include <iostream>
using namespace std;


AbstarctFactory::AbstarctFactory()
{

}

AbstarctFactory::~AbstarctFactory()
{

}


ConcreteFactory1::ConcreteFactory1()
{

}
ConcreteFactory1::~ConcreteFactory1()
{

}

AbstractProductA* ConcreteFactory1::MakeProductA()
{
	return new ProductA1();
}

AbstractProductA* ConcreteFactory1::MakeProductB()
{
	return new ProductB1();
}


ConcreteFactory2::ConcreteFactory2()
{

}
ConcreteFactory2::~ConcreteFactory2()
{

}

AbstractProductA* ConcreteFactory2::MakeProductA()
{
	return new ProductA2();
}

AbstractProductA* ConcreteFactory2::MakeProductB()
{
	return new ProductB2();
}



