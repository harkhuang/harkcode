#include <iostream>
using namespace std;
class A 
{
public:
	void set(int =30,int=5);
	void count(bool=false);
private:
	int w;
	int h;
};
void A::set(int width,int height)
{
	w=width;
	h=height;
}
void A::count(bool val)
{
	if (val==true)
	{
		cout<<"val��ֵΪ��ʱ��"<<w*h<<endl;
	}
	else
	{
		cout<<"val��ֵΪ��ʱ��"<<w*h/2<<endl;
	}
}
int main()
{
	A a;
	a.set();
	a.count();
	a.count(true);
	return 0;
}

1�����غ���ʹ�÷��㣬������⡣
Ĭ�ϲ����ĺ����粻�ӱ�ע�Ļ������ױ����ԣ�
�������ױ��в�����ͬ���������ǡ�
2������Ĭ�ϲ����ĺ������ص��ǲ�������ֵ��
�����غ������ص��ǲ��������͡�