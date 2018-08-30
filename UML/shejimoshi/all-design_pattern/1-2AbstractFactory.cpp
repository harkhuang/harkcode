#include <iostream>
using namespace std;


//��Ʒ����Ҳʹ���˽ӿڵ�����,�����Ϳ�����������ͬ�Ĳ�Ʒ����
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


//ϣ���ﵽ��Ŀ����,ͨ������ָ������ҵ����еķ���,�൱�ڹ����˲�Ʒ�б�����,������ʲô������ʲô
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

    // ������̬
    Factory* fac = new ConcreteFactory();
    // ���ö�̬
    Product* p = fac->CreateProduct();
    return 0;
}