#include <iostream>
using namespace std;
void show();
void show()
{
	cout<<"hello world\n";
}
class Human
{
public:
	void set(int w);

	int show(){return weight;}
private:
	int weight;
};
void Human::set(int w)
{
	if (w>0&&w<100)
	{
		weight=w;
	}
	else
	{
		cout<<"�뽫set�����Ĳ�������Ϊһ������0��С��100�����֣�����Ĭ�Ϸ���0\n";
		weight=0;
	}
}
int main()
{
	/*Human Tom;
	Tom.set(80);
	cout<<"��ķ������Ϊ��"<<Tom.show()<<"\n";
	Human Mike;
	Mike.set(90);
	cout<<"���˵�����Ϊ��"<<Mike.show()<<"\n";
	*/
	show();
	return 0;
}
