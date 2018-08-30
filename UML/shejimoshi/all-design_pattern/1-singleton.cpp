
#include <iostream>
using namespace std;

//Singleton.h
#include <iostream>
using namespace std;


class A
{
public:
    A(){cout <<"xx"<<endl;}
protected:
    ~A();
private:

};

class Singleton
{
public:
    static Singleton* Instance();
protected:
    Singleton();
private:
    static Singleton* _instance;
public:
    static A *pa;
};



Singleton* Singleton::_instance = 0;


Singleton::Singleton()
{
	cout<<"Singleton...."<<endl;
}


Singleton* Singleton::Instance()
{
	if (_instance == 0)
	{
		_instance = new Singleton();
	}
	return _instance;
}

A* Singleton::pa = NULL;
int main()
{
    Singleton* sgn = Singleton::Instance();
    Singleton::pa = new A();
    return 0;
}
