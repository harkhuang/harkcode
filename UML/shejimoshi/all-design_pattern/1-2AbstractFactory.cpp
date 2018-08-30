#include <iostream>
using namespace std;


//产品定义也使用了接口的形势,这样就可以派生出不同的产品种类
class Product
{
public:
    virtual ~Product() =0 {};
protected:
    Product(){}
private:
};

class ConcreteProduct:public Product
{
public:
    ~ConcreteProduct(){}
  
    ConcreteProduct()
    {
         cout<<"ConcreteProduct...."<<endl;
    }
protected:
private:
};


//希望达到的目的是,通过基类指针就能找到所有的方法,相当于构建了产品列表索引,想生产什么就生产什么
class Factory
{
public:
    virtual ~Factory() = 0 {};
    virtual Product* CreateProduct() = 0;
protected:
    Factory(){}
private:
};


class ConcreteFactory:public Factory
{
public:
    ~ConcreteFactory()
    {
         cout<<"~ConcreteFactory....."<<endl;
    }
    ConcreteFactory()
    {
         cout<<"ConcreteFactory....."<<endl;
    }
    Product* CreateProduct()
    {
        return new ConcreteProduct();
    }
protected:
private:
};



class Base
{
public:
    Base();
    virtual ~Base() = 0 ;
};
int main()
{
    Base b;

    // 产生多态
    Factory* fac = new ConcreteFactory();
    // 利用多态
    Product* p = fac->CreateProduct();
    return 0;
}