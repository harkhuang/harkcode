#ifndef  _PRODUCT_H_
#define  _PRODUCT_H_

#include  <iostream>

class Product
{
public:
    //´¿ÐéÎö¹¹º¯Êý
    virtual ~Product() =0;//Pure virtual function in a subclass must override achieve
protected:
    Product();
private:
};

class ConcreteProduct:public Product
{
public:
    ~ConcreteProduct();
    ConcreteProduct();
protected:
private:
};
#endif
