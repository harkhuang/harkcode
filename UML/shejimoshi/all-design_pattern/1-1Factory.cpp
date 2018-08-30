#include <iostream>
using namespace std;


class AbstractProductA
{
public:
    virtual ~AbstractProductA() { cout<<"~AbstractProductA...."<<endl;};
protected:
    AbstractProductA() { cout<<"AbstractProductA...."<<endl;};
private:
};
class AbstractProductB
{
public:
    virtual ~AbstractProductB(){ cout<<"~AbstractProductB...."<<endl;};
protected:
    AbstractProductB(){ cout<<"AbstractProductB...."<<endl;};
private:
};
class ProductA1:public AbstractProductA
{
public:
    ProductA1(){ cout<<"ProductA1...."<<endl;};
    ~ProductA1(){ cout<<"~ProductA1...."<<endl;};
protected:
private:
};
class ProductA2:public AbstractProductA
{
public:
    ProductA2(){cout<<"ProductA2...."<<endl;};
    ~ProductA2(){cout<<"~ProductA2...."<<endl;};
protected:
private:
};
class ProductB1:public AbstractProductB
{
public:
    ProductB1(){cout<<"ProductB1...."<<endl;};
    ~ProductB1(){cout<<"~ProductB1...."<<endl;};
protected:
private:
};
class ProductB2:public AbstractProductB
{
public:
    ProductB2(){cout<<"ProductB2...."<<endl;};
    ~ProductB2(){cout<<"~ProductB2...."<<endl;};
protected:
private:
};


class AbstractFactory
{
public:
    virtual ~AbstractFactory() = 0 {cout<<"~AbstractFactory...."<<endl;};
    virtual AbstractProductA* CreateProductA() = 0;
    virtual AbstractProductB* CreateProductB() = 0;
protected:
    AbstractFactory(){cout<<"AbstractFactory...."<<endl;};
private:
};
class ConcreteFactoryNick:public AbstractFactory
{
public:
    ConcreteFactoryNick(){cout<<"ConcreteFactoryNick...."<<endl;};
    ~ConcreteFactoryNick(){cout<<"~ConcreteFactoryNick...."<<endl;};
    AbstractProductA* CreateProductA(){  return new ProductA2(); }
    AbstractProductB* CreateProductB(){  return new ProductB2(); }
protected:
private:
};
class ConcreteFactoryAdidas:public AbstractFactory
{
public:
    ConcreteFactoryAdidas(){cout<<"ConcreteFactoryAdidas...."<<endl;};
    ~ConcreteFactoryAdidas(){cout<<"~ConcreteFactoryAdidas...."<<endl;};
    AbstractProductA* CreateProductA(){ return new ProductA1();  };
    AbstractProductB* CreateProductB(){ return new ProductB1();  };
protected:
private:
};

int main(int argc,char* argv[])
{
    AbstractFactory* cf1 = new ConcreteFactoryNick();
    cf1->CreateProductA();
    cf1->CreateProductB();
    AbstractFactory* cf2 = new ConcreteFactoryAdidas();
    cf2->CreateProductA();
    cf2->CreateProductB();

    delete cf1;
    delete cf2;
    return 0;
}