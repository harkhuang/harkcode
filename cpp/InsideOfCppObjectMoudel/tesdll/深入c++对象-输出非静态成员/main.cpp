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
	void (Ctest::*p_dynFunc)();//ע��Ǿ�̬��Ա����ָ��Ķ�����ָ�����Ǹ��������
	void (Ctest::*p_virtFunc)();
	p_statFunc = &Ctest::statFunc;
	p_dynFunc = &Ctest::dynFunc;
	gettest gegt =  &Ctest::dynFunc;
	p_dynFuncxxxx calldyn = &Ctest::dynFunc;
	(Object.*calldyn)();
	p_virtFunc = &Ctest::virtFunc;
	p_statFunc();
	//�Ǿ�̬��Ա����ָ��ĵ���Ҳ����ͨ������ͬ��������Ϊ.*�����ȼ���()�ͣ�������Ҫ�����Ű���ߵĲ���
	//�������������д��Object.*p_dynFunc();���޷�ͨ������

	// 
	(Object.*p_dynFunc)();
	(Object.*p_virtFunc)();
	 Ctest *aaaa;
	(Object.*p_virtFunc)();
	while(1);
}