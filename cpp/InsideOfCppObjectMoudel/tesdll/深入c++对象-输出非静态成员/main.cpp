#include <iostream>
#include <stdio.h>
using namespace std;
class Ctest
{
public:
	static void statFunc()
	{  cout << "statFunc" << endl; }
	void dynFunc()
	{  cout << "dynFunc" << endl; }
	virtual void virtFunc()
	{  cout << "virtFunc" << endl; }
};
typedef void (*gettest)();
 
typedef  void (*pfunc)( );
typedef  void (Ctest::*p_dynFuncxxxx)();

void main()
{
	Ctest Object;
	Ctest* pObject = &Object;
	cout << "address of Ctest::statFunc:" << &Ctest::statFunc << endl;
	printf( "address of Ctest::dynFunc :X\n", &Ctest::dynFunc);
	printf( "address of Ctest::virtFunc:X\n", &Ctest::virtFunc);
	static void (*p_statFunc)();
	void (Ctest::*p_dynFunc)();//注意非静态成员函数指针的定义需指明在那个类的域内
	void (Ctest::*p_virtFunc)();
	p_statFunc = &Ctest::statFunc;
	p_dynFunc = &Ctest::dynFunc;
	gettest gegt =  &Ctest::dynFunc;
	p_dynFuncxxxx calldyn = &Ctest::dynFunc;
	(Object.*calldyn)();
	p_virtFunc = &Ctest::virtFunc;
	p_statFunc();
	//非静态成员函数指针的调用也与普通函数不同，另外因为.*的优先级比()低，所以需要用括号把左边的操作
	//数括起来，如果写成Object.*p_dynFunc();将无法通过编译

	// 
	(Object.*p_dynFunc)();
	(Object.*p_virtFunc)();
	 Ctest *aaaa;
	(Object.*p_virtFunc)();
	while(1);
}