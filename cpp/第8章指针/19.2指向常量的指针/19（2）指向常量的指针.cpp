#include <iostream>
using namespace std;
class A 
{
public:
	int get() const{return i;}
	void set(int x){i=x;}
private:
	int i;

};
int main()
{
   const A*p=new A;
   p=p+1;
   p->set(11);
   return 0;
}