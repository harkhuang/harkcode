/**
 * @file				product.h
 * @brief				���󹤳�ģʽ
 * @author			harkhuang
 * @date				2014��9��30��
 * @version			����
 * @par				��Ȩ����(C), 2013-2023, ����ؾ�
 * @par History:
 * 1.��    ��: 		2014��9��30��
 *   ��    ��: 		harkhuang
 *   �޸�����:	�����ļ�
*/
#ifndef _PRODUCT_H_
#define _PRODUCT_H_
#include <iostream>
#include "abstractfactory.h"
using namespace std;

class AbstractProductA
{
public:
	virtual ~AbstractProductA();//��Ϊ���麯������Ҫ������������
protected:
	AbstractProductA();
private:
		
};



class AbstractProductB
{
public:
	virtual AbstractProductB();
protected:
	AbstractProductB();
private:

};


class ProductA1:public AbstractProductA
{
public:
	virtual ~ProductA1();
	ProductA1();
protected:
	
private:
	
};


class ProductA2:public AbstractProductA
{
public:
	virtual ~ProductA2();
	ProductA2();
protected:
	
private:
	
};
class ProductB1:public AbstractProductB
{
public:
	~ProductB1();
	ProductB1();
protected:
private:
};


class ProductB2:public AbstractProductB
{
public:
	~ProductB2();
	ProductB2();
protected:
private:
};

#endif
