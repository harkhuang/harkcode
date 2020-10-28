#include <iostream>
#include <stdio.h>
using namespace std;
class Animal
{

public:
	Animal()
	{

	}
    ~Animal()
	{

	}
	void  speack()
	{  cout << "Animal speack" << endl; }
	
};


class Dog:Animal
{
public:
	Dog(){};
	~Dog(){};
	void  speack()
	{  cout << "wang wang" << endl; }

};
class Cat:public virtual Animal
{
public:
	Cat(){};
	~Cat(){};
	void speack()
	{  cout << "miao miao" << endl; }

};


class ZeroFunc : public Animal
{
public:
	long l;
	char c;
	int a;
	ZeroFunc()
	{
		c = 'a';
		a =1;
		l = 100;
	}
	~ZeroFunc()
	{}
	void foo1()
	{

	}
};

class A{
public:
	A(){cout << "A construct " <<endl;};
public:
	int a;
};
class B{
public:
	B(){cout << "B construct " <<endl;};
public:
	char a;
};
class D{
public:
	D(){cout << "D construct " <<endl;};
public:
	char  a[100];
};

class C{
public:
	C(){cout << "C construct " <<endl;};
	A a;
	B b;
	D d;
};
void main()
{

	C c;
	Animal animal;
	Cat cat;
	Animal *panimal = &cat;
	panimal->speack();

	getchar();
}