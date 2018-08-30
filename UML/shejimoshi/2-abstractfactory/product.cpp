#include "product.h"

#include <iostream>
using namespace std;

AbstractProductA::AbstractProductA()
{

}

AbstractProductA::~AbstractProductA()
{

}


AbstractProductB::AbstractProductB()
{

}

AbstractProductB::~AbstractProductB()
{

}

ProductA1::ProductA1()
{
cout<<"Construct productA1..."<<endl;
}

ProductA1::~ProductA1()
{
cout<<"Destructor productA1..."<<endl;
}

ProductA2::productA2()
{
	cout<<"Construct productA2..."<<endl;
}

ProductA2::~productA2()
{
	cout<<"Destructor productA2..."<<endl;
}

ProductB1::ProductB1()
{
cout<<"Construct productB1..."<<endl;
}
ProductB1::~ProductB1()
{
cout<<"Destructor productB1..."<<endl;
}