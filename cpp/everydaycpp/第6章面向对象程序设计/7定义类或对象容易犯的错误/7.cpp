#include <iostream>
using std::cout;
class Human
{
public:
	void walk(){cout<<"我是人，我会走路！\n";}
	void speak(){cout<<"我是人，我会说话！\n";}
	void run(){cout<<"我是人，我会跑步!\n";}
	void eat(){cout<<"我是人，我会吃饭！\n";}
	void sleep(){cout<<"我是人，我会睡觉！\n";}
	
	
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