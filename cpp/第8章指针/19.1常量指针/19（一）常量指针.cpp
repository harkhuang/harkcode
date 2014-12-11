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
   A*p=new A;
   cout<<p<<endl;
   p=p+1;
   cout<<p<<endl;
   A*const p1=new A;
   p1++;
   p1->set(11);
   cout<<p1->get();
   return 0;
}