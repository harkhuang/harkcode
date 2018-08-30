#include <iostream>
using namespace std;


class AbstractProductA
{
public:
    virtual ~AbstractProductA();
protected:
    AbstractProductA();
private:
};
class AbstractProductB
{
public:
    virtual ~AbstractProductB();
protected:
    AbstractProductB();
private:
};
class ProductA1:public AbstractProductA
{
public:
    ProductA1();
    ~ProductA1();
protected:
private:
};
class ProductA2:public AbstractProductA
{
public:
    ProductA2();
    ~ProductA2();
protected:
private:
};
class ProductB1:public AbstractProductB
{
public:
    ProductB1();
    ~ProductB1();
protected:
private:
};
class ProductB2:public AbstractProductB
{
public:
    ProductB2();
    ~ProductB2();
protected:
private:
};
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
    cout<<"ProductA1..."<<endl;
}
ProductA1::~ProductA1()
{
}
ProductA2::ProductA2()
{
    cout<<"ProductA2..."<<endl;
}
ProductA2::~ProductA2()
{
}
ProductB1::ProductB1()
{
    cout<<"ProductB1..."<<endl;
}
ProductB1::~ProductB1()
{
}
ProductB2::ProductB2()
{
    cout<<"ProductB2..."<<endl;
}
ProductB2::~ProductB2()
{
}



class AbstractFactory
{
public:
    virtual ~AbstractFactory();
    virtual AbstractProductA* CreateProductA() = 0;
    virtual AbstractProductB* CreateProductB() = 0;
protected:
    AbstractFactory();
private:
};
class ConcreteFactoryNick:public AbstractFactory
{
public:
    ConcreteFactoryNick();
    ~ConcreteFactoryNick();
    AbstractProductA* CreateProductA();
    AbstractProductB* CreateProductB();
protected:
private:
};
class ConcreteFactoryAdidas:public AbstractFactory
{
public:
    ConcreteFactoryAdidas();
    ~ConcreteFactoryAdidas();
    AbstractProductA* CreateProductA();
    AbstractProductB* CreateProductB();
protected:
private:
};

AbstractFactory::AbstractFactory()
{
}
AbstractFactory::~AbstractFactory()
{
}
ConcreteFactoryNick::ConcreteFactoryNick()
{
}
ConcreteFactoryNick::~ConcreteFactoryNick()
{
}
AbstractProductA* ConcreteFactoryNick::CreateProductA()
{
    return new ProductA1();
}
AbstractProductB* ConcreteFactoryNick::CreateProductB()
{
    return new ProductB1();
}
ConcreteFactoryAdidas::ConcreteFactoryAdidas()
{
}
ConcreteFactoryAdidas::~ConcreteFactoryAdidas()
{
}
AbstractProductA* ConcreteFactoryAdidas::CreateProductA()
{
    return new ProductA2();
}
AbstractProductB* ConcreteFactoryAdidas::CreateProductB()
{
    return new ProductB2();
}

int main(int argc,char* argv[])
{
    AbstractFactory* cf1 = new ConcreteFactoryNick();
    cf1->CreateProductA();
    cf1->CreateProductB();
    AbstractFactory* cf2 = new ConcreteFactoryAdidas();
    cf2->CreateProductA();
    cf2->CreateProductB();
    return 0;
}