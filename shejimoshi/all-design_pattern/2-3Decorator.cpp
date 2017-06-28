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

//װ����Ʒ����ʵ��  �������Ϊװ���е��·�
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


//װ����Ʒ����ʵ��  �������Ϊװ���еĿ���
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

	//�������װ����ĳ�����
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
		_com->Operation();//ͨ������ķ���ȥ���þ����װ����
		this->AddedBehavior();//ʹ�ø�װ���������
	};
	void AddedBehavior(){
		std::cout<<"ConcreteDecorator::AddedBehavior()"<<std::endl;
	};
protected:
private:
};

int main(int argc,char* argv[])
{

	//ͨ��ConcreteComponent��װ��
	Component* com = new ConcreteComponent();
	Decorator* dec = new ConcreteDecorator(com);
	dec->Operation();

	//ͨ��ConcreteComponent1��װ��
	Component* com1 = new ConcreteComponent1();
	dec = new ConcreteDecorator(com1);
	dec->Operation();

	delete dec;
	return 0;
}