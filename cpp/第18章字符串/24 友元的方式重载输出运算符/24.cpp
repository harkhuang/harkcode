//��18.24  ��Ԫ�ķ�ʽ������������

#include <iostream>
using namespace std;
class A 
{
public:
	A(int x,int y){rx=x;ry=y;}
	friend ostream& operator<<(ostream &s,const A c)
	{
		s<<c.rx;
		s<<c.ry;
		return s;
	}
	
private:
	int rx;
	int ry;
};

int main()
{
	A a(3,4),b(5,6);
	cout<<a<<b<<endl;
	return 0;
}
