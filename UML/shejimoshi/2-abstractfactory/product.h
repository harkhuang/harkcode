/**
 * @file				product.h
 * @brief				抽象工厂模式
 * @author			harkhuang
 * @date				2014年9月30日
 * @version			初稿
 * @par				版权所有(C), 2013-2023, 翻版必究
 * @par History:
 * 1.日    期: 		2014年9月30日
 *   作    者: 		harkhuang
 *   修改内容:	创建文件
*/
#ifndef _PRODUCT_H_
#define _PRODUCT_H_
#include <iostream>
#include "abstractfactory.h"
using namespace std;

class AbstractProductA
{
public:
	virtual ~AbstractProductA();//因为有虚函数所以要用虚析构函数
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
