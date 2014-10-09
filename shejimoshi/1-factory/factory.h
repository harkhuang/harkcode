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


    //1.chunxuhanshu   zileibixushixian
    //2.wei zilei tigong yige  chuangjian de jiekou
    //3.
public:
    virtual Product * MakeProduct() = 0;
};

class ConcreteFactory:public Factory
{
public:
    ~ConcreteFactory();
    ConcreteFactory();

public:
    Product * MakeProduct();
protected:
private:
};

#endif
