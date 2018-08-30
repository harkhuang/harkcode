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


    //1.���麯���������ʵ��
    //2.Ϊ�����ṩһ�������ӿ�
    //3.�ú����ķ���ֵ��һ����ָ��
public:
    virtual Product * MakeProduct() = 0;
};

class ConcreteFactory:public Factory
{
public:
    ~ConcreteFactory();
    ConcreteFactory();

public:
    Product * MakeProduct();//����ֵ��һ����ָ��   ��������������
protected:
private:
};

#endif
