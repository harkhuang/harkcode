#include <iostream>
using namespace std;
class A 
{
public:
	A(){cout<<"ִ�й��캯������һ������\n";}
	A(A&){cout<<"ִ�и��ƹ��캯�������ö���ĸ���\n";}
	~A(){cout<<"ִ����������ɾ���ö���\n";}
	void set(int i){x=i;}
	int get()const{return x;}
private:
	int x;
};
const A& func(const A & one)
{
	//one.set(33);
	return one;
}
int main()
{
	A a;
	a.set(11);
	A const &b=func(a);
	cout<<b.get()<<endl;
	//b.set(33);
    cout<<b.get()<<endl;
	return 0;
}
