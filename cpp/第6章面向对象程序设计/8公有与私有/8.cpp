#include <iostream>
using std::cout;
class Human
{
public:
	void set(int w)
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
	int print(){return weight;}
private:
	int weight;
};
int main()
{
	Human Tom;
	Tom.set(-1);
	cout<<"��ķ������Ϊ��"<<Tom.print()<<"\n";
	Human Mike;
	Mike.set(101);
	cout<<"���˵�����Ϊ��"<<Mike.print()<<"\n";
	return 0;
}