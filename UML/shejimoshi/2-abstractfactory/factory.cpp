#include "factory.h"
AbstractProductA* ConcreteFactory2::MakeProductA()
{
	return new ProductA();
}