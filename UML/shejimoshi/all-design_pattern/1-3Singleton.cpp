#include <iostream>

using namespace std;


class Singleton
{
public:
	static Singleton* Instance();
protected:
		 Singleton();
private:
	static Singleton* _instance;
};


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
Singleton* Singleton::_instance = 0;



int main(int argc,char* argv[])
{
	Singleton* sgn = Singleton::Instance();

	//Singleton* sgn11 = Singleton::Instance();
	return 0;
}