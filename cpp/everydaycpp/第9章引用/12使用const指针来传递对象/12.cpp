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
const A*const func(const A *const one)
{
	one->get();
	//one->set(99);
	//one++;
	return one;
}
int main()
{
	A a;
	a.set(11);
	const A*const p=func(&a);
	//p++;
	//p->set(11);
	cout<<p->get()<<endl;
	return 0;
}