#include <iostream>
using namespace std;
class Human
{
public:
	int get()const{return i;}
	void set(int x){i=x;}
private:
	int i;
};
int main()
{
	Human *p=new Human;
	p->set(1);
	cout<<p->get()<<endl;
	delete p;
	return 0;
}
