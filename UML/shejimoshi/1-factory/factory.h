#ifndef _FACTORY_H_
#define _FACTORY_H_
#include <iostream>
using namespace std;

class Product;

class Factory
 {
public:
    virtual ~Factory() = 0;
protected:
    Factory();


    //1.纯虚函数子类必须实现
    //2.为子类提供一个创建接口
    //3.该函数的返回值是一个类指针
public:
    virtual Product * MakeProduct() = 0;
};

class ConcreteFactory:public Factory
{
public:
    ~ConcreteFactory();
    ConcreteFactory();

public:
    Product * MakeProduct();//返回值是一个类指针   创建和生产分离
protected:
private:
};

#endif
