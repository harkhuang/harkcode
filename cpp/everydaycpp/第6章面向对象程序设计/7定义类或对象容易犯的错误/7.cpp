#include <iostream>
using std::cout;
class Human
{
public:
	void walk(){cout<<"�����ˣ��һ���·��\n";}
	void speak(){cout<<"�����ˣ��һ�˵����\n";}
	void run(){cout<<"�����ˣ��һ��ܲ�!\n";}
	void eat(){cout<<"�����ˣ��һ�Է���\n";}
	void sleep(){cout<<"�����ˣ��һ�˯����\n";}
	
	
};
int main()
{
	Human Tom;
	Tom.walk();
	Tom.eat();
	Tom.run();
	Tom.speak();
	Tom.sleep();
	return 0;
}