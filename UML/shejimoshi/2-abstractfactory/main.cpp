#include "abstractfactory.h"

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	AbstarctFactory * cf1 = new ConcreteFactory1();
	cf1->CreateProductA();
	cf1->CreateProductB();
	AbstarctFactory * cf2 = new ConcreteFactory2();
	cf2->CreateProductA();
	cf2->CreateProductB();
	return 0;
}
