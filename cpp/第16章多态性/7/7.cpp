#include <iostream>
using namespace std;
class Animal 
{
public:
	Animal(int);
	virtual ~Animal(){cout<<"��������...\n";}
	virtual int GetAge(){return itsage;}
	virtual void Sleep()=0;
	virtual void Propagate()=0;
	virtual void Move()=0;
	virtual void Body()=0;
	virtual void Eat()=0;
	virtual void Show()=0;
private:
	int itsage;
};
Animal::Animal(int age):itsage(age)
{
	cout<<"��������...\n";
}
class Mammalia:public Animal
{
public:
	Mammalia(int age):Animal(age)
	{
		cout<<"����������...\n";
	}
	virtual ~Mammalia()
	{
		cout<<"����������...\n";
	}
	virtual void Propagate()
	{
		cout<<"��������̥�����ͨ����̥����ֳ�����\n";
	}
};
class Bird:public Animal
{
public:
	Bird(int age):Animal(age)
	{
		cout<<"��������...\n";
	}
	virtual ~Bird()
	{
		cout<<"��������...\n";
	}
	virtual void Sleep()
	{
		cout<<"����ϲ��վ��˯����\n";
	}
	virtual void Eat()
	{
		cout<<"������������⣬�������ǳ��ء�\n";
	}
	virtual void Propagate()
	{
		cout<<"�������������ͨ����������ֳ�����\n";
	}
	virtual void Move()
	{
		cout<<"������Է�...\n";
	}
	virtual void Body()
	{
		cout<<"�����������ë��ǰ֫��Ϊ��\n";
	}
	virtual void Show()
	{
		cout<<"�����һ������Ϊ��"<<GetAge()<<"��"<<endl;
	}
};
class Human:public Mammalia 
{
public:
	Human(int age):Mammalia(age)
	{
		cout<<"��������...\n";
	}
	virtual ~Human()
	{
		cout<<"��������...\n";
	}
	virtual void Sleep()
	{
		cout<<"����Ҫ�ڴ���˯����\n";
	}
	virtual void Eat()
	{
		cout<<"������˲�����ʳ��\n";
	}
	virtual void Propagate()
	{
		cout<<"����ͨ����̥��ֳ�����\n";
	}
	virtual void Move()
	{
		cout<<"���࿿��������·...\n";
	}
	virtual void Body()
	{
		cout<<"���������ë��\n";
	}
	virtual void Show()
	{
		cout<<"�����һ������Ϊ��"<<GetAge()<<"��"<<endl;
	}
};
class Pig:public Mammalia
{
public:
	Pig(int age):Mammalia(age)
	{
		cout<<"��������...\n";
	}
	virtual ~Pig()
	{
		cout<<"��������...\n";
	}
	virtual void Sleep()
	{
		cout<<"��ϲ����������˯����\n";
	}
	virtual void Eat()
	{
		cout<<"������ʳ�ද�\n";
	}
	virtual void Propagate()
	{
		cout<<"��Ҳͨ����̥��ֳ�����\n";
	}
	virtual void Move()
	{
		cout<<"����������·...\n";
	}
	virtual void Body()
	{
		cout<<"�����ë��\n";
	}
	virtual void Show()
	{
		cout<<"����ΪҪ�������˳ԣ�����һ������Ϊ��"<<GetAge()<<"��"<<endl;
	}
};
int main()
{
	Animal*p=0;
	int choice=0;
	bool quit=false;
	while (1)
	{
		cout<<"(1)����(2)����(3)����(0)�˳�";
		cin>>choice;
		switch(choice)
		{
		case 1:p=new Pig(1);
			break;
		case 2:p=new Human(80);
			break;
		case 3:p=new Bird(50);
			break;
		default:quit=true;
			break;
		}
		if (quit)
		{
			break;
		}
		p->Show();
		p->Eat();
		p->Propagate();
		p->Move();
		p->Sleep();
		p->Body();
		cout<<"\n";
		delete p;
	}
	return 0;
}