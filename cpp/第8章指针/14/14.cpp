#include <iostream>
using namespace std;
class Human
{
public:
	int get()const{return *i;}
	void set(int x){*i=x;}
	~Human();
	Human();
private:
	int *i;
};
int main()
{
	Human *p=new Human;
	//p->set(1);
	cout<<p->get()<<endl;
	delete p;
	return 0;
}
Human::Human()
{
	cout<<"���캯��ִ����...\n";
	i=new int(999);
}
Human::~Human()
{
	cout<<"�����캯��ִ����...\n";
	delete i;
}