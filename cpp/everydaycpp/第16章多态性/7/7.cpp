#include <iostream>
using namespace std;
class Animal 
{
public:
	Animal(int);
	virtual ~Animal(){cout<<"析构动物...\n";}
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
	cout<<"创建动物...\n";
}
class Mammalia:public Animal
{
public:
	Mammalia(int age):Animal(age)
	{
		cout<<"创建哺乳类...\n";
	}
	virtual ~Mammalia()
	{
		cout<<"析构哺乳类...\n";
	}
	virtual void Propagate()
	{
		cout<<"哺乳类是胎生动物，通过胚胎来繁殖后代。\n";
	}
};
class Bird:public Animal
{
public:
	Bird(int age):Animal(age)
	{
		cout<<"创建鸟类...\n";
	}
	virtual ~Bird()
	{
		cout<<"析构鸟类...\n";
	}
	virtual void Sleep()
	{
		cout<<"鸟类喜欢站着睡觉。\n";
	}
	virtual void Eat()
	{
		cout<<"极个别鸟类吃肉，其他都是吃素。\n";
	}
	virtual void Propagate()
	{
		cout<<"鸟类是卵生动物，通过排卵来繁殖后代。\n";
	}
	virtual void Move()
	{
		cout<<"鸟类可以飞...\n";
	}
	virtual void Body()
	{
		cout<<"鸟类体表被覆羽毛，前肢变为翼！\n";
	}
	virtual void Show()
	{
		cout<<"鸟类的一般寿命为："<<GetAge()<<"年"<<endl;
	}
};
class Human:public Mammalia 
{
public:
	Human(int age):Mammalia(age)
	{
		cout<<"创建人类...\n";
	}
	virtual ~Human()
	{
		cout<<"析构人类...\n";
	}
	virtual void Sleep()
	{
		cout<<"人类要在床上睡觉。\n";
	}
	virtual void Eat()
	{
		cout<<"大多数人不吃生食。\n";
	}
	virtual void Propagate()
	{
		cout<<"人类通过胚胎繁殖后代。\n";
	}
	virtual void Move()
	{
		cout<<"人类靠两条腿走路...\n";
	}
	virtual void Body()
	{
		cout<<"人类体表无毛！\n";
	}
	virtual void Show()
	{
		cout<<"人类的一般寿命为："<<GetAge()<<"年"<<endl;
	}
};
class Pig:public Mammalia
{
public:
	Pig(int age):Mammalia(age)
	{
		cout<<"创建猪类...\n";
	}
	virtual ~Pig()
	{
		cout<<"析构猪类...\n";
	}
	virtual void Sleep()
	{
		cout<<"猪喜欢在烂泥里睡觉。\n";
	}
	virtual void Eat()
	{
		cout<<"猪是杂食类动物。\n";
	}
	virtual void Propagate()
	{
		cout<<"猪也通过胚胎繁殖后代。\n";
	}
	virtual void Move()
	{
		cout<<"猪靠四条腿走路...\n";
	}
	virtual void Body()
	{
		cout<<"猪体表被毛！\n";
	}
	virtual void Show()
	{
		cout<<"猪因为要被人宰了吃，所以一般寿命为："<<GetAge()<<"年"<<endl;
	}
};
int main()
{
	Animal*p=0;
	int choice=0;
	bool quit=false;
	while (1)
	{
		cout<<"(1)猪类(2)人类(3)鸟类(0)退出";
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