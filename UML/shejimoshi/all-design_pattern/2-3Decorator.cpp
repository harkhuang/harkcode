#include <iostream>
using namespace std;

class Component
{
public:
	virtual ~Component(){
		cout<<"~Component()"<<endl;
	};
	virtual void Operation(){
	};

protected:
	Component(){
		cout<<"Component()"<<endl;
	};
private:
};

//装饰物品具体实现  可以理解为装饰中的衣服
class ConcreteComponent:public Component
{
public:
	ConcreteComponent(){
		cout<<"ConcreteComponent()"<<endl;
	};
	~ConcreteComponent(){
		cout<<"~ConcreteComponent()"<<endl;
	};
	void Operation(){
		std::cout<<"ConcreteComponent::operation()"<<std::endl;
	};
protected:
private:
};


//装饰物品具体实现  可以理解为装饰中的裤子
class ConcreteComponent1:public Component
{
public:
	ConcreteComponent1(){
		cout<<"ConcreteComponent1()"<<endl;
	};
	~ConcreteComponent1(){
		cout<<"~ConcreteComponent1()"<<endl;
	};
	void Operation(){
		std::cout<<"ConcreteComponent1::operation()"<<std::endl;
	};
protected:
private:
};


class Decorator:public Component
{
public:
	Decorator(Component* com){
		this->_com = com;
	};
	virtual ~Decorator(){
		delete _com;
	};
	void Operation(){
		std::cout<<"Decorator::Operation()"<<std::endl;
	};
protected:

	//这个就是装饰物的抽象类
	Component* _com;
private:
};



class ConcreteDecorator:public Decorator
{
public:
	ConcreteDecorator(Component* com):Decorator(com){
		cout<<"ConcreteDecorator(com)"<<endl;
	};
	~ConcreteDecorator(){
		cout<<"~ConcreteDecorator()"<<endl;
	};
	void Operation(){
		_com->Operation();//通过抽象的方法去调用具体的装饰物
		this->AddedBehavior();//使用该装饰物的特性
	};
	void AddedBehavior(){
		std::cout<<"ConcreteDecorator::AddedBehavior()"<<std::endl;
	};
protected:
private:
};

int main(int argc,char* argv[])
{

	//通过ConcreteComponent来装饰
	Component* com = new ConcreteComponent();
	Decorator* dec = new ConcreteDecorator(com);
	dec->Operation();

	//通过ConcreteComponent1来装饰
	Component* com1 = new ConcreteComponent1();
	dec = new ConcreteDecorator(com1);
	dec->Operation();

	delete dec;
	return 0;
}